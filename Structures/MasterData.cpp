//#pragma once
#include<iostream>


using namespace std;

struct Master
{   
    int index;
    int custId;
    string name;
    double balance;
    double finalBal;
};
struct Transaction
{
    int custId;
    int qty;
    double orderprice;
    double amountpay;
    char type;
    string orderName;
    int orderId;

};
