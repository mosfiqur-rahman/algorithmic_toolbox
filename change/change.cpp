/**

	Purpose: The following algorithm computes the minimum number of coins needed to change the input value (an integer) into coins with denominations 1, 5, and 10.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <iostream>

using namespace std;

int get_change(int m) {
  int coin_of_tens = (int)m/10;
  int remainder = m - (10*coin_of_tens);

  int coin_of_fives = (int)remainder/5;
  int coin_of_ones = remainder%5;

  int total_coins = coin_of_tens + coin_of_fives + coin_of_ones;
  return total_coins;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}

