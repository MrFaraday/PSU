/* ������� �.�.
 * 17-���
 * ������� 8
 *
 * ��������� � ��������� ��������� ������
 * ������������ �5
 * ������� 1
 * � ���� ������ ��������� ���������� ��� ���������� ����� ��������� �������:
 *  ����: ������� �������� ��� ��������� ���� � ������ ����� �� ������, ���������� ������� ������.
 *  ��������: ���������� ������, ������� ������� �� �����, �������� ��������� � ������ ������� �����, ���������� ��� �����. ��� ������ ������� ���������� ����� � ������ ������� ������ � �������� �� � ������. ���� ����� ��� ���� � ������, �������� ������� ��� ��������� � ������ ������� �����.
 *  �����: ����� ����� ����� ����������� ����� � ���������� ������� ������ �� ���������� ������� � �������������� �������� �����, ��� ����������� ������ �����.
 */

 // ���������� �����
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT); _setmode(_fileno(stdin),  _O_U16TEXT); _setmode(_fileno(stderr), _O_U16TEXT); std::wostream& out = std::wcout; std::wistream& in = std::wcin;
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include <fstream>
#include <sstream>
#include <set>
#include <list>
#include "..\..\sadp_lab-4\task-1\Binary_Tree.h"

struct Word {
  std::wstring word;
  size_t count = 1;
  std::set<size_t> strings;

  void countPlus() {
    count++;
  }

  void addStr(size_t str) {
    std::set<size_t>::iterator it = strings.begin();
    strings.insert(it, str);
  }

  bool operator < (const Word& word) {
    return this->word < word.word;
  }
};

void wordCorrection(std::wstring&);
void printWord(Word&);

template <class T>
bool haveWord(std::wstring&, Binary_Tree<T>&);

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  Binary_Tree<Word> words;
  std::locale::global(std::locale(""));
  std::wifstream fIn(".\\concord.txt");
  if (!fIn.is_open()) {
    std::wcout << L"\n\r" << L"bad" << L"\n\r";
    return 0;
  }

  //std::wstring file((std::istreambuf_iterator<wchar_t>(fIn)),  // ���������� ����� � ������
  //                  std::istreambuf_iterator<wchar_t>());
  //std::wistringstream input = std::wistringstream(file);

  std::wstring word, line;
  std::wistringstream input;
  input.ignore(INT_MAX);
  size_t str = 0;
  // ����������� ������
  while (true) {
    // ������������ ������
    if (input.eof()) {
      if (fIn.eof()) break;
      str++;
      std::getline(fIn, line);
      input = std::wistringstream(line);
    }
    input >> word;
    wordCorrection(word);

    // ���������� � ������

    // ���� ������ ������
    if (words.empty()) {
      words.insert({ word }, 1);
      words.getData(1).addStr(str);
      continue;
    }
    // ���� �� ����� � ������
    if (haveWord(word, words)) {
      // ����� ���� � ������
      for (size_t i = words.getMinKey(); i <= words.getMaxKey(); i++)
        if (words.getData(i).word == word) {
          Word* p = &words.getData(i);
          p->addStr(str);
          p->countPlus();
          break;
        }
    } else {
      // ���������� ����� � ������
      size_t key = words.getMaxKey() + 1;
      words.insert({ word }, key);
      words.getData(key).addStr(str);  /////////////////////////////////////////////
    }
  }

  // ����� ��������
  std::list<Word> oList;
  std::list<Word>::iterator it = oList.begin();
  for (size_t i = words.getMinKey(); i <= words.getMaxKey(); i++)
    oList.insert(it, words.getData(i));
  oList.sort();
  it = oList.begin();
  while (it != oList.end()) {
    printWord(*it);
    it++;
  }

  fIn.close();
  return 1;
}

void wordCorrection(std::wstring& word) {
  // ��������� ������ ����������
  for (int i = 0, len = word.size(); i < len; i++) {
    if (ispunct(word[i])) {
      word.erase(i--, 1);
      len = word.size();
    }
  }
  // ������� � ������ �������
  std::transform(word.begin(), word.end(), word.begin(),
                 [](wchar_t c) { return std::tolower(c); });
}

template <class T>
bool haveWord(std::wstring& word, Binary_Tree<T>& words) {
  bool is = false;
  for (size_t i = words.getMinKey(); i <= words.getMaxKey(); i++)
    if (words.getData(i).word == word) is = true;

  return is;
}

void printWord(Word& word) {
  std::wcout << word.word;
  for (size_t i = 0; i < 20 - word.word.length(); i++)
    std::wcout << L'.';
  std::wcout << word.count << L":  ";
  std::set<size_t>::iterator it = word.strings.begin();
  while (it != word.strings.end()) {
    std::wcout << *it << L"   ";
    it++;
  }
  std::wcout << L"\n\r";
}
