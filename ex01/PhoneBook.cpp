

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

PhoneBook::PhoneBook() : currentSize(0), nextIndex(0) {}

void PhoneBook::addContact() 
{
    if (currentSize >= 8) {
        if (!contacts[nextIndex].setDetails()) 
        {
            std::cout << "Contact information is incomplete. The contact was not updated.\n";
            return;
        }
        nextIndex = (nextIndex + 1) % 8;
    } else {
        if (contacts[currentSize].setDetails()) {
            currentSize++;
            nextIndex = currentSize % 8;
        } else {
            std::cout << "Contact information is incomplete. The contact was not added.\n";
        }
    }
}

void PhoneBook::searchContacts() const {
    for (int i = 0; i < currentSize; i++) {
        contacts[i].displayContactSummary(i);
    }
    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
        std::cout << "No index entered. Returning to main menu.\n";
        return;
    }

    std::istringstream iss(input);
    int index;
    if (!(iss >> index)) {
        std::cout << "Invalid input. Please enter a numeric value.\n";
        return;
    }

    std::string remaining;
    if (iss >> remaining) { 
        std::cout << "Invalid index. Please enter a number between 0 and 7.\n";
        return;
    }

    if (index < 0 || index > 7) {
        std::cout << "Invalid index. Please enter a number between 0 and 7.\n";
        return;
    } else if (index >= currentSize) {
        std::cout << "Contact not found. Please enter a valid index.\n";
    } else {
        contacts[index].displayFullDetails();
    }
}