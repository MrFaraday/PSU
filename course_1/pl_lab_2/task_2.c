/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �2
 * ������� 2(40 ���.)
 * ����������� ��������� �������� �������� �������. ���� ������ ������������ �� ��������� ������, ���� �� ��� �� ������ ����. ��� ���������� ��������� ������������ �������� ������ switch.
 * ���� ��� ����� �����: D (����) � M (�����), ������������ ���������� ���� ����������� ����. ������� �������� D � M ��� ����, �������������� ���������.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

int main(void) {
  setlocale(LC_ALL, "Rus");

	int d, m;

  start:
	printf("������� ����� D(����������� �����): ");
  if (scanf("%d", &d) != 1) exit(0);
  fflush(stdin);
  printf("������� ����� M(����������� �����): ");
  if (scanf("%d", &m) != 1) exit(0);
  fflush(stdin);

  switch (d <= 0 || d >= 32 || m <= 0 || m >= 13) {
    case 1:
      printf("\n���������� ���.\n\n");
      goto start;
    default:
      break;
  }

  switch (d >= 2) {
    case 1:
      printf("\n%d.%d\n", --d, m);
      break;
    case 0:
      switch (m) {
        case 1:
          printf("\n%d.%d\n", 31, 12);
          break;
        case 2:
          printf("\n%d.%d\n", 31, 1);
          break;
        case 3:
          printf("\n%d.%d\n", 29, 2);
          break;
        case 4:
          printf("\n%d.%d\n", 31, 3);
          break;
        case 5:
          printf("\n%d.%d\n", 30, 4);
          break;
        case 6:
          printf("\n%d.%d\n", 31, 5);
          break;
        case 7:
          printf("\n%d.%d\n", 30, 6);
          break;
        case 8:
          printf("\n%d.%d\n", 31, 7);
          break;
        case 9:
          printf("\n%d.%d\n", 31, 8);
          break;
        case 10:
          printf("\n%d.%d\n", 30, 9);
          break;
        case 11:
          printf("\n%d.%d\n", 31, 10);
          break;
        case 12:
          printf("\n%d.%d\n", 30, 11);
          break;
        default:
          printf("���-�� ����� �� ���...\n");
      }
      break;
    default:
      printf("���-�� ����� �� ���...\n");
  }

  printf("\n������� ENTER ��� ������ ...\n");

	return 0;
}
