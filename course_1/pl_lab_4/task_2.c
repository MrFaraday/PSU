/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �4
 * ������� 2(25 ���.)
 * ����������� ��������� �������� �������� �������. ������������ ����� ����� �� ����� 80 ��������. ��� ���������� ��������� ���������� ������������ ������� ��� ��������� ����� �� ��������� stdlib.h � string.h
 * ������ ������, ���������� ����� � ������������ �����. ����� ��������� �����, ���� � ���� ������� ������� �����. ������������ ��� ������, ������ �� ������� ����� ��������� ������ ������������ �����, � ������ � ������ ����� � ��� �� ������� ����������, ��� � �������� ������.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
  setlocale(LC_ALL, "Rus");

  char str[42000];
  printf("������� ������: ");
  gets(str);

    // ������� ���������� �����
  int quantity = 0;
  for (int i = 0; str[i] != '\0'; i++)
    if ((str[i] != ' ' && str[i-1] == ' ') || (str[i] != ' ' && i == 0)) ++quantity;

    // ����� ������� ����
  char *s;
  int
    longest = 0,
    counter = 0;
  s = str;
  while (*s) {
    if (*s++ == ' ') counter = 0;
      else counter++;
    if (longest < counter) longest = counter;
  }

    // ������� ������ � �������
  char nums[quantity][longest+1];
  int curr_num = 0;
  counter = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ') nums[curr_num][counter++] = str[i];
    if (str[i] == ' ' && str[i-1] != ' ') nums[curr_num][counter++] = '\0';
    if (str[i] == ' ' && str[i+1] != ' ') {
      counter = 0;
      curr_num++;
    }
    if (str[i] != ' ' && str[i+1] == '\0') nums[curr_num][counter] = '\0';
  }

  char
    int_str[42000],
    float_str[42000],
    *ints,
    *fs;
  ints = int_str;
  fs = float_str;
  for (int i = 0; i < quantity; i++) {
    if (fmod(atof(nums[i]), 1) == 0) {
      s = nums[i];
      while (*s) *ints++ = *s++;
      *ints++ = ' ';
    } else {
      s = nums[i];
      while (*s) *fs++ = *s++;
      *fs++ = ' ';
    }
  }
  *ints = '\0';
  *fs = '\0';

  puts(int_str);
  puts(float_str);

  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}
