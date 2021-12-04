bool Miller_Rabin(unsigned long long n)
{
	unsigned long long time =2;
	if(n < 2) return false;
	if(n == 2) return true;
	bool flag = false;
	for(unsigned long long k = 0;k <= time;++k)
	{
		flag = false;
		unsigned long long d = n - 1,r = 0,t,a = rand()%(n-2) + 2;
		while((d & 1) == 0)
		{
			d = d>>1;
			r++;
		}
		t = Modular_exponent(a,d,n);
		if(t == 1 || t == n-1) {flag = true;continue;}
		for(unsigned long long i = 1;i < r;i++)
		{
			t = multi(t,t,n);
			if(t == 1) {flag = false;return  flag;}
			if(t == n-1) {flag = true;break;}
		}
		if(!flag) break;
	}
	return flag;
}
