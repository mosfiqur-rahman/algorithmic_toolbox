/**

	Purpose: The following  algorithm computes the the last digit of a sum of the first n Fibonacci numbers.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long fibonacci_sum_last_digit(int n) {
    vector<long long> fibonacci(n+1);

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    if (n > 1)
       {
    	for( int i = 2 ; i <= n ; i++)
    		{
    	    	fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    	    }
    	}
	unsigned long long sum_fibonacci = accumulate(fibonacci.begin(),  fibonacci.end(),  0);

    return sum_fibonacci % 10;
}

int main() {
    int n;
    cin >> n;

    cout << fibonacci_sum_last_digit(n) << '\n';
    return 0;
}

