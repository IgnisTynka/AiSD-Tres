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
}

MatrixGraph::MatrixGraph(int nodes, std::vector<std::set<int>> list) {
    _nodes = nodes;
    _matrix = std::vector<bool>(_nodes * _nodes, false);
    for (int i = 0; i < _nodes; i++) {
        for (int node : list[i]){ 
            _matrix[i * _nodes + (node-1)] = true;
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
    if (from > _nodes || to > _nodes) {
        return false;
    }
    
    return _matrix[(from-1) * _nodes + (to-1)];
}

std::vector<int> MatrixGraph::bfs() {
    std::vector<bool> visited(_nodes, false);
    std::queue<int> queue;
    std::vector<int> bfs;
    
    for (int i = 0; i < _nodes; i++) {
        if(!visited[i]) {
            _bfs(visited, queue, bfs, i);
        }
    }

    return bfs;
}

std::vector<int> MatrixGraph::dfs() {
    std::vector<bool> visited(_nodes, false);
    std::stack<int> stack;
    std::vector<int> dfs;
    
    for (int i = 0; i < _nodes; i++) {
        if(!visited[i]) {
            _dfs(visited, stack, dfs, i);
        }
    }

    return dfs;
}

std::vector<int> MatrixGraph::kahn() {
    std::vector<int> kahn;
    std::queue<int> queue;
    std::vector<int> inDegree(_nodes, 0);

    for (int i = 0; i < _nodes; i++) {
        for (int j = 0; j < _nodes; j++) {
            if (_matrix[j * _nodes + i]) {
                inDegree[i]++;
            }
        }
    }
    
}

std::vector<int> MatrixGraph::tarjan() {
    
}

void MatrixGraph::_bfs(std::vector<bool>& visited, std::queue<int>& queue, std::vector<int>& bfs, int startNode) {
    visited[startNode] = true;
    queue.push(startNode);

    while (!queue.empty()) {
        int curr = queue.front();
        queue.pop();
        bfs.push_back(curr + 1);

        for (int i = 0; i < _nodes; i++) {
            if (_matrix[curr * _nodes + i] && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    
}

void MatrixGraph::_dfs(std::vector<bool>& visited, std::stack<int>& stack, std::vector<int>& dfs, int startNode) {
    visited[startNode] = true;
    stack.push(startNode);

    while(!stack.empty()) {
        int curr = stack.top();
        stack.pop();
        dfs.push_back(curr + 1);

        for (int i = _nodes; i > 0; i--) {
            if (_matrix[curr * _nodes + i] && !visited[i]) {
                visited[i] = true;
                stack.push(i);
            }
        }
    }
}
