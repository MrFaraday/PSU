#pragma once

#include <Windows.h>

#define M_PI 3.14159265358979323846
#define BLACK_s 1
#define WHITE_s 2
#define BLACK_can_move 3
#define WHITE_can_move 4

// ������� �����
// 0 - ������ ������
// 1 - ������ ������� �����
// 2 - ����� ������� �����
// 3 - ����������� ���� ��� ������
// 4 - ����������� ���� ��� �����
extern char board[8][8];

extern bool gameMode;  // ����� ����: 0 - ���� � ��, 1 - ���� �� 2 ������

extern USHORT
  wndWidth,       // ������ ����
  wndHeight,      // ������ ����

  fieldWidth,     // ������ ������� ����
  fieldHeight,    // ������ ������� ����

  xInit,          // ����� ���������� �����
  yInit,
  boardSize,      // ������ �����

  blackScore,     // ���-�� ����� � ������
  whiteScore,     // ���-�� ����� � �����
  whoMoves;       // ��� �����

extern WCHAR
  firstString_buff[32],   // ����� ������ ������
  secondString_buff[32];  // ����� ������ ������
