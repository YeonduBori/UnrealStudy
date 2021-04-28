#include <iostream>
using namespace std;
#include <deque>
#include <vector>
#include <map>

#pragma region deque
//int main()
//{
//    // 시퀀스 컨테이너(Sequence Container)
//    // 데이터가 삽입 순서대로 나열되는 형태
//    // vector list deque
//
//    // deque : double-ended queue 데크
//    // [    ]
//    // [    ]
//
//    //deque<int> dq;
//    //dq.push_back(1);
//    //dq.push_front(2);
//    //cout << dq[0] << endl;
//    //capacity X
//    // vector와 마찬가지로 배열 기반으로 동작
//    // 다만 메모리 할당 정책이 다르다
//
//    // vector
//    // [        ]      ]
//
//    //deque
//    // [    3 3]
//    // [ 1  1  1  2]
//    // [ 2     ]
//
//    vector<int> v(3, 1);
//    deque<int> dq(3, 1);
//
//    v.push_back(2);
//    v.push_back(2);
//    dq.push_back(2);
//    dq.push_back(2);
//
//    dq.push_front(3);
//    dq.push_front(3);
//
//    // deque의 동작 원리
//    // - 중간 삽입/삭제 (BAD / BAD)
//    // - 처음/끝 삽입/삭제 (GOOD / GOOD)
//    // - 임의 접근
//    return 0;
//}
#pragma endregion

#pragma region map
class Player
{
public:
	Player(): _playerId(0) { }
	Player(int playerId) : _playerId(playerId) {}
public:
	int _playerId;
};

class Node
{
public:
	Node* _left;
	Node* _right;
	//Data
	int _key;
	Player* _value;
};

int main()
{
	srand((unsigned int)time(nullptr));
	////연관 컨테이너
	////
	//vector<Player*> v;
	////10만명 입장
	//for (int index = 0; index < 100000; index++)
	//{
	//	Player* p = new Player(index);
	//	v.push_back(p);
	//}

	//// 5만명이 퇴장
	//for (int index = 0; index < 50000; index++)
	//{
	//	int randIndex = rand() % v.size();
	//	Player* p = v[randIndex];
	//	delete p;

	//	v.erase(v.begin() + randIndex);
	//}

	//// (ID = 2만 플레이어)가 (ID = 1만 Player)를 공격하고 싶어요
	//// Q) ID = 1만인 Player를 찾아주세요.
	//// A) 찾아온다.

	//bool found = false;

	//for (int index = 0; index < v.size(); index++)
	//{
	//	if (v[index]->_playerId == 10000)
	//	{
	//		found = true;
	//		break;
	//	}
	//}

	////vector, list의 치명적인 단점
	//// -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 없다.

	//map : 균형 이진 트리(AVL)
	// - 노드 기반

	// (Key, value)
	map<int, int> m;

	//pair<map<int, int>::iterator, bool> ok;
	//ok = m.insert(make_pair(1, 100));
	//ok = m.insert(make_pair(1, 200));
	//동일한 키가 있다면 덮어쓰는 것이 아니라 무시됨
	//  
	// 10만명
	for (int index = 0; index < 100000; index++)
	{
		m.insert(pair<int, int>(index, index * 100));
	}

	// 5만명 퇴장
	for (int index = 0; index < 50000; index++)
	{
		int randomValue = rand() % 50000;

		//제거에 여러 버전이 있지만 일단은 Key값 이용
		m.erase(randomValue);
	}
	//unsigned int count = 0;
	//count = m.erase(10000); 삭제 성공시 1 실패시 0 (true, false?)
	//count = m.erase(10000);
	// Q) ID = 1만인 Player 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음

	map<int,int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "못찾음" << endl;
	}

	// map 순회

	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = (*it);
		int key = it->first;
		int value = it->second;

		cout << key << " " << value << endl;
	}

	//없으면 추가, 있으면 수정
	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		findIt->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	//없으면 추가, 있으면 수정 v2
	m[5] = 500;

	// [] 연산자 사용할때 주의
	// 대입을 하지 않더라도 (key/value) 형태의 데이터가 추가된다.
	m.clear();
	for (int index = 0; index < 10; index++)
	{
		cout << m[index] << endl;
	}
	return 0;
}
#pragma endregion