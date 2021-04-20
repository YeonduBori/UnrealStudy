#include <iostream>
using namespace std;

void Test2()
{
    int b = 0;
}

void Test1()
{
    int a = 5;
    
    Test2();
}

int main()
{
    Test1();
    cout << "Hello World!\n";
}
