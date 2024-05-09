#pragma once

#include <queue>
#include <stack>

#include "graph.h"

class ListGraph : public Graph {
public:
    ListGraph(int nodes, float saturation);
    ListGraph(int nodes, std::vector<std::set<int>> list);
    ~ListGraph();

    virtual void print() override;

    virtual bool findEdge(int from, int to) override;

    virtual std::vector<int> bfs() override;
    virtual std::vector<int> dfs() override;

    virtual std::vector<int> kahn() override;
    virtual std::vector<int> tarjan() override;

protected:
    int _nodes;
    std::vector<std::set<int>> _list;

private:
    void _bfs(std::vector<bool> &visited, std::queue<int> &queue, std::vector<int> &bfs, int startNode);
    void _dfs(std::vector<bool> &visited, std::stack<int> &stack, std::vector<int> &dfs, int startNode);  
};
