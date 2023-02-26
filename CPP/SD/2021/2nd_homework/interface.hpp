#pragma once
#include <iostream>
#include <fstream>

#include <string>
#include <forward_list>
#include <list>
#include <queue>
#include <exception>
#include <stack>
using std::string;

struct Menu {
    std::vector<std::string> menu;
    std::string command;
    Menu() {
        menu.push_back("Help");//0
        menu.push_back("Load");//1
        menu.push_back("Save");//2
        menu.push_back("Find");//3
        menu.push_back("Num Subordinates");//4
        menu.push_back("Manager");//5
        menu.push_back("Num Employees");//6
        menu.push_back("Overloaded");//7
        menu.push_back("Join");//8
        menu.push_back("Fire");//9
        menu.push_back("Hire");//10
        menu.push_back("Salary");//11
        menu.push_back("Longest chain");//12
        menu.push_back("Incorporate");//13
        menu.push_back("Modernize");//14
        menu.push_back("Print");//15
        menu.push_back("Exit");//16
    }
};
struct node {
    std::string data;
    std::vector<node*> subordinates;// the count of  subordiantes
    node* boss;
    node(const std::string& data_):data(data_){}
    node(const std::string& data_, std::vector<node*> subordinates_, node* boss_ = nullptr) : data(data_),subordinates(subordinates_), boss(boss_){}
};

class Hierarchy_tree{
    
    private:
        
        node* root;
        size_t size;

        node* copy(node* root) {
            return root ? new node(root->data, root->subordinates,root->boss) : root;
        }

        void clear(node* root) {
            if(root) { 
                std::queue<node*> func_helper;
                func_helper.push(root);
                while(!func_helper.empty()) {
                    node* current = func_helper.front();
                    func_helper.pop();
                    for (size_t i = 0; i < current->subordinates.size(); i++)
                    {
                        func_helper.push(current->subordinates[i]);
                    }
                    delete[] current;
                }
            }
        }
        std::vector<std::string> validate_string(const std::string &data, char key) {
            std::vector<std::string> toReturn;
            std::string temp;
            for(size_t i = 0; i < data.size(); i++) {
                if (data[i] == key) {
                    toReturn.push_back(temp);
                    temp.clear();
                } else {
                    temp.push_back(data[i]);
                }
            }
            if (!temp.empty()) {
                toReturn.push_back(temp);
            }
            return toReturn;
        }
    public:
        Hierarchy_tree() : root(nullptr), size(0){}
        Hierarchy_tree(const std::string &data_) {
            if(data_ == "") {
                root = nullptr;
                size = 0;
            } else {
                root = nullptr;
                std::vector<std::string>checkForNewRow = validate_string(data_, '\n');
                for (size_t i = 0; i < checkForNewRow.size(); i++)
                {
                    std::vector<std::string> checkForSpace = validate_string(checkForNewRow[i], '-');
                   
                    if(checkForSpace.size() == 2) {
                        insert(checkForSpace[1], checkForSpace[0]);
                    }
                }
            }
        }
        // "Uspeshnia Gosho
        // Uspeshnia Misho
        // Uspeshnia-Slavi
        // Gosho-Dancho
        // Gosho-PeshonSlavi-Slav1
        // Slavi-Slav2
        // Dancho-Boris
        // Dancho-Kamen
        // Pesho-Alex
        // Slav1-Mecho
        // Mecho-Q12Adl"

        Hierarchy_tree(node* initial_node){
            std::swap(root, initial_node);
        }
        ~Hierarchy_tree() {
            clear(root);
        }
        Hierarchy_tree(const Hierarchy_tree& newTree) : root(copy(newTree.root)), size(newTree.size){}
        Hierarchy_tree(Hierarchy_tree&& newTree){ 
            std::swap(root, newTree.root);
            std::swap(size, newTree.size);
        }
        Hierarchy_tree& operator=(const Hierarchy_tree& newTree){
            if(this != &newTree) {
                clear(root);
                root = copy(newTree.root);
                size = newTree.size;
            }
            return *this;
        }
        bool find(const std::string& name) const { 
            if(!root){return false;}
            else {
                 std::queue<node*> func_helper;
                    func_helper.push(root);
                    while (!func_helper.empty())
                    {
                        if(name == func_helper.front()->data) {
                            return true;
                        }
                        node* current = func_helper.front();
                        func_helper.pop();
                        for (size_t i = 0; i < current->subordinates.size(); i++)
                        {
                            func_helper.push(current->subordinates[i]);
                        }
                    }
                    return false;
            }
            //iterate trough the  employees of the root 
            //if you find a node, whose data is name -> return true
            //if not return false;
                 
        }
        node* findNode(const std::string& name) const {
    
            std::queue<node*> func_helper;
            func_helper.push(root);
            while (!func_helper.empty())
            {
                node* current = func_helper.front();
                if(name == current->data) {
                    node* current_copy = current;
                    return current_copy;
                }
                func_helper.pop();
                for (size_t i = 0; i < current->subordinates.size(); i++)
                {
                    func_helper.push(current->subordinates[i]);
                }
            }
        }

