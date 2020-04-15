#include <iostream>
#include <string>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bsd(const unordered_map<string, vector<string>>& graph)
{
    vector<string> checked;
    queue<string> checking;

    checking.push("Alice");

    while(!checking.empty())
    {
        const auto& next = checking.front();

        if(find(checked.begin(), checked.end(), next) != checked.end()) 
        {
            checking.pop();
            continue;
        }

        if(next == "Murka") return 1;

        vector<string> neighbours;

        try
        {
            neighbours = graph.at(next);
        }
        catch(...)
        {
            checking.pop();
            continue;
        }

        for(const auto& next : neighbours)
        {
            checking.push(next);
        }

        checked.push_back(next);
        checking.pop();
    }

    return 0;
}

int main()
{
    unordered_map<string, vector<string>> graph;

    graph["Alice"] = vector<string>{"Bob", "Frog", "Dog"};
    graph["Bob"] = vector<string>{"Cat", "Frog"};
    graph["Dog"] = vector<string>{"Bob", "Cat"};
    graph["Frog"] = vector<string>{"Bob", "Murka", "Dog"};

    cout << bsd(graph) << endl;

    return 0;
}

