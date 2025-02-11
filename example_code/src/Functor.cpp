#include <iostream>
class Functor {
  public:
    int operator() (int arg) const {
      return num + arg;
    }
    Functor(int num) {
      this->num = num;
    }

  private:
    int num; // capture clause
};

int main() {
  int num = 0;
  auto lambda = [&num](int arg) { num += arg; };

  lambda(5);
  std::cout << num << std::endl;

  Functor functor_instance(5);
  std::cout << "functor output: " << functor_instance(10) << std::endl;

  return 0;
}
