#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;
bool hasLang;
const char* lang;

class Reading {
public:
    void readFile(string fname, int type);
    void readFolder(string filename, int type);
};
void Reading::readFile(string fname, int type)
{
    std::ifstream file(fname.c_str());
    filesystem::path dir(fname);
    fname = dir.filename();
    size_t lastindex = fname.find_last_of(".");
    string rawname = fname.substr(0, lastindex);
    // Create output file.
    std::ofstream htmlFile;
    htmlFile.open("dist/" + rawname + ".html");
    // write the header
    htmlFile << "<!doctype html>" << '\n'
             << "<html lang=";
    // Choose language
    if (!hasLang) {
        htmlFile << "\"en-ca\">" << '\n';
    } else {
        htmlFile << "\"" << lang << "\">" << '\n';
    }
    htmlFile << "<head>" << '\n'
             << "<meta charset=\"utf-8\">"
             << "\n"
             << "<title>" << rawname << "</title>" << '\n'
             << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" << '\n'
             << "</head>" << '\n'
             << "<body>" << '\n';
    // Write the body
    // Getting Title
    string line1, line2, line3;
    getline(file, line1);
    getline(file, line2);
    getline(file, line3);

    if (line1 != "" && line2 == "" && line3 == "") {
        string title = line1;
        htmlFile << "<h1>" << title << "</h1>" << '\n';
    } else {
        htmlFile << "<p>" << line1 << "</p>" << '\n';
        htmlFile << "<p>" << line2 << "</p>" << '\n';
        htmlFile << "<p>" << line3 << "</p>" << '\n';
    }
    // read a line
    std::string line {};
    if (type == 1) {
        while (std::getline(file, line)) {
            // Write line with <p> tag
            if (!line.size())
                htmlFile << '\n';
            else
                htmlFile << "<p>" << line << "</p>" << '\n';
        }
    } else if (type == 2) {
        while (std::getline(file, line)) {
            // Write line with <p> tag
            if (!line.size())
                htmlFile << '\n';
            else if (line[0] == '#') {
                line.erase(0, 2);
                htmlFile << "<h1>" << line << "</h1>" << '\n';
            } else
                htmlFile << "<p>" << line << "</p>" << '\n';
        }
    }
    // End of body
    htmlFile << "</body>" << '\n'
             << "</html>" << '\n';
}

// End of body
void Reading::readFolder(string filename, int type)
{
    // Convert folder
    for (const auto& dir : std::filesystem::recursive_directory_iterator(filename)) {
        string path = dir.path().string();
        size_t extension;
        if (type == 1)
            extension = path.find(".txt");
        else if (type == 2)
            extension = path.find(".md");
        if (extension != string::npos) {
            cout << "Converting: " << path << endl;
            if (type == 1)
                Reading::readFile(path, 1);
            if (type == 2)
                Reading::readFile(path, 2);
        }
    }
}
