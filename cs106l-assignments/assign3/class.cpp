#include "class.h"
#include <iostream>

DynamicArray::DynamicArray(int size) {
  _size = size;
  _data = new int[size];
}

DynamicArray::~DynamicArray() {
  delete[] _data;
}

void DynamicArray::setSquaredIndices() {
  for (int i = 0; i < _size; i++) {
    _data[i] = i * i;
  }
}

void DynamicArray::displayElements() {
  for (int i = 0; i < _size; i++) {
    std::cout << _data[i] << " ";
  }
  std::cout << '\n';
}