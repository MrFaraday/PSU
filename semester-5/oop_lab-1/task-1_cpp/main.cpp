﻿/* Ляхович Д.А.
 * 17-ИТд
 * Вариант 8
 *
 * Объектно-ориентированные технологии программирования и стандарты проектирования
 * Лабораторная №1
 * Задание 1
 * Ход работы:
 *  1. Создать класс описывающий сущность согласно варианту(ноутбук).
 *  2. Создать конструктор без параметров
 *  3. Создать конструктор с параметрами
 *  4. Создать деструктор
 *  5. Создать методы для чтения данных в объект и вывода из объекта.
 *  6. Реализовать программы на С++, С#, Java
 *  7. * Создать конструктор копирования для объекта на языке С++.
 */

  // Консольный вывод
#define CONSOLE_OUTPUT       _setmode(_fileno(stdout), _O_U16TEXT);
#include <conio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "Laptop.h"

int main() {
  #ifdef CONSOLE_OUTPUT
  CONSOLE_OUTPUT
  #endif

  _getwch();

  return 1;
}
