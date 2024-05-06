

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

PhoneBook::PhoneBook() : _currentSize(0), _nextIndex(0) {}

void PhoneBook::addContact() 
{
    if (_currentSize >= 8) {
        if (!_contacts[_nextIndex].setDetails()) 
        {
            std::cout << "Contact information is incomplete. The contact was not updated.\n";
            return;
        }
        _nextIndex = (_nextIndex + 1) % 8;
    } else {
        if (_contacts[_currentSize].setDetails()) {
            _currentSize++;
            _nextIndex = _currentSize % 8;
        } else {
            std::cout << "Contact information is incomplete. The contact was not added.\n";
        }
    }
}

void PhoneBook::searchContacts() const {
    for (int i = 0; i < _currentSize; i++) {
        _contacts[i].displayContactSummary(i);
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
    } else if (index >= _currentSize) {
        std::cout << "Contact not found. Please enter a valid index.\n";
    } else {
        _contacts[index].displayFullDetails();
    }
}