#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::swap;

void print(vector<int> v)
{
  for(int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << std::endl;
}

void partition2(vector<int> &a, int l, int r, int &i, int &j) {
  int k;
  int middle=(l+r)/2;
  
  /*Selecting pivot as median of low, high and middle*/
  if(((a[l]<=a[middle]) && (a[middle]<=a[r])) || ((a[r]<=a[middle]) && (a[middle]<=a[l])))
	  k=middle;
  else if(((a[middle]<=a[l]) && (a[l]<=a[r])) || ((a[r]<=a[l]) && (a[l]<=a[middle])))
	  k=l;
  else if(((a[middle]<=a[r]) && (a[r]<=a[l])) || ((a[l]<=a[r]) && (a[r]<=a[middle])))
	  k=r;
  
  swap(a[l], a[k]);
  print(a);
  
  int low_value = a[l];
  int index_low = l;
  int index_high = l;
  int counter=l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < low_value) {
      swap(a[i], a[index_low]);
	  counter++;
	  low_value=a[l];
    }
	else if(a[i]==low_value)
	{
		index_high++;
		swap(a[i], a[index_high]);		
	}
	print(a);
  }
  
  i=counter;
  j=index_high;
  std::cout<<i<<" "<<j<<std::endl;
  //swap(a[l], a[j]);
  //return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  
  int i,j;
  partition2(a, l, r, i, j);

  randomized_quick_sort(a, l, i-1);
  randomized_quick_sort(a, j+1, r);
}

/*****************************************************************************************/
void merge_vector(vector<int> &left, vector<int> &right, vector<int> &a_b)
{
   //cout<<"in merge\n";
   //printf(a_b);
   a_b.clear();
   while ((int)(left.size()) > 0 || (int)(right.size()) > 0) {
      if ((int)(left.size()) > 0 && (int)(right.size()) > 0) {
         if ((left.front()) <= (right.front())) {
			 //cout<<"Left array greater\n";
            a_b.push_back((left.front()));
            left.erase(left.begin());
         } 
   else {
            //cout<<"Right array greater\n";
			a_b.push_back((right.front()));
            right.erase(right.begin());
        }
      }  else if ((int)(left.size()) > 0) {
            for (int i = 0; i < (int)(left.size()); i++){
               a_b.push_back(left.at(i));
			}
            break;
      }  else if ((int)(right.size()) > 0) {
            for (int i = 0; i < (int)(right.size()); i++){
               a_b.push_back(right.at(i));
			}
            break;
      }
   }
}

void mergeSort(vector<int> &a_b)
{
   //cout<<"in mergesort\n";
   //printf(a_b);
   if (a_b.size() <= 1)
      return;
 
   vector<int> left, right;
   
   int middle = ((int)a_b.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(a_b.at(i));
   }

   for (int i = middle; i < (int)a_b.size(); i++) {
      right.push_back(a_b.at(i));
   }
 
   mergeSort(left);
   mergeSort(right);
   merge_vector(left,right,a_b);
}
/*******************************************************************************************/

int main() {
  int n;
  std::cin >> n;
  //while(1){
  //n=100+rand()%99999;
  //std::cout<<n<<std::endl;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
	//a[i]=1+rand()%99999999;
  }
  //randomized_quick_sort(a, 0, a.size() - 1);
  mergeSort(a);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  //std::cout<<"Pass\n";  
  //}
  return 0;
}
