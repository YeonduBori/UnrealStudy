#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Edge
{
public:
    int node[2] = { 0, };
    int distance = 0;
    Edge(int nodeStart, int nodeEnd, int distance) :node{ nodeStart, nodeEnd }, distance(distance)
    {
    }
};

struct CompareEdge
{
    bool operator()(Edge e1, Edge e2)
    {
        return e1.distance > e2.distance;
    }
};

int Prim(vector<Edge>& matrix, int startNode)
{
    int mstValue = 0;
    vector<int> connectedNode;
    priority_queue<Edge, vector<Edge>, CompareEdge> candidateEdgesQueue;
    //스타트 노드를 넣고 스타트노드에 연결된 모든 간선들을 우선순위(거리) Edge큐에 집어넣음
    connectedNode.push_back(startNode);
    {
        auto it = find_if(matrix.begin(), matrix.end(), [&](Edge edge) {return startNode == edge.node[0]; });
        while (it != matrix.end())
        {
            candidateEdgesQueue.push(*it);
            it = find_if(it + 1, matrix.end(), [&](Edge edge) {return startNode == edge.node[0]; });
        }
    }

    while (!candidateEdgesQueue.empty())
    {
        Edge e = candidateEdgesQueue.top();
        candidateEdgesQueue.pop();
        //가장 작은 간선길이를 가진 노드의 종착지가 싸이클에 포함되지 않는지 확인
        //사이클에 포함되지 않음 왜냐면 반복자로 find했을때 end에 도달하였기때문
        if (find(connectedNode.begin(), connectedNode.end(), e.node[1]) == connectedNode.end())
        {
            connectedNode.push_back(e.node[1]);//연결된 노드 리스트에 넣어주고
            mstValue += e.distance;// 최소신장트리에 간선 길이 더해줌

            //더해준 노드들의 연결된 간선들을 다 추가해줌
            auto it = find_if(matrix.begin(), matrix.end(), [&](Edge edge) {return e.node[1] == edge.node[0];});
            while (it != matrix.end())
            {
                candidateEdgesQueue.push(*it);
                it = find_if(it + 1, matrix.end(), [&](Edge edge) {return e.node[1] == edge.node[0];});
            }
        }

    }
    return mstValue;
}

int main()
{
    vector<Edge> matrix;
    matrix.push_back(Edge(0,1,5));
    matrix.push_back(Edge(0,3,7));
    matrix.push_back(Edge(1,4,3));
    matrix.push_back(Edge(1,2,3));
    matrix.push_back(Edge(2,3,4));
    matrix.push_back(Edge(2,4,2));
    matrix.push_back(Edge(3,5,1));
    matrix.push_back(Edge(4,5,4));
    int size = matrix.size();
    for (int index = 0; index < size; index++)
    {
        matrix.push_back(Edge(matrix[index].node[1], matrix[index].node[0], matrix[index].distance));
    }

    cout << Prim(matrix, 0) << endl;
}


