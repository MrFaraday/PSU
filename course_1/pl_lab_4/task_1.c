/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �4
 * ������� 1(40 ���.)
 * ����������� ��������� �������� �������� �������. ������������ ����� ����� �� ����� 50 ��������. ��� ���������� ��������� ������������� ������� ��� ������ �� �������� �� ��������� stdlib.h � string.h ���������. ���� �������� ������� ������ ����� �������� �� ���������� ����, �� ��������� ����������� ������������ ����������� ��������.
 * ���� ������ �����������. ����������� ��� ����� � ����������� � ���������� �������.
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>

int main(void) {
  setlocale(LC_ALL, "Rus");

  char str[42000];
  printf("������� ������: ");
  gets(str);

    // ������� ���������� ����
  int quantity = 0;
  for (int i = 0; str[i] != '\0'; i++)
    if ((str[i] != ' ' && str[i-1] == ' ') || (str[i] != ' ' && i == 0)) ++quantity;

    // ����� ������� �����
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
  char words[quantity][longest+1];
  int curr_word = 0;
  counter = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ') words[curr_word][counter++] = str[i];
    if (str[i] == ' ' && str[i-1] != ' ') words[curr_word][counter++] = '\0';
    if (str[i] == ' ' && str[i+1] != ' ') {
      counter = 0;
      curr_word++;
    }
    if (str[i] != ' ' && str[i+1] == '\0') words[curr_word][counter] = '\0';
  }

    // ����������
  char
    *p,
    *gen = str;
  int to_add;
  for (int k = 0; k < quantity; k++) {
    for (int h = 0; h < quantity; h++)
      if (words[h][0] != '\0') {
        to_add = h;
        break;
      }
    for (int i = 0; i < quantity; i++) {
      if (words[i][0] == '\0') continue;
      if (to_add != i) {
        s = words[i];
        p = words[to_add];
        while (*s) {
          if (*p == '\0') break;
          if (*s > *p) break;
          if (*s < *p) {
            to_add = i;
            break;
          }
          *s++;
          *p++;
          if (*s == '\0') to_add = i;
        }
      }
    }

    s = words[to_add];
    while (*s) *gen++ = *s++;
    if (k+1 != quantity) *gen++ = ' ';
    words[to_add][0] = '\0';
  }

  puts(str);
  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}
