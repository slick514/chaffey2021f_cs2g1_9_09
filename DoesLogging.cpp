//
// Created by Justin Gries on 10/27/2021.
//

#include <iostream>
#include <sstream>
#include "DoesLogging.h"

using namespace std;

void DoesLogging::print_logs() const {
    if (this->logs.empty()) cout << "No Logs Found" << endl;
    for (auto &str : this->logs)
        cout << str << endl;
}

void DoesLogging::print_errors() const {
    if (this->error_logs.empty()) cout << "No Error Logs Found" << endl;
    for (auto &str : this->error_logs)
        cout << str << endl;
}

void DoesLogging::put_log(const string &test_description, bool b_passes) {
    std::ostringstream stream;
    stream << test_description << ": " << (b_passes ? "PASS" : "FAIL");
    this->logs.push_back(stream.str());
    if (!b_passes) this->error_logs.push_back(stream.str());
}

void DoesLogging::compound(const DoesLogging &from_logs) {
    merge_vectors(this->logs, from_logs.logs);
    merge_vectors(this->error_logs, from_logs.error_logs);
}

void DoesLogging::merge_vectors(vector<std::string> &to, const vector<std::string> &from){
    to.insert(std::end(to), std::begin(from), std::end(from));
}
