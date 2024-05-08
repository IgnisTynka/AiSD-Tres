#pragma once

#include <set>
#include <vector>

class Graph {
public:
    Graph(){}
    ~Graph(){}

    virtual void print() = 0;

    virtual bool findEdge(int from, int to) = 0;

    virtual std::vector<int> bfs() = 0;
    virtual std::vector<int> dfs() = 0;

    virtual std::vector<int> kahn() = 0;
    virtual std::vector<int> tarjan() = 0;
};
