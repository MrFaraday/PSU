/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������� � ��������� ��������� ������
 * ������������ �6
 * ������� 3
 * ������������ �������� ������ ��������. ��� ������ ������� ������� ������� ������ ����������. ������� �������� � �������������� ������ �� �����.
 */

#define CONSOLE_OUTPUT    _setmode(_fileno(stdout), _O_U16TEXT); \
                          _setmode(_fileno(stdin),  _O_U16TEXT); \
                          _setmode(_fileno(stderr), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#define OUT      std::wcout
#define IN       std::wcin
#define STR      std::wstring

#include <set>
#include "..\..\sadp_lab-4\task-1\Binary_Tree.h"

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  Binary_Tree<wchar_t> chars;
  for (int i = 0; i < 100; i++)
    chars.insert((rand() % 33) + L'�', i);
  chars.printTree();

  std::set<wchar_t> vowels = { L'�', L'�', L'�', L'�', L'�', L'�', L'�', L'�', L'�' };
  chars.delTree_lab6Func(vowels);
  OUT << L"\r\n";
  OUT << L"������ ����� �������� ������ ����������� � ������� ������:\r\n";
  chars.printTree();

  return 1;
}
