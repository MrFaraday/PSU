/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������� � ��������� ��������� ������
 * ������������ �2
 * ������� 2
 * ���� �������� ������������������, ��������� �� ����� � ������ ������ ��������� �������� �����. ��� ����������, ����� �� �������� � ��� ����� � ����� �������������� �������� ���, ����� ���������� ���������� �������������� ���������.
 */

 // ���������� �����
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include <stack>

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  std::stack<wchar_t> s;

  std::wstring seq;
  std::wcout << L"Enter sequence: ";
  std::wcin >> seq;

  const wchar_t* p = seq.c_str();
  while (*p != L'\0') {
    if (!(*p == L'(' || *p == L'[' || *p == L'{' || *p == L'}' || *p == L']' || *p == L')')) {
      std::wcout << L"Bad input";
      return 0;
    }

    switch (*p) {
    case L'(':
    case L'[':
    case L'{':
      s.push(*p);
      break;
    case L'}':
      if (s.top() != L'{') {
        std::wcout << L"NO";
        return 0;
      } else s.pop();
      break;
    case L']':
      if (s.top() != L'[') {
        std::wcout << L"NO";
        return 0;
      } else s.pop();
      break;
    case L')':
      if (s.top() != L'(') {
        std::wcout << L"NO";
        return 0;
      } else s.pop();
      break;
    default:
      break;
    }
    
    p++;
  }

  std::wcout << L"YES";

  return 1;
}
