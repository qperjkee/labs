#pragma once

using namespace std;

void file_create(string filename);
void read_file(string filename);
bool check_date(string date);
bool compare_dates(string date1,string date2);
char is_year_leap(int year);
void add_new_products(string filename);
int calculate_days_till_expiration(string dateOfManufacture, string expirationDate);
void adjust_prices(string filename);
void copy_products_before_current_month(const string& input_filename, const string& output_filename);