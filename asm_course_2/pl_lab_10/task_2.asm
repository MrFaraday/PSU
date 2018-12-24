; ������� �.�.
; 17-���
; ������� 9
;
; ����� ����������������
; ������������ �10
; ������� 2
; ����������� ��������� ���������� ��������������� ���������. ��������� ������� � ����� ������� ���� ������ � ��������� ������. ��� �������� ����� �������� ����� ������������ 16 ���. ��� ������� ����������� � ��������� ������.
; (2*C-D/3)/(B-A/4)

.486                                      ;�������� ������ ������
.model small                              ;small - ������ ������ EXE-���������
Data SEGMENT use16
  ASSUME ds:Data
  ValA dw -100                            ;�������� A
  ValB dw 25                              ;�������� B
  ValC dw 200                             ;�������� C
  ValD dw -150                            ;�������� D
  Sign db 0                               ;������� �������������� ��������
  Strk db 7 dup(0), 0                     ;�������������� ������ ��� ������
Data ENDS
Stk SEGMENT use16 STACK
  ASSUME ss:Stk
  dw 256 dup(0)
Stk ENDS
Code SEGMENT use16
ASSUME cs:Code
start:

  mov ax, seg ValB                        ;������ � AX �������� Data
  mov ds, ax                              ;������ � DS AX
  mov ax, ValC                            ;������ � AX �������� C
  mov cx, 2                               ;������ � CX �������� 2
  imul cx                                 ;��������� AX*CX -> DX:AX
  
  push dx                                 ;������� � ���� ������� ����� ���������� �*2
  push ax                                 ;������� � ���� ������ ����� ���������� �*2
  
  xor dx, dx                              ;������� DX
  mov ax, ValD                            ;������ � AX �������� D
;//===================//  ����
  or ax, ax                               ;�������� AX �� ����
  jns next0                               ;���� ����� > 0, �� ������� �� next0
;//===================//  ��
  not dx                                  ;����������� DX ��� ������� ����� �������������� ����� DX:AX
;//===================//
next0:
  mov cx, 3                               ;������� � CX �������� 3
  idiv cx                                 ;����� DX:AX �� CX
  mov bx, ax                              ;�������� ��������� ������� � BX
  
  pop ax
  pop dx                                  ;������ ������� ��������� 2*C
  
  sub ax, bx
  
  push dx
  push ax                                 ;������� � ���� ��������� 2*C-D/3
 
  xor dx, dx
  mov ax, ValA
;//===================//  ����
  or ax, ax                               ;�������� AX �� ����
  jns next1                               ;���� ����� > 0, �� ������� �� next0
;//===================//  ��
  not dx                                  ;����������� DX ��� ������� ����� �������������� ����� DX:AX
;//===================//
next1:
  mov cx, 4
  idiv cx                                 ;����� �� 4
  
  mov bx, ValB                            ;���������� � AX
  sub bx, ax                              ;�������� A/4 �� B
  
  pop ax
  pop dx                                  ;������ 2*C-D/3
  
  idiv bx                                 ;����� 2*C-D/3[DX:AX] �� B-A/4[BX]
  
;//==================   ����� ����������
  
  or ax, ax                               ;�������� AX �� ����
  jns next6                               ;���� ����� > 0, �� ������� �� next6
  neg ax                                  ;����������� � ������������� �����
  mov byte ptr Sign, 1                    ;��������� � Sign ������� �������������� ����������
next6:
  lea si, Strk                            ;��������� � SI �������� Strk
  add si, 6                               ;��������� � ����� ������
  mov cx, 10                              ;������� � CX �������� 10
  next7:
    xor dx, dx                            ;������� DX
    div cx                                ;������� DX:AX / CX
    add dl, 48                            ;��������� ������� � ����� �0�
    mov ds:[si], dl                       ;���������� � ������
    or ax, ax                             ;�������� AX �� ����
    jz next8                              ;���� ����, �� ��������� �� next8
    dec si                                ;��������� SI �� 1
    jmp next7                             ;������� �� next7
next8:
  mov ax, 0b800h                          ;������� � AX ����� �������� �����������
  mov es, ax                              ;������������� ES �� ����������
  xor di, di                              ;������� DI
  mov ah, 0Fh                             ;� AH ���������� ��� �����
  cmp byte ptr Sign, 1                    ;���� ��������� ��� �������������, ��
  jnz next9                               ;������� �� next9
  mov al, '-'                             ;���������� � AL ��� �-�
  stosw                                   ;������ AX � ES:[DI]
  next9:
    lodsb                                 ;�������� � AL �� DS:[SI]
    or al, al                             ;�������� AL �� ����
    jz nextA                              ;���� ����, �� ������� �� nextA
    stosw                                 ;������ AX � ES:[DI]
    jmp next9                             ;������� �� next9
  nextA:
    in al, 60h                            ;������ � AL �� ����� 60h
    cmp al, 1                             ;��������� � 1 (ESC)
    jnz nextA                             ;���� �� �����, �� ������� �� nextA
    
  mov ax, 4c00h                           ;������ � AX ����� ������� ������
  int 21h                                 ;���������� ���������
  
Code ENDS
end start
