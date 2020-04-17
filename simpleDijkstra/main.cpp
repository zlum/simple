#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct Edge
{
    explicit Edge(int a, int b, int c): from(a), to(b), cost(c) {}

    int from; // Begin node number
    int to; // End node number
    int cost; // Distance
};

class Graph
{
public:
    void addEdge(int from, int to, int cost)
    {
        _edges[from].emplace_back(from, to, cost);
    }

    unordered_map<int, int> dijkstra(int startNode);

private:
    // Finds node with minimal weight
    // Minimal weight node will be a neighbour of visited one
    // Farther nodes have INT32_MAX weight value
    int findLowestCostNotVisited(const unordered_map<int, int>& weights,
                                 const vector<int>& visited)
    {
        int minCost = INT32_MAX;
        int res = INT32_MAX;

        for(auto it = weights.begin(); it != weights.end(); ++it)
        {
            // Skip visited
            if(find(visited.begin(), visited.end(), it->first) != visited.end())
            {
                continue;
            }

            int cost = it->second;

            if(cost < minCost)
            {
                // Better cost node has been found
                minCost = cost;
                res = it->first;
            }
        }

        return res;
    }

private:
    unordered_map<int, vector<Edge>> _edges;
};

unordered_map<int, int> Graph::dijkstra(int startNode)
{
    vector<int> visited; // Visited nodes
    unordered_map<int, int> backtrace; // Save path to reconstruct
    unordered_map<int, int> weights; // Node weights
    int curNode = startNode;

    // Set every node weight to MAX and start to ZERO
    for(unsigned i = 0; i < _edges.size() + 1; i++) weights[i] = INT32_MAX;
    weights[startNode] = 0;

    // Traverse graph
    while(curNode != INT32_MAX)
    {
        int cost = weights.at(curNode);

        try
        {
            // Throws exception on last node
            for(const auto& neighbour : _edges.at(curNode))
            {
                // Compares current cost with previously calculated one
                int curCost = neighbour.cost + cost;
                int neiCost = weights.at(neighbour.to);

                if(curCost < neiCost)
                {
                    // Better path has been found
                    weights[neighbour.to] = curCost;
                    backtrace[neighbour.to] = neighbour.from;
                }
            }
        }
        catch(...)
        {
            return backtrace;
        }

        visited.push_back(curNode);
        curNode = findLowestCostNotVisited(weights, visited);
    }

    return backtrace;
}

void printBacktrace(const unordered_map<int, int>& backtrace, int endNode)
{
    int res = backtrace.at(endNode);

    cout << endNode << endl;

    if(res == 0)
    {
        return;
    }
    else
    {
        printBacktrace(backtrace, res);
    }
}

int main()
{
    Graph graph;

    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 35);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 4, 15);
    graph.addEdge(3, 4, 75);
    graph.addEdge(4, 5, 99);
    graph.addEdge(4, 6, 10);
    graph.addEdge(5, 7, 10);
    graph.addEdge(6, 7, 99);

    auto backtrace = graph.dijkstra(0);

    printBacktrace(backtrace, 7);

    return 0;
}
