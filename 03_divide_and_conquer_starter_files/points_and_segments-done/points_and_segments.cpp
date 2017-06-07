#include <iostream>
#include <vector>

using std::vector;

/////////////////////////////////////////////////////////////////////////////////////////////
void merge_vector_single(vector<int> &left, vector<int> &right, vector<int> &value_per_unit)
{
   value_per_unit.clear();
 
   while ((int)(left.size()) > 0 || (int)(right.size()) > 0) {
      if ((int)(left.size()) > 0 && (int)(right.size()) > 0) {
         if ((left.front()) <= (right.front())) {
			 
            value_per_unit.push_back((left.front()));
            left.erase(left.begin());
			
         } 
   else {
            
			value_per_unit.push_back((right.front()));
            right.erase(right.begin());
			
         }
      }  else if ((int)(left.size()) > 0) {
            for (int i = 0; i < (int)(left.size()); i++){
               value_per_unit.push_back(left.at(i));
			   
			}
            break;
      }  else if ((int)(right.size()) > 0) {
            for (int i = 0; i < (int)(right.size()); i++){
               value_per_unit.push_back(right.at(i));
			   
			}
            break;
      }
   }
   
}

void mergeSort_single(vector<int> &value_per_unit)
{
   
   if (value_per_unit.size() <= 1)
      return;
 
   vector<int> left, right;
   
   int middle = ((int)value_per_unit.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(value_per_unit.at(i));
	  
   }

   for (int i = middle; i < (int)value_per_unit.size(); i++) {
      right.push_back(value_per_unit.at(i));
	  
   }
 
   mergeSort_single(left);
   mergeSort_single(right);
   merge_vector_single(left, right,value_per_unit);

}

////////////////////////////////////////////////////////////////////////////////////////////

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


void fast_count_segments(vector<int> &starts, vector<int> &ends, vector<int> &points, vector <int> &cnt)
{
	mergeSort(starts,ends);
	mergeSort_single(points);
	
	int j=0;
	while(((int)starts.size())!=0)
	{
		if(points[j]>=starts[0])
		{
			for(int i=j;i<((int)points.size());i++)
			{
				if(points[i]<=ends[0])
				{
					cnt[i]+=1;
				}
				else
					break;
			}
			
			starts.erase(starts.begin());
			ends.erase(ends.begin());
			
		}
		else
		{
			j++;			
		}			
	}		
}

int binary_search(vector<int> &a, int x,int &left,int &right) {
  int left_temp = left, right_temp = right;
  int middle=(left_temp+right_temp)/2;

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


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (int i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  vector<int> temp(m);
  for (int i = 0; i < points.size(); i++) {
    std::cin >> points[i];
	temp[i]=points[i];
  }
  
  vector <int> cnt(m);
  for (int i = 0; i < cnt.size(); i++) {
    cnt[i]=0;
  }
  
  int left=0;
  int right=cnt.size();
  int result;
  
  fast_count_segments(starts,ends,points,cnt);
  
  for (int i = 0; i < cnt.size(); i++) {
    result=binary_search(points,temp[i],left,right);
	std::cout << cnt[result] << ' ';
  }
  return 0;
}
