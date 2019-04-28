#include <iostream>

#include "Editor.cpp"

using namespace std;
int main(int argc, char *argv[]) {
    Editor ed = Editor();
    ed.loop();
    return 0;
}