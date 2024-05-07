#pragma once

#include <vector>

#include "graph.h"

class ListGraph : public Graph {
public:
    ListGraph();
    ListGraph(int nodes, std::vector<int> from, std::vector<int> to) { create(nodes, from, to); }
    ~ListGraph();
    
    virtual void create(int nodes, std::vector<int> from, std::vector<int> to) override;

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