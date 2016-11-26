/**

	Purpose: The following code computes the Last Digit of a Large Fibonacci Number.
        Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/


#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit_naive(int n)
{
	vector<int> fibonacci(n+1);

	    fibonacci[0] = 0;
	    fibonacci[1] = 1;

	    if (n >= 1)
	       {
	    	for( int i = 2 ; i <= n ; i++)
	    		{
	    	    	fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2])%10;
	    	    }
	    	}
	    return fibonacci[n];
}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << '\n';
    }

