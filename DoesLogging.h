//
// Created by Justin Gries on 10/27/2021.
//

#ifndef CHAFFEY2021F_CS2G1_9_09_DOESLOGGING_H
#define CHAFFEY2021F_CS2G1_9_09_DOESLOGGING_H


#include <vector>
#include <string>

class DoesLogging {
public:
    void print_logs() const;
    void print_errors() const;
    void put_log(const std::string &test_description, bool b_passes);
    void compound(const DoesLogging &from_logs);
private:
    std::vector<std::string> error_logs;
    std::vector<std::string> logs;
};

static void merge_vectors(std::vector<std::string> &to, const std::vector<std::string> &from);

#endif //CHAFFEY2021F_CS2G1_9_09_DOESLOGGING_H
