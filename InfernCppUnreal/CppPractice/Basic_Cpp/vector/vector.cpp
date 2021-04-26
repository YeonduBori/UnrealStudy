#include <iostream>
using namespace std;
#include <vector>

#pragma region vector_1
//int main()
//{
//    //STL(Standard Template Library)
//    //프로그래밍할 때 필요한 자료구조/알고리즘들을 
//    //템플릿으로 제공하는 라이브러리
//
//    //Container(컨테이너) : 데이터를 저장하는 객체 (자료구조)
//
//    //vector(동적 배열)
//    // - vector의 동작 원리(size/capacity)
//    // - 중간 삽입/삭제
//    // - 처음/끝 삽입/삭제
//    // - 임의 접근
//
//    ////배열
//    //const int MAX_SIZE = 10;
//    //int arr[MAX_SIZE] = {};
//
//    //for (int i = 0; i < MAX_SIZE; i++)
//    //    arr[i] = i;
//    //
//    //for (int i = 0; i < MAX_SIZE; i++)
//    //    cout << arr[i] << endl;
//
//    // 동적 배열
//    // 1) 여유분을 두고 메모리를 할당한다.
//    // 2) 여유분까지 꽉 찼으면, 메모리를 증설한다.
//    // 
//    // [        ][              ]
//    // [                        ]
//    // Q1) 여유분은 얼만큼이 적당할까?
//    // Q2) 증설을 얼만큼 해야 할까?
//    // Q3) 기존의 데이터를 어떻게 처리해야할까? 기존 데이터를 새로 확보한 공간에 복사 <- 오버헤드 발생
//    // 더 큰 부분을 증설해서 사용 부족하면
//    vector<int> v;
//    //v.push_back(1);
//    //v.push_back(2);
//    //v.push_back(3);
//    //v.push_back(4);
//    //v.push_back(5);
//
//    //size? capacity?
//    //size(실제 사용 데이터 개수)
//    // 1 2 3 4 5 6 7 ...
//    //capacity(여유분을 포함한 총 용량 개수)
//    // 1 2 3 4 6 9 13 19 28 42 63
//    //v.reserve(1000);// capacity 예약 확보
//    v.resize(1000);// [1000개 할당]
//
//    for (int index = 0; index < 1000; index++)
//    {
//        v[index] = 100;
//        cout << v.size() << " " << v.capacity() << endl;
//    }
//    cout << v.front() << endl;
//    cout << v.size() << " " << v.capacity() << endl;
//    cout << v.back() << endl;
//    cout << v.size() << " " << v.capacity() << endl;
//    v.pop_back();
//    cout << v.size() << " " << v.capacity() << endl;
//    v.clear();
//    cout << v.size() << " " << v.capacity() << endl;
//    vector<int>().swap(v);//임시객체랑 스왑해서 깔끔하게 메모리 날림
//    cout << v.size() << " " << v.capacity() << endl;
//    //const int size = v.size();
//    //for (int i = 0; i < size; i++)
//    //{
//    //    cout << v[i] << endl;
//    //}
//
//    return 0;
//}
#pragma endregion

#pragma region vector_2
//int main()
//{
//	vector<int> v(10);
//
//	for (vector<int>::size_type i = 0; i < v.size(); i++)
//		v[i] = i;
//
//	/*vector<int>::iterator it;
//	int* ptr;
//
//	it = v.begin();
//	ptr = &v[0];
//	cout << (*it) << endl;
//	cout << (*ptr) << endl;
//
//	it++;
//	++it;
//	ptr++;
//	++ptr;
//
//	vector<int>::iterator itBegin = v.begin();
//	vector<int>::iterator itEnd = v.end();*/
//
//	//iterator는 vector 뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
//	//str 한정 공통점이 생김
//	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		cout << (*it) << endl;
//	}
//
//	int* ptrBegin = &v[0];//v.begin()._Ptr;
//	int* ptrEnd = ptrBegin + 10;//v.end()._Ptr;
//	for (int* ptr = ptrBegin; ptr != ptrEnd; ptr++)
//	{
//		cout << (*ptr) << endl;
//	}
//
//	//const int*
//	vector<int>::const_iterator cit1 = v.cbegin();
//	//*cit1 = 100;// 수정 블락
//	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
//	{
//		cout << (*it) << endl;
//	}
//
//	//vector = 동적 배열 = 동적으로 커지는 배열 = 배열
//	// 원소가 하나의 메모리 블럭에 연속하게 저장된다!!
//
//	// - 중간 삽입/삭제 (BAD)
//	// 	   삽입이나 삭제시 앞으로 당겨오거나 뒤로 미는 작업이 필요
//	// 	   처음 / 끝 삽입/삭제 (BAD / GOOD)
//	// - 임의 접근(Random Access)	
//	//[                 ]
//	//[0][1][2][3][4][][]
//	v.push_back(1);
//	v.pop_back();
//
//	//// 3번째 데이터는 어디 있나요
//	//v[2] = 3;
//
//	//vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
//	//vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
//	//vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);
//
//	for (vector<int>::iterator it = v.begin(); it != v.end();)
//	{
//		int data = *it;
//		if (data == 3)
//		{
//			it = v.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//
//	return 0;
//}
#pragma endregion

template<typename T>
class Iterator
{
public:
	Iterator() :_ptr(nullptr)
	{

	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator temp = *this;
		_ptr--;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)
	{
		return !(*this == right);
	}

	T& operator*()
	{
		return *_ptr;
	}
public:
	T* _ptr;
};

template<typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	void push_back(const T& val)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = val;

		// 데이터 개수 증가
		_size++;
	}

	void reserve(int capacity)
	{
		_capacity = capacity;
		T* newData = new T[_capacity];
	
		// 데이터 복사
		for (int index = 0; index < _size; index++)
			newData[index] = _data[index];

		// 기존에 있던 데이터 날린다.
		if (_data)
			delete[] _data;

		_data = newData;
	}

	T& operator[](const int pos)
	{
		return _data[pos];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }
private:
	T* _data;
	int _size;
	int _capacity;
};

int main()
{
	vector<int> v;

	for (int index = 0; index < 100; index++)
	{
		v.push_back(index);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int index = 0; index < v.size(); index++)
	{
		cout << v[index] << endl;
	}

	cout << "--------------------------" << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}