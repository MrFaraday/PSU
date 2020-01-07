/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������� � ��������� ��������� ������
 * ������������ �2
 * ������� 3
 * ������� n ������ � ����� ��������, ��������� � ������. �������� �������������� �� ���� � ���� ����� ��������� �������: ������ �������� �� ����, ������ � ��� ��� ������, ������ � �� ����, ��������� � ��� ��� ������ � �.�., ���� ��� �������� �� ����� �������� �� ����. ����� ������ ���� �������� ������������ �������� � ������, ����� ����������� �� ����� �������� ������������ �� �����: �����, ������, �����, ������ � �.�.?
 */

 // ���������� �����
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include <queue>

void clear(std::queue<bool>& qu);

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  std::queue<bool> qu;
  std::queue<bool> temp;
  int n;
  std::wcout << L"Enter quantity: ";
  std::wcin >> n;
  if (n <= 0) return 0;

  int i = n;  // �������� �� �����
  bool next = true;
  bool sw = true;
  bool test;
  while (sw) {
    clear(qu);
    i = n;
    while (i > 1) {
      if (next) {
        qu.push(true);
        next = false;
      } else {
        qu.push(false);
        next = true;
      }
      qu.push(qu.front());
      qu.pop();
      i--;
    }

    clear(temp);
    while (!qu.empty()) {
      temp.push(qu.front());
      qu.pop();
    }
    temp.push(next);

    while (!temp.empty()) {
      qu.push(temp.front());
      test = temp.front();
      temp.pop();
      if (test == true && temp.empty()) sw = false;
      else next = false;
    }
  }
  
  while (!qu.empty()) {
    std::wcout << qu.front();
    qu.pop();
  }

  return 1;
}

void clear(std::queue<bool>& qu) {
  std::queue<bool> empty;
  empty.swap(qu);
}
