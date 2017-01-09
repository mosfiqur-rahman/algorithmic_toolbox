/**

	Purpose: The following algorithm computesan algorithm for the fractional knapsack problem.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>


using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values,  int num_of_inputs)
{
  long double value = 0.0;
  vector<double>unit_per_weight(num_of_inputs);
  for(int i = 1; i <= num_of_inputs ; i++)
  {
  	unit_per_weight[i - 1] = (double)values[i - 1]/weights[i - 1];
  }

  vector<double>sorted_units(num_of_inputs);
  vector<double>sorted_weight(num_of_inputs);
  vector<double>sorted_value(num_of_inputs);
  int list = 0;

  vector<double>::iterator max_index;

  for( int k = 1 ; k <= num_of_inputs ; k++)
  {
  double max_unit = *max_element(unit_per_weight.begin(), unit_per_weight.end());

  max_index = max_element(unit_per_weight.begin(), unit_per_weight.end());

  int position_max_unit = distance(unit_per_weight.begin(), max_index);

  sorted_units[list] = max_unit;
  sorted_weight[list] = weights[position_max_unit];
  sorted_value[list] = values[position_max_unit];
  unit_per_weight[position_max_unit] = 0;

  list++;
  }

  for(int l = 1 ; l<= num_of_inputs ; l++)
  {

  	if(capacity > sorted_weight[l-1])
	{
		value += sorted_value[l-1];
		capacity -= sorted_weight[l-1];
	}

	else
	{
		value += ((capacity * sorted_value[l-1]) / sorted_weight[l-1]);
		capacity = 0;
	}

	if(capacity == 0)
		break;
  }

 return value;
}


int main()
{
  int num_of_inputs;
  int capacity;
  cin >> num_of_inputs >> capacity;
  vector<int> values(num_of_inputs);
  vector<int> weights(num_of_inputs);
  for (int i = 0; i < num_of_inputs; i++)
  {
    cin >> values[i] >> weights[i];
  }

  long double optimal_value = get_optimal_value(capacity, weights, values, num_of_inputs);

  cout << setprecision (4) << fixed <<optimal_value << endl;
  return 0;
}

