/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������-��������������� ���������� ���������������� � ��������� ��������������
 * ������������ �2
 * ������� 1
 * ������� ���������� ������.
 *  1. ���������� �������� ������� (�����, �������, �����, ���������).
 *  2. ���������� � ������ ����������� ���������� - ��������� �� ������ ���������� ������ �������� � ����������� ������� ��� ��������� ������.
 *  3. ����������� ������.
 *  4. �������� ���������������� ���������, � ������� ��������� ������� ��������� ������� � ���������� � ������, ����� ���� ������ ���������������.
 *  5. ������� ��������������� ������ �� ������������ � ����������,
��� �����.
 *  6. ����������� ������ �� ����� �# � Java.
 */

 // ���������� �����
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "Domain.h"
#include "Metropolis.h"
#include "City.h"
#include "Place.h"

Domain* Domain::listStart = nullptr;

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  Domain dom1 = Domain(L"Columbia");
  Domain dom2 = Domain(L"Alaska");
  Domain dom3 = Domain(L"Washington");
  Domain dom4 = Domain(L"Wisconsin");
  Domain dom5 = Domain(L"Georgia");
  Metropolis metro1 = Metropolis(L"Highway");
  Metropolis metro2 = Metropolis(L"Brooklin");
  City city1 = City(L"New York");
  Place bridge1 = Place(L"Golden Gate");

  Domain::showList();

  return 1;
}
