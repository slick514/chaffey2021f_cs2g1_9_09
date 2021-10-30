#include <iostream>
#include <string>
#include <iomanip>
#include "cashregistertest.h"
using namespace std;

static const char CHOICE_VIEW_ERR_LOGS = 'E';
static const char CHOICE_VIEW_LOGS = 'L';
static const char CHOICE_DO_REGISTER = 'R';
static const char CHOICE_ADD_ITEM = 'A';
static const char CHOICE_ADD_TAXABLE_ITEM = 'X';
static const char CHOICE_ITEM_COUNT = 'N';
static const char CHOICE_SALE_TOTAL = 'T';
static const char CHOICE_VIEW_SALE = 'V';
static const char CHOICE_CLEAR_SALE = 'C';
static const char CHOICE_RESET_DAILY_SALES = 'R';
static const char CHOICE_VIEW_SALES_TOTAL = 'S';
static const char CHOICE_DAILY_SALES_COUNT = 'D';
static const char CHOICE_QUIT = 'Q';
static const string LINE_SEPARATOR = "\n\r_____________________________\n\r"; //NOLINT

double read_in_double();
void run_use_register();
int run_initial_tests(CashRegisterTest &register_tester);
double get_sales_tax_from_user();
char get_choice_from_user(double *value);
void display_value_missing_err();
char read_in_char_to_upper();
void add_menu_item_and_clear_stream(stringstream &stream, vector<string> &menu_items);
void display_menu_options(const vector<string> &menu_items);
int find_max_width(const vector<string> &strings);
vector<string> build_register_menu_items();
vector<string> build_initial_menu_items(int &num_errors);

/*
 * Course: Chaffey College 2021-Fall CS2
 * Prof: Dr. Tracy Kocher
 * Date: 2021-10-12
 * Project: 9.09 (NINE-NINE!)
 * Coder: Justin Gries
 * Tester(s):
 *
 * Prompt: see "CashRegister.cpp"
 *
 * Main will act as the user interface for the cash-register
 *
 * inputs:
 * outputs:
 */
int main() {
    cout << "Hello 9.09" << endl;
    CashRegisterTest register_tester;

    char choice;
    bool invalid_option;
    int num_errors = run_initial_tests(register_tester);
    cout << endl;

    vector<string> options = build_initial_menu_items(num_errors);
    do {
        invalid_option = false;
        display_menu_options(options);
        choice = read_in_char_to_upper();
        switch(choice){
            case CHOICE_VIEW_LOGS:
                cout << "-------LOGS-------" << endl;
                register_tester.print_logs();
                break;
            case CHOICE_VIEW_ERR_LOGS:
                cout << "-------ERRORS-------" << endl;
                register_tester.print_errors();
                break;
            case CHOICE_DO_REGISTER:{
                cout << "Welcome to your cash register" << endl;
                run_use_register();
                break;
            }
            case CHOICE_QUIT:
                break;
            default: {
                cout << "Your input, '" << choice << "', is not recognized. Please try again." << endl;
                invalid_option = true;
            }
        }
    }while(invalid_option);
    return 0;
}

vector<string> build_initial_menu_items(int &num_errors) {
    vector<string> options;
    stringstream string_builder;
    string_builder << "View (" << CHOICE_VIEW_LOGS << ")og entries";
    add_menu_item_and_clear_stream(string_builder, options);
    if(num_errors > 0) {
        string_builder << "View (" << CHOICE_VIEW_ERR_LOGS << ")rror logs";
        add_menu_item_and_clear_stream(string_builder, options);
    }
    string_builder << "(" << CHOICE_DO_REGISTER << ")un Register";
    add_menu_item_and_clear_stream(string_builder, options);
    string_builder << "(" << CHOICE_QUIT << ")uit";
    add_menu_item_and_clear_stream(string_builder, options);
    return options;
}

int run_initial_tests(CashRegisterTest &register_tester) {

    string value;
    int num_errors = register_tester.run_tests();
    cout << "Running tests... " << (num_errors == 0 ? "PASS" : "FAIL") << endl;
    cout << "The number of logged errors is " << num_errors << endl;
    return num_errors;
}

