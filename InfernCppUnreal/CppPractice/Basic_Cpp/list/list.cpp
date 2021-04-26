#include <iostream>
using namespace std;
#include <vector>
#include <list>

class Node
{
public:
    Node*   _next;
    Node*   _prev;
    int     _data;
};

int main()
{
    // list (연결 리스트) <- size는 있지만 capacity는 없다
    // - list 의 동작 원리
    // - 중간 삽입 / 삭제
    // - 처음/끝 삽입/삭제
    // - 임의 접근

    list<int> li;

    for (int i = 0; i < 100; i++)
    {
        li.push_back(i);
    }
    li.push_front(10);
    int size = li.size();

    int first = li.front();
    int last = li.back();

    list<int>::iterator itBegin = li.begin();
    list<int>::iterator itEnd = li.end();

    int* ptrBegin = &(li.front());
    int* ptrEnd = &(li.back());

    //첫 노드의 경우
    // [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [6] <-> [_Myhead : end()] <-> [1]<-유효한 노드인지 확인
    // end 값에서 뒤로 이동은 가능

    //list<int>::iterator itTest1 = --itBegin;// 에러
    //list<int>::iterator itTest2 = --itEnd;// 오케
    //list<int>::iterator itTest1 = ++itEnd;// 에러

    // 임의 접근이 안되는데 중간 삭제가 빠르다는게 말이 되나?

    list<int>::iterator it = li.begin();
    // 이미 삭제할 포인터를 갖고 있으면 삭제 자체는 빠름
    // 다만 삭제할 대상을 찾아야한다면 과연 빠른가 분리해서 생각해야됨

    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << endl;
    }

    li.insert(itBegin, 100);
    li.erase(li.begin());
    li.pop_front();

    li.remove(10);
    return 0;
}
