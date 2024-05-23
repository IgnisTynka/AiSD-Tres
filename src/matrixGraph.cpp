#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>

#include "matrixGraph.h"

MatrixGraph::MatrixGraph(int nodes, float saturation) {
    _nodes = nodes;
    std::vector<bool> matrix(_nodes * _nodes, false);
    _matrix = std::vector<bool>(_nodes * _nodes);

    for (int i = 0; i < _nodes-1; i++) {
        int j = i + 1;
        int edge = rand() % (_nodes - j) + j;
        matrix[i * _nodes + edge] = true;
        if (saturation == 0.f) {
            continue;
        }
        for (int k = j; k < _nodes-1; k++) {
            float p = (float)rand() / RAND_MAX;
            if (p <= saturation) {
                matrix[i * _nodes + k] = true;
            }
        }
    }

    std::vector<int> newOrder(_nodes);
    for (int i = 0; i < _nodes; i++){
        newOrder[i] = i;
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::shuffle(std::begin(newOrder), std::end(newOrder), rng);

    for (int i = 0; i < _nodes; i++) {
        for (int j = 0; j < _nodes; j++) {
            _matrix[i * _nodes + j] = matrix[newOrder[i]*_nodes + newOrder[j]];
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
    if (--from > _nodes || --to > _nodes) {
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

    for (int i = 0; i < _nodes; i++) {
        if (inDegree[i] == 0) {
            queue.push(i);
        }
    }

    while (!queue.empty()) {
        int curr = queue.front();
        queue.pop();
        kahn.push_back(curr + 1);

        for (int i = 0; i < _nodes; i++) {
            if (_matrix[curr * _nodes + i]) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue.push(i);
                }
            }
        }
    }

    if (kahn.size() != _nodes) {
        return std::vector<int>();
    }

    return kahn;    
}

std::vector<int> MatrixGraph::tarjan() {
    std::vector<int> tarjan;
    std::queue<int> queue;
    std::vector<int> inDegree(_nodes, 0);
    std::vector<bool> permanent (_nodes, false);
    std::vector<bool> temporary (_nodes, false);

    for (int i = 0; i < _nodes; i++) {
        for (int j = 0; j < _nodes; j++) {
            if (_matrix[j * _nodes + i]) {
                inDegree[i]++;
            }
        }
    }

    for (int i = 0; i < _nodes; i++) {
        if (inDegree[i] == 0) {
            queue.push(i);
        }
    }

    while(!queue.empty()) {
        int curr = queue.front();
        queue.pop();

        if (!permanent[curr]) {
            _visit(tarjan, permanent, temporary, curr);
        }
    }

    if (tarjan.size() != _nodes) {
        return std::vector<int>();
    } 

    std::reverse(tarjan.begin(), tarjan.end());
    return tarjan;
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

void MatrixGraph::_visit(std::vector<int> &tarjan, std::vector<bool> &permanent, std::vector<bool> &temporary, int startNode) {
    if (temporary[startNode]) {
        return;
    }

    temporary[startNode] = false;

    for (int i = 0; i < _nodes; i++) {
        if (_matrix[startNode * _nodes + i] && !permanent[i]) {
            _visit(tarjan, permanent, temporary, i);
        }
    }

    permanent[startNode] = true;
    tarjan.push_back(startNode + 1);
}
