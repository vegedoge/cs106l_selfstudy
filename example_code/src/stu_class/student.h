#include <string>

class Student { 
  private:
    std::string name;
    std::string state;
    int age;

  public:
    // constructor
    Student(std::string name, std::string state, int age);
    // default constructor
    Student();
    // method
    std::string getName() const;
    std::string getState();
    int getAge() const;
    bool operator < (const Student &rhs) const;
    friend bool operator> (const Student &lhs, const Student &rhs);

    void setName(std::string name);
    void setState(std::string state);
    void setAge(int age);

    ~Student();
};

bool operator> (const Student& lhs, const Student& rhs) {
  return lhs.age > rhs.age;
}