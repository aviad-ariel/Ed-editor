#include "Editor.h"
#include <iostream>
Editor::Editor(){
    doc = Document();
    collecting = false;
}

void Editor::loop(){
    while (true){
        getline(std::cin, line);
        if(!line.compare(" ") || !line.compare("")){
            continue;
        }
        if(isNumber(line)){
            if(!doc.goTo(stoi(line))){
                std::cout << line << stoi(line)<<"\n" << "Line Not Found\n";
            }
            continue;
        }
        //currCommand = commandToInt(line);
        switch(commandToInt(line)){
            case command::NOT_FOUND:
                std::cout << line << " Its Not a Command";
                continue;

            case command::PRINT:
                doc.printCurrLine();
                break;

            case command::PRINT_NUM_TAB_LINE:
                doc.printNumTabLine();
                break;
            
            case command::PRINT_ALL_LINES:
                doc.printAllLines();
                break;

            case command::APPEND:
                collect();
                doc.append(buffer);
                buffer.clear();             
                break;

            case command::END_BLOCK:
                continue;

            case command::NEW_LINE_BEFORE:
                collect();  
                doc.newLinesBefore(buffer);
                buffer.clear();
                break;

            case command::CHANGE_LINE:
                collect(); 
                doc.changeLine(buffer);
                buffer.clear(); 
                break;
            
            case command::DELETE_CURR_LINE:
                doc.deleteCurrLine();
                break;
            case command::SEARCH:
                doc.search(line);
                doc.printCurrLine();
                break;
            case command::SEARCH_AND_REPLACE:
                newLine.push_back(doc.searchAndReplace(line));
                doc.changeLine(newLine);
                newLine.clear();
                break;

            case command::QUIT:
                return;
            };
        }
    }


command Editor::commandToInt(std::string cmd){
    if(!cmd.compare("p")){return command::PRINT;}
    if(!cmd.compare("n")){return command::PRINT_NUM_TAB_LINE;}
    if(!cmd.compare("%p")){return command::PRINT_ALL_LINES;}
    if(!cmd.compare("a")){return command::APPEND;}
    if(!cmd.compare("i")){return command::NEW_LINE_BEFORE;}
    if(!cmd.compare("c")){return command::CHANGE_LINE;}
    if(!cmd.compare("d")){return command::DELETE_CURR_LINE;}
    if((cmd.size() >= 2) && cmd[0] == 's' && cmd[1] == '/'){return command::SEARCH_AND_REPLACE;}
    if(cmd[0] == '/'){return command::SEARCH;}
    if(!cmd.compare("Q")){return command::QUIT;}
    if(!cmd.compare(".")){return command::END_BLOCK;}
    return command::NOT_FOUND;
}

bool Editor::isNumber(std::string str){
    for(char c : str) {
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}

void Editor::collect(){
    std::string line;
    while(true){
        getline(std::cin, line);
        if(!line.compare(".")){
            return;
        }
        buffer.push_back(line);
    }
    
}

