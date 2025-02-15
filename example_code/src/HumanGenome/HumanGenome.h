#include <vector>
#include <iostream>

class HumanGenome {
  private:
    std::vector<char> data;
  public:
    HumanGenome(HumanGenome&& other) noexcept :
      data(std::move(other.data)) {
        std::cout << "data moved" << std::endl;
      }
    HumanGenome& operator=(HumanGenome&& other) noexcept {
      if (this != &other) {
        data = std::move(other.data);
        std::cout << "HumanGenome moved with =" << '\n';
      }
      return *this;
    }
};