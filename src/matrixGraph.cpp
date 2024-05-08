#include <iostream>
#include <random>
#include <cstdlib>

#include "matrixGraph.h"

MatrixGraph::MatrixGraph(int nodes, float saturation) {
    _nodes = nodes;
    _matrix = std::vector<bool>(_nodes * _nodes, false);
    
    for (int i = 0; i < _nodes-1; i++) {
        int j = i + 1;
        int edge = rand() % (_nodes - j) + j;
        _matrix[i * _nodes + edge] = true;
        if (saturation == 0.f) {
            continue;
        }
        for (int k = j; k < edge; k++) {
            int p = (float)rand() / RAND_MAX;
            if (p <= saturation) {
                _matrix[i * _nodes + k] = true;
            }
        }
    }

    // std::vector<int> shuffledNodes(_nodes);
    // for (int i = 0; i < _nodes; i++) {
    //     shuffledNodes[i] = i;
    // }

    // std::shuffle(shuffledNodes.begin(), shuffledNodes.end(), std::default_random_engine());

}

MatrixGraph::MatrixGraph(int nodes, std::vector<std::vector<int>> list) {
    _nodes = nodes;
    _matrix = std::vector<bool>(_nodes * _nodes, false);
    for (int i = 0; i < _nodes; i++) {
        for (int j = 0; j < list[i].size(); j++) {
            _matrix[i * _nodes + (list[i][j]-1)] = true;
        }
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