void run_use_register() {
    string input;
    bool end_loop = false;
    char choice;
    double value;
    double sales_tax;
    string value_str;
    sales_tax = get_sales_tax_from_user();
    CashRegister cr(sales_tax);
    vector<string> menu_items = build_register_menu_items();
    do{
        cout << endl;
        value = 0.0;
        display_menu_options(menu_items);
        choice = get_choice_from_user(&value);
        value_str = (value >=.01) ? (" " + CashRegister::to_money_str(value)) : "";
        cout << endl << "You entered '"<< choice << "'" << value_str << endl;
        switch (choice) {
            case CHOICE_ADD_ITEM: {
                if(value >= 0.01) {
                    cr.add_item(value);
                    cout << "You added " << CashRegister::to_money_str(value) << " to the register" << endl;
                }else{
                    display_value_missing_err();
                }
                break;
            }
            case CHOICE_ADD_TAXABLE_ITEM: {
                if(value >= 0.01) {
                    cr.add_taxable_item(value);
                    cout << "You added " << CashRegister::to_money_str(value) << " (taxable) to the register" << endl;
                }else{
                    display_value_missing_err();
                }
                break;
            }
            case CHOICE_RESET_DAILY_SALES: {
                cr.reset_sales();
                cout << "Daily sales reset" << endl;
                break;
            }
            case CHOICE_DAILY_SALES_COUNT:
                cout << "The number of daily sales is " << cr.get_sales_count() << endl;
                break;
            case CHOICE_VIEW_SALE:
                cr.display_all();
                cout << endl;
                break;
            case CHOICE_SALE_TOTAL:
                cout << "The total for this sale is is " << CashRegister::to_money_str(cr.get_total()) << endl;
                break;
            case CHOICE_ITEM_COUNT:
                cout << "The number of items in this sale is " << cr.get_count() << endl;
                break;
            case CHOICE_CLEAR_SALE:
                cr.clear();
                cout << "Sale has been cleared." << endl;
                break;
            case CHOICE_VIEW_SALES_TOTAL:
                cout << "Daily sales total: " << CashRegister::to_money_str(cr.get_sales_total());
                break;
            case CHOICE_QUIT:
                end_loop = true;
                break;
            default:
                cout << "Your input, '" << choice << "', is not recognized. Please try again." << endl;
        }
    }while(!end_loop);
}

void display_value_missing_err() {
    cout << "A value of at least .01 must be provide when adding an item to the register." << endl;
}

char get_choice_from_user(double *value) {
    string input;
    char choice;
    *value = 0.0;

    choice = read_in_char_to_upper();
    switch (choice) {
        case CHOICE_ADD_ITEM:
        case CHOICE_ADD_TAXABLE_ITEM: {
            cout << "Please enter amount:" << endl;
            double amount = read_in_double();
            *value = amount;
            break;
        }
        default:
            ;
    }

    return choice;
}

vector<string> build_register_menu_items() {
    stringstream stream;
    vector<string> menu_items;
    stream << "(" << CHOICE_ADD_ITEM << ")dd <amount>";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "Add Ta(" << CHOICE_ADD_TAXABLE_ITEM << ")able <amount>";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "Show (" << CHOICE_ITEM_COUNT << ")umber of sale items";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "Show sale (" << CHOICE_SALE_TOTAL << ")otal";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "(" << CHOICE_VIEW_SALE << ")iew sale";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "(" << CHOICE_CLEAR_SALE << ")lear sale";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "View (" << CHOICE_VIEW_SALES_TOTAL << ")um of daily sales";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "Show number of (" << CHOICE_DAILY_SALES_COUNT << ")aily sales";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "(" << CHOICE_RESET_DAILY_SALES << ")eset daily sales";
    add_menu_item_and_clear_stream(stream, menu_items);
    stream << "(" << CHOICE_QUIT << ")uit";
    add_menu_item_and_clear_stream(stream, menu_items);
    return menu_items;
}

double get_sales_tax_from_user() {
    stringstream stream;
    cout << "Please enter the sales tax as xx.xx(%)" << endl;
    cout << "e.g., 8.5% would be entered as '8.5':" << endl;
    double rate;
    do {
        rate = read_in_double();
    }while(rate == 0.0);
    stream << setprecision(2) <<  rate << "%" << " entered" << endl;
    cout << stream.str();
    return rate / 100;
}

double read_in_double(){
    string input;
    char *ptr;
    double output;
    cin >> input;
    output = strtod(input.c_str(), &ptr);
    if(output <= 0.0) {
        cout << "Your entry, '" << input << "' is non-numeric." << endl;
        cout << "Please enter a numerical value: " << endl;
    }
    return output;
}

char read_in_char_to_upper() {
    string input;
    cin >> input;
    return (char)toupper(input[0]);
}

void add_menu_item_and_clear_stream(stringstream &stream, vector<string> &menu_items) {
    menu_items.push_back(stream.str());
    stream.clear();
    stream.str(std::string());
}

void display_menu_options(const vector<string> &menu_items){
    int counter = 0;
    const int num_columns = 3;
    cout << std::left;
    const int field_w = find_max_width(menu_items);
    cout << "OPTIONS" << LINE_SEPARATOR;

    for (const string &item : menu_items){
        bool last = false;
        switch(counter % num_columns){
            case 0:
                cout << "|  " << setw(field_w) <<  item << "  |";
                counter = 0;
                break;
            case 2:
                last = true;
            case 1:
            default: {
                cout << "  " << setw(field_w) << item << "  |";
                if(last){
                    cout << endl;
                }
            }
        }
        counter ++;
    }
    cout << endl;
}

int find_max_width(const vector<string> &strings) {
    int max_w = 0;
    for(const string &s: strings){
        if(s.length() > max_w) max_w = (int)(s.length());
    }
    return max_w;
}






