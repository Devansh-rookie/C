#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 1, 5, 67, 7, 87,5 ,353,45};
    int n = 9;
    int i, j;
    for(i = 1;i < n;i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i=0;i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}