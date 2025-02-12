#include "animal.h"

void func(Animal* animal) {
  animal->speak();
}

int main() {
  Animal *myAnimal = new Animal;
  Dog *myDog = new Dog;
  func(myAnimal);
  func(myDog);
}