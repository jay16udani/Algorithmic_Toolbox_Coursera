#include <iostream>
//#include <cstdlib>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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

int main() {
  long long a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << (long long)gcd_fast(a, b) << std::endl;
  //std::cout<<sizeof(int)<<" "<<sizeof(long int)<<" "<<sizeof(long long int)<<std::endl;
  return 0;
}
