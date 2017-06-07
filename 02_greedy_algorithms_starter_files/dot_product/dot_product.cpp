#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void merge_vector(vector<int> &left, vector<int> &right, vector<int> &a_b)
{
   //cout<<"in merge\n";
   //printf(a_b);
   a_b.clear();
   while ((int)(left.size()) > 0 || (int)(right.size()) > 0) {
      if ((int)(left.size()) > 0 && (int)(right.size()) > 0) {
         if ((left.front()) >= (right.front())) {
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



long long max_dot_product(vector<int> &a, vector<int> &b) {
  // write your code here
  mergeSort(a);
  mergeSort(b);
  
  long long result = 0;
  while(a.size()!=0)
  {
    result += ((long long) a[0]) * b[0];
	a.erase(a.begin());
	b.erase(b.begin());
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
  return 0;
}
