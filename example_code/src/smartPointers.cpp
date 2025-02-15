#include <iostream>
#include <memory>

struct Resource {
  Resource(){std::cout << "Resource acquired\n";}
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

void uniquePtrExample() {
  std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>();
  // No copy allowed
  // std::unique_ptr<Resource> ptr2 = ptr1;

  std::unique_ptr<Resource> ptr2 = std::move(ptr1);
  if (!ptr1)
    std::cout << "ptr1 is now empty\n";
}

void sharedPtrExample() {
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(); 
    {
        std::shared_ptr<Resource> ptr2 = ptr1; // Rc + 1
        std::cout << "Shared count: " << ptr1.use_count() << "\n";
        std::cout << "Shared count: " << ptr2.use_count() << "\n";
    } // Rc -1

    std::cout << "Shared count: " << ptr1.use_count() << "\n";
} // Rc = 0

int main() {
  uniquePtrExample();
  sharedPtrExample();
}