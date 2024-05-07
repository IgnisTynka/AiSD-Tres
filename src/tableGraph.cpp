#include <iostream>

#include "tableGraph.h"

TableGraph::TableGraph(int nodes, float saturation) {
    _nodes = nodes;
    _table.resize(_nodes);
}

TableGraph::TableGraph(int nodes, std::vector<int> from, std::vector<int> to) {
    _nodes = nodes;
    Edge temp;
    for (int i = 0; i < from.size(); i++) {
        temp.from= from[i];
        temp.to = to[i];
        _table.push_back(temp);
    }
}

void TableGraph::print() {
    for (int i = 0; i < _table.size(); i++) {
        std::cout << _table[i].from << " " << _table[i].to << std::endl;
    }
}

bool TableGraph::findEdge(int from, int to) {
    for (int i = 0; i < _table.size(); i++) {
        if (_table[i].from == from && _table[i].to == to) {
            return true;
        }
    }
    return false;
    
}

std::vector<int> TableGraph::bfs() {
        
}
std::vector<int> TableGraph::dfs() {
    
}

std::vector<int> TableGraph::kahn() {
    
}
std::vector<int> TableGraph::tarjan() {
    
}