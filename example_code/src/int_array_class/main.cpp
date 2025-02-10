#include <iostream>
#include "IntArray.h"

static void printElement(const IntArray& arr, size_t index) {
  std::cout << arr.at(index) << std::endl;
}

int main() {
  IntArray arr = IntArray(10);
  int &secondVal = arr.at(1);
  secondVal = 28;
  printElement(arr, 1);
  return 0;
}