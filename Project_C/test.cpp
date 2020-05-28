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
	~Circle();
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

Circle::Circle() : Circle(5)
{
	cout << "Circle ��ü ����" << endl;
}

Circle::~Circle()
{
	cout << "�Ҹ��� ȣ��" << this << "\n";
}
class Singleton {
public:
	static Singleton &GetInstance() {
		if (instance_ == NULL)
			instance_ = new Singleton();
		return *instance_;
	}
	int testNumber = 5;
private:
	Singleton() {}
	static Singleton* instance_;
};
int main()
{
	//Circle circle;
	//circle.setRadius(5);
	//Circle circle_instance = Circle(5);
	//cout << circle.getArea() << " <- circle's Area\n" << circle_instance.getArea() 
	//	<< " <- ������ �׽�Ʈ" << endl;
	Singleton singleton = Singleton::GetInstance();
	cout << singleton.testNumber << " singleton Works";
	return 0;
}