        int num_direct_employees(const std::string name){
            if(root){
                if(!findNode(name)->subordinates.empty()){
                    return findNode(name)->subordinates.size();
                } else {return 0;}
            } else {return 0;}
        }

        int num_indirect_employees(const std::string name) {
            if(root){
                if(!findNode(name)->subordinates.empty()){
                    int indirect_subs = 0;
                    std::queue<node*> func_helper;
                    func_helper.push(findNode(name));
                    while (!func_helper.empty())
                    {
                        node* current = func_helper.front();
                        func_helper.pop();
                        for (size_t i = 0; i < current->subordinates.size(); i++)
                        {
                            func_helper.push(current->subordinates[i]);
                            indirect_subs++;
                        }
                        
                    }
                    indirect_subs -= num_direct_employees(name);
                    return indirect_subs;
                } else {return 0;}
            } else {return 0;}
        }
        
        bool insert( std::string name_subordinate, std::string boss) { 
            if(root == nullptr && boss == "Uspeshnia") {
                root = new node(boss);
            }
            std::vector<node*> subs;

            node* toInsert = new node(name_subordinate, subs);
            std::queue<node*> func_helper;
            func_helper.push(root);
            while(!func_helper.empty()) {
                node* current = func_helper.front();
                if(current->data == boss) {
                    current->subordinates.push_back(toInsert);
                    toInsert->boss = current;
                }
                func_helper.pop();
                for (size_t i = 0; i < current->subordinates.size(); i++)
                {
                    func_helper.push(current->subordinates[i]);
                }
            }

            if(findNode(boss)->subordinates.back() == toInsert) {
                return true;
            } else {
                return false;
            }
        }
        
        bool remove(const std::string name) {
           
            if(!root){return false;}
            else {
                if(find(name) == false) {return false;}
                //find the node we want to remove
                node* toDelete = findNode(name);
                if(!toDelete->subordinates.empty()) {
                    for (size_t i = 0; i < toDelete->subordinates.size(); i++) {
                        toDelete->boss->subordinates.push_back(toDelete->subordinates[i]);
                    }
                }
                for (size_t i = 0; i < toDelete->boss->subordinates.size(); i++)
                {
                    if(toDelete->data == toDelete->boss->subordinates[i]->data) {
                        toDelete->boss->subordinates.erase(toDelete->boss->subordinates.begin() + i);
                        break;
                    }
                }
                
                //link all of his subordinates to his boss as  subbs
                delete toDelete;
                return true;
                
                //if that is successful return  true
            }
        }
        size_t getHeight() const {
            if(!root) return 0;
            std::queue<std::pair<node*, int>> height_helper;
            int height = 0;
            height_helper.push({root,0});
            while (!height_helper.empty())
            {
                std::pair<node*, int> current = height_helper.front();
                height = std::max(height, current.second);
                height_helper.pop();
                for (size_t i = 0; i < current.first->subordinates.size(); i++)
                {
                    height_helper.push({current.first->subordinates[i], current.second+1});
                }
                
            }
            
            return height;
        }
        node* getRoot() const {
            return this->root;
        }
        size_t getsize() const {
            return this->size;
        }
        std::string print() {
            if(root == nullptr) {
                throw std::runtime_error("There is no created hierarchy!");
            } else {
                std::string toReturn;
                if(root->subordinates.empty()) {
                    toReturn += root->data;
                } else {
                        std::queue<node*> print_helper;
                        print_helper.push(root);
                        while (!print_helper.empty())
                        {
                            node* current = print_helper.front();
                            print_helper.pop();
                            for (size_t i = 0; i < current->subordinates.size(); i++)
                            {
                                print_helper.push(current->subordinates[i]);
                                std::string helper{current->data+ "-" + current->subordinates[i]->data  + "\n"};
                                toReturn += helper;
                            }
                        }
       }
       
       return toReturn;
   }
        }
};

