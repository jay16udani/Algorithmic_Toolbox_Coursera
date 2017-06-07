#include <iostream>
#include <vector>
#include <cstdlib>
using std::vector;

long int count=0;
//int count_simple=0;

void merge_vector(vector<int> &left, vector<int> &right, vector<int> &a_b)
{
   //cout<<"in merge\n";
   //printf(a_b);
   a_b.clear();
   while ((int)(left.size()) > 0 || (int)(right.size()) > 0) {
      if ((int)(left.size()) > 0 && (int)(right.size()) > 0) {
         if ((left.front()) <= (right.front())) {
			 //cout<<"Left array smaller\n";
            a_b.push_back((left.front()));
            left.erase(left.begin());
         } 
   else {
            //cout<<"Right array smaller\n";
			a_b.push_back((right.front()));
            count+=((int)left.size());
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

/*void getInvCount(vector<int> &arr)
{
  int inv_count = 0;
  for (int i = 0; i < ((int)arr.size()) - 1; i++)
    for (int j = i+1; j < ((int)arr.size()); j++)
      if (arr[i] > arr[j])
        count_simple++;
}*/

int main() {
  int n;
  std::cin >> n;
  //while(1){
	//  n=10000+rand()%90000;
	  //std::cout<<n<<std::endl;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
	//a[i]=1000000+rand()%10000000;
  }
  //getInvCount(a);
  mergeSort(a);
  /*if(count_simple!=count)
  {
	  std::cout <<"Error:Count_Simple:"<<count_simple<<" Count_merge: "<<count<< '\n';
	  break;
  }
  
  else
	  std::cout<<"PASS"<<std::endl;*/
	std::cout<<count<<std::endl;
  return 0;
}
