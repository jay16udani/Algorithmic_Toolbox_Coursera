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



int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

int main() {
  int n,counter,prev_element,current_element;
  bool result=false;
  std::cin >> n;
  vector<int> a(n);
  
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  mergeSort(a);
  
  /*for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i];
  }*/
  if(a[0]==a[n-1])
	  result=true;
  else{
  prev_element=a[0];
  counter=1;
  for(int i=1;i<n;i++)
  {
	  current_element=a[i];
	  if(current_element>prev_element)
	  {
		  if(counter<=(n/2))
		  {
			  counter=1;
			  prev_element=a[i];
		  }
		  else
		  {
			  result=true;
			  //break;
		  }
	  }
	  else
	  {
		  counter++;
		  prev_element=a[i];
	  }
	  if(result==true)
		  break;
  }
  if(counter>(n/2))
	  result=true;
  }
  std::cout << result<<std::endl;
  return 0;
}
