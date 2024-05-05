
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	welcomeMenu(void)
{
	std::cout << "Please select from the menu:" << std::endl;
    std::cout << "[---- ADD ----]" << std::endl;
    std::cout << "[---- SEARCH -----]" << std::endl;
    std::cout << "[---- EXIT -----]" << std::endl;
    std::cout << "Enter your choice : ";
}

int main() 
{
    PhoneBook phoneBook;
    std::string command;

    while (1) 
    {
        if (std::cin.eof())
            break;
        welcomeMenu();
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "wrong command please enter (ADD or SEARCH or EXIT)" << std::endl;
        
    }
}