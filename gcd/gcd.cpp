/**

	Purpose: The following code calls two algorithms for computing the Greatest Common Divisor.
                 1. Naive Algorithm
		 2. Fast  Algorithm
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/


#include <iostream>

using namespace std;

int gcd_naive(int a, int b) {
  
  int current_gcd = 1;
  
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  
  return current_gcd;
}



int gcd_fast(int a, int b) 
{
  
  int current_gcd = 1;
  
  if (b == 0)
    {
	  return a;
    }
   else
    {
	 int a_prime = a%b;
	 // the remainder when a is divided by b

	 return gcd_fast(b, a_prime);
    }
}


int main()

{

  int a, b;
  cin >> a >> b;

 // cout << gcd_naivet(a, b) << endl;
  cout << gcd_fast(a, b) << endl;

  return 0;
}

