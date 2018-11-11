/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �7
 * ������� 1(25 ���.)
 * � ������ ������� ���������� ����������� ��������� ���������� �����(��� ������) �������� ������� ��������. ��� ����� ���������� � ���������� ��������� ������, � ���� ��� �� �������, �� �������� � ����������.
 * ���� �������� ����� �����. �������� ��� �����, �������������� ����� ��� � ������������� ������� ���������� 2^n (��� n � �������). ��������: 8 � 2^3, 32 � 2^5.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Rus");

  int from_arg = 1;
  char file_name[260];
  FILE
    *file = fopen(argv[1], "r"),
    *temp = fopen("~tmp", "w");
  if (!file) {
    printf("������� ��� �����: ");
    gets(file_name);
    file = fopen(file_name, "r");

    while (!file) {
      printf("���������� ���: ");
      gets(file_name);
      file = fopen(file_name, "r");
    }
    from_arg = 0;
  }

  char c[2];
  double num;
  c[1] = '\0';

  for (int i = 0; (c[0] = getc(file)) != EOF; i++) {
    if (atof(c) == 0) {
      fprintf(temp, "%s", c);
      continue;
    }

    fseek(file, -1, SEEK_CUR);

    fscanf(file, "%lf", &num);
    if (fmod(log2(num), 1) != 0) {
      fprintf(temp, "%lf", num);
      continue;
    }

    fprintf(temp, "2^%d", (int) log2(num));
  }

  fclose(file);
  fclose(temp);

  if (from_arg) file = fopen(argv[1], "w");
    else file = fopen(file_name, "w");
  temp = fopen("~tmp", "r");

  for (int i = 0; (c[0] = getc(temp)) != EOF; i++) {
    fprintf(file, "%s", c);
  }

  remove("~tmp");
  printf("�������!!!\n");

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}
