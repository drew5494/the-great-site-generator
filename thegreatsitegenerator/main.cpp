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
#include "TGSGConfig.h"

using namespace std;
bool hasLang;
const char* lang;
void readFile(string fname);
void readMarkdownFile(string fname);

int main(int argc, const char** argv) {
    if (argv[1] == "-h"sv || argv[1] == "--help"sv){
        cout << "Please type -i followed by the name of the the text file or folder.\n";
        cout << "Please type -m followed by the name of the the markdown file or folder.\n";
    }
    else if (argv[1] == "-v"sv || argv[1] == "--version"sv){
        cout << "Version " << TGSG_VERSION_MAJOR << "." << TGSG_VERSION_MINOR << endl;
    }
    else if (argv[1] == "-i"sv || argv[1] == "--input"sv){
        if (filesystem::exists(argv[2])){
            if (argv[3]){
            if (argv[3] == "-l"sv || argv[3] == "--lang"sv){
                if (argv[4] && (argv[4] == "en-ca"sv || argv[4] == "pt-br"sv || argv[4] == "fr"sv)){
                    lang = argv[4];
                    hasLang = true;
                } else {
                    cerr << "Please enter a valid language. Type -h for more details.\n"; 
                    return 1;
                }
            } else {
                cerr << "Please enter a valid argument. Type -h for more details.\n"; 
                return 1;
            }
            }
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
            cerr << "File or folder does not exist. Type -h for more details.\n"; //Identify user
            return 1;
        }
    }
    else if (argv[1] == "-m"sv || argv[1] == "--markdown"sv){
        if (argv[2]){
            string filename = argv[2];
            size_t lastindex = filename.find_last_of(".");
            //Create new directory
            if (mkdir("dist", 0777) == -1)
                cerr << "Error: " << strerror(errno) << endl;
            else
                cout << "Directory created...\n";
            //Convert text file
            if (lastindex != string::npos) {
                cout << "Converting: " << filename << endl;
                readMarkdownFile(filename);
            } else {
                //Convert folder
                for (const auto& dir : std::__fs::filesystem::recursive_directory_iterator(filename)) {
                    string path = dir.path().string();
                    size_t markdown = path.find(".md");
                    
                    if (markdown != string::npos) {
                        cout << "Converting markdown: " << path << endl;
                        readMarkdownFile(path);
                    }
                }
            }
            cout << "\033[1mALL DONE!\033[0m\nYour GREAT html has been placed in the dist folder.\nHave a wonderful day :)\n";
        }
        else {
            cerr << "Please enter a valid file name. Type -h for more details.\n"; //Identify user
            return 1;
        }
    }
    else {
        cerr << "Type -h for more details.\n"; //Identify user
        return 1;
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
    htmlFile << "<!doctype html>" << '\n'<< "<html lang=";
    //Choose language       
    if (!hasLang){
        htmlFile  << "\"en-ca\">" << '\n';
    }
    else {
        htmlFile  << "\"" << lang << "\">" << '\n';
    }
    htmlFile << "<head>" << '\n' << "<meta charset=\"utf-8\">" << "\n" << "<title>" << rawname << "</title>" << '\n' << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" << '\n' << "</head>" << '\n' << "<body>" << '\n';
    // Write the body
    //Getting Title
    string line1, line2, line3;
    getline(file, line1);
    getline(file, line2);
    getline(file, line3);

    if (line1 != "" && line2 == "" && line3 == "")
    {
        string title = line1;
        htmlFile << "<h1>" << title << "</h1>" << '\n';
    }
    else
    {
        htmlFile << "<p>" << line1 << "</p>" << '\n';
        htmlFile << "<p>" << line2 << "</p>" << '\n';
        htmlFile << "<p>" << line3 << "</p>" << '\n';
    }
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

void readMarkdownFile(string fname) {
    std::ifstream file (fname.c_str());
    fname = fname.substr(fname.find_last_of("/\\") + 1);
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
        else if(line[0] == '#'){
            line.erase (0,2);
            htmlFile << "<h1>" << line << "</h1>" << '\n';
        }
        else
            htmlFile << "<p>" << line << "</p>" << '\n';
    }
    // End of body
    htmlFile << "</body>" << '\n' << "</html>" << '\n';
}