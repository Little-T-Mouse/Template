// GCD and LCM
#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b){
    return __gcd(a,b);
}
int LCM(int a, int b){
    return a*b/GCD(a,b);
}
