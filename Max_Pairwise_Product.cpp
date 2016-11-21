/**
 
	Purpose: Computes the maximum pairwise products of given input numbers.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;\


	/*****************
							BRUTE FORCE

  
  long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)numbers[i]) * numbers[j] > result) {
        result = ((long long)numbers[i]) * numbers[j];
      }
    }
  }
  return result;
}

	*****************/

long long MaxPairwiseProductFast(const vector<int>& numbers) {

	int n = numbers.size();

  int max_index1 = -1;
  for (int i = 0; i < n; ++i)
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
      max_index1 = i;

  int max_index2 = -1;
  for (int j = 0; j < n; ++j)
    if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
      max_index2 = j;
  // cout << max_index1 << ' ' << max_index2 << endl;
  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {

	/*****
																			//    								STRESS TEST

	while (true) {
	  int n = rand() % 1000 + 2;
	  cerr << n << "\n";
	  vector<int> a;
	  for (int i = 0; i < n; ++i) {
	    a.push_back(rand() % 100000);
	  }
	  for (int i = 0; i < n; ++i) {
	    cerr << a[i] << ' ';
	  }
	  cerr << "\n";
	  long long res1 = MaxPairwiseProduct(a);
	  long long res2 = MaxPairwiseProductFast(a);
	  if (res1 != res2) {
	    cerr << "Wrong answer: " << res1 << ' ' << res2 << "\n";
	    break;
	  }
	  else {
	    cerr << "OK\n";
	  }
	}
	
	*****/


    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }



	long long result = MaxPairwiseProductFast(numbers);

	//long long result = MaxPairwiseProductFast(vector<int>(200000, 0));

    cout << result << "\n";
    return 0;
}

