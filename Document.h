#include <string>
#include <fstream>
#include <algorithm> 
#include <iostream>
class Document {

    private:
    std::vector<std::string> buffer;
    int currLine;
    public:
    inline Document();
    int totalLines;
    inline std::vector<std::string> split(std::string line);
    inline void append(std::vector<std::string> toAppend);
    inline void save();
    inline void printCurrLine();
    inline void printNumTabLine();
    inline void printAllLines();
    inline bool goTo(int lineNumber);
    inline void newLinesBefore(std::vector<std::string> toInserts);
    inline void changeLine(std::vector<std::string> toChange);
    inline void deleteCurrLine();
    inline void search(std::string toSearch);
    inline std::string searchAndReplace(std::string line);
    inline std::vector<std::string> pharse(std::string line);
};

