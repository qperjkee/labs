#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool isMode(const char* modeValue, int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) { // Проходимо по всіх аргументах командного рядку
        if (strcmp(argv[i], "-mode") == 0 && i + 1 < argc) { // Якщо знаходимо режим "-mode"
            return strcmp(argv[i+1], modeValue) == 0; // Повертаємо, чи відповідає наступний аргумент режиму modeValue
        }
    }
    return false; // Якщо не знайдено режим "-mode", повертаємо false
}

int line_length(string line){
    int char_count = 0; // ініціалізуємо змінну, що буде лічильником символів
    for (int i = 0; i < line.length(); i++) { // проходимо крізь кожен символ у рядку
            if (line[i] != '.' && line[i] != ',' && line[i] != ' ' && line[i] != '\n') { // перевіряємо, чи символ не є комою, крапкою, пробілом або символом переносу рядка
                char_count++; // якщо символ не є комою, крапкою, пробілом або символом переносу рядка, то збільшуємо лічильник символів
            }
}
return char_count; // повертаємо кількість символів у рядку
}
int line_length(const char* line) {
    int char_count = 0; // ініціалізуємо змінну, що буде лічильником символів
    for(int i = 0; line[i] != '\0'; i++) { // проходимо крізь кожен символ у масиві символів до тих пір, поки не знайдемо нуль-термінований рядок '\0'
        if (line[i] != '.' && line[i] != ',' && line[i] != ' ' && line[i] != '\n') { // перевіряємо, чи символ не є комою, крапкою, пробілом або символом переносу рядка
            char_count++; // якщо символ не є комою, крапкою, пробілом або символом переносу рядка, то збільшуємо лічильник символів
        }
    }
    return char_count; // повертаємо кількість символів у рядку
}

int full_length(const char* line) {
    // цикл ітерується по кожному символу рядка,
    // доки не зустрічає символ '\0', що позначає кінець рядка
    for (int i = 0; ; i++) if (line[i] == '\0') return i;// якщо знайдено кінець рядка, повертаємо довжину рядка
}

void file_sort(const string& inputFile, const string& outputFile){
// Відкриваємо вхідний файл для читання
ifstream in(inputFile);
// Відкриваємо вихідний файл для запису
ofstream out(outputFile);
string line;
string* lines = nullptr;
int count = 0;

// Рахуємо кількість рядків у вхідному файлі
while (getline(in, line)) {
    count++;
}

// Створюємо масив для зберігання рядків
lines = new string[count];

// Повторно відкриваємо вхідний файл, щоб зчитати рядки
in.clear();
in.seekg(0, ios::beg);

// Зчитуємо рядки з вхідного файлу та зберігаємо їх у масиві
int i = 0;
while (getline(in, line)) {
    lines[i++] = line;
}

// Сортуємо рядки за зменшенням довжини
for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
        if (line_length(lines[i]) < line_length(lines[j])) {
            swap(lines[i], lines[j]);
        }
    }
}

// Записуємо відсортовані рядки у вихідний файл
for (int i = 0; i < count; i++) {
    if(line_length(lines[i]) > 0){
    out << line_length(lines[i]) << " " << lines[i] << endl;
    }
}

// Звільняємо пам'ять, виділену для масиву рядків
delete[] lines;
}
void file_sort(const char* inputFile, const char* outputFile) {
// Відкриваємо вхідний файл для читання та вихідний файл для запису.
FILE *in = fopen(inputFile, "r");
FILE *out = fopen(outputFile, "w");
char line[1024];
char **lines = nullptr;
int count = 0;

// Рахуємо кількість рядків у файлі.
while (fgets(line, sizeof(line), in)) {
    count++;
}

// Виділяємо пам'ять під масив рядків.
lines = new char*[count];

// Повертаємось на початок файлу.
fseek(in, 0, SEEK_SET);

int i = 0;
// Зчитуємо кожен рядок з файлу та додаємо його до масиву рядків.
while (fgets(line, sizeof(line), in)) {
    lines[i] = new char[strlen(line) + 1];
    strcpy(lines[i++], line);
}

// Сортуємо масив рядків у порядку спадання на основі довжини кожного рядка.
for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
        if (line_length(lines[i]) < line_length(lines[j])) {
            char *temp = lines[i];
            lines[i] = lines[j];
            lines[j] = temp;
        }
    }
}

// Записуємо відсортований масив рядків до вихідного файлу.
for (int i = 0; i < count; i++) {
    if (line_length(lines[i]) > 0) {
        fprintf(out, "%d %s", line_length(lines[i]), lines[i]);
        if (lines[i][full_length(lines[i]) - 1] != '\n') fputc('\n', out);
    }
    // Звільняємо пам'ять, виділену для кожного рядка.
    delete[] lines[i];
}

// Звільняємо пам'ять, виділену для масиву рядків.
delete[] lines;
// Закриваємо вхідний та вихідний файли.
fclose(in);
fclose(out);
}

void file_create(string filename){
    ofstream created_file(filename); // створюємо новий файл з іменем, що передано як параметр
    created_file.close(); // закриваємо файл
}
void file_create(const char* filename) {
    FILE* created_file = fopen(filename, "w"); // створюємо новий файл з іменем, що передано як параметр та режимом "запису" ('w')
    fclose(created_file); // закриваємо файл
}

void file_output(string filename){
    ifstream file(filename); // відкриваємо файл для зчитування
    string line;
    while (getline(file, line)) { // зчитуємо кожен рядок файла по черзі
        cout << line << endl; // виводимо кожен рядок на екран
    }
}
void file_output(const char* filename) {
    FILE* file = fopen(filename, "r"); // відкриваємо файл для зчитування
    char line[1024];
    while (fgets(line, 1024, file) != NULL) { // зчитуємо кожен рядок файла по черзі
        printf("%s", line); // виводимо кожен рядок на екран
    }
    fclose(file); // закриваємо файл
}

void file_append(string filename) {
    ofstream file(filename, ios_base::app); // відкриваємо файл в режимі доповнення
    string line;
    cout << "Fill in file. Press >> at the beginning of a new line to stop." << endl; // виводимо повідомлення користувачеві
    bool first_line = true;
    while (getline(cin, line)) { // зчитуємо кожен рядок, який вводить користувач
        if (line == ">>") { // якщо введено ">>", то закінчуємо цикл
            break;
        }
        if (!first_line) file << endl;
        first_line = false;
        file << line; // дописуємо вміст файлу кожен рядок, який вводить користувач
    }
    file.close(); // закриваємо файл
    cout << "The file has been successfully added."; // виводимо повідомлення про успішне доповнення файлу
}
void file_append(const char* filename) {
    FILE* file = fopen(filename, "a"); // відкриваємо файл для додавання (append)
    char line[1024];
    int counter = 0; // лічильник для кількості символів в рядку
    bool first_line = true; // флаг, щоб переконатися, що перший рядок не отримує символ нового рядка
    cout << "Fill in file. Press >> at the beginning of a new line to stop." << endl; // вивід повідомлення для користувача
    while (fgets(line, sizeof(line), stdin)) { // читаємо рядок з користувацького вводу
        if (strcmp(line, ">>\n") == 0) { // якщо рядок починається з >>, то припинити читання вводу
            break;
        }
        if (!first_line) fputc('\n', file); // якщо не перший рядок, то додати символ нового рядка до файлу
        while (line[counter] != '\n') fputc(line[counter++], file); // додати символи рядка до файлу
        counter = 0; // скинути лічильник символів
        first_line = false; // встановити флаг на false
    }
    fclose(file); // закрити файл
}