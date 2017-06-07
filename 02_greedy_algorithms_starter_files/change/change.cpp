#include <iostream>

int get_change(int m) {
  int n=0,temp;
  while(m!=0)
  {
	  if(10<=m)
		  m-=10;
	  else if(5<=m)
		  m-=5;
	  else
		  m-=1;
	  n++;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  return 0;
}
