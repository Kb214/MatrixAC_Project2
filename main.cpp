#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

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
    // out << "\nLinsey r w/r np np r";
    // out << "\nJared w/r w/r r r np";
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
    std::map<std::string, std::map<std::string,std::string> >EmpolyeePerm;
    std::vector<std::string> files = {"File1", "File2", "File3", "File4", "File5"};
    // EmpolyeePerm["Alice"]["File1"] = "r/w";
    // EmpolyeePerm["Alice"]["File2"] = "r/w";
    // EmpolyeePerm["Alice"]["File3"] = "r";
    // EmpolyeePerm["Alice"]["File4"] = "r";
    // EmpolyeePerm["Alice"]["File5"] = "r";

    //how to input with reading??


    std::string line;


    in.open("MAC.txt");

    //to add into map 


    while(getline(in, line)){
        std::istringstream ss(line);
        std::string Subject; 
        std::vector<std::string>permissions;
        std::string per;

        if(!(ss >> Subject)){
            continue;
        }

        while(ss >> per){
            permissions.push_back(per);
        }

        if(permissions.size() != files.size()){
            continue;
        }

        for( auto i = 0; i< files.size(); ++i){
            EmpolyeePerm[Subject][files[i]] = permissions[i];
        }

    }

    in.close();

    std::cout << "\n\n";

    //to print out

    for (const auto& outer_pair : EmpolyeePerm){
        std::cout << outer_pair.first;
        for(const auto& inner_pair : outer_pair.second){
            std::cout << "\n";
            std::cout << " has permission " << inner_pair.second << " in " << inner_pair.first;
        }

        std::cout << "\n";
    }

    // std::unordered_map<std::string, std::unordered_map<std::string,std::string>>::iterator itr;
    // std::unordered_map<std::string,std::string>::iterator ptr;

    // for(itr = EmpolyeePerm.begin(); itr != EmpolyeePerm.end(); itr++){

    //     for(ptr = itr->second.begin(); ptr != itr->second.end(); ptr++){

    //         std::cout << itr->first << " permission in file " << ptr->first << " is " << ptr->second << "\n";

    //     }

    // }

    




    //



    return 0;
}