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
#include <filesystem>
using namespace std;
void readFile(string fname);
int main(int argc, const char** argv) {
    if (argv[1] == "-h"sv || argv[1] == "--help"sv){
        cout << "Please type -i followed by the name of the the text file or folder.\n";
    }
    else if (argv[1] == "-v"sv || argv[1] == "--version"sv){
        cout << "version 0.1 of the GREAT html site generator.\n";
    }
    else if (argv[1] == "-i"sv || argv[1] == "--input"sv){
        if (argv[2]){
            string filename = argv[2];
            size_t lastindex = filename.find_last_of(".");
            //Create new directory
            filesystem::create_directory("dist");
            //Convert text file
            if (lastindex != string::npos) {
                cout << "Converting: " << filename << endl;
                readFile(filename);
            } else {
                //Convert folder
                for (const auto& dir : std::__fs::filesystem::recursive_directory_iterator(filename)) {
                    string path = dir.path().string();
                    size_t text = path.find(".txt");
                    if (text != string::npos) {
                        cout << "Converting: " << path << endl;
                        readFile(path);
                    }
                }
            }
            cout << "\033[1mALL DONE!\033[0m\nYour GREAT html has been placed in the dist folder.\nHave a wonderful day :)\n";
        }
        else {
            cout << "Please enter a valid file name. Type -h for more details.\n"; //Identify user
        }
    }
    else {
        cout << "Type -h for more details.\n"; //Identify user
    }
    return 0;
}
void readFile(string fname) {
    std::ifstream file (fname.c_str());
    filesystem::path dir (fname);
    fname = dir.filename();
    size_t lastindex = fname.find_last_of(".");
    string rawname = fname.substr(0, lastindex);
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
}
