
class Shape {
  public:
    virtual double area() const = 0;
};

class Circle : public Shape {
  private:
    double _radius;
  public:
    // constructor
    Circle(double radius) : _radius{radius} {};
    double area() const {
      return 3.14 * _radius * _radius;
    }
};

class Rectangle: public Shape {
  private:
    double _width;
    double _height;
  public:
    //constructor
    Rectangle(double height, double width) : _height{height},
    _width{width} {};
    double area() const {
      return _height * _width;
    }
};