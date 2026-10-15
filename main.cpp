#include <iostream>
#include <algorithm>
#include <fstream>

int main(){

    std::ifstream in;
    in.open("MAC.txt");

    if(in.fail()){
        std::cout << "Fail to open\n";
        return 1;
    }

    std::string item;
    int count;
    char ch;

    while(in >> item){
        if(ch == '\n'){
            std::cout << "\n";
        }
        std::cout << item;
    }

    return 0;
}