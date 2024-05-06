

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

    _firstName = firstTemp;
    _lastName = lastTemp;
    _nickname = nickTemp;
    _phoneNumber = phoneTemp;
    _darkestSecret = secretTemp;
    _isValid = true;
    return true;
}

void Contact::displayContactSummary(int index) const 
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << "|";
    std::cout << std::setw(10) << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << "|";
    std::cout << std::setw(10) << (_nickname.length() > 10 ? _nickname.substr(0, 9) + "." : _nickname) << std::endl;
}

void Contact::displayFullDetails() const 
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}