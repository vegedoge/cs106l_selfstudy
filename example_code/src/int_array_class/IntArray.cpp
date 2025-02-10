#include "IntArray.h"
#include <stdexcept>

IntArray::IntArray(size_t size): _size(size), _array(new int[size]){}

IntArray::~IntArray() {
  delete[] _array;
}

int& IntArray::at(size_t index) {
  return _array[index];
}

const int& IntArray::at(size_t index) const{
  return _array[index];
}

int IntArray::size() {
  return this->_size;
}

int& IntArray::findItem(int value){
  for (size_t i = 0; i < _size; ++i) {
    if (_array[i] == value) { return _array[i]; }
  }

  throw std::out_of_range("Item not found");
}

const int& IntArray::findItem(int value) const {
  return const_cast<IntArray&>(*this).findItem(value);
}