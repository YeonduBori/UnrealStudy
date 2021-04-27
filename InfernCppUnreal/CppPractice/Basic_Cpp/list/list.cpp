#include <iostream>
using namespace std;
#include <vector>
#include <list>

#pragma region list
//class Node
//{
//public:
//    Node* _next;
//    Node* _prev;
//    int     _data;
//};
//
//int main()
//{
//    // list (연결 리스트) <- size는 있지만 capacity는 없다
//    // - list 의 동작 원리
//    // - 중간 삽입 / 삭제
//    // - 처음/끝 삽입/삭제
//    // - 임의 접근
//
//    list<int> li;
//
//    for (int i = 0; i < 100; i++)
//    {
//        li.push_back(i);
//    }
//    li.push_front(10);
//    int size = li.size();
//
//    int first = li.front();
//    int last = li.back();
//
//    list<int>::iterator itBegin = li.begin();
//    list<int>::iterator itEnd = li.end();
//
//    int* ptrBegin = &(li.front());
//    int* ptrEnd = &(li.back());
//
//    //첫 노드의 경우
//    // [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [6] <-> [_Myhead : end()] <-> [1]<-유효한 노드인지 확인
//    // end 값에서 뒤로 이동은 가능
//
//    //list<int>::iterator itTest1 = --itBegin;// 에러
//    //list<int>::iterator itTest2 = --itEnd;// 오케
//    //list<int>::iterator itTest1 = ++itEnd;// 에러
//
//    // 임의 접근이 안되는데 중간 삭제가 빠르다는게 말이 되나?
//
//    list<int>::iterator it = li.begin();
//    // 이미 삭제할 포인터를 갖고 있으면 삭제 자체는 빠름
//    // 다만 삭제할 대상을 찾아야한다면 과연 빠른가 분리해서 생각해야됨
//
//    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
//    {
//        cout << *it << endl;
//    }
//
//    li.insert(itBegin, 100);
//    li.erase(li.begin());
//    li.pop_front();
//
//    li.remove(10);
//    return 0;
//}
#pragma endregion

#pragma region list_Implement

template<typename T>
class Node
{
public:
	Node(): _next(nullptr), _prev(nullptr), _data(T())
	{
	}

	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value)
	{

	}
public:
	Node*	_prev;
	Node*	_next;
	T		_data;
};

template<typename T>
class Iterator
{
public:
	Iterator() :_node(nullptr)
	{

	}

	Iterator(Node<T>* node):_node(node)
	{

	}

	Iterator<T>& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Iterator<T> operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	Iterator<T>& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Iterator<T> operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& right)
	{
		return _node == right._node;
	}

	bool operator!=(const Iterator& right)
	{
		return _node != right._node;
	}
public:
	Node<T>* _node;
};

//[header]
template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}

	~List()
	{
		//TODO
		while (_size > 0)
			pop_back();

		delete _header;
	}

	void push_back(const T& value)
	{
		AddNode(_header, value);
	}

	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* node = new Node<T>(value);
		node->_prev = before->_prev->_next;
		node->_next = before->_prev;
		before->_prev = node;

		_size++;

		return node;
	}
	
	//[before] <-> [node] <-> [next]
	//[before]		<->		  [next]
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;
		prevNode->_next = node->_next;
		nextNode->_prev = node->_prev;

		delete node;
		_size--;

		return nextNode;
	}

	void pop_back()
	{
		RemoveNode(_header->_prev);
	}

	int size()
	{
		return _size;
	}

public:
	typedef Iterator<T> iterator;

	iterator begin(){ return iterator(_header->_next);}
	iterator end(){ return iterator(_header);}

	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}
public:
	Node<T>* _header;
	int _size;
};

int main()
{
	List<int> li;

	List<int>::iterator eraseIt;

	for (int index = 0; index < 10; index++)
	{
		if (index == 5)
		{
			eraseIt = li.insert(li.end(), index);
		}
		else
		{
			li.push_back(index);
		}
	}

	li.pop_back();

	li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}
#pragma endregion

