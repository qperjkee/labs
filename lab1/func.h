#pragma once
#include <string>

using namespace std;

int line_length(string);
int line_length(const char*);

void file_sort(const string&, const string&);
void file_sort(const char*, const char*);

void file_create(string);
void file_create(const char*);

void file_output(string);
void file_output(const char*);

void file_append(string);
void file_append(const char*);