#include "Document.h"
Document::Document(){
    currLine = 0;
    totalLines = 0;
}

void Document::append(std::vector<std::string> toAppend){
    for(auto str : toAppend){
        if(currLine < totalLines){
            auto it = buffer.begin() + currLine;
            buffer.insert(it, str);
            currLine++;
            totalLines++;
        }
        else{
            buffer.push_back(str);
            currLine++;
            totalLines++;
        }
    }
}

void Document::printCurrLine(){
    std::cout << buffer.at(currLine - 1) << "\n";
}

void Document::printNumTabLine(){
    std::cout << currLine << "    " << buffer.at(Document::currLine - 1) << "\n";
}

void Document::printAllLines(){
    for(auto str : buffer){
        std::cout << str;
        std::cout << "\n";
    }
}

bool Document::goTo(int lineNumber){
    if(lineNumber <= totalLines && lineNumber >= 0){
        currLine = lineNumber;
        printCurrLine();
        return true;
    }
    return false;
}

void Document::newLinesBefore(std::vector<std::string> toInserts){
    currLine--;
    append(toInserts);
}

void Document::changeLine(std::vector<std::string> toChange){
    deleteCurrLine();
    append(toChange);
}

void Document::deleteCurrLine(){
    buffer.erase(buffer.begin() + currLine - (1 ? currLine>0 : 0));
    currLine--;
    totalLines--;
}
void Document::search(std::string toSearch){
    toSearch = toSearch.substr(1, toSearch.size() - 1);
    int j = 0;
    std::vector<std::string> splitedToSearch = split(toSearch);
    for(int i=currLine-1;i != currLine-2;i=(i+1)%totalLines){
        std::vector<std::string> splitedBuffer = split(buffer.at(i));
        for (auto str : splitedBuffer){
            if(!str.compare(splitedToSearch.at(j))){
                if(j == splitedToSearch.size() - 1){
                    currLine = i + 1;
                    return;
                }
                j++;
            }
            else{j = 0;}
        }
    }
}

std::vector<std::string> Document::split(std::string line){
    int start = 0, len = 0, counter = 0;
    std::vector<std::string> ans;
    for(char c : line){
        if(c == ' '){
            ans.push_back(line.substr(start, len));
            counter += line.substr(start, len).size();
            start = len + 1;
            len = 0;
            counter++;
            continue;
        }
        len++;  
    }
    ans.push_back(line.substr(counter, line.size() - counter));
    return ans;
}

std::string Document::searchAndReplace(std::string line){
    std::string ans = "", curr = buffer.at(currLine - 1);
    line = line.substr(2, line.size() - 1);
    std::vector<std::string> oldNew = pharse(line);
    std::vector<std::string> currSpllited = split(curr);
    for(int i = 0 ; i < currSpllited.size() ; i++){
        if(!currSpllited.at(i).compare(oldNew.at(0))){
            currSpllited.at(i) = oldNew.at(1);
        }
    }
    for(auto str : currSpllited){
        ans += str + " ";
    }
    return ans;
}

std::vector<std::string> Document::pharse(std::string line){
    std::vector<std::string> ans;
    std::string tmp = "";
    for(int i = 0 ; i < line.size() ; i++){
        if(line.at(i) == '/'){
            ans.push_back(tmp);
            tmp = "";
            tmp = line.substr(i+1);
            tmp = tmp.substr(0, tmp.size()-1);
            ans.push_back(tmp);
            return ans;
        }
        tmp += line.at(i);
    }
}