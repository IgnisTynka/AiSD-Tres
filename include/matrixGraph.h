#pragma once

#include "graph.h"

class MatrixGraph : public Graph{
public:
    MatrixGraph(int nodes, float saturation);
    MatrixGraph(int nodes, std::vector<int> from, std::vector<int> to);
    ~MatrixGraph();

    virtual void print() override;

    virtual bool findEdge(int from, int to) override;

    virtual std::vector<int> bfs() override;
    virtual std::vector<int> dfs() override;

    virtual std::vector<int> kahn() override;
    virtual std::vector<int> tarjan() override;

protected:
    int _nodes;
    std::vector<bool> _matrix;
};
