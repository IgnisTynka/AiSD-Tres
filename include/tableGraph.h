#pragma once

#include "graph.h"

class TableGraph : public Graph{
public:
    TableGraph(int nodes, float saturation);
    TableGraph(int nodes, std::vector<int> from, std::vector<int> to); 
    ~TableGraph();

    virtual void print() override;

    virtual bool findEdge(int from, int to) override;

    virtual std::vector<int> bfs() override;
    virtual std::vector<int> dfs() override;

    virtual std::vector<int> kahn() override;
    virtual std::vector<int> tarjan() override;

protected:
    struct Edge {
        int from;
        int to;
    };
    
    int _nodes;
    std::vector<Edge> _table;
};