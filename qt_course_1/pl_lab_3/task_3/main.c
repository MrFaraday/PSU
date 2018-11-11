/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �3
 * ������� 3(10 ���.)
 * ����������� ��������� �������� �������� �������. ���� � ����� ������ ������������ ���������. ���� � ������� �������, ��� ������� ����������, �� �� ������ �������� ����� ������.
 * ������ ������������� ������� �������� NxM. ���������� ������ ������� � ������ �������� ����������� ������������ ������� �������.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

int main(void) {
  setlocale(LC_ALL, "Rus");

  int n, m;
  printf("������� ����������� ����� �������(����� �����): ");
  if (scanf("%d", &n) != 1) exit(0);
  fflush(stdin);

  printf("������� ����������� �������� �������(����� �����): ");
  if (scanf("%d", &m) != 1) exit(0);
  fflush(stdin);

  int arr[n][m];
  for (int i = 0; i < n; i++) {
    printf("������� �������� ������� ������ %d ����� ������(����� �����): ", i + 1);
    for (int j = 0; j < m; j++)
      if (scanf("%d", &arr[i][j]) != 1) exit(0);
    fflush(stdin);
  }

  int
    n_max = 0,
    m_max = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (arr[i][j] > arr[n_max][m_max]) {
        n_max = i;
        m_max = j;
      }
    }
  }

  printf("\n������������ ������� ��������� � ������ %d � ������� %d\n", n_max + 1, m_max + 1);

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}
