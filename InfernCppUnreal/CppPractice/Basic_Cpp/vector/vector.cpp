#include <iostream>
using namespace std;
#include <vector>

int main()
{
    //STL(Standard Template Library)
    //프로그래밍할 때 필요한 자료구조/알고리즘들을 
    //템플릿으로 제공하는 라이브러리

    //Container(컨테이너) : 데이터를 저장하는 객체 (자료구조)

    //vector(동적 배열)
    // - vector의 동작 원리(size/capacity)
    // - 중간 삽입/삭제
    // - 처음/끝 삽입/삭제
    // - 임의 접근

    ////배열
    //const int MAX_SIZE = 10;
    //int arr[MAX_SIZE] = {};

    //for (int i = 0; i < MAX_SIZE; i++)
    //    arr[i] = i;
    //
    //for (int i = 0; i < MAX_SIZE; i++)
    //    cout << arr[i] << endl;

    // 동적 배열
    // 1) 여유분을 두고 메모리를 할당한다.
    // 2) 여유분까지 꽉 찼으면, 메모리를 증설한다.
    // 
    // [        ][              ]
    // [                        ]
    // Q1) 여유분은 얼만큼이 적당할까?
    // Q2) 증설을 얼만큼 해야 할까?
    // Q3) 기존의 데이터를 어떻게 처리해야할까? 기존 데이터를 새로 확보한 공간에 복사 <- 오버헤드 발생
    // 더 큰 부분을 증설해서 사용 부족하면
    vector<int> v;
    //v.push_back(1);
    //v.push_back(2);
    //v.push_back(3);
    //v.push_back(4);
    //v.push_back(5);

    //size? capacity?
    //size(실제 사용 데이터 개수)
    // 1 2 3 4 5 6 7 ...
    //capacity(여유분을 포함한 총 용량 개수)
    // 1 2 3 4 6 9 13 19 28 42 63
    //v.reserve(1000);// capacity 예약 확보
    v.resize(1000);// [1000개 할당]

    for (int index = 0; index < 1000; index++)
    {
        v[index] = 100;
        cout << v.size() << " " << v.capacity() << endl;
    }
    cout << v.front() << endl;
    cout << v.size() << " " << v.capacity() << endl;
    cout << v.back() << endl;
    cout << v.size() << " " << v.capacity() << endl;
    v.pop_back();
    cout << v.size() << " " << v.capacity() << endl;
    v.clear();
    cout << v.size() << " " << v.capacity() << endl;
    vector<int>().swap(v);//임시객체랑 스왑해서 깔끔하게 메모리 날림
    cout << v.size() << " " << v.capacity() << endl;
    //const int size = v.size();
    //for (int i = 0; i < size; i++)
    //{
    //    cout << v[i] << endl;
    //}

    return 0;
}
