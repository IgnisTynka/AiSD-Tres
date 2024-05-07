#include <iostream>

#include "functions.h"

int main(int argc, const char* argv[]){

    std::string mode = std::string(argv[1]);
    Graph* graph;

    if (mode == "--generate") {
        graph = generate();
        graph->print();
    } else if (mode == "--user-provided") {  
        // graph = userBuild();
    } else {
        std::cout << "Invalid mode" << std::endl;
        return 1;
    }

    // menu(graph);

    return 0;
}
