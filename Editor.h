#include <string>
#include <fstream>
#include <vector>
#include "Document.cpp"
#include <iostream>
enum class command {PRINT, PRINT_NUM_TAB_LINE, PRINT_ALL_LINES, APPEND, NEW_LINE_BEFORE,
 CHANGE_LINE, DELETE_CURR_LINE, SEARCH, SEARCH_AND_REPLACE, QUIT, END_BLOCK, NOT_FOUND};
class Editor {
    private:
    bool collecting;
    std::vector<std::string> newLine;
    std::string line;
    command currCommand;
    std::vector<std::string> buffer;
    std::vector<std::string> lineToSearch;
    Document doc;
    inline command commandToInt(std::string command);
    inline bool isNumber(std::string str);
    inline void collect();

    public:
    Editor();
    void loop();
};