class Hierarchy {
public:
    Hierarchy(Hierarchy&& r) noexcept;
    Hierarchy(const Hierarchy& r);
    Hierarchy(const std::string& data);
    ~Hierarchy() noexcept;
    void operator=(const Hierarchy&) = delete;

    std::string print()const;

    int longest_chain() const;
    bool find(const std::string& name) const;
    int num_employees() const;
    int num_overloaded(int level = 20) const;

    std::string manager(const std::string& name) const;
    int num_subordinates(const std::string& name) const;
    unsigned long getSalary(const std::string& who) const;

    bool fire(const std::string& who);
    bool hire(const std::string& who, const std::string& boss);

    void incorporate();
    void modernize();

    Hierarchy join(const Hierarchy& right) const;

    
    //If you need it - add more public methods here
    void saveToFile();
    void loadFromFile();
    void start();
private:
    //Add whatever you need here
    Hierarchy_tree* hierarchy;
    Menu command_menu;
    std::string filename;
};

Hierarchy::Hierarchy(const std::string& data) {
    Hierarchy_tree* newTree = new Hierarchy_tree(data);
    this->hierarchy = newTree;
}

Hierarchy::Hierarchy(const Hierarchy& r) {
    hierarchy = new Hierarchy_tree(*r.hierarchy);
}

Hierarchy::Hierarchy(Hierarchy&& r) noexcept {
    std::swap(hierarchy, r.hierarchy);
}
Hierarchy::~Hierarchy() noexcept {
    hierarchy->~Hierarchy_tree();
}

//void Hierarchy::operator=(const Hierarchy&) = delete

std::string Hierarchy::print() const {
   if(!hierarchy) {
       throw std::runtime_error("There is no created hierarchy!");
   } else {
       std::string toReturn;
       if(hierarchy->getRoot()->subordinates.empty()) {
           toReturn += hierarchy->getRoot()->data;
       } else {
            std::queue<node*> print_helper;
            print_helper.push(hierarchy->getRoot());
            while (!print_helper.empty())
            {
                node* current = print_helper.front();
                print_helper.pop();
                for (size_t i = 0; i < current->subordinates.size(); i++)
                {
                    print_helper.push(current->subordinates[i]);
                    std::string helper{current->data + "-" + current->subordinates[i]->data + "\n"};
                    toReturn += helper;
                }
            }
       }
       
       return toReturn;
   }
}
int Hierarchy::longest_chain() const{
    return hierarchy->getHeight() + 1;
}
bool Hierarchy::find(const std::string& name) const {
    if(hierarchy) {
        return hierarchy->find(name);
    } else {
        throw std::runtime_error("The hierarchy is empty, create a new one");
    }
}
int Hierarchy::num_employees() const {
    if(hierarchy) {
        if(hierarchy->getRoot()->subordinates.empty()) {return 1;}
        else {
            std::queue<node*> func_helper;
            func_helper.push(hierarchy->getRoot());
            int toReturn = 1;
            while (!func_helper.empty())
            {
                node* current = func_helper.front();
                func_helper.pop();
                for (size_t i = 0; i < current->subordinates.size(); i++)
                {
                    func_helper.push(current->subordinates[i]);
                    toReturn ++;
                }
            }
            return toReturn + 1;
        }
    } else {
        return 0;
    }
}
int Hierarchy::num_overloaded(int level) const{
    if(hierarchy) {
        if(hierarchy->getRoot()->subordinates.empty()) {return 0;}
        else {
            std::queue<node*> func_helper;
            func_helper.push(hierarchy->getRoot());
            int toReturn = 0;
            while (!func_helper.empty())
            {
               node* current = func_helper.front();
               if(current->subordinates.size() >= level) {toReturn++;}
               func_helper.pop();
               for (size_t i = 0; i < current->subordinates.size(); i++)
               {
                    func_helper.push(current->subordinates[i]);
               }
            }
            return toReturn;
        }
        
        //check the mumber if employees to every boss
        //for everyone except the leaves
        //add anyone who has above 20 subs in a counter
        //return the counter;

    } else {
       return 0;
    }
}

std::string Hierarchy::manager(const std::string& name) const {
   return hierarchy->findNode(name)->boss->data;
}
int Hierarchy::num_subordinates(const std::string& name) const {
    return hierarchy->getRoot()->subordinates.size();
}
unsigned long Hierarchy::getSalary(const std::string& who) const {
    if(hierarchy) {
        if(find(who)) {
            return hierarchy->num_direct_employees(who)*500 + hierarchy->num_indirect_employees(who)*50;
        } else {
            return -1;
        }
        
    } else {
        return -1;
    }
}

