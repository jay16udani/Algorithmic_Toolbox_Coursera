#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

/*void printf(vector<double> v)
{
  for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}


void print(vector<int> v)
{
  for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}*/

void merge_vector(vector<double> &left, vector<double> &right, vector<double> &value_per_unit, vector<int> &left_array, vector<int> &right_array, vector<int> &array)
{
   //cout<<"in merge\n";
   //printf(value_per_unit);
   value_per_unit.clear();
   array.clear();
   while ((int)(left.size()) > 0 || (int)(right.size()) > 0) {
      if ((int)(left.size()) > 0 && (int)(right.size()) > 0) {
         if ((left.front()) >= (right.front())) {
			 //cout<<"Left array greater\n";
            value_per_unit.push_back((left.front()));
            left.erase(left.begin());
			array.push_back((left_array.front()));
            left_array.erase(left_array.begin());
         } 
   else {
            //cout<<"Right array greater\n";
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

void mergeSort(vector<double> &value_per_unit, vector <int> &array)
{
   //cout<<"in mergesort\n";
   //printf(value_per_unit);
   if (value_per_unit.size() <= 1)
      return;
 
   vector<double> left, right;
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

double get_optimal_value_vector(int capacity, vector <int> &array,vector <double> &value_per_unit) {
  
  double money =0,temp;
 
  if((int)(value_per_unit.size())>1)
  {
	  mergeSort(value_per_unit,array);
	  //cout<<"\nAfter sorting\n";
	  //printf(value_per_unit);
  }
  
  
  while(!((value_per_unit.size()==0) || (capacity==0)))
  {
		temp=std::min(array.at(0),capacity);
		money += temp*value_per_unit.at(0);
		capacity-=temp;
		array.at(0)-=temp;
		if(array.at(0)==0)
		{
			array.erase(array.begin());
			value_per_unit.erase(value_per_unit.begin());
		}
  }
  
  return money;
}

int main() {
  int capacity,value,weight;
  double rate;
  std::cin >> n >> capacity;
  vector<int> array; 		//vector for holding weights of different items
  vector<int> values;		//vector for holding values of different items
  vector<double> value_per_unit;
  for (int i = 0; i < n; i++){
    std::cin >> value >> weight;
	values.push_back(value);
	array.push_back(weight);
	rate=((double)value)/((double)weight);
	//cout<<rate<<"\n";
	value_per_unit.push_back(rate);
	//printf(value_per_unit);
  }
  
  double optimal_value = get_optimal_value_vector(capacity,array,value_per_unit);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
