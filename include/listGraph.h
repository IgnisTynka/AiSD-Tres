#pragma once

#include "graph.h"

class ListGraph : public Graph {
public:
    ListGraph(int nodes, float saturation);
    ListGraph(int nodes, std::vector<int> from, std::vector<int> to);
    ~ListGraph();

    virtual void print() override;

    virtual bool findEdge(int from, int to) override;

    virtual std::vector<int> bfs() override;
    virtual std::vector<int> dfs() override;

    virtual std::vector<int> kahn() override;
    virtual std::vector<int> tarjan() override;

protected:
    int _nodes;
    std::vector<std::vector<int>> _list;
};
