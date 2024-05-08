#include <iostream>
#include <ctime>

#include "tableGraph.h"

TableGraph::TableGraph(int nodes, float saturation) {
    _nodes = nodes;
    std::pair<int, int> temp;
    for (int i = 0; i < _nodes-1; i++) {
        int j = i + 1;
        int edge = rand() % (_nodes - j) + j;
        temp.first = i;
        temp.second = edge;
        _table.insert(temp);
        if (saturation == 0.f) {
            continue;
        }
        for (int k = j; k < edge; k++) {
            int p = (float)rand() / RAND_MAX;
            if (p <= saturation) {
                temp.first = i;
                temp.second = k;
                _table.insert(temp);
            }
        }
    }

}

TableGraph::TableGraph(int nodes, std::vector<std::set<int>> list) {
    _nodes = nodes;
    std::pair<int, int> temp;
    for (int i = 0; i < _nodes; i++) {
        for (int node : list[i]){
            temp.first = i;
            temp.second = node -1;
            _table.insert(temp);
        }
    }
}

void TableGraph::print() {
    for (const std::pair<int, int> &edge : _table) {
        std::cout << edge.first + 1 << " " << edge.second + 1 << std::endl;
    }
}

bool TableGraph::findEdge(int from, int to) {
    for (const std::pair<int, int> &edge : _table) {
        if (edge.first == from && edge.second == to) {
            return true;
        }
    }
    return false;
    
}

std::vector<int> TableGraph::bfs() {
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

std::vector<int> TableGraph::dfs() {
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

std::vector<int> TableGraph::kahn() {
    
}
std::vector<int> TableGraph::tarjan() {
    
}

void TableGraph::_bfs(std::vector<bool> &visited, std::queue<int> &queue, std::vector<int> &bfs, int startNode) {
        
    visited[startNode] = true;
    queue.push(startNode);

    while(!queue.empty()) {
        int curr = queue.front();
        queue.pop();
        bfs.push_back(curr + 1);

        for(const std::pair<int, int> &edge : _table) {
            if (edge.first == curr && !visited[edge.second]) {
                visited[edge.second] = true;
                queue.push(edge.second);
            }
        }
    }
}

void TableGraph::_dfs(std::vector<bool> &visited, std::stack<int> &stack, std::vector<int> &dfs, int startNode) {
    visited[startNode] = true;
    stack.push(startNode);

    while(!stack.empty()) {
        int curr = stack.top();
        stack.pop();
        dfs.push_back(curr + 1);

        for(std::set<std::pair<int, int>>::reverse_iterator it = _table.rbegin(); it != _table.rend(); it++) {
            if ((*it).first == curr && !visited[(*it).second]) {
                visited[(*it).second] = true;
                stack.push((*it).second);
            }            
        }
    }
}
