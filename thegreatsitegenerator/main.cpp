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
        if (argv[1] == "-h"sv || argv[1] == "--help"sv){
            cout << "Please type -i followed by the name of the the TXT file.\n";
        }
        else if (argv[1] == "-v"sv || argv[1] == "--version"sv){
            cout << "version 0.1 of the GREAT html site generator.\n";
        }
        else if (argv[1] == "-i"sv || argv[1] == "--input"sv){
            if (argv[2]){
            cout << "Generating your GREAT html...\n"; //Identify user
            string filename = argv[2];
            std::ifstream file (filename.c_str());
            if (file) {
                //Create new directory
                if (mkdir("dist", 0777) == -1)
                    cerr << "Error :  " << strerror(errno) << endl;
                else
                    cout << "Directory created...\n";
                //Remove file extension
                size_t lastindex = filename.find_last_of(".");
                string rawname = filename.substr(0, lastindex);
                // Create output file.
                std::ofstream htmlFile;
                htmlFile.open ("dist/"+rawname+".html");
                // write the header
                htmlFile << "<!doctype html>" << '\n' << "<html lang=\"en\">" << '\n' << "<head>" << '\n' << "<meta charset=\"utf-8\">" << "\n" << "<title>" << rawname << "</title>" << '\n' << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" << '\n' << "</head>" << '\n' << "<body>" << '\n';
                // Write the body
                // read a line
                std::string line{};
                while (std::getline(file, line)) {
                // Write line with <p> tag
                if(!line.size())
                    htmlFile << '\n';
                else
                    htmlFile << "<p>" << line << "</p>" << '\n';
                }
                // End of body
                htmlFile << "</body>" << '\n' << "</html>" << '\n';
                cout << "\033[1mALL DONE!\033[0m\nYour GREAT html has been placed in the dist folder.\nHave a wonderful day!\n";
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
