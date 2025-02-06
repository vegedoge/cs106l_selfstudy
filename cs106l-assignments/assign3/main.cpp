/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <iostream>

/* #### Please don't change this line! #### */
int run_autograder();

int main() {
  // STUDENT TODO: Construct an instance of your class!
  int size;
  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  DynamicArray arr(size);
  arr.setSquaredIndices();
  arr.displayElements();
  /* #### Please don't change this line! #### */
  return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"