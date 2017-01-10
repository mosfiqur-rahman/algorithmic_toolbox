/**

	Purpose: The following algorithm  arranges given numbers to form the biggest number.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);
 
    // then append X at the end of Y
    string YX = Y.append(X);
 
    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}

string largest_number(vector<string> a) 
{
  
  sort(a.begin(), a.end(), myCompare);
  
  stringstream ret;
  for (size_t i = 0; i < a.size(); i++) 
  {
		ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() 
{
  int n;
  cin >> n;
  vector<string> a(n);
  
  for (size_t i = 0; i < a.size(); i++) 
  {
		cin >> a[i];
  }
  cout << largest_number(a);
}
