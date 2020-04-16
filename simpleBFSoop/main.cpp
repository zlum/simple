#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph
{
public:
    void addEdge(int a, int b);
    void bsd(int start);

private:
    unordered_map<int, vector<int>> _edges;
};

void Graph::addEdge(int a, int b)
{
    _edges[a].emplace_back(b);
}

void Graph::bsd(int start)
{
    vector<int> checked;
    queue<int> checking;

    checking.push(start);

    while(!checking.empty())
    {
        int next = checking.front();

        if(find(checked.begin(), checked.end(), next) != checked.end())
        {
            checking.pop();
            continue;
        }

        checked.push_back(next);
        cout << next << endl;

        for(const auto& next : _edges[next])
        {
            checking.push(next);
        }
    }
}

int main()
{
    Graph graph{};

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 0);
    graph.addEdge(2, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.bsd(0);

    return 0;
}
