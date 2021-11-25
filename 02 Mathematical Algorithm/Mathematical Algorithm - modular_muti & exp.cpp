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
