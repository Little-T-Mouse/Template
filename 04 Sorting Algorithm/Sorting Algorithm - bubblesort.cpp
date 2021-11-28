void bubbleSort(int arr[], int n){
    bool swapped = false;
    for(int i=0; i<n-1; i++){
        swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swapped = true;
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        if(!swapped) break;
    }
}
void printArray(int intArr[], int n){
    for(int i = 0; i < n; i++){
        cout<<intArr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int intArr1[10] = {10,9,8,7,6,5,4,3,2,1};
    int intArr2[10] = {1,2,3,4,5,6,7,8,9,10};
    bubbleSort(intArr1,10);
    bubbleSort(intArr2,10);
    printArray(intArr1,10);
    printArray(intArr2,10);
    return 0;
}
