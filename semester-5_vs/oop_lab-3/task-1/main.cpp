﻿/* Ляхович Д.А.
 * 17-ИТд
 * Вариант 8
 *
 * Объектно-ориентированные технологии программирования и стандарты проектирования
 * Лабораторная №3
 * Задание 1
 * Порядок выполнения работы.
 *  1. Выбрать класс АТД в соответствии с вариантом.
    АТД − однонаправленный список с элементами типа char. Дополнительно перегрузить следующие операции:
    +   – добавить элемент в начало(char+list);
    --  – удалить элемент из начала(типа --list);
    ==  – проверка на равенство.
 *  2. Определить и реализовать в классе конструкторы, деструктор, функции Input (ввод с клавиатуры) и Print (вывод на экран), перегрузить операцию присваивания.
 *  3. Написать программу тестирования класса и выполнить тестирование.
 *  4. Дополнить определение класса заданными перегруженными операциями ( в соответствии с вариантом).
 *  5. Реализовать эти операции. Выполнить тестирование.
 *  6. Реализовать вариант на языке С++ и (С#/Java на выбор).
 */

 // Консольный вывод
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "Chars.h"

int main() {
#ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  Chars arr;
  arr + 'a';
  arr + 'b';
  arr + 'c';
  
  bool tf = 'c' == arr.getCh();
  std::wcout << tf << L"\n\r";  // должен быть true(1)
  --arr;

  tf = 'c' == arr.getCh();
  std::wcout << tf << L"\n\r";  // должен быть false(0)
  --arr;

  tf = 'a' == arr.getCh();
  std::wcout << tf << L"\n\r";  // должен быть true(1)
  --arr;

  return 1;
}