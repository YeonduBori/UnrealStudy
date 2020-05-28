#include <iostream>
using namespace std;

class Circle
{
public:
	int radius;
	double getArea();
	void setRadius(int radius)
	{
		this->radius = radius;
	}
	Circle();
	Circle(int radius)
	{
		this->radius = radius;
	}
private:
	double area;
};

double Circle::getArea()
{
	area = 3.14 * radius * radius;	
	return area;
}

Circle::Circle()
{
	cout << "Circle 按眉 积己" << endl;
}

int main()
{
	//double a = 3.7;
	//double b = 7.3;

	//*(int*)&a = *(int*)&a ^ *(int*)&b;
	//*(int*)&b = *(int*)&a ^ *(int*)&b;
	//*(int*)&a = *(int*)&a ^ *(int*)&b;
	//cout << a << " " << b << endl;

	//float a = 3.7;
	//float b = 7.3;

	//*(int*)&a = *(int*)&a ^ *(int*)&b;
	//*(int*)&b = *(int*)&a ^ *(int*)&b;
	//*(int*)&a = *(int*)&a ^ *(int*)&b;
	//cout << a << " " << b << endl;
	
	Circle circle;
	circle.setRadius(5);

	Circle circle_instance = Circle(5);
	cout << circle.getArea() << "<- circle's Area\n" << circle_instance.getArea() << " <- 积己磊 抛胶飘" << endl;
}

