#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

#include "person.h"

class Notebook {
private:
    Person people[100];
    int count;
    std::string filename;

public:
    Notebook(const std::string& filename);
    void addPerson(const Person& person);
    void isValidPhoneNumber(const char* phoneNumber);
    void isValidDateOfBirth(const char* dateOfBirth);
    void isValidName(const char* name);
    void saveToFile();
    std::string checkDuplicatePeople(const Notebook& otherNotebook);
    std::string getFileContents();
};
