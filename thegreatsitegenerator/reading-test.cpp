#include "reading.h"
#include <gtest/gtest.h>
// Demonstrate some basic assertions.
using namespace std;
TEST(fileTest, BasicAssertions)
{
    std::string testerTextfile = "the-great-site-generator-sample.txt";
    Reading r;
    r.readFile(testerTextfile, 1);
    ifstream ifile;
    ifile.open("dist/the-great-site-generator-sample.html");
    if (ifile) {
        cout << "file exists";
        string line;
        for (int i = 0; i < 11; i++) {
            std::getline(ifile, line);
        }
        string first = "<p>The GREAT Site Generator is actually just another simple site generator that can generate static sites based off of text data.</p>";
        EXPECT_EQ(first, line);
    }
}
TEST(folderTest, BasicAssertions)
{
    std::string testerTextFolder = "sample";
    Reading r;
    r.readFolder(testerTextFolder, 1);
}
