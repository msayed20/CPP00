

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
private:
    Contact _contacts[8];
    int _currentSize;
    int _nextIndex;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif