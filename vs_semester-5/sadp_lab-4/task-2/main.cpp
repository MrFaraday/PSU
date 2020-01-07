/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������� � ��������� ��������� ������
 * ������������ �4
 * ������� 2
 * ������� ���������� ������ ��������� ��������� ������. ������� ��� �������� � �� ������.
 */

 // ���������� �����
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT); _setmode(_fileno(stdin),  _O_U16TEXT); _setmode(_fileno(stderr), _O_U16TEXT); std::wostream& out = std::wcout; std::wistream& in = std::wcin;
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "..\task-1\Binary_Tree.h"

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  Binary_Tree<std::wstring> binTree;
  // ����������
  {
    binTree.insert(L"FireTeam", 5);
    binTree.insert(L"TeamSpeak", 3);
    binTree.insert(L"HolyShot", 7);
    binTree.insert(L"SpecOps", 10);
    binTree.insert(L"DevOps", 1);
    binTree.insert(L"LiveAction", 11);
    binTree.insert(L"SocialClub", 2);
    binTree.insert(L"Steam", 0);
    binTree.insert(L"Complex", 8);
    binTree.insert(L"PowerRangers", 4);
  }

  /*out << binTree.getLevel(0) << L"\n\r";
  out << binTree.isNode(0) << L"\n\r";
  out << binTree.isNode(12) << L"\n\r";
  out << binTree.getMinKey() << L"\n\r";
  out << binTree.getMaxKey() << L"\n\r";*/

  size_t count = 0;
  for (size_t i = binTree.getMinKey(); i <= binTree.getMaxKey(); i++)
    if ((i % 2) == 0)
      if (binTree.isNode(i)) {
        out<< i << L" : " << binTree.getVlue(i) << L"\n\r";
        count++;
      }
  out << L"����������� ������ ���������: " << count << L"\n\r";

  return 1;
}
