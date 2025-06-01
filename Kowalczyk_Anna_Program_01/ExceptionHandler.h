#pragma once
#include <iostream>
#include <stdexcept>

class ExceptionHandler {
public:
    static void handle(const std::exception& e) {
        std::cerr << "Wyst�pi� b��d: " << e.what() << std::endl;
    }
};
