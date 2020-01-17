/* Ляхович Д.А.
 * 17-ИТд
 * Вариант 8
 *
 * Операционые системы и системное программрование
 * Лабораторная №4
 * Задание 1
 * 1) Вынести всю функциональную часть индивидуального задания в библиотеку.
 * 2) Скомпилировать данную библиотеку как статическую и как динамическую.
 * 3) Сделать три версии программы: со статической линковкой библиотеки, с динамической с ранним связыванием, с динамической с поздним связыванием.
 * Приведение слов к общему виду по определенным условиям.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("Недостаточно параметров\n");
    exit(1);
  }
  char str[256] = {'\0'};
  strcpy(str, argv[1]);
  processing(&str[0]);
  printf("%s\n", str);

  return 0;
}