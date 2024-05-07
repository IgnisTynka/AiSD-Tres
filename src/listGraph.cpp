#include <iostream>

#include "listGraph.h"

ListGraph::ListGraph(int nodes, float saturation) {
    _nodes = nodes;
    _list.resize(_nodes);
    
}

ListGraph::ListGraph(int node,std::vector<int> from, std::vector<int> to) {
    _nodes = node;
    _list.resize(_nodes);
    for (int i = 0; i < from.size(); i++) {
        _list[from[i]-1].push_back(to[i]-1);
    }
}

void ListGraph::print() {
    for (int i = 0; i < _nodes; i++) {
        std::cout << i+1 << " -> ";
        for (int j = 0; j < _list[i].size(); j++) {
            std::cout << _list[i][j]+1 << " ";
        }
        std::cout << std::endl;
    }

}

bool ListGraph::findEdge(int from, int to) {
    for (int i = 0; i < _list[from-1].size(); i++) {
        if (_list[from-1][i] == to-1) {
            return true;
        }
    }
    return false;
}

std::vector<int> ListGraph::bfs() {

}

std::vector<int> ListGraph::dfs() {

}

std::vector<int> ListGraph::kahn() {

}
std::vector<int> ListGraph::tarjan() {

}