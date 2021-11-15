bool isprime(int a){ // Check if number is prime
    if(a<2) return false;
    else if(a==2) return true;
    for(int i=2; i<sqrt(a); i++){
        if(a%i==0) return false;
    }
    return true;
}
