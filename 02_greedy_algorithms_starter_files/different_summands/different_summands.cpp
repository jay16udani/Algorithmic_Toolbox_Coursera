#include <iostream>
#include <vector>

using std::vector;

vector<long int> optimal_summands(long int n) {
  vector<long int> summands;
  long int i=1,j,k,temp;
  int existing_number;
  if(n==2 || n==1)
  {
	  summands.push_back(n);
	  return summands;
  }
  else
  {
	  while(1)
	  {
		  existing_number=0;
		  summands.push_back(i);
		  n-=i;
		  if(n==0)
			  break;
		  j=i;
		  j++;
		  temp=n-j;
		  if(temp==j)
			  i=n;
		  else
		  {
			  for(k=0;k<summands.size();k++)
			  {
				  if(summands[k]==temp)
				  {
					  existing_number=1;
					  break;
				  }
			  }
			  if(existing_number)
			  {
				  i=n;
			  }
			  else
				  i++;		  			  
		  }
		  
	  }
  } 
  
  return summands;
}

int main() {
  long int n;
  std::cin >> n;
  vector<long int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (long int i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
  return 0;
}
