#include<iostream>
void call_reference(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
    std::cout<<"Inside values of a: %d and b: %d\n",a,b;
}