#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

//add functions:  AddUser, OutputUserstxt, OutputUsersmap, AccessFiles, ChangeUserPerm
//  std::string& sub,  std::string& p1,  std::string& p2, std::string& p3, std::string& p4, std::string& p5

void AddUser(std::string& input){
    std::string perm1, perm2, perm3, perm4, perm5, sub;
    std::istringstream NS(input);


    if(NS >> sub >> perm1 >> perm2 >> perm3 >> perm4 >> perm5){
        std::ofstream out("MAC.txt",std::ios::app);
        if(!out){
            return;
        }

        out << '\n' << sub << ' ' << perm1 << ' ' << perm2 << ' ' << perm3 << ' ' << perm4 << ' ' << perm5;

       
    }


    
}



void OutputUsertxt(){
  
}



void OutputUsermap(){


}



void SaveUsermap(std::map<std::string, std::map<std::string,std::string> >EP){
   
}



void AccessFiles( ){
   

}



void ChangeUserPerm(){
    //figure out how to change user permission without over writting the entire file ALSO without adding it on 
    //Must change value in the map and in the text file
}

int main(){

    std::map<std::string, std::map<std::string,std::string> >EmpolyeePerm;
    std::vector<std::string> files = {"File1", "File2", "File3", "File4", "File5"};
    std::vector<std::string>permissions;
    // std::string perm1,perm2,perm3,perm4,perm5;
    // std::string Subject;
    std::string newUser;
   
   
    std::string choice = "y";
    int op;
    std::string user;




    std::cout << "Welcome to the Access Control Matrix! To get started, who are you?\n";
    std::cout << "User: "; 
    std::cin >> user; 

    if (user == "Admin"){

        while(op != 5){

            std::cout << "1. Add User andPermissions\n2. Read Users and Permissions\n3. Update User Permission\n4. Authorize Access of User\n5. Exit\n\n";
            std::cout << "OPTION:";
            std::cin >> op; 

            if(op == 1){
                std::cin.ignore();
                std::cout << "\nEnter New User: ";
                std::getline(std::cin, newUser);
                std::ofstream outp;
                
                std::cout << "\n";
                AddUser(newUser);

            }else if(op == 2){

               
            }else if(op == 3){
                //update user permission
            }else if(op == 4){
                
               
            }else{

                std::cout << "    ===== EXITING... ====    \n";
                continue;
            }



        }

        std::cout << "Hello Admin! Here are your options: \n";
        std::cout << "1. Add User and Permissions\n2. Read Users and Permissions\n3. Update User Permission\n4.exit\n\n";


    }else{

        std::cout << "ACCESS DENIED: You are not allowed to access this Matrix system!!";

    }


    return 0;
}