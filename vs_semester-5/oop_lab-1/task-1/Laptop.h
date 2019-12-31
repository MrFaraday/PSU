#pragma once

#include <string>
#include <iostream>

class Laptop {
public:
  // ������� ��������
  std::wstring
    mark,
    model;
  float
    CPU_clockRate,
    GPU_clockRate;
  int
    RAM_size,
    GPU_RAM_size;

public:
    // ����������� ��� ����������
  Laptop();

    // ����������� � �����������
  Laptop(
    std::wstring mark,
    std::wstring model,
    float CPU_clockRate,
    float GPU_clockRate,
    int RAM_size,
    int GPU_RAM_size
  );

    // ����������� �����������
  Laptop(const Laptop & obj);

    // ����������
  ~Laptop();

    // ��������� ��������
  std::wstring getMark();
  std::wstring getModel();
  float getCPUcr();
  float getGPUcr();
  int getRAMs();
  int getGPUrs();

    // ��������� ��������
  std::wstring setMark(std::wstring value);
  std::wstring setModel(std::wstring value);
  float setCPUcr(float value);
  float setGPUcr(float value);
  int setRAMs(int value);
  int setGPUrs(int value);

  // ��� 4-�� ������� 
  Laptop& operator = (const Laptop& copy);
  friend bool operator == (const Laptop& ob_l, const Laptop& ob_r);
  friend bool operator != (const Laptop& ob_l, const Laptop& ob_r);
  friend bool operator > (const Laptop& ob_l, const Laptop& ob_r);
  friend bool operator < (const Laptop& ob_l, const Laptop& ob_r);
  friend std::wostream& operator << (std::wostream& out, const Laptop& ob);
  friend std::wistream& operator >> (std::wistream& in, Laptop& ob);
};
