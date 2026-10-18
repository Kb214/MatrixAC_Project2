#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

//add functions:  AddUser, OutputUserstxt, OutputUsersmap, AccessFiles, ChangeUserPerm

void AddUser( std::string& sub,  std::string& p1,  std::string& p2, std::string& p3, std::string& p4, std::string& p5){
    std::ofstream out("MAC.txt");
    out.open("MAC.txt",std::ios::app);
    std::string newSubject;
    // std::getline(std::cin,newSubject);
    std::istringstream NS(newSubject);

    if(!(NS >> sub >> p1 >> p2 >> p3 >> p4 >> p5)){
        out << "\n" << sub << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5;
    }

    out.close();

}



void OutputUsertxt(){
    std::ifstream in;
    in.open("MAC.txt");
    std::string item;
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


}



void OutputUsermap( const std::map<std::string, std::map<std::string,std::string>>& EP){

    for (const auto& outer_pair : EP){
        std::cout << outer_pair.first;
        for(const auto& inner_pair : outer_pair.second){
            std::cout << "\n";
            std::cout << " has permission " << inner_pair.second << " in " << inner_pair.first;
        }

        std::cout << "\n";
    }

}



void SaveUsermap(std::map<std::string, std::map<std::string,std::string>>& EP, std::vector<std::string>& f){
    std::string line;
    std::ifstream in("MAC.txt");

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

        if(permissions.size() != f.size()){
            continue;
        }

        for( auto i = 0; i< f.size(); ++i){
            EP[Subject][f[i]] = permissions[i];
        }

    }
    in.close();
}



void AccessFiles(std::map<std::string, std::map<std::string,std::string>>& EP, std::istringstream& SubjectAccess ){
    std::string fnumb;
    std::string sub;

    if(SubjectAccess >> sub >> fnumb){
        for (const auto& outer_pair : EP){
            if(outer_pair.first == sub){
                std::cout << outer_pair.first << "Found!\n";

                for(const auto& inner_pair : outer_pair.second){
                    if(inner_pair.first == fnumb){
                        std::cout << inner_pair.first << "Found!\n";

                        if(inner_pair.second == "r" || inner_pair.second == "r/w"){
                            std::cout << "\nEmployee " << outer_pair.first << " has permission " << inner_pair.second << "\n";
                            std::cout << "Opening " << inner_pair.first << " for " << inner_pair.second << "\n"; 
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


}



void ChangeUserPerm(){
    //figure out how to change user permission without over writting the entire file ALSO without adding it on 
    //Must change value in the map and in the text file
}

int main(){

    std::map<std::string, std::map<std::string,std::string> >EmpolyeePerm;
    std::vector<std::string> files = {"File1", "File2", "File3", "File4", "File5"};
    std::vector<std::string>permissions;
    std::string perm1,perm2,perm3,perm4,perm5;
    std::string Subject;
    std::string newUser;
    std::ifstream in("MAC.txt");
    std::ofstream out("MAC.txt");
    std::string choice = "y";
    int op;
    std::string user;




    std::cout << "Welcome to the Access Control Matrix! To get started, who are you?\n";
    std::cout << "User: "; 
    std::cin >> user; 

    if (user == "Admin"){
        std::cout << "Hello Admin! Here are your options: \n";
        std::cout << "1. Add User and Permissions\n2. Read Users and Permissions\n3. Update User Permission\n4.exit\n\n";

        while(op != 5){

            std::cout << "1. Add User and Permissions\n2. Read Users and Permissions\n3. Update User Permission\n4. Authorize Access of User\n5. Exit\n\n";

            std::cout << "OPTION:";
            std::cin >> op; 
            


            if(op == 1){
                std::cout << "Add New User: ";
                std::getline(std::cin, newUser);
                AddUser(Subject, perm1, perm2, perm3, perm4, perm5);
                SaveUsermap(EmpolyeePerm,files);

                std::cout << "Your Employees: \n\n";
                OutputUsermap(EmpolyeePerm);

            }else if(op == 2){

                std::cout << "\nYour Employees: \n";
                OutputUsertxt();
                std::cout << "\n\n";

            }else if(op == 3){
                //update user permission
            }else if(op == 4){
                
                std::string SFL;
                std::getline(std::cin, SFL);
                std::istringstream SubAc(SFL);
                AccessFiles(EmpolyeePerm,SubAc);

            }else{

                std::cout << "    ===== EXITING... ====    \n";
                continue;
            }



        }


    }else{

        std::cout << "ACCESS DENIED: You are not allowed to access this Matrix system!!";

    }


    return 0;
}