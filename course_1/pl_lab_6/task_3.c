/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �6
 * ������� 3(10 ���.)
 * ���������� ����������� ��������� �������� �������� �������. ��� ���������� ������� ������������ �������� �������� ��������������� ����� ����������. � ������� ������� main ����������� ������������ ������ ������������� ������� � ��������� ������ ����������.
 * ����������� ������� ������ ������������� ������� ��������, ����� ���������� � �������� ���������� ����� �����.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>

int max_even(int, ...);

int main(void) {
  setlocale(LC_ALL, "Rus");

  printf("������� 5 ����� ����� � ���� ������: ");
  int var1, var2, var3, var4, var5;
  if (scanf("%d", &var1) != 1) exit(0);
  if (scanf("%d", &var2) != 1) exit(0);
  if (scanf("%d", &var3) != 1) exit(0);
  if (scanf("%d", &var4) != 1) exit(0);
  if (scanf("%d", &var5) != 1) exit(0);
  fflush(stdin);

  int max = max_even(5, var1, var2, var3, var4, var5);

  if (max == -1 || max == 0)
    printf("\n������ ����� ���.\n");
  else
    printf("\n������������ ������ �����: %d\n", max);

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}

int max_even(int n, ...) {
  va_list ap;
  int i = 0;
  int max = -1;
  va_start(ap, n);

  while(i < n) {
    int var = va_arg(ap, int);
    if (var % 2 == 0 && var > max) max = var;
    i++;
  }

  va_end(ap);
  return max;
}
