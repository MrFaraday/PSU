/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������� � ��������� ��������� ������
 * ������������ �3
 * ������� 5
 * ��������� ���������������� �������� ������ ��������� ���������� �������, ������������� �����������������, ���������� ��� � ����������� ����� ��������. ��������� ��������� �����������:
    - �� ������ �������� �������;
    - �� ������� ������ ������� ���������.
 */

 // ���������� �����
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT); _setmode(_fileno(stdin),  _O_U16TEXT); _setmode(_fileno(stderr), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include <forward_list>
#include <queue>
#include <string>

struct subscriber {
  std::wstring lastName;
  std::wstring firstName;
  std::wstring middleName;
  unsigned int phone;

  bool operator < (const subscriber& sub) {
    if (this->lastName == sub.lastName)
      if (this->firstName == sub.firstName)
        return this->middleName < sub.middleName;
      else return this->firstName < sub.firstName;
    else return this->lastName < sub.lastName;
  }
};

template <class T>
void clear(std::queue<T>&);

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  std::forward_list<subscriber> subscribers;
  std::forward_list<subscriber>::iterator it;
  // ���������� ������
  {
    it = subscribers.insert_after(subscribers.before_begin(), { L"���������",  L"�������", L"��������", 1823070 });
    subscribers.insert_after(it, { L"������",  L"�����", L"���������", 5638821 });
    subscribers.insert_after(it, { L"������",  L"��������", L"��������", 8823805 });
    subscribers.insert_after(it, { L"���������",  L"����", L"����������", 9839646 });
    subscribers.insert_after(it, { L"������������",  L"����", L"����������", 2427242 });
    subscribers.insert_after(it, { L"�������",  L"���", L"�������������", 3541691 });
    subscribers.insert_after(it, { L"������",  L"�����", L"����������", 3657431 });
    subscribers.insert_after(it, { L"��������",  L"������", L"����������", 8544910 });
    subscribers.insert_after(it, { L"���������",  L"������", L"�������������", 1493951 });
    subscribers.insert_after(it, { L"������������",  L"����", L"���������", 8058386 });
  }

  subscribers.sort();

  wchar_t c = 0;
  std::queue<subscriber> output;
  while (c != L'e') {
    system("cls");
    clear(output);
    std::wcout << L"Find by Last Name (L)" << L"\n\r";
    std::wcout << L"Find by Phone (P)" << L"\n\r";
    std::wcout << L"Exit (E)" << L"\n\r";
    c = _getwch();

    if (c == L'l') {
      std::wstring lName;
      std::wcout << L"Enter Last Name: ";
      std::wcin >> lName;
      it = subscribers.begin();
      while (it != subscribers.end()) {
        if (lName == it->lastName) output.push(*it);
        it++;
      }
      if (output.empty()) std::wcout << L"Nothing found";
      else {
        while (!output.empty()) {
          std::wcout << output.front().lastName << L" ";
          std::wcout << output.front().firstName << L" ";
          std::wcout << output.front().middleName << L"    ";
          std::wcout << output.front().phone << L"\n\r";
          output.pop();
        }
      }
      _getwch();
    }

    if (c == L'p') {
      std::wstring phone;
      std::wcout << L"Enter Phone: ";
      std::wcin >> phone;
      it = subscribers.begin();
      while (it != subscribers.end()) {
        if (phone == std::to_wstring(it->phone)) output.push(*it);
        it++;
      }
      if (output.empty()) std::wcout << L"Nothing found";
      else {
        while (!output.empty()) {
          std::wcout << output.front().lastName << L" ";
          std::wcout << output.front().firstName << L" ";
          std::wcout << output.front().middleName << L"    ";
          std::wcout << output.front().phone << L"\n\r";
          output.pop();
        }
      }
      _getwch();
    }
  }

  return 1;
}

template <class T>
void clear(std::queue<T>& q) {
  std::queue<T> empty;
  std::swap(q, empty);
}
