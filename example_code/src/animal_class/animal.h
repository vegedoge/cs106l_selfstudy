#include <iostream>
class Animal {
  public:
    virtual void speak() {
      std::cout << "I am an animal" << std::endl;
    }
};

class Dog : public Animal {
  public: 
    void speak() {
      std::cout << "I am a dog" << std::endl;
    }
};