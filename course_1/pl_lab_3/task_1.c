 /* ������� �.�.
  * 17-���
  * ������� 10
  *
  * ����� ����������������
  * ������������ �3
  * ������� 1(40 ���.)
  * ����������� ��������� �������� �������� �������. ���� � ����� ������� ������������ � ���� ������.
  * ����� ������������ ������ ������� N. ������������� ������ � ������� ����������� �������� ������� ����� ��� ���������. ������: 2.15 3.1 4.05 5.25 6.2 7.3 -> 4.05 3.1 2.15 6.2 5.25 7.3
  */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  setlocale(LC_ALL, "Rus");

  int n;
  printf("������� ����� �������: ");  // ����������� � ����� ��������
  if (scanf("%d", &n) != 1) exit(0);  // ���� ����� �������
  fflush(stdin);

  double arr[n];  // �������� ������� ������������� ����
  printf("������� �������� ������� ����� ������(������� �����): ");
  for (int i = 0; i < n; i++)
    if (scanf("%lf", &arr[i]) != 1) exit(0);
  fflush(stdin);

  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      if(fmod(arr[j], 1) > fmod(arr[j+1], 1)) {
        double tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }

  for(int i = 0; i < n; i++) printf("%lf ", arr[i]);
  printf("\n");

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}
