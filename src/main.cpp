#include <iostream>

#include "../include/tableGraph.h"
#include "../include/matrixGraph.h"
#include "../include/listGraph.h"

int main(int argc, const char* argv[]){

    std::string mode = std::string(argv[1]);

    if (mode == "--generate") {
        
    } else if (mode == "--user-provided") {

    } else {
        std::cout << "Invalid mode" << std::endl;
        return 1;
    }
}