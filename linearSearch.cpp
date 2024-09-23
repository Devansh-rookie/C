#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 4, 4, 1 ,7, 8};
    int key = 2;
    bool flag = true;
    for(int i=0;i < 6;i++){
        if(key == arr[i]){
            cout << "Key found at index : "<< i<<endl;
            flag = false;
        }
    }
    if(flag) cout<< "Key not found" << endl;
   return 0;
}