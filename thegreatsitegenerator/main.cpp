//
//  main.cpp
//  the-great-site-generator
//
//  Created by Andrew Tassone on 2021-09-14.
//

#include <iostream>
using namespace std;
int main(int argc, const char** argv) {
    using namespace std::literals;

    std::cout << "Welcome to The Great Site Generator. Type -h or --help to learn more\n";

    if (argv[0] == "-v"sv || argv[0] == "--version"sv) {
        std::cout << "The Great Site Generator";
    }
    if (argv[0] == "-h"sv || argv[0] == "--help"sv) {
        std::cout << "The Great Site Generator";
    }
    return 0;
}
