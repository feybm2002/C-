
#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <iostream>
#include <string>

class Name{
private:
    std::string name;
    std::string lastName;
public:
    Name();
    void setName(const std::string&);
    void setLastName(const std::string&);
    std::string getName()const;
    std::string getLastName()const;
    std::string ToString()const;
};
#endif // NAME_H_INCLUDED
