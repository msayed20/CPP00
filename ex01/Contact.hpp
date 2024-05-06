#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    bool _isValid;

public:
    Contact() : _isValid(false) {}
    bool setDetails();
    void displayContactSummary(int index) const;
    void displayFullDetails() const;
    bool isValidContact() const { return _isValid; }

};

#endif