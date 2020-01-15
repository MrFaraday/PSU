/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������� � ��������� ��������� ������
 * ������������ �1
 * ������� 1
 * � ������� ���������� ����������� ���������, � ������� ����������� ���� ������������� ������������� ����. ������ �������� ��������� � ������������ �������, ������� ���������� ����� � ���� ������ ������. ������ � ���������������. ��� ��������� ��������� ����������� �������: ���������� �������� � ����� ������, ������� �������� ����� ������� ��������� ������, �������� �������� �� ������. ��� ����� ������ ������ ��������������� �� ������������� ���� (�������� �������� �������). ����������� �������������� �� ����� ������������. ���������� ������ ������� �� �����.
 * �������:
    - �������� ����� (����� ������������� �����)
    - ����� - ������ (������ 20 ��������);
    - ��� ������� (����� �������������� �����);
    - ����� ������ (����� �����, � �����).
 * ���� ����������: �������� �����
 * �������������� ���������: ������� ��� �������� � ������ ����� ������ ����� �����, ���������� �������������.
 * ������ �����: �������� ����� ����� � ������, ��� �������, ����� ������
 */

 // ���������� �����
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "Planes.h"

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  std::wcout << L"������������.\n\r";
  Planes planes = Planes();
  std::wcout << L"\n\r";

  std::wcout << L"������� ����� ���-�� ����� ��� ��������: ";
  UINT hours;
  std::wcin >> hours;
  planes.planesFilter(hours);

  system("cls");
  planes.printList();

  return 1;
}