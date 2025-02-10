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

    void setName(std::string name);
    void setState(std::string state);
    void setAge(int age);

    ~Student();
};