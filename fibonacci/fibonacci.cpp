/**

	Purpose: The following code calls two algorithms for computing a Fibonacci number.
                 1. Naive Algorithm
		 2. Fast  Algorithm
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

//							BRUTE FORCE

int fibonacci_naive(int n)
{
    if (n <= 1)
    {
    	return n;
    }
    else
    {
    	 return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
    }
}


int fibonacci_fast(int n) {
    vector<int> fibonacci(n+1);

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    if (n >= 1)
       {
    	for( int i = 2 ; i <= n ; i++)
    		{
    	    	fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    	    }
    	}

    return fibonacci[n];
}


void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}


int main() {
    int n;
    cin >> n;

    //cout << fibonacci_naive(n) << '\n';
    //test_solution();

    cout << fibonacci_fast(n) << '\n';
    return 0;
}

