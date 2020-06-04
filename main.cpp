//
// Created by hanane on 6/2/20.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include"Structures/MasterData.cpp"
using namespace std;


int main() {
    
    //declares variabes 
    int index = 0;
    int j = 0;
    //declare structures
    
    Master mRecord[5];
    Transaction tRecord[25];
    
    
    

    ifstream min,tin;
    min.open("Data/master.txt", ios::in);
    tin.open("Data/transaction.txt", ios::in);

    ofstream fout;
    fout.open("Receipt/receipt.txt", ios::out);
    
    if(!min)
    {
        cout<<"Error while opening the file"<<endl;
        return 1;
    }
    //Get the value and store them in struct array 
    for(int i=0; i<5;i++)
    {
      min>>mRecord[i].custId>>mRecord[i].name>>mRecord[i].balance;
      mRecord[i].index = i;
      
      mRecord[i].finalBal=mRecord[i].balance;
    }
     
    //read from the transaction text 
      
    for(int i=0;i<25;i++)
    { 
      tin>>tRecord[i].type;
      if(tRecord[i].type=='P')
      {
         tin>>tRecord[i].custId>>tRecord[i].orderId>>tRecord[i].amountpay;

         if(tRecord[i].custId==mRecord[index].custId)
         {
            mRecord[index].finalBal-= tRecord[i].amountpay;
         }
         else
          index++;
      }
      else if(tRecord[i].type=='O')
      {
         tin>>tRecord[i].custId>>tRecord[i].orderId>>tRecord[i].orderName>>tRecord[i].qty>> tRecord[i].orderprice;

         if(tRecord[i].custId==mRecord[index].custId)
         {
            mRecord[index].finalBal+= tRecord[i].orderprice*tRecord[i].qty;
         }
         else
          index++;
      }
      
    }
    
   
    //print the record 
    
    for(int i=0; i<5;i++)
    { 
       fout<<  "*************************************************************"<<endl
          <<setw(50)<<  "ABC Company-A/R program version 1.0 "<<setw(30)<<endl
          <<"*************************************************************"<<endl;
      fout<< mRecord[i].name<<" "<<mRecord[i].custId<<endl
      <<setw(30)<<"Previous Balance"<<setw(10)<<"$"<<mRecord[i].balance
      <<endl;

      while(mRecord[i].custId==tRecord[j].custId)
      {
        if(tRecord[j].type=='P')
           fout<<tRecord[j].orderId<<setw(15)<<"Payment"<<setw(25)<<"$"<<tRecord[j].amountpay<<endl;
        else if(tRecord[j].type=='O')
        {
          fout<<tRecord[j].orderId<<setw(15)<<tRecord[j].orderName<<setw(25)<<"$"<<tRecord[j].orderprice<<endl;
        }
        j++;
      }
     fout<<endl;
     fout<<setw(30)<<" Balance Due"<<setw(10)<<"$"<<mRecord[i].finalBal
      <<endl;
    }
      
  fout.close();
  min.close();
  tin.close();
  ofstream mout;
  mout.open("Data/master.txt", ios::out);
  
          
   for(int i=0; i<5;i++)
    { 
      
      mout<<mRecord[i].custId<<setw(10)<<mRecord[i].name<<setw(10)<<mRecord[i].finalBal<<endl;
    }
  mout.close();
  cout<<"Processed Successfully, exit with code '0'"<<endl;
   return 0; 
}


