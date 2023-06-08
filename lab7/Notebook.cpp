#include "Notebook.h"
using namespace System::Windows::Forms;
using namespace System;
Notebook::Notebook(const std::string& filename)
    : count(0), filename(filename) {}

void Notebook::addPerson(const Person& person) {
        people[count++] = person;
        saveToFile();
}

void Notebook::isValidPhoneNumber(const char* phoneNumber) {
    for (size_t i = 0; i < strlen(phoneNumber); i++) {
        if (!isdigit(phoneNumber[i])) {
            throw std::invalid_argument("Phone number error: Phone number consists of numbers only");
        }
    }

    if (strlen(phoneNumber) != 12) {
        throw std::invalid_argument("Phone number error: Invalid number of symbols should be 12");
    }

}

void Notebook::isValidDateOfBirth(const char* dateOfBirth) {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    int day, month, year;
    if (sscanf(dateOfBirth, "%2d-%2d-%4d", &day, &month, &year) != 3) {
        throw std::invalid_argument("Date of birth error: Invalid format should be dd-mm-yyyy");
    }
    if (strlen(dateOfBirth) != 10) {
        throw std::invalid_argument("Date of birth error: Invalid number of symbols");
    }
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1901 || year > 2023) {
        throw std::invalid_argument("Date of birth error: Invalid date range");
    }
    
    int daysInMonth;
    switch (month) {
    case 2:
        daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
        break;
    }

    if (day > daysInMonth) {
        throw std::invalid_argument("Date of birth error: Invalid number of days in month");
    }

    if (year == currentYear && month == currentMonth && day == currentDay) {
        throw std::invalid_argument("Date of birth error: Date of birth cannot be today's date.");
    }

    if (year == currentYear && month == currentMonth && day > currentDay || year == currentYear && month > currentMonth && day == currentDay || year == currentYear && month > currentMonth && day > currentDay) {
        throw std::invalid_argument("Date of birth error: Impossible date of birth.");
    }
}


void Notebook::isValidName(const char* name) {
    std::string nameString(name);

    int wordCount = 0;
    std::istringstream ss(nameString);
    std::string word;
    while (ss >> word) {
        wordCount++;
    }
    if (wordCount > 3) {
        throw std::invalid_argument("Full name error: No more than 3 words");
    }

    for (char c : nameString) {
        if (isdigit(c)) {
            throw std::invalid_argument("Full name error: Name consists of letters only");
        }
    }
}

void Notebook::saveToFile() {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Failed to create file: " << filename << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        size_t nameLength = strlen(people[i].getName()) + 1;
        file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        file.write(people[i].getName(), nameLength);

        size_t dobLength = strlen(people[i].getDateOfBirth()) + 1;
        file.write(reinterpret_cast<const char*>(&dobLength), sizeof(dobLength));
        file.write(people[i].getDateOfBirth(), dobLength);

        size_t phoneNumberLength = strlen(people[i].getPhoneNumber()) + 1;
        file.write(reinterpret_cast<const char*>(&phoneNumberLength), sizeof(phoneNumberLength));
        file.write(people[i].getPhoneNumber(), phoneNumberLength);
    }

    file.close();
}

std::string Notebook::checkDuplicatePeople(const Notebook& otherNotebook) {
    std::string contents;
    for (int i = 0; i < count; i++) {
        bool isDuplicate = false;

        for (int j = 0; j < otherNotebook.count; j++) {
            if (strcmp(people[i].getName(), otherNotebook.people[j].getName()) == 0 &&
                strcmp(people[i].getDateOfBirth(), otherNotebook.people[j].getDateOfBirth()) == 0 &&
                strcmp(people[i].getPhoneNumber(), otherNotebook.people[j].getPhoneNumber()) == 0) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate) {
            contents += "Name: " + std::string(people[i].getName()) + " \r\n";
            contents += "Date of Birth: " + std::string(people[i].getDateOfBirth()) + " \r\n";
            contents += "Phone Number: " + std::string(people[i].getPhoneNumber()) + " \r\n\r\n";
            std::cout << contents << std::endl;
        }
    }
    return contents;
}

std::string Notebook::getFileContents() {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return "";
    }

    std::string contents;

    int fileCount = 0;

    while (!file.eof() && fileCount < count) {
        size_t nameLength;
        file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        file.read(people[fileCount].name, nameLength);

        size_t dobLength;
        file.read(reinterpret_cast<char*>(&dobLength), sizeof(dobLength));
        file.read(people[fileCount].dateOfBirth, dobLength);

        size_t phoneNumberLength;
        file.read(reinterpret_cast<char*>(&phoneNumberLength), sizeof(phoneNumberLength));
        file.read(people[fileCount].phoneNumber, phoneNumberLength);

        // Формуємо рядок з вмістом файлу
        contents += "Contact: " + std::to_string(fileCount + 1) +  "\r\n";
        contents += "Name: " + std::string(people[fileCount].name) + " \r\n";
        contents += "Phone Number: " + std::string(people[fileCount].phoneNumber) + " \r\n";
        contents += "Date of Birth: " + std::string(people[fileCount].dateOfBirth) + " \r\n\r\n";
        fileCount++;
    }

    file.close();

    return contents;
}