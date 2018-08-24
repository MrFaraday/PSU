/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �6
 * ������� 3(10 ���.)
 * ���������� ����������� ��������� �������� �������� �������. ��� ���������� ������������ ��������� �� ������� � (���) ������� ���������� �� �������. � �������� � ��������� ��� �������� ������ � �������� ��������� �������� �������������.
 * ��� ������������ ������. ����������� ������ ����� ���������: � ������� ����������� �������� ���������; � ������� �������� ������� ����� ���������; � ������� ����������� ����� ������ ������� �������� ������� ����� ���������. � ������� ���������� ������ ������������ ��������� �� ������� ��������� ���� ���������. ������ ���������� �������� ������������.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void sort(double [], int, int (*)(double, double));
int inc(double, double);
int dec(double, double);
int what(double, double);

int main(void) {
  setlocale(LC_ALL, "Rus");

  printf("������� ����������� ��������� �������: ");
  int size;
  if (scanf("%d", &size) != 1) exit(0);
  fflush(stdin);

  double arr[size];
  printf("������� ��������� ������� ����� ������(������� �����): ");
  for (int i = 0; i < size; i++)
    if (scanf("%lf", &arr[i]) != 1) exit(0);
  fflush(stdin);

  printf("\n������� ������� ����������:\n");
  printf("1: � ������� ����������� �������� ����������\n");
  printf("2: � ������� �������� ������� ����� ���������\n");
  printf("3: � ������� ����������� ����� ������ ������� �������� ������� ����� ���������\n");
  int type;
  if (scanf("%d", &type) != 1) exit(0);
  fflush(stdin);
  if (!(type == 1 || type == 2 || type == 3)) exit(0);

  int (*compare)(double, double) = NULL;
  switch (type) {
    case 1:
      compare = inc;
      break;
    case 2:
      compare = dec;
      break;
    case 3:
      compare = what;
      break;
  }

  sort(arr, size, compare);
  for (int i = 0; i < size; i++)
    printf("%lf ", arr[i]);
  printf("\n");

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}

void sort(double arr[], int size, int (*compare)(double, double)) {
  double temp;
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (compare(arr[i], arr[j])) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
}

int inc(double a, double b) {
  if (a > b) return 1;
  return 0;
}

int dec(double a, double b) {
  if (fmod(a, 1) < fmod(b, 1)) return 1;
  return 0;
}

int what(double a, double b) {
  double x, y;
  modf(a * 10000, &x);
  modf(b * 10000, &y);

  int i = (int) x % 10000;
  int k = (int) y % 10000;

  i = i % 10 + (i/10 % 10) + (i/100 % 10) + (i/1000 % 10);
  k = k % 10 + (k/10 % 10) + (k/100 % 10) + (k/1000 % 10);

  if (i > k) return 1;
  return 0;
}
