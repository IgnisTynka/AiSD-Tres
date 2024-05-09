#pragma once

#include <queue>
#include <stack>

#include "graph.h"

class MatrixGraph : public Graph{
public:
    MatrixGraph(int nodes, float saturation);
    MatrixGraph(int nodes, std::vector<std::set<int>> list);
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

private:
    void _bfs(std::vector<bool> &visited, std::queue<int> &queue, std::vector<int> &bfs, int startNode);
    void _dfs(std::vector<bool> &visited, std::stack<int> &stack, std::vector<int> &dfs, int startNode);
    void _visit(std::vector<int> &kahn, std::vector<bool> &permanent, std::vector<bool> &temporary, int startNode);
};
