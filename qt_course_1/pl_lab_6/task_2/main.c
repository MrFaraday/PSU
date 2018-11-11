/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �6
 * ������� 2(25 ���.)
 * �� ���� �������� ���������� ����������� ��������� �������� �������� �������. ��� ���������� ������� ������������ �������� �������� ���������� �� ������. � �������� ������� main ����������� ������������ ������ ������������� ���������������� �������. ���� � ����� ���� ������ �������������� � ������� main.
 * ����������� �������, �������������� ����� � ������������ ������� ���� ��������� �������� ������� ���� � ����� �� ��������. ������ � ��� ������ ���������� � �������� ����������. ������� ������ ������� ������� ��������� ���������. ��������� ������������� ������� ����������� ����� � N ��������, ��������� �������������.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

struct Positions {
  int firstPos;
  int secPos;
};

struct Positions search(float [], int *);

int main(void) {
  setlocale(LC_ALL, "Rus");

  printf("������� ����������� ��������: ");
  int n;
  if (scanf("%d", &n) != 1) exit(0);
  fflush(stdin);

  int poss[n][2];
  for (int i = 1; i <= n; i++) {
    printf("\n������� ����������� ��������� ������� %d: ", i);
    int size;
    if (scanf("%d", &size) != 1) exit(0);
    fflush(stdin);

    float arr[size];
    printf("������� �������� ������� %d ����� ������(������� �����): ", i);
    for (int j = 0; j < size; j++)
      if (scanf("%f", &arr[j]) != 1) exit(0);
    fflush(stdin);

    struct Positions result = search(arr, &size);
    poss[i][0] = result.firstPos;
    poss[i][1] = result.secPos;
  }

  for (int i = 1; i <= n; i++) printf("\n� ������� %d ����������� ������� � �������� %d � %d.", i, poss[i][0]+1, poss[i][1]+1);

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}

struct Positions search(float arr[], int *size) {
  float indexes[*size][3];
  for (int i = 0; i < *size; i++) {
    indexes[i][0] = i;
    for (int j = 0; j < *size; j++) {
      if (j == 0 && i != 0) {
        indexes[i][1] = j;
        indexes[i][2] = fabsf(arr[i] - arr[j]);
      }
      if (j == 0 && i == 0) {
        indexes[i][1] = j+1;
        indexes[i][2] = fabsf(arr[i] - arr[j+1]);
      }
      if (indexes[i][2] > fabsf(arr[i] - arr[j]) && j != i) {
        indexes[i][1] = j;
        indexes[i][2] = fabsf(arr[i] - arr[j]);
      }
    }
  }

  int min = 0;
  for (int i = 0; i < *size; i++)
    if (indexes[min][2] > indexes[i][2]) min = i;

  struct Positions result;
  result.firstPos = (int) indexes[min][0];
  result.secPos = (int) indexes[min][1];

  return result;
}
