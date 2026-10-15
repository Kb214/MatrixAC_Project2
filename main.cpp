#include <iostream>
#include <algorithm>
#include <fstream>

int main(){
    //reading
    std::ifstream in;
    in.open("MAC.txt");

    if(in.fail()){
        std::cout << "Fail to open\n";
        return 1;
    }

    std::string item;
    int count;
    char ch;

    while(in >>item ){
        std::cout << item << " ";

        if(in >> std::noskipws >> ch){
            if(ch == '\n'){
                std::cout << "\n";
            }
        }

    }
    in.close();
    
    //writing

    std::ofstream out;
    out.open("MAC.txt",std::ios::app);
    out << "\nLinsey r w/r np np r";
    out << "\nJared w/r w/r r r np";
    out.close();


    in.open("MAC.txt");
    std::cout << "\n\n" << "NEW OUTPUT:\n";

    while(in >> item){
        std::cout << item << " ";

        if(in >> std::noskipws >> ch){
            if(ch == '\n'){
            std::cout << "\n";
            }  
        }

        
    }

    in.close();

    return 0;
}