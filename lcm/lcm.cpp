/**

	Purpose: The following  algorithm computes the least common multiple of two positive integers.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/
#include <iostream>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b)
{
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

long long lcm_fast(int a, int b)
{
     int current_gcd = gcd_fast(a, b);
     long long a_multiply_b = (long long)a*b;
     long long lcm = a_multiply_b/current_gcd;
 	 return lcm;

}


int main() {
  int a, b;
  cin >> a >> b;

  //cout << lcm_naive(a, b)  << endl;
  cout << lcm_fast(a, b) << endl;
  return 0;
}

