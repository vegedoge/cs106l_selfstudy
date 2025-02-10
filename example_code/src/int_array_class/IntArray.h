#include <cstddef>
class IntArray {
  private:
    int *_array;
    size_t _size;
  public:
    // constructor
    IntArray(size_t size);
    ~IntArray();
    int& at(size_t index);
    const int &at(size_t index) const;
    int size();
    int &findItem(int value);
    const int& findItem(int value) const;
};