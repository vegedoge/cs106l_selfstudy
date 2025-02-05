#include "student.h"

Student::Student(std::string name, std::string state, int age) {
  this->name = name;
  this->state = state;
  this->age = age;
}

// default constructor
Student::Student() {
  name = "John Wick";
  state = "CA";
  age = 30;
}

// methods
std::string Student::getName() {
  return this->name;
}

std::string Student::getState() {
  return this->state;
}

int Student::getAge() {
  return this->age;
}

void Student::setName(std::string name) {
  this->name = name;
}

void Student::setState(std::string state) {
  this->state = state;
}

void Student::setAge(int age) {
  this->age = age;
}

Student::~Student() {
  // destructor
}