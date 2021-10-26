#include <iostream>
#include <string>
#include "CashRegister.h"
#include "cashregistertest.h"

void get_tax_rate(double rate);

using namespace std;


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
int main(int argc, char **argv) {
    cout << "Hello 9.09" << endl;
    CashRegisterTest tester;
    tester.run_tests();
    tester.print_errors();
    return 0;
}

void get_tax_rate(double &rate) {

}






