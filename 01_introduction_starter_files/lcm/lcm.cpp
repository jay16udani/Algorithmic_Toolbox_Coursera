#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long int gcd_fast(long long a,long long b)
{
	//std::cout<<a<<" "<<b<<"\n"<<std::endl;
	if(a==1 || b==1)
		return 1;
	else if(b==0)
		return a;
	else if(a==0)
		return b;
	if(a>b)
		return (long long)gcd_fast(a%b,b);
	else 
		return (long long)gcd_fast(a,b%a);
}


long long lcm_fast(long long a,long long b)
{
	long long gcd=(long long)gcd_fast(a,b);
	long long product = a*b;
	return (long long)(product/gcd);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
