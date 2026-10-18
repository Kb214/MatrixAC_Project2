#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>


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
    std::string Subject; 
    std::vector<std::string>permissions;
    std::string per;
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

    




    //adding people to MAC.txt
    //read like we read the file lines with getline

    std::cout << "\nadd people to the text file.\n\n";
    std::cout << "New Employee (format Employee perm1 perm2 perm3 perm4 perm5): ";

    //read the input
    //save the input into the txt file
    //read the text file to save into map

    //format must be:  Subject perm1 perm2 perm3 perm4 perm5
    std::string newSubject;
    std::string perm1, perm2, perm3, perm4, perm5;


    std::getline(std::cin,newSubject);
    std::istringstream NS(newSubject);

    if(NS >> Subject >> perm1 >> perm2 >> perm3 >> perm4 >> perm5){
        out.open("MAC.txt",std::ios::app);

        out << "\n" << Subject << " " << perm1 << " " << perm2 << " " << perm3 << " " << perm4 << " " << perm5;

        out.close();
    }


    std::cout << "\n\n\n";
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


    in.open("MAC.txt");


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

    std::cout << "\n\n\n";


    for (const auto& outer_pair : EmpolyeePerm){
        std::cout << outer_pair.first;
        for(const auto& inner_pair : outer_pair.second){
            std::cout << "\n";
            std::cout << " has permission " << inner_pair.second << " in " << inner_pair.first;
        }

        std::cout << "\n";
    }


    //accessing files
    //Subject file# --> we do something based on the value
    //need to know how to access based on key inputs
    //use algorithms to look through and validate

    std::string SFL;
    std::string fileNumb;

    std::getline(std::cin, SFL);
    std::istringstream SubjectAccess(SFL);

    if(SubjectAccess >> Subject >> fileNumb){

        for (const auto& outer_pair : EmpolyeePerm){

            if(outer_pair.first == Subject){
                std::cout << outer_pair.first << " Found!\n";

                for(const auto& inner_pair : outer_pair.second){

                    if(inner_pair.first == fileNumb){
                        std::cout <<  inner_pair.first << " Found!\n";
                        
                        if(inner_pair.second == "r" || inner_pair.second == "r/w"){
                            std::cout << "\nEmployee " << outer_pair.first << " has permission " << inner_pair.second << "\n";
                            std::cout << "Opening " << inner_pair.first << " for " << inner_pair.second << "\n";  
                            if(inner_pair.second == "r"){
                                //use in
                                in.open(inner_pair.first);
                                //read contents of file
                                in.close();
        

                            }else if(inner_pair.second == "r/w"){
                                //use out
                                in.open(inner_pair.first);
                                //print contents of file to read
                                //give person option to write

                                in.close();
                            }
                        }else if(inner_pair.second == "np"){
                            std::cout << "\nEmployee " << outer_pair.first << "does not have persmission to access " << inner_pair.first << "\n";
                        }else{
                            std::cout << "\nCannot read employee permissions. Try again.\n";
                        }

                        
                    }
                    continue;
                }

            }
            continue;
        }


    }

    


    return 0;
}