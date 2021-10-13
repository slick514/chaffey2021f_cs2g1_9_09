//
// Created by justi on 10/13/2021.
//

#ifndef CHAFFEY2021F_CS2G1_9_09_CASHREGISTER_H
#define CHAFFEY2021F_CS2G1_9_09_CASHREGISTER_H


class CashRegister {
public:
    double get_sales_total(){return sales_total;}
    unsigned int get_sales_count(){return salesCount;}
    int reset_sales();
private:
    double sales_total;
    unsigned int salesCount;
};


#endif //CHAFFEY2021F_CS2G1_9_09_CASHREGISTER_H
