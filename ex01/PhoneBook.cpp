

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

PhoneBook::PhoneBook() : currentSize(0), nextIndex(0) {}

void PhoneBook::addContact() 
{
    // If adding the first contact after reaching maximum size,
    // nextIndex should be 0 to replace the first (oldest) contact.
    if (currentSize >= 8) {
        // Overwrite the contact at the current value of nextIndex.
        if (!contacts[nextIndex].setDetails()) 
        {
            std::cout << "Contact information is incomplete. The contact was not updated.\n";
            return; // Early return if the details were not successfully set.
        }
        // After successfully adding a contact, increment nextIndex for the next addition.
        nextIndex = (nextIndex + 1) % 8; // Ensure nextIndex wraps around to 0 after reaching 7.
    } else {
        // The phone book has not yet reached its maximum size.
        if (contacts[currentSize].setDetails()) {
            // Increment currentSize only if the contact details were successfully set.
            currentSize++;
            // Update nextIndex accordingly. Before reaching the maximum size,
            // nextIndex should track currentSize to ensure it points to the oldest contact.
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

    // Using std::istringstream to convert string to integer
    std::istringstream iss(input);
    int index;
    if (!(iss >> index)) { // If conversion fails
        std::cout << "Invalid input. Please enter a numeric value.\n";
        return;
    }

    // Checking the entire string was consumed during conversion to ensure validity
    std::string remaining;
    if (iss >> remaining) { // Checks if there's any remaining part that wasn't converted
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