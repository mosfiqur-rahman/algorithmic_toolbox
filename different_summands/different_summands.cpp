/**

	Purpose: The following algorithm Maximizes the Number of Prize Places in a Competition.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  if(n<=2)
	{
		summands.push_back(n);
	}
  else
  {
	  int l = 1;
	  while(n > 2*l)
	  {
		  summands.push_back(l);
		  n -= l;
		  l++;
	  }
	  summands.push_back(n);
  }


  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';

  for (size_t i = 0; i < summands.size(); ++i)
  {
    cout << summands[i] << ' ';
  }
}

