//
//  main.cpp
//  the-great-site-generator
//
//  Created by Andrew Tassone on 2021-09-14.
//
#include "TGSGConfig.h"
#include "reading.h"

using namespace std;

int main(int argc, const char** argv) {
    Reading r;
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
                    r.readFile(filename, 1);
                    }
            else
            {
                r.readFolder(filename, 1);
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
                r.readFile(filename, 2);
                    }
            else
            {
                r.readFolder(filename, 2);
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