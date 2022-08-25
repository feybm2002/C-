#include <iostream>
#include "Name.h"
#include "string"

Name::Name() {}
void Name::setName(const std::string& Name) {
    name=Name;
}
void Name::setLastName(const std::string& lastname) {
    lastName=lastname;
}
std::string Name::getName()const {
    return name;
}
std::string Name::getLastName()const {
    return lastName;
}
std::string Name::ToString()const {
    return name + " " + lastName;
}

