#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>

struct Permiss{

};

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


    std::string input; 
    std::unordered_map<std::string, std::unordered_map<std::string,std::string> >EmpolyeePerm;
    EmpolyeePerm["Alice"]["File1"] = "r/w";
    EmpolyeePerm["Alice"]["File2"] = "r/w";
    EmpolyeePerm["Alice"]["File3"] = "r";
    EmpolyeePerm["Alice"]["File4"] = "r";
    EmpolyeePerm["Alice"]["File5"] = "r";

    //how to input with reading??

    


    return 0;
}