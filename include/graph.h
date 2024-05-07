#pragma once

#include <vector>

class Graph {
public:
    Graph(){}
    ~Graph(){}

    virtual void create(int nodes, std::vector<int> from, std::vector<int> to) = 0;

    virtual void print() = 0;

    virtual bool findEdge(int from, int to) = 0;

    virtual std::vector<int> bfs() = 0;
    virtual std::vector<int> dfs() = 0;

    virtual std::vector<int> kahn() = 0;
    virtual std::vector<int> tarjan() = 0;
};
