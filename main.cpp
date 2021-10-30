#include <iostream>
#include <string>
#include "CashRegister.h"
#include "cashregistertest.h"
using namespace std;

const char CHOICE_VIEW_ERR_LOGS = 'E';
const char CHOICE_VIEW_LOGS = 'L';

char evaluate_choice(const string &str);

/*


 * get total tax_cents (sale)
 * get (daily) sales total
 * get sales count

 */

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
    string choice;
    CashRegisterTest test_register;
    int num_errors = test_register.run_tests();
    cout << "Test " << (num_errors == 0 ? "PASSES" : "FAILS") << endl;
    cout << "The number of logged errors is " << num_errors << endl;
    cout << "Enter '" << CHOICE_VIEW_LOGS << "' to view logs, ";
    cout << "'" << CHOICE_VIEW_ERR_LOGS << "' to view error-logs, " ;
    cout << "or any other key to exit: ";
    cin >> choice;
    switch(evaluate_choice(choice)){
        case CHOICE_VIEW_LOGS:
            cout << "____LOGS____" << endl;
            test_register.print_logs();
            break;
        case CHOICE_VIEW_ERR_LOGS:
            cout << "____ERRORS____" << endl;
            test_register.print_errors();
            break;
        default:
            ;
    }
    return 0;
}

char evaluate_choice(const string &str) {
    char choice = ' ';
    if(!str.empty()){
        char first_char = str[0];
        first_char =(char)toupper(first_char);
        if (first_char == CHOICE_VIEW_LOGS) choice = CHOICE_VIEW_LOGS;
        else if (first_char == CHOICE_VIEW_ERR_LOGS) choice = CHOICE_VIEW_ERR_LOGS;
    }
    return choice;
}






