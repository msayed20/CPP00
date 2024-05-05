/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman_marzouk <ayman_marzouk@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:12:41 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/03/29 02:43:15 by ayman_marzo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	printMenu(void)
{
	std::cout << "Please select an option:" << std::endl;
    std::cout << "1️⃣ ADD 📝" << std::endl;
    std::cout << "2️⃣ SEARCH 🔍" << std::endl;
    std::cout << "3️⃣ EXIT 🚪" << std::endl;
    std::cout << "Enter your choice 💻: ";
}

int main() 
{
    PhoneBook phoneBook;
    std::string command;

    while (true) 
    {
        if (std::cin.eof())
            break;
        printMenu();
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << std::endl;
        
    }
}