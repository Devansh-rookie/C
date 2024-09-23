#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 5 , 6, 8, 10, 100, 500};
    int key = 10;
    int n = 7;
    int high = n;
    int low = 0;
    int mid;
    int flag = true;
    while(high >= low){
        mid = low + (high - low)/2;
        if(arr[mid] == key){
            cout << "Key found at : "<< mid<< endl;
            flag = false;
            break;
        }
        else if(arr[mid] < key) low = mid+1;
        else high = mid - 1;
    }
    if(flag) cout << "Key not Found" << endl;
    return 0;
}