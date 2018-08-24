/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �7
 * ������� 2(10 ���.)
 * � ������ ������� ���������� ����������� ��������� ��������� �����(��� ������) �������� ������� ��������. ��� ����� ���������� � ���������� ��������� ������, � ���� ��� ��� �� �������, �� �������� � ����������. ��� ���������� ������� ����������� ��������� ��������� ��������� �����.
 * ��� ����, ���������� ����� ����� (��� int). ��������� ����� ���� �����, ���������� ������ ��� � ������������� ������� (1,2,4,8,...).
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Rus");

  char file_name[260];
  int choise = 0;
  FILE *file = NULL;

  int
    result = 0,
    numb = 0,
    *pointer;
  pointer = &numb;

  if (argv[1]) strcpy(file_name, argv[1]);

  while (choise != 'q') {
    printf("\n\n������������� ����(G) ������� ����(R) �����(Q)\n");
    choise = getch();

    if (choise == 'g') {
      file = NULL;
      if (argv[1]) {
        printf("\n����, �������� � ��������� ��������� ������ ����� �����������(���� �� ����������)\n");
        printf("����������?\n������� N ��� ������, ����� ������� ��� �����������");
        if (getch() == 'n') {
          printf("\n");
          continue;
        }
        printf("\n");
      }

      file = fopen(file_name, "wb");
      if (!file) {
        printf("\n������� ��� �����:\n");
        gets(file_name);
        file = fopen(file_name, "wb");
      }

      printf("������� ��� ����� �����:\n");
      int
        numb,
        *pointer;

      if (scanf("%d", &numb) != 1) exit(0);
      while (!feof(stdin)) {
        pointer = &numb;
        fwrite(pointer, sizeof (int), 1, file);
        if (getchar() == '\n') break;
        if (scanf("%d", &numb) != 1) exit(0);
      }
      fflush(stdin);

      printf("���� ������������!\n");

      fclose(file);
    }

    if (choise == 'r') {
      file = NULL;
      if (!file) file = fopen(file_name, "rb");
      if (!file) {
        printf("\n������� ��� �����: ");
        gets(file_name);
        file = fopen(file_name, "rb");

        while (!file) {
          printf("���������� ���: ");
          gets(file_name);
          file = fopen(file_name, "rb");
        }
      }

      result = 0;
      numb = 0;

      rewind(file);
      while (!feof(file)) {
        fread(pointer, sizeof (int), 1, file);
        if (fmod(log2(numb), 1) == 0) result += numb;
      }

      fclose(file);

      printf("\nC����  �����, ���������� ������ ��� � ������������� ������� �����: %d\n", (int) result);
    }

  }

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}
