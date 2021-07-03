#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <set>
using namespace std;
#pragma region Prim Algorithm
//class Edge
//{
//public:
//    int node[2] = { 0, };
//    int distance = 0;
//    Edge(int nodeStart, int nodeEnd, int distance) :node{ nodeStart, nodeEnd }, distance(distance)
//    {
//    }
//};
//
//struct CompareEdge
//{
//    bool operator()(Edge e1, Edge e2)
//    {
//        return e1.distance > e2.distance;
//    }
//};
//
//int Prim(vector<Edge>& matrix, int startNode)
//{
//    int mstValue = 0;
//    vector<int> connectedNode;
//    priority_queue<Edge, vector<Edge>, CompareEdge> candidateEdgesQueue;
//    //스타트 노드를 넣고 스타트노드에 연결된 모든 간선들을 우선순위(거리) Edge큐에 집어넣음
//    connectedNode.push_back(startNode);
//    {
//        auto it = find_if(matrix.begin(), matrix.end(), [&](Edge edge) {return startNode == edge.node[0]; });
//        while (it != matrix.end())
//        {
//            candidateEdgesQueue.push(*it);
//            it = find_if(it + 1, matrix.end(), [&](Edge edge) {return startNode == edge.node[0]; });
//        }
//    }
//
//    while (!candidateEdgesQueue.empty())
//    {
//        Edge e = candidateEdgesQueue.top();
//        candidateEdgesQueue.pop();
//        //가장 작은 간선길이를 가진 노드의 종착지가 싸이클에 포함되지 않는지 확인
//        //사이클에 포함되지 않음 왜냐면 반복자로 find했을때 end에 도달하였기때문
//        if (find(connectedNode.begin(), connectedNode.end(), e.node[1]) == connectedNode.end())
//        {
//            connectedNode.push_back(e.node[1]);//연결된 노드 리스트에 넣어주고
//            mstValue += e.distance;// 최소신장트리에 간선 길이 더해줌
//
//            //더해준 노드들의 연결된 간선들을 다 추가해줌
//            auto it = find_if(matrix.begin(), matrix.end(), [&](Edge edge) {return e.node[1] == edge.node[0]; });
//            while (it != matrix.end())
//            {
//                candidateEdgesQueue.push(*it);
//                it = find_if(it + 1, matrix.end(), [&](Edge edge) {return e.node[1] == edge.node[0]; });
//            }
//        }
//
//    }
//    return mstValue;
//}
//
//int main()
//{
//    vector<Edge> matrix;
//    matrix.push_back(Edge(0, 1, 5));
//    matrix.push_back(Edge(0, 3, 7));
//    matrix.push_back(Edge(1, 4, 3));
//    matrix.push_back(Edge(1, 2, 3));
//    matrix.push_back(Edge(2, 3, 4));
//    matrix.push_back(Edge(2, 4, 2));
//    matrix.push_back(Edge(3, 5, 1));
//    matrix.push_back(Edge(4, 5, 4));
//    int size = matrix.size();
//    for (int index = 0; index < size; index++)
//    {
//        matrix.push_back(Edge(matrix[index].node[1], matrix[index].node[0], matrix[index].distance));
//    }
//
//    cout << Prim(matrix, 0) << endl;
//}
//

#pragma endregion

#pragma region Programmers
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//    vector<int> answer;
//    for (int commandIndex = 0; commandIndex < commands.size(); commandIndex++)
//    {
//        vector<int> tempVector;
//        int startIndex = commands[commandIndex][0];
//        int endIndex = commands[commandIndex][1];
//        for (int index = startIndex - 1; index < endIndex; index++)
//        {
//            tempVector.push_back(array[index]);
//        }
//        sort(tempVector.begin(), tempVector.end(), less<int>());
//        int selectIndex = commands[commandIndex][2];
//        answer.push_back(tempVector[selectIndex - 1]);
//    }
//    return answer;
//}
//
//int main()
//{
//    vector<int> answer = solution({ 1,5,2,6,3,7,4 }, { {2,5,3},{4,4,1},{1,7,3} });
//    for (auto number : answer)
//    {
//        cout << number << endl;
//    }
//}
#pragma endregion

#pragma region Programmers Union-Find
//int findParent(int container[], int number)
//{
//    if (container[number] != number)
//    {
//        container[number] = findParent(container, container[number]);
//        return container[number];
//    }
//    return container[number];
//}
//
//void Union(int container[], int num1, int num2)
//{
//    int parent1 = findParent(container, num1);
//    int parent2 = findParent(container, num2);
//    if (parent1 > parent2)
//    {
//        container[parent1] = parent2;
//    }
//    else
//    {
//        container[parent2] = parent1;
//    }
//}
//
//int solution(int n, vector<vector<int>> computers)
//{
//    int answer = 0;
//    //Init parents
//    int* parents = new int[n];
//    for (int index = 0; index < n; index++)
//    {
//        parents[index] = index;
//    }
//
//
//    for (int index = 0; index < computers.size(); index++)
//    {
//        for (int vectorIndex = 0; vectorIndex < computers[index].size(); vectorIndex++)
//        {
//            if (computers[index][vectorIndex] == 1 && index != vectorIndex)
//            {
//                Union(parents, index, vectorIndex);
//            }
//        }
//    }
//    set<int> parentSet;
//    for (int index = 0; index < n; index++)
//    {
//        parents[index] = findParent(parents, index);
//        parentSet.insert(parents[index]);
//    }
//    answer = parentSet.size();
//    delete[] parents;
//    return answer;
//}
//
//int main()
//{
//    cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} });
//	return 0;
//}

#pragma endregion



//int main()
//{
//	int numbers[8] = { 0, };
//	
//	for (int number = 0; number < 8; number++)
//	{
//		cin >> numbers[number];
//	}
//
//	if (numbers[0] == 1)
//	{
//		for (int number = 1; number < 8; number++)
//		{
//			if (numbers[number - 1] > numbers[number])
//			{
//				cout << "mixed";
//				return 0;
//			}
//		}
//		cout << "ascending";
//	}
//	else if (numbers[0] == 8)
//	{
//		for (int number = 1; number < 8; number++)
//		{
//			if (numbers[number - 1] < numbers[number])
//			{
//				cout << "mixed";
//				return 0;
//			}
//		}
//		cout << "descending";
//	}
//	else
//	{
//		cout << "mixed";
//	}
//	return 0;
//}

int main()
{
	int totalCard = 0;
	int totalSum = 0;

	cin >> totalCard;
	cin >> totalSum;

	int* cards = new int[totalCard];
	
	for (int count = 0; count < totalCard; count++)
	{
		cin >> cards[count];
	}

	int nearSum = -100;
	// Init end
	//Logic
	for (int index = 0; index < totalCard; index++)
	{
		int localSum = cards[index];
		for (int secIndex = index + 1; secIndex < totalCard; secIndex++)
		{
			localSum += cards[secIndex];
			for (int thirdIndex = secIndex + 1; thirdIndex < totalCard; thirdIndex++)
			{
				localSum += cards[thirdIndex];
				if (localSum <= totalSum && nearSum < localSum)
				{
					nearSum = localSum;
				}
				localSum -= cards[thirdIndex];
			}
			localSum -= cards[secIndex];
		}
	}
	cout << nearSum;

	// Clear Memory
	if (cards != nullptr)
	{
		delete[] cards;
		cards = nullptr;
	}


	return 0;
}
