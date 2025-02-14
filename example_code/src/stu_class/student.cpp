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
std::string Student::getName() const{
  return this->name;
}

std::string Student::getState() {
  return this->state;
}

int Student::getAge() const {
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

bool Student::operator<(const Student& rhs) const {
  return this -> age < rhs.age;
}

Student::~Student() {
  // destructor
}