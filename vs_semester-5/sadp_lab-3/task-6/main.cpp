/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������� � ��������� ��������� ������
 * ������������ �3
 * ������� 6
 * ��������� ��������������� ��������������� ������ ������� ���������: ����������� � ���������, ����������� � ���������. ����������� ������ ������ ������ � ��������� ������������� ���������������� ������, �� ������� � ���� ������ ��������� ���������.
 */

 // ���������� �����
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT); _setmode(_fileno(stdin),  _O_U16TEXT); _setmode(_fileno(stderr), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include <list>
#include <string>

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  std::list<std::wstring> phoneNums;
  std::list<std::wstring>::iterator it = phoneNums.begin();
  // ����������
  {
    phoneNums.insert(it, L"1684618");
    phoneNums.insert(it, L"5201679");
    phoneNums.insert(it, L"101");
    phoneNums.insert(it, L"2571190");
    phoneNums.insert(it, L"9840180");
    phoneNums.insert(it, L"1187876");
    phoneNums.insert(it, L"4486359");
    phoneNums.insert(it, L"102");
    phoneNums.insert(it, L"7878775");
    phoneNums.insert(it, L"9378136");
    phoneNums.insert(it, L"112");
    phoneNums.insert(it, L"3570790");
    phoneNums.insert(it, L"5138126");
    phoneNums.insert(it, L"5023020");
    phoneNums.insert(it, L"103");
  }


  // �������� ������ ������
  it = phoneNums.end();
  it--;
  while (it != phoneNums.begin()) {
    std::wcout << *it << L"\n\r";
    it--;
  }
  std::wcout << *it << L"\n\r";

  // ���������� � ��������
  it = phoneNums.begin();
  while (it != phoneNums.end())
    if (it->length() == 3) it = phoneNums.erase(it);
    else it++;
  phoneNums.sort();

  // �������� ���������������� � ���������������� ������
  it = phoneNums.begin();
  std::wcout << L"\n\r";
  std::wcout << L"Sorted list:" << L"\n\r";
  while (it != phoneNums.end()) {
    std::wcout << *it << L"\n\r";
    it++;
  }

  return 1;
}
