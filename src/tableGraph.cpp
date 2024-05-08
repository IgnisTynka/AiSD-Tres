#include <iostream>
#include <ctime>

#include "tableGraph.h"

TableGraph::TableGraph(int nodes, float saturation) {
    _nodes = nodes;
    Edge temp;
    for (int i = 0; i < _nodes-1; i++) {
        int j = i + 1;
        int edge = rand() % (_nodes - j) + j;
        temp.from = i + 1;
        temp.to = edge + 1;
        _table.push_back(temp);
        if (saturation == 0.f) {
            continue;
        }
        for (int k = j; k < edge; k++) {
            int p = (float)rand() / RAND_MAX;
            if (p <= saturation) {
                temp.from = i + 1;
                temp.to = k + 1;
                _table.push_back(temp);
            }
        }
    }

}

TableGraph::TableGraph(int nodes, std::vector<std::vector<int>> list) {
    _nodes = nodes;
    Edge temp;
    for (int i = 0; i < _nodes; i++) {
        for (int j = 0; j < list[i].size(); j++){
            temp.from = i + 1;
            temp.to = list[i][j];
        }
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