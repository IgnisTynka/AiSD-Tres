#include <iostream>
#include <sstream>
#include <ctime>

#include "functions.h"
#include "graph.h"

void menu(Graph* graph) {
    std::string option;

    while (true) {
        std::cout << "action> ";
        std::cin >> option;
        std::cout << option << std::endl;

        if (option == "help"){
            std::cout << "Commands:" << std::endl;
            std::cout << "help \t\t Show this message" << std::endl;
            std::cout << "print \t\t Print the graph" << std::endl;
            std::cout << "find \t\t Check if the edge exist in graph" << std::endl;
            std::cout << "bfs \t\t Breadth-first search" << std::endl;
            std::cout << "dfs \t\t Depth-first search" << std::endl;
            std::cout << "sort \t\t Sort the graph using Kahn and Tarjan algorithm" << std::endl;
            std::cout << "exit \t\t Exits the program (same as ctrl+C)" << std::endl;
        }

        else if (option == "print") {
            graph->print();
        }

        else if (option == "find") {
            int from, to;

            while (true) {
                std::cout << "from> ";
                std::cin >> from;
                std::cout << from << std::endl;

                if (from > 0) {
                    break;
                }
                
                std::cout << "Invalid node number (>0)" << std::endl;
            }

            while (true) {
                std::cout << "to> ";
                std::cin >> to; 
                std::cout << to << std::endl;

                if (to > 0) {
                    break;
                }
                
                std::cout << "Invalid node number (>0)" << std::endl;
            }
            if (graph->findEdge(from, to)) {
                std::cout << "Edge ("<<from <<", "<< to <<") exists" << std::endl;
            } else {
                std::cout << "Edge ("<<from <<", "<< to <<") does not exist" << std::endl;
            }
        }

        else if (option == "bfs") {
            std::vector<int> bfs = graph->bfs();
            std::cout << "BFS: ";
            for (int i = 0; i < bfs.size(); i++) {
                std::cout << bfs[i] << " ";
            }
            std::cout << std::endl;            
        }

        else if (option == "dfs") {
            std::vector<int> dfs = graph->dfs();
            std::cout << "DFS: ";
            for (int i = 0; i < dfs.size(); i++) {
                std::cout << dfs[i] << " ";
            }
            std::cout << std::endl;            
        }

        else if (option == "kahn_sort") {
            std::vector<int> kahn = graph->kahn();

            std::cout << "Kahn algorithm: ";
            if (kahn.size() == 0) {
                std::cout << "Graph has a cycle" << std::endl;
            }
            else {
                for (int i = 0; i < kahn.size(); i++) {
                    std::cout << kahn[i] << " ";
                }
                std::cout << std::endl;
            }
        }
        
        else if (option == "tarjan_sort") {
            std::vector<int> tarjan = graph->tarjan();

            std::cout << "Tarjan algorithm: ";
            if (tarjan.size() == 0) {
                std::cout << "Graph has a cycle" << std::endl;
            } else {
                for (int i = 0; i < tarjan.size(); i++) {
                    std::cout << tarjan[i] << " ";
                }
                std::cout << std::endl;
            }
        }

        else if (option == "exit") {
            std::cout << "Exiting..." << std::endl;
            return;
        }

        else {
            std::cout << "Invalid option. Type help for the command list" << std::endl;
        }
    }
}
