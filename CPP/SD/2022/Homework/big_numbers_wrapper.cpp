#include "big_numbers_interface.cpp"

class Wrapper{
    protected:
    std::vector<std::string> menu;
    std::string command;
    BigNumber* number;

    public:
    Wrapper(){
        this->number = new BigNumber;
        menu.push_back("input");
        menu.push_back("output");
        menu.push_back("add");
        menu.push_back("subtract");
        menu.push_back("multiply");
        menu.push_back("divide");
        menu.push_back("sqrt");
        menu.push_back("help");
        menu.push_back("exit");

    }
    void start(){
        int flag;
        std::cout << "Starting the program... \n" << "Enter 'help' to see all commands \n";
        do
        {
            std::cout << "Enter: "; 
            command = "";
            std::cin >> command;
            flag = -1;
            for(int i = 0; i < menu.size(); i++)
            {
                if(command == menu[i])
                {
                    flag = i;
                    break;
                }
            }

            switch(flag){
                case 0: {
                    std::string bigNum;
                    std::cout << "Enter your number: ";
                    std::cin >> bigNum;
                    this->number = new BigNumber(bigNum);
                    break;
                }
                case 1: {
                    std::string numeric;
                    std::cout << "Possible numeric outputs: dec, hex \n";
                    std::cout << "Enter a numeric system you want the output in: ";
                    std::cin >> numeric;
                    if(numeric == "dec") std::cout << "Your number in decimal is: " << *number << "\n";
                    if(numeric == "hex") std::cout << "Your number in hexadecimal is: " << (number->toHex()) << "\n";
                    break;
                }
                case 2: {
                    std::string toAdd;
                    std::cout << "Enter a number to add to your number: ";
                    std::cin >> toAdd;
                    BigNumber toAddNum(toAdd);
                    std::cout << "The addition of the two numbers is: " << (*number + toAddNum) << "\n";
                    break;

                }
                case 3: {
                    std::string toSubtract;
                    std::cout << "Enter a number to subtract with your number: ";
                    std::cin >> toSubtract;
                    BigNumber toSubtractNum(toSubtract);
                    std::cout << "The subtraction of the two numbers is: " << (*number - toSubtractNum) << "\n";
                    break;
                }
                case 4: {
                    std::string toMyltiply;
                    std::cout << "Enter a number to multiply with your number: ";
                    std::cin >> toMyltiply;
                    BigNumber toMyltiplyNum(toMyltiply);
                    std::cout << "The multiplication of the two numbers is: " << (*number * toMyltiplyNum) << "\n";
                    break;

                }
                case 5: {
                    std::string toDivide;
                    std::cout << "Enter a number to divide with your number: ";
                    std::cin >> toDivide;
                    BigNumber toDivideNum(toDivide);
                    std::cout << "The division of the two numbers is: " << (*number / toDivideNum) << "\n";
                    break;

                }
                case 6: {
                    std::cout << "The sqare root of your number is: " << (number->SQRT()) << "\n";
                    break;

                }
                case 7: {
                    std::cout << "The list of commands is: '\n";
                    std::cout << "input -> you enter your number '\n"
                              << "output -> you can see your numebr '\n"
                              << "add -> adds your number with an entered one '\n"
                              << "subtract -> subtracts your number with an entered one '\n "
                              << "multiply -> multiplies your number with an entered one '\n "
                              << "divide -> divides your number with an entered one '\n "
                              << "sqrt -> returns the sqare root of your number '\n "
                              << "help -> see all the commands '\n"
                              << "exit -> exits the program '\n";
                    break;
                }
                case 8: {
                    std::cout << "Exiting the program..." << std::endl;   
                    break;
                }
                default: "Invalid command";  
            }
        }
        while(command != "exit");
    }
};