// Recursion Version
string DeciToBin(int n, string bin){
    if(n == 0) return bin;
    if(n%2==0) return DeciToBin(n/2, '0'+bin);
    else return DeciToBin(n/2, '1'+bin);
}
