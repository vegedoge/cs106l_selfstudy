#include <iostream>
#include <vector>
#include <math.h>

void shift(std::vector<std::pair<int, int>> &nums) {
  // we are modifing the variables inside pairs, 
  // so another & is needed to capture the ref
  // inside of pairs
  for (auto& [num1, num2] : nums) {
    num1++;
    num2++;
  }
}

int main() {
  std::vector<std::pair<int, int>> nums = {{1, 2}, {3, 4}, {5, 6}};
  shift(nums);
  for (const auto& [num1, num2] : nums) {
    printf("num1: %d, num2: %d \n", num1, num2);
  }
    return 0;
}