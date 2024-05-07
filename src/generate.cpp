#include <iostream>

#include "functions.h"
#include "tableGraph.h"
#include "matrixGraph.h"
#include "listGraph.h"

Graph* generate() {
    int nodes;
    float saturation;
    std::string type;
    
    while (true) {
        std::cout << "nodes> ";
        std::cin >> nodes;
        if (nodes > 0) {
            break;
        }
        std::cout << "\nInvalid number of nodes (>0)" << std::endl;
    }

    while (true) {
        std::cout << "saturation> ";
        std::cin >> saturation;
        if (saturation >= 0 && saturation <= 1) {
            break;
        }
        std::cout << "\nInvalid saturation (<0,1>)" << std::endl;
    }

    while (true) {
        std::cout << "type> ";
        std::cin >> type;
        if (type == "matrix") {
            return new MatrixGraph(nodes, saturation);
        }
        if (type == "list") {
            return new ListGraph(nodes, saturation);
        }
        if (type == "table") {
            return new TableGraph(nodes, saturation);
        }
        std::cout << "\nInvalid type (matrix, list, table)" << std::endl;
    }
    
}
