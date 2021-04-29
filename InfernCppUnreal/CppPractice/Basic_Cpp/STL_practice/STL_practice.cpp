#include <iostream>
using namespace std;
#include <deque>
#include <vector>
#include <map>
#include <set>

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
//class Player
//{
//public:
//	Player(): _playerId(0) { }
//	Player(int playerId) : _playerId(playerId) {}
//public:
//	int _playerId;
//};
//
//class Node
//{
//public:
//	Node* _left;
//	Node* _right;
//	//Data
//	int _key;
//	Player* _value;
//};
//
//int main()
//{
//	srand((unsigned int)time(nullptr));
//	////연관 컨테이너
//	////
//	//vector<Player*> v;
//	////10만명 입장
//	//for (int index = 0; index < 100000; index++)
//	//{
//	//	Player* p = new Player(index);
//	//	v.push_back(p);
//	//}
//
//	//// 5만명이 퇴장
//	//for (int index = 0; index < 50000; index++)
//	//{
//	//	int randIndex = rand() % v.size();
//	//	Player* p = v[randIndex];
//	//	delete p;
//
//	//	v.erase(v.begin() + randIndex);
//	//}
//
//	//// (ID = 2만 플레이어)가 (ID = 1만 Player)를 공격하고 싶어요
//	//// Q) ID = 1만인 Player를 찾아주세요.
//	//// A) 찾아온다.
//
//	//bool found = false;
//
//	//for (int index = 0; index < v.size(); index++)
//	//{
//	//	if (v[index]->_playerId == 10000)
//	//	{
//	//		found = true;
//	//		break;
//	//	}
//	//}
//
//	////vector, list의 치명적인 단점
//	//// -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 없다.
//
//	//map : 균형 이진 트리(AVL)
//	// - 노드 기반
//
//	// (Key, value)
//	map<int, int> m;
//
//	//pair<map<int, int>::iterator, bool> ok;
//	//ok = m.insert(make_pair(1, 100));
//	//ok = m.insert(make_pair(1, 200));
//	//동일한 키가 있다면 덮어쓰는 것이 아니라 무시됨
//	//  
//	// 10만명
//	for (int index = 0; index < 100000; index++)
//	{
//		m.insert(pair<int, int>(index, index * 100));
//	}
//
//	// 5만명 퇴장
//	for (int index = 0; index < 50000; index++)
//	{
//		int randomValue = rand() % 50000;
//
//		//제거에 여러 버전이 있지만 일단은 Key값 이용
//		m.erase(randomValue);
//	}
//	//unsigned int count = 0;
//	//count = m.erase(10000); 삭제 성공시 1 실패시 0 (true, false?)
//	//count = m.erase(10000);
//	// Q) ID = 1만인 Player 찾고 싶다!
//	// A) 매우 빠르게 찾을 수 있음
//
//	map<int,int>::iterator findIt = m.find(10000);
//	if (findIt != m.end())
//	{
//		cout << "찾음" << endl;
//	}
//	else
//	{
//		cout << "못찾음" << endl;
//	}
//
//	// map 순회
//
//	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
//	{
//		pair<const int, int>& p = (*it);
//		int key = it->first;
//		int value = it->second;
//
//		cout << key << " " << value << endl;
//	}
//
//	//없으면 추가, 있으면 수정
//	map<int, int>::iterator findIt = m.find(10000);
//	if (findIt != m.end())
//	{
//		findIt->second = 200;
//	}
//	else
//	{
//		m.insert(make_pair(10000, 200));
//	}
//
//	//없으면 추가, 있으면 수정 v2
//	m[5] = 500;
//
//	// [] 연산자 사용할때 주의
//	// 대입을 하지 않더라도 (key/value) 형태의 데이터가 추가된다.
//	m.clear();
//	for (int index = 0; index < 10; index++)
//	{
//		cout << m[index] << endl;
//	}
//	return 0;
//}
#pragma endregion

