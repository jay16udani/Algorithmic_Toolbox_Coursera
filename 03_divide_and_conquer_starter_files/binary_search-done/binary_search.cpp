#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

long int binary_search(vector<long int> &a, long int x,long int &left,long int &right) {
  long int left_temp = left, right_temp = right;
  long int middle=(left_temp+right_temp)/2;

  if(left>right)
	  return -1;
  else if(a[middle]==x)
	  return middle;
  else if(x<a[middle])
  {
	  right_temp=middle-1;
	  binary_search(a,x,left_temp,right_temp);
  }
  else if(x>a[middle])
  {
	  left_temp=middle+1;
	  binary_search(a,x,left_temp,right_temp);
  }
}

/*int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}*/

int main() {
  long int n;
  long int result;
  long int left=0;
  std::cin >> n;
  vector<long int> a(n);
  for (long int i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long int right=(long int)a.size();
  
  long int m;
  std::cin >> m;
  vector<long int> b(m);
  vector<long int> c;
  for (long int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (long int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
	result=binary_search(a,b[i],left,right);
	c.push_back(result);
  }
  
  for (long int i = 0; i < m; ++i)
  {
	  std::cout<<c[i]<<" ";
  }
  return 0;
}
