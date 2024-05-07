#include <iostream>
#include <vector>

#include "functions.h"
#include "tableGraph.h"
#include "matrixGraph.h"
#include "listGraph.h"

Graph* userBuild() {
    std::string type;
    int nodes;
    std::vector<int> from;
    std::vector<int> to;
    
    while (true) {
        std::cout << "nodes> ";
        std::cin >> nodes;
        if (nodes > 0) {
            break;
        }
        std::cout << "\nInvalid number of nodes (>0)" << std::endl;
    }

    while (true) {
            std::cout << "type> ";
            std::cin >> type;
            if (type == "matrix") {
                return new MatrixGraph(nodes, from, to);
            }
            if (type == "list") {
                return new ListGraph(nodes, from, to);
            }
            if (type == "table") {
                return new TableGraph(nodes, from, to);
            }
            std::cout << "\nInvalid type (matrix, list, table)" << std::endl;
        }

}
