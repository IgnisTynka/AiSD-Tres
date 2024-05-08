#include <iostream>

#include "listGraph.h"

ListGraph::ListGraph(int nodes, float saturation) {
    _nodes = nodes;
    _list.resize(_nodes);

    for (int i = 0; i < _nodes-1; i++) {
        int j = i + 1;
        int edge = rand() % (_nodes - j) + j;
        _list[i].insert(edge);
        if (saturation == 0.f) {
            continue;
        }
        for (int k = j; k < edge; k++) {
            int p = (float)rand() / RAND_MAX;
            if (p <= saturation) {
                _list[i].insert(k);
            }
        }
    }

}

ListGraph::ListGraph(int node, std::vector<std::set<int>> list) {
    _nodes = node;
    _list = std::vector<std::set<int>>(_nodes);
    for (int i = 0; i < _nodes; i++) {
        for (int node : list[i]) {
            _list[i].insert(node - 1);
        }
    }
}

void ListGraph::print() {
    for (int i = 0; i < _nodes; i++) {
        std::cout << i+1 << " -> ";
        for (int node : _list[i]) {
            std::cout << node + 1 << " ";
        }
        std::cout << std::endl;
    }
}

bool ListGraph::findEdge(int from, int to) {
    for (int node : _list[from-1]) {
        if (node == to-1) {
            return true;
        }
    }
    return false;
}

std::vector<int> ListGraph::bfs() {
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

std::vector<int> ListGraph::dfs() {
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

std::vector<int> ListGraph::kahn() {

}
std::vector<int> ListGraph::tarjan() {

}

void ListGraph::_bfs(std::vector<bool> &visited, std::queue<int> &queue, std::vector<int> &bfs, int startNode) {
    visited[startNode] = true;
    queue.push(startNode);

    while(!queue.empty()){
        int curr = queue.front();
        queue.pop();
        bfs.push_back(curr + 1);
        
        for (int node : _list[curr]){
            if(!visited[node]) {
                visited[node] = true;
                queue.push(node);
            }
        }
    }
}

void ListGraph::_dfs(std::vector<bool> &visited, std::stack<int> &stack, std::vector<int> &dfs, int startNode) {
    visited[startNode] = true;
    stack.push(startNode);

    while(!stack.empty()) {
        int curr = stack.top();
        stack.pop();
        dfs.push_back(curr + 1);

        for (std::set<int>::reverse_iterator it = _list[curr].rbegin(); it != _list[curr].rend(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                stack.push(*it);
            }
        }
    }
}
