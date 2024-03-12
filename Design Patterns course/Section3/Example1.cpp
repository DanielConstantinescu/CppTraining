/* LIFE WITHOUT BUILDERS*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
using namespace std;


int main()
{
    auto text = "hello";
    string output;
    output += "<p>"; // opening paragraph tag
    output += text;
    output += "</p>"; // closing paragraph tag
    cout << output << endl;

    string words[] = {"hello", "world"};
    ostringstream oss;
    oss << "<ul>"; // opening tag of an unordered list
    for(auto w : words)
        oss << " <li>" << w << "</li>";
    oss << "</ul>";
    cout << oss.str() << endl;

    return 0;
}