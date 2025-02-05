#include "shape.h"
#include <iostream>

int main() {
  // create a new instance of the class
  Rectangle rect(10, 20);
  Circle circle(10);
  printf("Area of the rectangle: %f\n", rect.area());
  printf("Area of the circle: %f\n", circle.area());

  return 0;
}