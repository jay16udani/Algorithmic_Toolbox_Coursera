#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<long int> v)
{
  for(long int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}

vector<long int> optimal_points(vector<long int> &a,vector<long int> &b) {
  vector<long int> points;
  long int temp_min;
  long int index;
  long int size;
  
  if(a.size()==1)
  {
	  points.push_back(b[0]);
  }
  else
  {
	while(a.size()!=0)
	{
		//find minimum right end point
		temp_min=b[0];
		index=0;
		size=a.size();
		for(long int i=1;i<b.size();i++)
		{
			if(b[i]<temp_min)
			{
				temp_min=b[i];
				index=i;
			}
		}
		//insert that element into result vector
		points.push_back(b[index]);
		
		//delete that entry corresponding to that index
		a.erase(a.begin()+index);
		b.erase(b.begin()+index);
		size-=1;
		
		//find all the left points smaller or equal to that min value and delete those entries
		for(long int j=0;j<size;)
		{
			if(a[j]<=temp_min)
			{
				a.erase(a.begin()+j);
				b.erase(b.begin()+j);
				size-=1;
			}
			else
				j++;
		}		
	}  
  }
  	  
  return points;
}

int main() {
  int n;
  long int numbers,times;
  std::cin >> n;
  vector<long int> a;
  vector<long int> b;
  for (long int i = 0; i < n; ++i) {
    std::cin >> numbers >> times;
	a.push_back(numbers);
	b.push_back(times);
  }
  vector<long int> points = optimal_points(a,b);
  std::cout << points.size() << "\n";
  for (long int j = 0; j < points.size(); ++j) {
    std::cout << points[j] << " ";
  }
  return 0;
}
