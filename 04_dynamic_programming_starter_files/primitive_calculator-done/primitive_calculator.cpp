#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

vector <int> dp_sequence(int n)
{
	vector <int> numbers;
	vector <int> no_operations;
	vector <int> sequence;
	int temp1,temp2,temp3;
	if(n==1)
	{
		numbers.push_back(1);
		no_operations.push_back(0);
	}
	else
	{
		for(int i=0;i<n;i++)
			numbers.push_back(i+1);
		
		no_operations.push_back(0);
		
		for(int i=1;i<n;i++)
		{
			if((i+1)%6==0)
				no_operations.push_back(min({(no_operations[i-1]+1),(no_operations[i/3]+1),(no_operations[i/2]+1)}));				
			else if((i+1)%3==0)
				no_operations.push_back(min((no_operations[i-1]+1),(no_operations[i/3]+1)));				
			else if((i+1)%2==0)
				no_operations.push_back(min((no_operations[i-1]+1),(no_operations[i/2]+1)));							
			else
				no_operations.push_back(no_operations[i-1]+1);
		}		
	}
	
		if(n==1)
		{
			sequence.push_back(1);
			return sequence;
		}
		sequence.push_back(n);
		while(n!=1)
		{
			{
				if(n%6==0)
				{
					temp1=no_operations[(n/3)-1];
					temp2=no_operations[n-2];
					temp3=no_operations[(n/2)-1];
					if(temp1<=temp2 && temp1<=temp3)
					{
						sequence.push_back(numbers[(n/3)-1]);
						n=n/3;
					}
					else if(temp2<=temp1 && temp2<=temp3)
					{
						sequence.push_back(numbers[n-2]);
						n-=1;
					}
					else if(temp3<=temp1 && temp3<=temp2)
					{
						sequence.push_back(numbers[(n/2)-1]);
						//sequence.push_back(numbers[n-2]);
						n=n/2;
					}
				}
				
				else if(n%3==0)
				{
					temp1=no_operations[(n/3)-1];
					temp2=no_operations[n-2];
					if(temp2>temp1)
					{
						sequence.push_back(numbers[(n/3)-1]);
						n=n/3;
					}
					else if(temp1>temp2)
					{
						sequence.push_back(numbers[n-2]);
						n-=1;
					}
					else
					{
						sequence.push_back(numbers[n-2]);
						n-=1;
					}
				}

				else if(n%2==0)
				{
					temp1=no_operations[(n/2) -1];
					temp2=no_operations[n-2];
					if(temp2>temp1)
					{
						sequence.push_back(numbers[(n/2) -1]);
						n=n/2;
					}
					else if(temp1>temp2)
					{
						sequence.push_back(numbers[n-2]);
						n-=1;
					}
					else
					{
						sequence.push_back(numbers[n-2]);
						n-=1;
					}
				}
				
				else
				{
					sequence.push_back(numbers[n-2]);
					n-=1;
				}
			}
		}
	
	return sequence;	
}


int main() {
  int n;
  std::cin >> n;
  
	  vector<int> sequence = dp_sequence(n);
	  
		  std::cout << (int)sequence.size() -1 << std::endl;
		  
		for (size_t i = 0; i < sequence.size(); ++i)
			std::cout << sequence[sequence.size()-1-i] << " ";
		
	  return 0;
}