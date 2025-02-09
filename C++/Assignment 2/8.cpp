//Write a C++ program to implement a class called Date that has private member variables for day, month, and year. Include member functions to set and get these variables, as well as to validate if the date is valid

#include<iostream>
using namespace std;
class Date{
    int day, month, year;
public:
    void input(){
        cin>>day>>month>>year;
    }
    void display(){
        if(year%4==0 && year%100!=0 || year%400==0){
            if(month==1){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
            else if(month==2){
                if(day>=1 && day<=29){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==3){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==4){
                if(day>=1 && day<=30){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==5){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==6){
                if(day>=1 && day<=30){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==7){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==8){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==9){
                if(day>=1 && day<=30){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==10){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==11){
                if(day>=1 && day<=30){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==12){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
        }
        else{
            if(month==1){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
            else if(month==2){
                if(day>=1 && day<=28){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==3){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==4){
                if(day>=1 && day<=30){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==5){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==6){
                if(day>=1 && day<=30){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==7){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==8){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==9){
                if(day>=1 && day<=30){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==10){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==11){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
                else if(month==12){
                if(day>=1 && day<=31){
                    cout<<"Valid"<<endl;
                }
                else{
                    cout<<"Invalid";
                }
            }
        }
    }
};

int main(){
    Date d;
    d.input();
    d.display();
}