#include <bits/stdc++.h>
using namespace std;

long long quickMul(long long x, long long y, long long mod) {
    if (y==0) return 0;
    return (x*(y&1)+quickMul((x+x)%mod,y>>1,mod))%mod;
}
long long quickPow(long long x, long long y, long long mod) {
    if (y==0) return 1;
    return quickMul((y&1?x:1),quickPow(quickMul(x,x,mod),y>>1,mod),mod);
}

int calculateJacobian(long long a, long long n)
{
    if (!a) return 0;
    int ans = 1;
    if (a < 0){
        a = -a;
        if (n % 4 == 3) ans = -ans;
    }

    if (a == 1) return ans;
    while(a){
        if (a < 0){
            a = -a;
            if (n % 4 == 3) ans = -ans;
        }
        while (a % 2 == 0){
            a = a / 2;
            if (n % 8 == 3 || n % 8 == 5) ans = -ans;
        }
        swap(a, n);
        if (a % 4 == 3 && n % 4 == 3) ans = -ans;
        a = a % n;
        if (a > n / 2) a = a - n;
    }
    if (n == 1) return ans;
    return 0;
}

bool solovoyStrassen(long long p, int iterations)
{
    if (p < 2) return false;
    if (p != 2 && p % 2 == 0) return false;

    for (int i = 0; i < iterations; i++){
        long long a = rand() % (p - 1) + 1;
        long long jacobian = (p + calculateJacobian(a, p)) % p;
        long long mod = quickPow(a, (p - 1) / 2, p);
        if (!jacobian || mod != jacobian) return false;
    }
    return true;
}

int main(){
    long long n;
    cin >> n;
    while(true){
        if (solovoyStrassen(n, 5000)){
            cout << n << endl;
            return 0;
        }
        n++;
    }
    return 0;
}
