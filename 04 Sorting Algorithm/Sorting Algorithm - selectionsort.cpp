void selectionSort(int arr[], int n){
    int minidx=-1;
    for(int i=0; i<n; i++){
        minidx = i;
        for(int j=i+1; j<n; j++){
            if(arr[minidx]>arr[j]) minidx = j;
        }
        int tmp = arr[minidx];
        arr[minidx] = arr[i];
        arr[i] = tmp;
    }
}
void printArray(int intArr[], int n){
    for(int i = 0; i < n; i++){
        cout<<intArr[i] <<" ";
    }
    cout<<endl;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int intArr1[10] = {10,9,8,7,6,5,4,3,2,1};
    int intArr2[10] = {1,2,3,4,5,6,7,8,9,10};
    selectionSort(intArr1,10);
    selectionSort(intArr2,10);
    printArray(intArr1,10);
    printArray(intArr2,10);
    return 0;
}
