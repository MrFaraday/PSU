/* ������� �.�.
 * 17-���
 * ������� 10
 *
 * ����� ����������������
 * ������������ �5
 * ������� 1(40 ���.)
 * �� ���� �������� ���������� ����������� ���������, � ������� ����������� ���� ������ ������� ������������� ����, � ����� � ��������� ������. ������� � ��������� ������ ��������� ������ ������ (����� �����), � ��� ������ ��������� � ���� ������������� ������� ��������. ���� ����� ������ �������������� � ����� ������. �������� �������� ���������� ����� ��������� �������. ��� ���������� ������� ������� ��������� (20 � 40 ������) ���������, ��� �������� ����, ������������ �������, ������ ���������, �������� ������� ����� �������� �� ���������� ���� � ����������� � ������� �������. ����������� ���� ���������� ��������� ������������.
 * ������� ������ �� �����, ���������� �� ������ ����������, � ������ ������� ������ ���������� �� ������� ���������.
 * ��������� 2:
 * - ����� ���������� ����������� (����� ������������� �������������� �����);
 * - ����� ��������� (������ 50 ��������);
 * - ����� ��������� (� ������� ��:��:��).
 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int time_convert(char *);

int main(void) {
  setlocale(LC_ALL, "Rus");

  int n;
  printf("������� ������ ������: ");
  if (scanf("%d", &n) != 1) exit(0);
  fflush(stdin);

  struct Message {
    int device_numb;
    char text[51];
    char time[9];
  };
  struct Message list[n];

  printf("\n������� ������ ��������� � �������:\n[� ���������� 4-� ������� �����] \"[����� ��������� �� 50 ��������]\" [���� � ������� ��:��:��]\n� ����� ���������� ��������� ������� ���� �� 4-�� ������.\n");
  for (int i = 0; i < n; i++) {
    char input[100];
    gets(input);
    char
      *input_p,
      numb[5],
      message[51],
      *message_p;

    for (int j = 0; j < 4; j++) if (!isdigit((int) input[j])) exit(0);
    strncpy(numb, input, 4);
    list[i].device_numb = atoi(numb);

    if (input[4] != ' ' || input[5] != '\"') exit(0);
    int counter = 1;
    input_p = &input[6];
    message_p = message;
    while (*input_p) {
      if (counter == 52) exit(0);
      if (*input_p == '\"') {
        *message_p = '\0';
        break;
      }
      *message_p++ = *input_p++;
      counter++;
    }
    strcpy(list[i].text, message);

    input_p = &input[6+counter];
    if (*input_p++ != ' ') exit(0);
    if (strlen(input_p) != 8) exit(0);
    char
      hr[3],
      min[3],
      sec[3],
      *time_p;
    time_p = input_p;
    strncpy(hr, time_p, 2);
    time_p = &input_p[3];
    strncpy(min, time_p, 2);
    time_p = &input_p[6];
    strncpy(sec, time_p, 2);
    if (
      !(isdigit((int) hr[0]) || isdigit((int) hr[1])) ||
      (1 > atoi(hr) || atoi(hr) > 23) ||
      !(isdigit((int) min[0]) || isdigit((int) min[1])) ||
      (1 > atoi(min) || atoi(min) > 59) ||
      !(isdigit((int) sec[0]) || isdigit((int) sec[1])) ||
      (1 > atoi(sec) || atoi(sec) > 59)
    ) exit(0);
    strcpy(list[i].time, input_p);
  }

  int
    sort_device,
    sort_time;
  printf("\n�������� ���������� �� ������ ��������� �� �����������(1) ��� �� ��������(0): ");
  if (scanf("%d", &sort_device) != 1) exit(0);
  fflush(stdin);
  if (!(sort_device == 1  || sort_device == 0)) exit(0);
  printf("�������� ���������� �� ������� ��������� ������� �������(1) ��� ������(0): ");
  if (scanf("%d", &sort_time) != 1) exit(0);
  fflush(stdin);
  if (!(sort_time == 1  || sort_time == 0)) exit(0);

  printf("\n");
  struct Message
    *ps_list[n],
    *temp;
  for (int i = 0; i < n; i++) ps_list[i] = &list[i];
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (
        (
          (sort_device == 1 && ps_list[i]->device_numb > ps_list[j]->device_numb) ||
          (sort_device == 0 && ps_list[i]->device_numb < ps_list[j]->device_numb)
        ) || ps_list[i]->device_numb == ps_list[j]->device_numb && (
            (sort_time == 1 && time_convert(ps_list[i]->time) < time_convert(ps_list[j]->time)) ||
            (sort_time == 0 && time_convert(ps_list[i]->time) > time_convert(ps_list[j]->time))
          )
      ) {
        temp = ps_list[i];
        ps_list[i] = ps_list[j];
        ps_list[j] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++) printf("%d \"%s\" %s\n", ps_list[i]->device_numb, ps_list[i]->text, ps_list[i]->time);
  printf("\n������� ENTER ��� ������ ...\n");

  return 0;
}

int time_convert(char *time) {
  char string[6] = {time[0], time[1], time[3], time[4], time[6], time[7]};
  return atoi(string);
}
