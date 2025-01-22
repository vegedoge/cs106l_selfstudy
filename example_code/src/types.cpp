#include <cmath>    // for sqrt
#include <iostream> // to print
#include <utility>  // for pairs

std::pair<size_t, size_t> find(std::string str, char c) {
  size_t first, last = std::string::npos;
  first = str.find(c);
  if (first != std::string::npos) {
    last = str.rfind(c);
  }
  return {first, last};
}

// type alias
using QuadraticResult = std::pair<bool, std::pair<int, int>>;

QuadraticResult solveQuadratic(int a, int b, int c) {
  // x = [-b +- sqrt(b^2 - 4ac)] / 2a
  int delta = b * b - 4 * a * c;
  if (delta < 0) {
    return std::make_pair(false, std::make_pair(0, 0));
  }
  int x1 = (-b + sqrt(delta)) / (2 * a);
  int x2 = (-b - sqrt(delta)) / (2 * a);
  return std::make_pair(true, std::make_pair(x1, x2));
}

int main() {
  std::string marquez = "Colonel Aureliano Buendía was to remember that distant afternoon";

  std::pair<size_t, size_t> result = find(marquez, 'a');
  std::cout << result.first << std::endl;
  std::cout << result.second << std::endl;

  auto solve_result = solveQuadratic(1, -3, 2);
  // Write code to display the two roots! Make sure to handle if
  // there are no real roots!
  if (result.first) {
    printf("Roots are: %d, %d\n", solve_result.second.first, solve_result.second.second);
  } else {
    printf("No real roots\n");
  }

  return 0;
}
