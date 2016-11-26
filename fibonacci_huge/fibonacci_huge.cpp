/**

	Purpose: The following algorithmccomputes a Fibonacci number Modulo M.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge(long long n, long long m)
{
	 vector<long long>fibonacci(n+1);
	 vector<long long>remainder(m+1);

	 if(n == 0)
		 return 0;

	 fibonacci[0] = 0;
	 fibonacci[1] = 1;

	 remainder[0] = 0;
	 remainder[1] = 1;

	 int counter = 2;

	 while(counter <= n)
	 {
		 fibonacci[counter] = fibonacci[counter - 1] + fibonacci[counter - 2];
		 remainder[counter] = fibonacci[counter] % m;

		 //if( counter == n)
			 //return remainder[counter];

		 if(remainder[counter - 1] == 0 && remainder[counter] == 1)
			 break;

		 counter++;
	 }

	 int smaller_n = (int)(n % (counter - 1)); // The period length is [counter -1]

	 return fibonacci[smaller_n] % m;

}
int main()
{
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge(n, m) << '\n';
}

