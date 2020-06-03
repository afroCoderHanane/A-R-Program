//
// Created by hanane on 6/2/20.
//
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Master
{
    int custId;
    string name;
    double balance;
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
int main() {
    //declares variables to stores the data
      //master
      int id;
      string nme;
      double bal;
      //transaction
    //declare structures

    Master mRecord[5];
    Transaction tRecord[25];
    int i = 0;
    ifstream min,tin;
    min.open("master.txt", ios::in);
    tin.open("transaction.txt", ios::in);
    if(!min)
    {
        cout<<"Error while opening the file"<<endl;
        return 1;
    }
     
    for(int i=0; i<5;i++)
    {
      min>>mRecord[i].custId>>mRecord[i].name>>mRecord[i].balance;
    }
     
    for(int i=0; i<5;i++)
    {
      cout<<mRecord[i].custId<<" "<<mRecord[i].name<<" "<<mRecord[i].balance<<endl;
    }
        
    for(int i=0;i<25;i++)
    {
      tin>>tRecord[i].type;
    }
    
}


