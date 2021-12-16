// 1
int binarySearch(int arr[], int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (condition) return m;
        if (condition_2) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
// 2
while(l<=r){
     mid = (l+r)/2;
     if(condition){
       r = mid-1;
     }else{
       l = mid+1;
     }
}
// 3
while(l<r){
      mid = (l+r)/2;
      if(condition)r=mid;
      else l = mid+1;
}
