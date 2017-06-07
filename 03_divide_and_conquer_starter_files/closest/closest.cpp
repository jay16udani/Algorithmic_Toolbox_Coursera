#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip> 

using std::vector;
using std::min;

double maxi = std::numeric_limits<double>::max();

void print(vector<int> v)
{
  for(int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << std::endl;
}


void merge_vector(vector<int> &left, vector<int> &right, vector<int> &value_per_unit, vector<int> &left_array, vector<int> &right_array, vector<int> &array)
{
   
   value_per_unit.clear();
   array.clear();
   while ((int)(left.size()) > 0 || (int)(right.size()) > 0) {
      if ((int)(left.size()) > 0 && (int)(right.size()) > 0) {
         if ((left.front()) <= (right.front())) {
			
            value_per_unit.push_back((left.front()));
            left.erase(left.begin());
			array.push_back((left_array.front()));
            left_array.erase(left_array.begin());
         } 
   else {
            
			value_per_unit.push_back((right.front()));
            right.erase(right.begin());
			array.push_back((right_array.front()));
            right_array.erase(right_array.begin());
         }
      }  else if ((int)(left.size()) > 0) {
            for (int i = 0; i < (int)(left.size()); i++){
               value_per_unit.push_back(left.at(i));
			   array.push_back(left_array.at(i));
			}
            break;
      }  else if ((int)(right.size()) > 0) {
            for (int i = 0; i < (int)(right.size()); i++){
               value_per_unit.push_back(right.at(i));
			   array.push_back(right_array.at(i));
			}
            break;
      }
   }
   
}

void mergeSort(vector<int> &value_per_unit, vector <int> &array)
{
   
   if (value_per_unit.size() <= 1)
      return;
 
   vector<int> left, right;
   vector<int> left_array, right_array;
   int middle = ((int)value_per_unit.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(value_per_unit.at(i));
	  left_array.push_back(array.at(i));
   }

   for (int i = middle; i < (int)value_per_unit.size(); i++) {
      right.push_back(value_per_unit.at(i));
	  right_array.push_back(array.at(i));
   }
 
   mergeSort(left,left_array);
   mergeSort(right,right_array);
   merge_vector(left, right,value_per_unit,left_array,right_array,array);

}

double calc_distance(vector<int> &x, vector<int> &y)
{
	double result;
	//print(x);
	//print(y);
	//std::cout<<(((x[0])-(x[1]))^2);
	//std::cout<<(((y[0])-(y[1]))^2);
	result = sqrt(pow(((x[0])-(x[1])),2) + pow(((y[0])-(y[1])),2));	
	return result;
}

double closest_partition(vector <int> &a,vector <int> &b,vector <int> &c,vector <int> &d, int n, double deltamin)
{
	double result=maxi,temp;
	vector <int> partition_x;
	vector <int> partition_y;
	
	if(n%2==0)
	{
		n=n/2;
		for(int i=0;i<n;i++)
		{
			if(abs(n-a[i])<deltamin)
			{
				partition_x.push_back(a[i]);
				partition_y.push_back(b[i]);
			}		
		}
		
		for(int i=0;i<n;i++)
		{
			if(abs(n-c[i])<deltamin)
			{
				partition_x.push_back(c[i]);
				partition_y.push_back(d[i]);
			}		
		}		
	}
	
	else
	{
		n=n/2;
		for(int i=0;i<n;i++)
		{
			if(a[i]<deltamin)
			{
				partition_x.push_back(a[i]);
				partition_y.push_back(b[i]);
			}		
		}
		
		for(int i=0;i<n+1;i++)
		{
			if(c[i]<deltamin)
			{
				partition_x.push_back(c[i]);
				partition_y.push_back(d[i]);
			}		
		}
	}
	
	mergeSort(partition_y,partition_x);
	
	//print(partition_x);
	//print(partition_y);
	
	for(int i=0;i<(((int)partition_x.size())-1);i++)
	{
		for(int j=i+1;j<min(6,((int)partition_x.size()));j++)
		{
			temp = sqrt(pow(((partition_x[i])-(partition_x[j])),2) + pow(((partition_y[i])-(partition_y[j])),2));	
			if(temp<result)
				result=temp;
		}
	}	
	return result;
}

double closest_pair(vector<int> &x, vector<int> &y, int n)
{
	double delta12,delta1,delta2,deltamin;
	if(n==1)
		return maxi;
	else if(n==2)
		return calc_distance(x,y);
	else
	{
		vector <int> a(n/2),b(n/2);
		vector <int> c(n/2),d(n/2);
		if(n%2==0)
		{
			
			for(int i=0;i<n/2;i++)
			{
				a[i]=x[i];
				b[i]=y[i];
			}
			
			
			for(int i=0;i<n/2;i++)
			{
				c[i]=x[(n/2)+i];
				d[i]=y[(n/2)+i];
			}
			
			delta1=closest_pair(a,b,n/2);
			delta2=closest_pair(c,d,n/2);
			deltamin=min(delta1,delta2);
			//std::cout<<"Deltamin:"<<deltamin<<std::endl;
			delta12=closest_partition(a,b,c,d,n,deltamin);
		}
		else
		{
			
			for(int i=0;i<n/2;i++)
			{
				a[i]=x[i];
				b[i]=y[i];
			}
			
			c.push_back(0);
			d.push_back(0);
			for(int i=0;i<(n/2)+1;i++)
			{
				c[i]=x[(n/2)+i];
				d[i]=y[(n/2)+i];
			}
			
			delta1=closest_pair(a,b,n/2);
			delta2=closest_pair(c,d,(n/2)+1);
			//std::cout<<"Delta1:"<<delta1<<std::endl;
			//std::cout<<"Delta2:"<<delta2<<std::endl;
			deltamin=min(delta1,delta2);
			//std::cout<<"Deltamin:"<<deltamin<<std::endl;
			delta12=closest_partition(a,b,c,d,n,deltamin);
		}	
		
		deltamin=min(deltamin,delta12);
		return deltamin;
	}
}

double minimal_distance(vector<int> &x, vector<int> &y, int n) {
  
  double delta;
  mergeSort(x,y);
  //print(x);
  //print(y);
  delta = closest_pair(x,y,n);
  
  return delta;
}

int main() {
  //std::cout<<maxi;
  int n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y, n) << "\n";
  return 0;
}
