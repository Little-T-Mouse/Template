#include <bits/stdc++.h>
using namespace std;

#define false 0
#define true 1
typedef unsigned long long LL; int S=4;
LL modular_multi(LL x,LL y,LL mo){
    LL t; x%=mo;
    for(t=0; y; x=(x<<1)%mo,y>>=1)
        if (y&1) t=(t+x)%mo;
    return t;
}
LL modular_exp(LL num,LL t,LL mo){
    LL ret=1,temp=num%mo;
    for(; t; t>>=1,temp=modular_multi(temp,temp,mo))
        if (t&1) ret=modular_multi(ret,temp,mo);
    return ret;
}
int miller_rabbin(LL n)
{
    if (n==2)return true;
    if (n<2||!(n&1))return false;
    int t=0; LL a,x,y,u=n-1;
    while((u&1)==0) t++,u>>=1;
    for(int i=0; i<S; i++){
        a=rand()%(n-1)+1;
        x=modular_exp(a,u,n);
        for(int j=0; j<t; j++){
            y=modular_multi(x,x,n);
            if (y==1&&x!=1&&x!=n-1)
                return false;
            x=y;
        }
        if (x!=1)return false;
    }
    return true;
}
int main(){
    LL n;
    for(scanf("%llu", &n); !miller_rabbin(n); n++);
    printf("%llu\n", n);
}
