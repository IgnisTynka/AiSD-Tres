#include <iostream>

#include "../include/matrixGraph.h"

void MatrixGraph::create(int nodes, std::vector<int> from, std::vector<int> to) {
    _nodes = nodes;
    _matrix.resize(_nodes * _nodes);
    for (int i = 0; i < from.size(); i++) {
        _matrix[(from[i]-1) * _nodes + (to[i]-1)] = true;
    }
}

void MatrixGraph::print() {
    for (int i = 0; i < _nodes; i++) {
        for (int j = 0; j < _nodes; j++) {
            std::cout << _matrix[i * _nodes + j] << " ";
        }
        std::cout << std::endl;
    }
}

bool MatrixGraph::findEdge(int from, int to) {
    return _matrix[(from-1) * _nodes + (to-1)];
}

std::vector<int> MatrixGraph::bfs() {
    
}
std::vector<int> MatrixGraph::dfs() {
    
}

std::vector<int> MatrixGraph::kahn() {
    
}
std::vector<int> MatrixGraph::tarjan() {
    
}