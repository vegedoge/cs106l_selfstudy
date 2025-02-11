#include <iostream>

// use template to run at compile time
template <unsigned n>
struct Factorial {
  enum
  {
    value = n * Factorial<n - 1>::value
  };
};

// specialization
template <>
struct Factorial<0> {
  enum
  {
    value = 1
  };
};
int main() {
  std::cout << Factorial<5>::value << std::endl;
  return 0;
}