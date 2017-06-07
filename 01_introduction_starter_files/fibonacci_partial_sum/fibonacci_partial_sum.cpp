#include <iostream>
#include <vector>
#include <cstdlib>
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/*int fibonacci_sum_fast(long long n)
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
	
	
}*/

int get_fibonacci_last_digit_fast(long long n)
{
	n=n%60;
	short int fib_array[2];
	//std::vector <char> fib_array;
	fib_array[0]=0;
	fib_array[1]=1;
	int j=0;
	for(int i=2;i<n+1;i++)
	{
		fib_array[j]=(fib_array[0]+fib_array[1])%10;
		//std::cout<<fib_array[0]<<" "<<fib_array[1]<<"\n";
		if(j==0)
			j=1;
		else
			j=0;
	}
	
	if(n%2==0)	
		return fib_array[0];
	else
		return fib_array[1];
}



int get_fibonacci_partial_sum_fast(long long from, long long to)
{
	if(from==to)
		return (get_fibonacci_last_digit_fast(from));
	else
	{
		int n,m,value;
		m=get_fibonacci_last_digit_fast(from+1);
		n=get_fibonacci_last_digit_fast(to+2);
		value=n-m;
		if(value<0)
			value=10+value;
		return value;
	}
	
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //to=10;
	//int i=1;
	//while(i){
	//from=rand()%9+1;
	//std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
	std::cout << get_fibonacci_partial_sum_fast(from, to) << "\n";
	/*if(get_fibonacci_partial_sum_naive(from, to)!=get_fibonacci_partial_sum_fast(from, to))
	{
		std::cout<<"FROM: "<<from<<" TO: "<<to<<"\n";
		std::cout<<"NO MATCH\n";
		std::cout<<"FAST: "<<get_fibonacci_partial_sum_fast(from,to)<<"\n";
		std::cout<<"SLOW: "<<get_fibonacci_partial_sum_naive(from,to)<<"\n";
		i=0;
	}
	}*/
	return 0;
}
