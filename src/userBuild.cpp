#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib> // for std::atoi

#include "functions.h"
#include "tableGraph.h"
#include "matrixGraph.h"
#include "listGraph.h"

Graph* userBuild() {
    std::string type;
    int nodes;
    std::vector<std::vector<int>> list;

    while (true) {
        std::cout << "nodes> ";
        std::string nodesStr;
        std::getline(std::cin, nodesStr);

        // Convert the string to an integer
        nodes = std::atoi(nodesStr.c_str());

        if (nodes > 0) {
            break;
        }
        std::cout << "\nInvalid number of nodes (>0)" << std::endl;
    }

    std::string sequence;
    for (int i = 0; i < nodes; i++) {
        std::cout << i+1 <<"> ";
        std::getline(std::cin, sequence);
        std::istringstream iss(sequence);

        std::vector<int> numbers;
        int num;
        while (iss >> num) {
            numbers.push_back(num);
            std::cout << num << " ";
        } 
    
        list.push_back(numbers);
        std::cout << std::endl;
    }

    while (true) {
        std::cout << "type> ";
        std::cin >> type;
        std::cout << type << std::endl;

        if (type == "matrix") {
            return new MatrixGraph(nodes, list);
        }
        if (type == "list") {
            return new ListGraph(nodes, list);
        }
        if (type == "table") {
            return new TableGraph(nodes, list);
        }
        std::cout << "Invalid type (matrix, list, table)" << std::endl;
    }

}
