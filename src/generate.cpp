#include <iostream>
#include <sstream>

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
        std::string nodesStr;
        std::getline(std::cin, nodesStr);
        
        std::cout << nodesStr << std::endl;
        nodes = std::atoi(nodesStr.c_str());
        
        if (nodes > 0)  {
            break;
        }
        std::cout << "Invalid number of nodes (>0)" << std::endl;
    }

    while (true) {
        std::cout << "saturation> ";
        std::string saturationStr;
        std::getline(std::cin, saturationStr);

        std::cout << saturationStr << std::endl;
        saturation = std::atof(saturationStr.c_str());

        if (saturation > 0 && saturation <= 1) {
            break;
        }
        std::cout << "Invalid saturation ((0,1>)" << std::endl;
    }

    while (true) {
        std::cout << "type> ";
        std::cin >> type;
        std::cout << type << std::endl;

        if (type == "matrix") {
            return new MatrixGraph(nodes, saturation);
        }
        if (type == "list") {
            return new ListGraph(nodes, saturation);
        }
        if (type == "table") {
            return new TableGraph(nodes, saturation);
        }
        std::cout << "Invalid type (matrix, list, table)" << std::endl;
    }
    
}
