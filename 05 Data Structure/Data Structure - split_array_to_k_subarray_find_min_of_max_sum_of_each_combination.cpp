// Approch: Binary Search
/*
Split the given array into K sub-arrays such that maximum sum of all sub arrays is minimum.
*/

#include <bits/stdc++.h>
using namespace std;
 
bool check(int mid, int array[], int n, int K){
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] > mid)
            return false;
        sum += array[i];
        if (sum > mid) {
            count++;
            sum = array[i];
        }
    }
    count++;
    if (count <= K)
        return true;
    return false;
}

int solve(int array[], int n, int K){
    int* max = max_element(array, array + n);
    int start = *max;
    int end = 0;
 
    for (int i = 0; i < n; i++) {
        end += array[i];
    }
    int answer = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (check(mid, array, n, K)) {
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
 
    return answer;
}

int main(){
    int array[] = { 1, 2, 3, 4 };
    int n = sizeof(array) / sizeof(array[0]);
    int K = 3;
    cout << solve(array, n, K);
}

// Note: From https://www.geeksforgeeks.org/split-the-given-array-into-k-sub-arrays-such-that-maximum-sum-of-all-sub-arrays-is-minimum/
