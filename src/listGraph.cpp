#include <iostream>

#include "listGraph.h"

ListGraph::ListGraph(int nodes, float saturation) {
    _nodes = nodes;
    _list.resize(_nodes);

    for (int i = 0; i < _nodes-1; i++) {
        int j = i + 1;
        int edge = rand() % (_nodes - j) + j;
        _list[i].push_back(edge);
        if (saturation == 0.f) {
            continue;
        }
        for (int k = j; k < edge; k++) {
            int p = (float)rand() / RAND_MAX;
            if (p <= saturation) {
                _list[i].push_back(k);
            }
        }

    }
    
}

ListGraph::ListGraph(int node, std::vector<std::vector<int>> list) {
    _nodes = node;
    _list.resize(_nodes);
    std::vector<int> nodes;
    for (int i = 0; i < _nodes; i++) {
        nodes.resize(list[i].size());
        for (int j = 0; j < list[i].size(); j++){
            nodes[j] = list[i][j] - 1;
        }
        _list[i] = nodes;
    }
}

void ListGraph::print() {
    for (int i = 0; i < _nodes; i++) {
        std::cout << i+1 << " -> ";
        for (int j = 0; j < _list[i].size(); j++) {
            std::cout << _list[i][j] + 1 << " ";
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