//
//  main.cpp
//  the-great-site-generator
//
//  Created by Andrew Tassone on 2021-09-14.
//
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
int main(int argc, const char** argv) {
    cout << "Generating your GREAT html...\n"; //Identify user
        if (argv[1] == "-h"sv || argv[1] == "--help"sv){
            cout << "Please type -i followed by the name of the the TXT file.\n"; //Identify user
        }
        else if (argv[1] == "-v"sv || argv[1] == "--version"sv){
            cout << "version 0.1 of the GREAT html site generator.\n";
        }
        else if (argv[1] == "-i"sv || argv[1] == "--input"sv){
            if (argv[2]){
            string filename = argv[2];
            std::ifstream file (filename.c_str());
            if (file) {
                //Create new directory
                if (mkdir("dist", 0777) == -1)
                    cerr << "Error :  " << strerror(errno) << endl;
                else
                    cout << "Directory created...\n";
                // Create output file.
                std::ofstream htmlFile;
                htmlFile.open ("dist/new.html");
                // write the header
                htmlFile << "<html>" << '\n' << "<head>" << '\n' <<"<title>" << argv[2] << "</title>" << '\n' << "</head>" <<
                "<body>" << '\n';
                // Write the body
                // read a line
                std::string line{};
                while (std::getline(file, line)) {
                // Write line with <p> tag
                    htmlFile << "<p>" << line << "</p>" << '\n';
                }
                // End of body
                htmlFile << "</body>" << '\n' << "</html>" << '\n';
                cout << "All done!\nYour GREAT html has been placed in the dist folder.\nHave a wonderful day!\n";
            }
            } else {
                cout << "Pelase insert a valid file name.\n";
            }
        }
        else {
            cout << "Please use valid arguments. Type -h for more details.\n"; //Identify user
        }
    return 0;
}

