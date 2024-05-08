#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <cstdlib> 

#include "functions.h"
#include "tableGraph.h"
#include "matrixGraph.h"
#include "listGraph.h"

Graph* userBuild() {
    std::string type;
    int nodes;
    std::vector<std::set<int>> list;

    while (true) {
        std::cout << "nodes> ";
        std::string nodesStr;
        std::getline(std::cin, nodesStr);

        // Convert the string to an integer
        nodes = std::atoi(nodesStr.c_str());
        std::cout << nodes << std::endl;
        
        if (nodes > 0)  {
            break;
        }
        std::cout << "Invalid number of nodes (>0)" << std::endl;
    }

    std::string sequence;
    for (int i = 0; i < nodes; i++) {
        std::cout << i+1 <<"> ";
        std::getline(std::cin, sequence);
        std::istringstream iss(sequence);

        std::set<int> numbers;
        int num;
        while (iss >> num) {
            if (num <= 0 || num > nodes) {
                std::cout << "Invalid node number " << num << " Skipped" << std::endl;
                continue;
            }
            numbers.insert(num);
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
