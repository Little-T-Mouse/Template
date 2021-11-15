import static java.lang.Math.*;
public boolean isprime(int a) {
	if(a < 2) return false;
	if(a == 2) return true;
	for(int i=0; i<Math.sqrt(a); i++) {
	        if(a%i==0) return false;
	}
	return true;
}