bool Hierarchy::fire(const std::string& who) {
   hierarchy->remove(who);
   if(hierarchy->find(who) == false) {
        return true;
    } else { return false; }
  
}
bool Hierarchy::hire(const std::string& who, const std::string& boss) {
    if(find(who)) {
        hierarchy->remove(who);
        hierarchy->insert(who, boss);
    }
    return hierarchy->insert(who, boss);
}

// void Hierarchy::incorporate() {
    
//    if(hierarchy->getRoot()->subordinates.empty()) {
//         throw std::runtime_error("Impossible to incorporate, no subordinates present -> Please, hire some!");
//    } else {
//         std::stack<node*> incoporate_helper;
//         std::queue<node*> helper_queue;
//         incoporate_helper.push(hierarchy->getRoot());
//         helper_queue.push(hierarchy->getRoot());
//         int highest_salary = 0;
//         node* toBePromoted;
//         std::vector<node*> toBeEmployeed;//the subordinates that we will assign to the newly promoted employee
//         while(!helper_queue.empty()) {
//             node* current = helper_queue.front();
//             for(size_t i = 0; i < current->subordinates.size(); i++) {
//                 incoporate_helper.push(current->subordinates[i]);
//                 helper_queue.push(current->subordinates[i]);
//             }
//             helper_queue.pop();
//         }
        
        
//        while (!incoporate_helper.empty()) { 
//             node* current = incoporate_helper.top();
//             if(current->boss->subordinates.size() >= 2) {
//                 for (size_t i = 0; i < current->boss->subordinates.size(); i++)
//                 {
//                     if(getSalary(current->boss->subordinates[i]->data) > highest_salary) {
//                         highest_salary = getSalary(current->boss->subordinates[i]->data);
//                     }
//                 } 
//                 for (size_t i = 0; i < current->boss->subordinates.size(); i++)
//                 {
//                     if(highest_salary == getSalary(current->boss->subordinates[i]->data)) {
//                         toBePromoted = current->boss->subordinates[i];
//                     } else {
//                         toBeEmployeed.push_back(current->boss->subordinates[i]);
//                         current->boss->subordinates.erase(current->boss->subordinates.begin() + i);
//                     }
//                 }
//            } 
//            incoporate_helper.pop();
//        }   
//        toBePromoted->subordinates = toBeEmployeed;
//        for (size_t i = 0; i < toBePromoted->subordinates.size(); i++)
//        {
//            toBePromoted->subordinates[i]->boss = toBePromoted;
//        }
       
//    }
// }
// void Hierarchy::modernize(){
//     if(hierarchy) {
       
//         std::stack<std::pair<node*, int>> modernize_helper;
//         std::queue<node*> helper_queue;
//         modernize_helper.push(std::pair<node*, int>{hierarchy->getRoot(),0});
//         helper_queue.push(hierarchy->getRoot());
//         while(!helper_queue.empty()) {
//             node* current = helper_queue.front();
//             for(size_t i = 0; i < current->subordinates.size(); i++) {
//                 std::pair<node*, int> current_stack = modernize_helper.top();
//                 modernize_helper.push(std::pair<node*, int>{current->subordinates[i], current_stack.second + 1});
//                 helper_queue.push(current->subordinates[i]);
//             }
//             helper_queue.pop();
//         }
        
//         while (!modernize_helper.empty()) {
//             std::pair<node*, int>current = modernize_helper.top();
//             if(current.second % 2 != 0) {
//                 fire(current.first->data);
//             }
//             modernize_helper.pop();
//         }
        
        
//     } else {
//         throw std::runtime_error("No instance of hierarchy created!");
//     }
//     //check if the hierarchy is empty
//     //if not find the bosses of an odd levels of the tree, starting from the bottom => DFs
//     //if those bosses have subs -> remove them and include their  subs to the  subs of their boss!! 
// }

