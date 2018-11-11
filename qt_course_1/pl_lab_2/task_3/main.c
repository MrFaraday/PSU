/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �2
 * ������� 3(10 ���.)
 * ����������� ��������� �������� �������� �������. ��� ���������� ��������� ������������ ��������� ������ (for, while, do�while).
 * ���� ��� ����� �����: � � �. ������� ��� ����� �����, ������������� ����� ������� � � � � ������� �����������.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

int main(void) {
  setlocale(LC_ALL, "Rus");

  int a, b;
  printf("������� A(����� �����): ");
  if (scanf("%d", &a) != 1) exit(0);
  fflush(stdin);
  printf("������� B(����� �����): ");
  if (scanf("%d", &b) != 1) exit(0);
  fflush(stdin);

  while (a != b) {
    (a > b) ? printf("%d\n", ++b) :
      printf("%d\n", ++a);
    if (abs(a - b) == 1) break;
  }

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}
