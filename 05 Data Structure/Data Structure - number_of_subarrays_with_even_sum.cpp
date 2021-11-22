#include <iostream>
using namespace std;
 
long long cntEvenSum(int a[], int n){
    int s = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] % 2 == 1){
            s = n - i - 1 - s;
        }
        else{
            s = s + 1;
        }
        res = res + s;
    }
    return res;
}
 
int main(){
    int arr[] = { 1, 2, 2, 3, 4, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The Number of Subarrays with even sum is " << cntEvenSum(arr, n);
    return 0;
}