// Hierarchy Hierarchy::join(const Hierarchy& right) const {
//     /*
//     Ако служител се среща и в двете йерархии, то в обединението той също се среща като там преките му подчинени са всички негови преки подчинени от двете йерархи. 
//     Предполага се Успешният да е на върха и на двете места. Това правило се прилага рекурсивно надолу (за всички служители от върха надолу). 
//     Ако в двата отдела този служител има различни ръководители, то в обединението трябва да остане само една инстанция, закачена към по-високо стоящия в йерархията ръководител. 
//     Ако двата са на едно ниво (например преки подчинени на Успешния), то изберете този с лексикографски по-малкото име. 
//     Не се предполага за двама служители в едната йерархия единият да е подчинен на другия, а в другата - обратно;
//     Ако даден служител се среща само в едната йерархия, той присъства в обединението, точно под инстанцията на ръководителя си (като негов пряк подчинен), 
//     заедно с всички свои подчинени от съответното дърво;
//     Сливането не е възможно ако има ситуация, в която служител X е подчинен на Y в едната йерархия (пряко или не), а в другата е обратно. 
//     В такъв случай не трябва да създавате слятата йерархия.
//     */
//     Hierarchy* newHierarchy = new Hierarchy(this->print());
//     std::queue<node*> func_helper;
//     func_helper.push(right.hierarchy->getRoot());
//     while(!func_helper.empty())
//     return *newHierarchy;
// }

    
    // //If you need it - add more public methods here
