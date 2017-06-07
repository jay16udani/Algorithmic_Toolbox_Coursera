#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> &a)
{
  string result;
  string max_final,x,y;
  int index;
  char max;
  std::stringstream ss;
  while(a.size()!=0)
  {
	  max=a[0][0];
	  max_final=a[0];
	  //std::cout<<max<<std::endl;
	  index=0;
	  for(int i=1;i<a.size();i++)
	  {
		  if((max<a[i][0]))
		  {
			  max=a[i][0];
			  index=i;
			  max_final=a[i];
		  }
		  else if((max==a[i][0]))
		  {
			  x=max_final+a[i];
			  y=a[i]+max_final;
			  if((y.compare(x))>0)
			  {
				max=a[i][0];
				max_final=a[i];
				index=i;
			  }
		  }
	  }
	  a.erase(a.begin()+index);
	  result+=max_final;
  }
  
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
  return 0;
}
