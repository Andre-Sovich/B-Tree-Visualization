#include <string>
#include <iostream>
using std::cout;
using std::endl;
/// @brief Takes an encoded log stored in a b-tree and returns the log translated
/// @param l
/// @return String
std::string translateLog(std::string l){
    // define our return log
    std::string returnLog;
    for(char i : l){
        switch (i) {
            // commands
            case 'i':// i for inserting
                returnLog += " Inserting ";
                break;
            case 'd':// d for deleting
                returnLog += " Deleting ";
                break;
            case 'f':// f for finding
                returnLog += " Finding ";
                break;
            case 's':// s for splitting
                returnLog += " Splitting ";
                break;
            case 'm':// m for merging
                returnLog += " Merging ";
                break;
            case 'p':// p for passing
                returnLog += " Passing " ;
                break;
            // descriptors
            case 'l':// l for left
                returnLog += " to the left of ";
                break;
            case 'r':// r for right
                returnLog += " to the right of ";
                break;
            case 'b':// b for between
                returnLog += " between ";
                break;
            // others
            case '&':
                returnLog += " and ";
                break;
            case '.':// . to declare new command line
                returnLog += "\n";
                break;
            default: // should add all numbers
                returnLog += i;
                break;
        }
    }
    return returnLog;
}

int main() {
    std::string test = translateLog("i1.p1r4.i1b23&42.s.p1&42l23.");
    cout << test;
}