void Hierarchy::saveToFile() {
    std::cout << "save";
    if(this->filename != ""){
        std::ofstream out(this->filename);
        out << hierarchy->print();
    }else{
        std::cout << "No opened file exists!"<< std::endl;
    }
}
void Hierarchy::loadFromFile() {
}
void Hierarchy::start() {
    int flag;
    do
    {
        std::cout << "Enter: ";
        command_menu.command = "";
        std::cin >> command_menu.command;
        flag = -1;
        for(int i = 0; i < command_menu.menu.size(); i++)
        {
            if(command_menu.command == command_menu.menu[i])
            {
                flag = i;
                break;
            }
        }
        
        switch(flag) {
            case 0:{ // Help
                std::cout <<"The following commands are supported: \n"
                          <<"Help -> Prints the list of commands! \n"
                          <<"Load -> Loads the data of a given hierarchy! \n"
                          <<"Save -> Enlists the information, regarding the hierarchy of the given object on the file, whoose name is given! \n"
                          <<"Correct Input -> Validates the given string and returns wether the data is valid! \n"
                          <<"Find -> Looks trough the hierarchy whethet the given person is a part of the hierarchy! \n"
                          <<"Num Subordinates -> Returns the number of employees, that the given employee has! \n"
                          <<"Manager -> Returns the manager of the given employee! \n"
                          <<"Num Employees -> Returns the number of employees, currently working in the company! \n"  
                          <<"Overloaded -> Returns the count of people, that have more than 20 subordinates, working under them! \n"
                          <<"Join -> Merges 2 hierarchies! \n"
                          <<"Fire -> Fires the given employee from the company! \n"
                          <<"Hire -> Hires a new employee in the company! \n"
                          <<"Salary -> Returns the salary, the given employee recieves! \n"
                          <<"Longest chain -> returns the longest boss-subordinate chain, currently present in the company! \n"
                          <<"Incorporate -> Promotes a given employee, whose salary is the highest amongst his collegues! \n"
                          <<"Modernize -> Fires the bosses of an odd row of the hierarchy! \n"
                          <<"Print -> Prints the whole hierarchy! \n"
                          <<"Exit -> Exits the program! \n";
                          break;
            }
            case 1: {// Load
                if (this->filename == "") {
                    std::string filename_;
                    std::cout << "Enter the name of the file you want to load: ";
                    std::cin >> filename_;
                    if(filename_ != "") {
                        this->filename.resize(filename_.size() + 1);
                        filename = filename_;
                        loadFromFile();
                    }
                    std::cout << this->filename << " loaded successfully! "<< "\n";
                } else {
                    std::cout << "A file is already opened \n";
                }
                break;
            }
            case 2: {//Save
                std::string filename_;
                    std::cout << "Enter the name of the file you want to save your hierarchy as: ";
                    std::cin >> filename_;
                    if(filename_ != "")
                    {
                        this->filename.resize(filename_.size()+ 1);
                        this->filename = filename_;
                    }
    
                saveToFile();
                std::cout << filename<< "saved \n";
                break;
            }
            case 3: { // Find
                std::string name_to_find;
                std::cout << "Please, enter the person you wish to find: ";
                std::cin >> name_to_find;
                if(find(name_to_find) == true) {
                    std::cout << name_to_find << " is employed in " << filename <<"\n";
                } else {
                    std::cout << name_to_find << " is not employed in " << filename <<"\n";
                }
                break;
            }
            case 4: {// Num Subordinates
                std::string name_to_find_subordinates;
                std::cout << "Please, enter the person, whoose subordinates you wish to find: ";
                std::cin >> name_to_find_subordinates;
                std::cout << name_to_find_subordinates<<" has " << num_subordinates(name_to_find_subordinates) << " subordinates \n";
                break;
            }
            case 5: {//Manager
                std::string name_to_find_manager;
                std::cout << "Please, enter the person, whoose manager you wish to find: ";
                std::cin >> name_to_find_manager;
                std::cout << "The manager of " << name_to_find_manager << " is " << manager(name_to_find_manager) <<"\n"; 
                break;
            }
            case 6: {//Num Employees
                std::string name_of_object;
                std::cout << "Please, enter the name of the company: ";
                std::cin >> name_of_object;
                if(name_of_object == filename) {
                    std::cout << "There are " << num_employees() << " in " << filename << "\n";
                } else {
                   std::cout << name_of_object << " is an unknown office! \n ";
                }
                break;
            }
            case 7: {//Overloaded
                std::string name_of_object;
                std::cout << "Please, enter the name of the company: ";
                std::cin >> name_of_object;
                if(name_of_object == filename) {
                    if(num_overloaded() != 0) {
                        std::cout << "There are " << num_overloaded() << " overloaded employees in " << filename << ".\n";
                    } else {
                        std::cout << "No overloaded employees in " << filename << ".\n";
                    }
                } else {
                   std::cout << name_of_object << " is an unknown office! \n ";
                }
                break;
            }
            case 8: {//Join

                break;
            }
            case 9: {//Fire
                std::string name_of_object;
                std::cout << "Please, enter the name of the company: ";
                std::cin >> name_of_object;
                if(name_of_object == filename) {
                    std::string name_of_person;
                    std::cout << "Please, enter the name of the employee, you wish to fire: ";
                    std::cin >> name_of_person;
                    fire(name_of_person);
                    std::cout << name_of_person << " was fired \n";
                }else {
                    std::cout << "There is no such object! \n";
                }
                break;
                
                
            }
            case 10: {//Hire
            
                std::string name_of_object;
                std::cout << "Please, enter the name of the company: ";
                std::cin >> name_of_object;
                if(name_of_object == filename) {
                    std::string name_of_person;
                    std::string name_of_boss;
                    std::cout << "Please, enter the name of the employee, you wish to hire: ";
                    std::cin >> name_of_person;
                    std::cout << "Please, enter the name of the employees' boss: ";
                    std::cin >> name_of_boss;
                    hire(name_of_person, name_of_boss);
                    std::cout << name_of_person << " was hired \n";
                }else {
                    std::cout << "There is no such object! \n";
                }
                break;
            }
            case 11:{//Salary
                std::string name_of_person;
                std::cout << "Please, enter the name of the employee, whoose salary you wish to check: ";
                std::cin >> name_of_person;
                std::cout << "The salary is: "<< getSalary(name_of_person) << "\n";
                break;
            }
            case 12: {//longest chain
                std::string name_of_object;
                std::cout << "Please, enter the name of the company: ";
                std::cin >> name_of_object;
                if(name_of_object == filename) {
                    std::cout << "The longest chain boss-employee in "<< filename<< " is: " << longest_chain()<< "\n";
                } else {
                    std::cout << "There is no such object! \n";
                }
                break;
            }
            case 13: {//Incorporate
                std::string name_of_object;
                std::cout << "Please, enter the name of the company: ";
                std::cin >> name_of_object;
                if(name_of_object == filename) {
                    incorporate();
                    std::cout << filename <<" incorporaded \n";
                } else {
                    std::cout << "There is no such object! \n";
                }
                break;
            }
            case 14: {//Modernize
                std::string name_of_object;
                std::cout << "Please, enter the name of the company: ";
                std::cin >> name_of_object;
                if(name_of_object == filename) {
                    modernize();
                    std::cout << filename <<" modernized \n";
                } else {
                    std::cout << "There is no such object! \n";
                }
                break;
            }
            case 15: {//print
                std::string name_of_object;
                std::cout << "Please, enter the name of the company: ";
                std::cin >> name_of_object;
                if(name_of_object == filename) {
                    std::cout << print();
                }else {
                    std::cout << "There is no such object! \n";
                }
                break;
            }
            case 16://exit
            {
                std::cout << "Exiting the program..." << std::endl;   
                break;
            }
            default: "Invalid command";
        }
    }
    while(command_menu.command != "Exit");
}