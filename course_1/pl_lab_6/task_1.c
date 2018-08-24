/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �6
 * ������� 1(10 ���.)
 * �� ���� �������� ���������� ����������� ��������� �������� �������� �������. � �������� ������� main ����������� ������������ ������ ������������� ���������������� �������. ���� � ����� ���� ������ �������������� � ������� main.
 * ����������� ������� ��� ���������� ����� ����: ln(n)/n!. ��������� ������������� ������� ��������� ����� ���� � ������� N �� ������� M.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

double row_sum(int, int);
int fact(int);

int main(void) {
  setlocale(LC_ALL, "Rus");

  printf("������� ��������� �������(����� �����): ");
  int n;
  if (scanf("%d", &n) != 1) exit(0);

  printf("������� �������� �������(����� �����): ");
  int m;
  if (scanf("%d", &m) != 1 || n > m) exit(0);

  printf("����� ����� ���� ln(n)/n! �� ������� %d �� %d �����: %lf", n, m, row_sum(n, m));

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}

double row_sum(int n, int m) {
  if (n == m) {
    return log(n)/fact(n);
  } else {
    return log(n)/fact(n) + row_sum(n + 1, m);
  }
}

int fact(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}
