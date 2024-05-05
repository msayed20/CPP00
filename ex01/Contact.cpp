/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman_marzouk <ayman_marzouk@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:11:11 by ayman_marzo       #+#    #+#             */
/*   Updated: 2024/03/29 14:29:52 by ayman_marzo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

bool Contact::setDetails() 
{
    std:: string firstTemp;
    std:: string lastTemp;
    std:: string nickTemp;
    std:: string phoneTemp;
    std:: string secretTemp;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstTemp);
    if (firstTemp.empty())
        return(std::cout << "First name cannot be empty. Please try again.\n", false);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastTemp);
    if (lastTemp.empty())
        return(std::cout << "Last name cannot be empty. Please try again.\n", false);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickTemp);
    if (nickTemp.empty())
        return(std::cout << "Nickname cannot be empty. Please try again.\n", false);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneTemp);
    if (phoneTemp.empty())
        return(std::cout << "Phone number cannot be empty. Please try again.\n", false);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin,secretTemp);
    if (secretTemp.empty())
        return(std::cout << "Darkest secret cannot be empty. Please try again.\n", false);

    firstName = firstTemp;
    lastName = lastTemp;
    nickname = nickTemp;
    phoneNumber = phoneTemp;
    darkestSecret = secretTemp;
    isValid = true;
    return true;
}

void Contact::displayContactSummary(int index) const 
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
    std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
    std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}

void Contact::displayFullDetails() const 
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}