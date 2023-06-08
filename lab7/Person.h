#pragma once
#include <iostream>
class Person {
public:
    char name[150];
    char dateOfBirth[12];
    char phoneNumber[15];

    Person();
    Person(const char* name, const char* dateOfBirth, const char* phoneNumber);
    const char* getName() const;
    const char* getDateOfBirth() const;
    const char* getPhoneNumber() const;
};



