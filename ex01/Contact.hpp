#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    bool isValid;

public:
    Contact() : isValid(false) {}
    bool setDetails();
    void displayContactSummary(int index) const;
    void displayFullDetails() const;
    bool isValidContact() const { return isValid; }

};

#endif