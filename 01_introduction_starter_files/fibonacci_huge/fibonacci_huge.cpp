#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_fibonacci_huge_fast(long long n,long long m)
{
	if(n>1 && (m%10!=0)){
	std::vector <int> mod_array;
	mod_array.push_back(0);
	mod_array.push_back(1);
	int c=1,mod_index=2,i=0,index,period;
	while(c)
	{
		mod_array.push_back((mod_array[mod_index-1] + mod_array[mod_index-2]) % m);
		if(mod_array[mod_index]==mod_array[i])
		{
			if(i==0)
				index=mod_index;
			++mod_index;
			++i;
			if(i==index)
			{
				c=0;
				period=index;
			}
		}
		else
		{
			++mod_index;
			i=0;			
		}
	}
	n=n%period;
	//std::cout<<n<<"\n";
	int array[n+1];
	array[0]=0;
	array[1]=1;
	for(int i=2;i<n+1;i++)
		array[i]=((array[i-1]+ array[i-2])%m);
	
	return array[n];
	}
	
	else if(n>1 && (m%10==0))
	{
		int period;
		if(m==10)
			period=60;
		else if(m==100)
			period=300;
		else
			period=15*(m/10);
		
		n=n%period;
		//std::cout<<n<<"\n";
		int array[n+1];
		array[0]=0;
		array[1]=1;
		for(int i=2;i<n+1;i++)
			array[i]=((array[i-1]+ array[i-2])%m);
		//std::cout<<array[n]<<"\n";
		return array[n];
	}
	else 
		return 1;
}

int main() {
    long long n, m;
	
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
	return 0;
}
