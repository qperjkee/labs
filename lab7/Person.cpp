#include "Person.h"
#include <cstring>

Person::Person() {}

Person::Person(const char* name, const char* dateOfBirth, const char* phoneNumber) {
    strncpy(this->name, name, sizeof(this->name) - 1);
    strncpy(this->dateOfBirth, dateOfBirth, sizeof(this->dateOfBirth) - 1);
    strncpy(this->phoneNumber, phoneNumber, sizeof(this->phoneNumber) - 1);
}

const char* Person::getName() const {
    return name;
}

const char* Person::getDateOfBirth() const {
    return dateOfBirth;
}

const char* Person::getPhoneNumber() const {
    return phoneNumber;
}