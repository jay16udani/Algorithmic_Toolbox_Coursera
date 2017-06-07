#include <iostream>
//#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;	
	else
	{
		n=n % 60;
		int array[n+3];
		array[0]=0;
		array[1]=1;
		for(int i=2;i<n+3;i++)
			array[i]=((array[i-1]+ array[i-2])%10);
		if(array[n+2]==0)
			return 9;
		else
			return ((array[n+2])-1);
	}
	
	
}


int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
	std::cout << fibonacci_sum_fast(n);
	return 0;
}
