#include <iostream>
#include <vector>

using namespace std;

int optimal_weight_dynamic(int W, vector <int> &w)
{
	int array[(int)w.size() + 1][W+1];
	int not_taken,taken;
	
	for(int i=0;i<W+1;i++)
		array[0][i]=0;
	
	for(int i=0;i<w.size()+1;i++)
		array[i][0]=0;
	
	for(int i=1;i<(int)w.size()+1;i++)
	{
		for(int j=1;j<W+1;j++)
		{
			array[i][j] = not_taken = array[i-1][j];
			if(w[i-1]<=j)
			{
				taken = array[i-1][j-w[i-1]] + w[i-1];
				if(taken > not_taken)
				{
					array[i][j] = taken;
				}
			}
		}
	}
	
	return array[(int)w.size()][W];
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight_dynamic(W, w) << '\n';
  return 0;
}