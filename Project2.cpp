#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <limits>

//add functions:  AddUser, OutputUserstxt, OutputUsersmap, AccessFiles, ChangeUserPerm
//  std::string& sub,  std::string& p1,  std::string& p2, std::string& p3, std::string& p4, std::string& p5

void AddUser(const std::string& input){
    std::string perm1, perm2, perm3, perm4, perm5, sub;
    std::istringstream NS(input);

    if(!(NS >> sub >> perm1 >> perm2 >> perm3 >> perm4 >> perm5) || (NS >> std::ws && !NS.eof())){
        std::cout << "\nWrong Format, Try Again!!\n\n";
        return;
    }

    std::ofstream out("MAC.txt", std::ios::app);

    if(!out){
        std::cout << "Could not save new user to MAC.txt\n";
        return;
    }

    out << '\n' << sub << ' ' << perm1 << ' ' << perm2 << ' ' << perm3 << ' ' << perm4 << ' ' << perm5;
    if(!out){
        std::cout << "Could not finish saving new user to MAC.txt\n";
    }
}




void OutputUsermap(std::map<std::string, std::map<std::string,std::string>>& EP){
    for (const auto& outer_pair : EP){
        std::cout << outer_pair.first;
        for(const auto& inner_pair : outer_pair.second){
            std::cout << "\n";
            std::cout << " has permission " << inner_pair.second << " in " << inner_pair.first;
        }

        std::cout << "\n\n";
    }

}



void SaveUsermap(std::map<std::string, std::map<std::string,std::string>>& EP, const std::vector<std::string>& f){
    std::string line;
    std::ifstream in("MAC.txt");

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
   
}



void AccessFiles(std::map<std::string, std::map<std::string,std::string>>& EP, const std::string& Subfilelook){
   
    std::string fileNumb;
    std::string Subject;
    

    
    std::istringstream SubjectAccess(Subfilelook);
    if(!(SubjectAccess >> Subject >> fileNumb)){

        std::cout << "\nWrong Format! Try Again!!\n";
        return;

    } 

   
        
    for (const auto& outer_pair : EP){


        if(outer_pair.first != Subject){
            std::cout << "\nEmployee Not Found!\n";
            break;
        }

        std::cout << outer_pair.first << " Found!\n";



        for(const auto& inner_pair : outer_pair.second){
            
            if(inner_pair.first != fileNumb){
                std::cout << "\nFile not found!!\n";
                break;
            }

            std::cout <<  inner_pair.first << " Found!\n";

            if(inner_pair.second == "r" || inner_pair.second == "r/w"){
                std::cout << "\nEmployee " << outer_pair.first << " has permission " << inner_pair.second << "\n";
                std::cout << "Opening " << inner_pair.first << " for " << inner_pair.second << "\n";  

                    
                std::ifstream file;
                std::string fullFile = inner_pair.first + ".txt";
                file.open(fullFile);
                std::string item;
                    

                while(file >> item){
                    std::cout << item << " ";
                    char ch; 
                    if(file >> std::noskipws >> ch){
                        if(ch == '\n'){
                            std::cout << "\n";
                        }
                    }
                }

                std::cout << "\n";
                file.close();
            
                        
                    
            }else if(inner_pair.second == "np"){

                std::cout << "\nEmployee " << outer_pair.first << "does not have persmission to access " << inner_pair.first << "\n";

            }else{

                std::cout << "\nCannot read employee permissions. Try again.\n";
                
            }


    

        }


      
        break;
    }



}



void ChangeUserPerm(std::map<std::string, std::map<std::string,std::string>>& EP, const std::vector<std::string>& f, const std::string& input){
    std::istringstream ss(input);
    std::string employee;
    std::string fileName;
    std::string newPermission;

    if(!(ss >> employee >> fileName >> newPermission)){
        std::cout << "\nWrong format, try again!\n";
        return;
    }

    auto employeeIT = EP.find(employee);
    auto fileIT = std::find(f.begin(), f.end(), fileName);


    if(employeeIT == EP.end()){
        std::cout << "\nEmployee Not Found\n";
        return;
    }
    if(fileIT == f.end()){
        std::cout << "\nFile Not Found\n";
        return;
    }
    if(!(newPermission == "r" || newPermission == "r/w" || newPermission == "np")){
        std::cout << "\nInvalid permission!!\n";
        return;
    }

    for(const auto& outer_pair : EP){
        for(const auto& file : f){
            if(outer_pair.second.find(file) == outer_pair.second.end()){
                std::cout << "Could not save permissions: missing!!" << file
                          << " for " << outer_pair.first << '\n';
                return;
            }
        }
    }

    std::ofstream out("MAC.txt");

    if(!out){
        std::cout << "\nCould not save permissions to MAC.txt\n";
        return;
    }

    employeeIT->second[fileName] = newPermission;

    for (const auto& outer_pair : EP){
        out << outer_pair.first;
        for(const auto& file : f){
            auto permission = outer_pair.second.find(file);
            out << ' ' << permission->second;
        }
        out << "\n";
    }
    if(!out){
        std::cout << "\nCould not finish saving permissions to MAC.txt\n";
    }


}



int main(){

    std::map<std::string, std::map<std::string,std::string> >EmpolyeePerm;
    std::vector<std::string> files = {"File1", "File2", "File3", "File4", "File5"};
    std::vector<std::string>permissions;
    std::string newUser;
    std::string SFL;
    std::string user;
    std::string newPerm; 
    int op;
    SaveUsermap(EmpolyeePerm, files);
   
   
   


    std::cout << "Welcome to the Access Control Matrix! To get started, who are you?\n";
    std::cout << "User: "; 
    std::cin >> user; 

    if (user == "Admin"){

        while(true){

            std::cout << "1. Add User and Permissions\n2. Read Users and Permissions\n3. Update User Permission\n4. Authorize Access of User\n5. Exit\n\n";
            std::cout << "OPTION:";

        

            if(!(std::cin >> op)){

                if(std::cin.eof()){
                    break;
                }
                
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Not Available Choose numbers from 1 to 5\n\n";
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if(op < 1 || op > 5){
                std::cout << "Not Available Choose numbers from 1 to 5\n\n";
                continue;
            }else if(op == 1){
                std::cout << "\nEnter New User: ";
                std::getline(std::cin, newUser);
            
                std::cout << "\n";
                AddUser(newUser);

                SaveUsermap(EmpolyeePerm, files);

            }else if(op == 2){
                std::cout << "\n\n Your Employees (Employee Perm1 Perm2 Perm3 Perm4 Perm5): \n\n";
                OutputUsermap(EmpolyeePerm);
               
            }else if(op == 3){
                //update user permission
                std::cout << "Update User Permission (Format: Employee    File Name    New Permission): ";
                std::getline(std::cin,newPerm);

                ChangeUserPerm(EmpolyeePerm,files,newPerm);
                std::cout << "\n";
            
        
            }else if(op == 4){
                
                std::cout << "Employee and Their File Permission You Want to Authorize (Name FileName): ";
                std::getline(std::cin, SFL);
    
                AccessFiles(EmpolyeePerm, SFL);
                std::cout << "\n";

            } else {
                std::cout << "    ===== EXITING... ====    \n";
                break; 
            }
        }

       
    }else{

        std::cout << "ACCESS DENIED: You are not allowed to access this Matrix system!!\n\n";

    }


    return 0;
}