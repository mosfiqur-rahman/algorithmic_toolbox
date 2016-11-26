/**

	Purpose: The following  algorithm computes the  last digit of a partial sum of Fibonacci numbers: F_m + F_ m+1 + ....... + F_n .
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long get_fibonacci_partial_sum(long long from, long long to)
{
    vector<long long> fibonacci(to+1);

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    if (to > 1)
       {
    	for( int i = 2 ; i <= to ; i++)
    		{
    	    	fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2]) % 10;
    	    }
    	}

		//fibonacci.erase (fibonacci.begin(),  fibonacci.begin()+from);
	unsigned long long sum_fibonacci = accumulate(fibonacci.begin()+from ,  fibonacci.end(),  0);

    return sum_fibonacci % 10;
}

int main() {
    long long from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum(from, to) << '\n';
    return 0;
}