#pragma region set multiset, multimap
//int main()
//{
//	//map과는 다르게 키와 밸류가 일치
//	//Key = Value
//	set<int> s;
//
//	//넣고
//	s.insert(10);
//	s.insert(30);
//	s.insert(20);
//	s.insert(50);
//	s.insert(40);
//	s.insert(70);
//	s.insert(90);
//	s.insert(80);
//	s.insert(100);
//
//	//빼고
//	s.erase(40);
//
//	//찾고
//	set<int>::iterator findIt = s.find(50);
//	if (findIt == s.end())
//	{
//		cout << "못 찾음" << endl;
//	}
//	else
//	{
//		cout << "찾음" << endl;
//	}
//
//	//순회하고
//	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
//	{
//		cout << (*it) << endl;
//	}
//
//	cout << "-----------------------------" << endl;
//
//	multimap<int, int> mm;
//
//	//넣고
//	mm.insert(make_pair(1, 100));
//	mm.insert(make_pair(1, 200));
//	mm.insert(make_pair(1, 300));
//	mm.insert(make_pair(2, 400));
//	mm.insert(make_pair(2, 500));
//
//	//mm[1] = 500; <- error!
//
//	////빼고
//	//unsigned int count = mm.erase(1);// 키가 1인 애들이 싹 사라짐
//	//cout << count << endl;
//	////찾고
//	//multimap<int, int>::iterator itFind == mm.find(1);
//	//if (itFind != mm.end())
//	//	mm.erase(itFind);
//
//	pair<multimap<int, int>::iterator, multimap<int, int>::iterator>itPair;
//	itPair = mm.equal_range(1);
//
//	multimap<int,int>::iterator itBegin = mm.lower_bound(1);
//	multimap<int, int>::iterator itEnd = mm.upper_bound(1);
//
//	for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
//	{
//		cout << it->first << " " << it->second << endl;
//	}
//
//	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it)
//	{
//		cout << it->first << " " << it->second << endl;
//	}
//
//	for (multimap<int, int>::iterator it = mm.begin(); it != mm.end(); ++it)
//	{
//		cout << it->first << " " << it->second << endl;
//	}
//	return 0;
//
//	cout << "-------------------------" << endl;
//
//	multiset<int> ms;
//
//	ms.insert(100);
//	ms.insert(100);
//	ms.insert(100);
//	ms.insert(200);
//	ms.insert(200);
//
//	multiset<int>::iterator findIt2 = ms.find(100);
//
//	pair<multiset<int>::iterator, multiset<int>::iterator> itPair2;
//	itPair2 = ms.equal_range(100);
//	for (multiset<int>::iterator it = itPair2.first; it != itPair2.second; ++it)
//	{
//		cout << *it << endl;
//	}
//
//	multiset<int>::iterator itBegin2 = ms.lower_bound(100);
//	multiset<int>::iterator itEnd2 = ms.upper_bound(100);
//
//	for (multiset<int>::iterator it = itBegin2; it != itEnd2; ++it)
//	{
//		cout << *it << endl;
//	}
//
//}
#pragma endregion

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}
	v.push_back(50);
	//Q1) number라는 숫자가 벡터에 있는지 체크하는 기능(bool, 첫 등장 iterator)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it;
		it = v.begin();

		for (vector<int>::iterator iter = it; iter != v.end(); ++iter)
		{
			if (*iter == number)
			{
				found = true;
				cout << "1번 문제 찾았습니다" << endl;
			}
		}
	}

	//Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
	{
		bool found = false;
		vector<int>::iterator it;
		it = v.begin();
		for (vector<int>::iterator iter = it; iter != v.end(); ++iter)
		{
			if (*iter%11 == 0 && *iter != 0)
			{
				found = true;
				cout << "2번 문제 찾았습니다" << endl;
			}
		}
	}

	//Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;
		vector<int>::iterator it;
		it = v.begin();
		for (vector<int>::iterator iter = it; iter != v.end(); ++iter)
		{
			if (*iter % 2 != 0)
			{
				count++;
				cout << "3번 문제 "<< *iter <<" "<< count << "개 찾았습니다" << endl;
			}
		}
	}

	//Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		vector<int>::iterator it;
		it = v.begin();
		for (vector<int>::iterator iter = it; iter != v.end(); ++iter)
		{
			cout << "4번 문제 원본 : " << *iter << endl;
			*iter = *iter * 3;
			cout << "3 곱한 결괏값 : " << *iter << endl;
		}
	}

	return 0;
}