/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �2
 * ������� 1(25 ���.)
 * ����������� ��������� �������� �������� �������. ���� ������ ������������ �� ��������� ������, ���� �� ��� �� ������ ����. ��� ���������� ��������� ������������ �������� ������� if ... else.
 *     { 3*k^3 + 3*p^2,  k > |p|
 * a = { |k - p|,        3 < k < |p|
 *     { (k - p)^2,      k = |p|
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  setlocale(LC_ALL, "Rus");

  int a, k, p;
  printf("������� ���������� K(����� �����): ");
  if (scanf("%d", &k) != 1) exit(0);  // ���� ����� K
  fflush(stdin);

  printf("������� ���������� P(����� �����): ");
  if (scanf("%d", &p) != 1) exit(0);  // ���� ����� P
  fflush(stdin);

  if (k > abs(p)) {
    a = 3 * pow(k, 3) + 3 * pow(p, 2);
    printf("\nA = %d\n", a);
  }
  else if (3 < k && k < abs(p)) {
    a = abs(k - p);
    printf("\nA = %d\n", a);
  }
  else if (k == abs(p)) {
    a = pow(k - p, 2);
    printf("\nA = %d\n", a);
  }
  else printf("3 >= k < |p|");

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}
