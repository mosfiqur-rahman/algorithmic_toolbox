/**

	Purpose:  Given a set of segments on a line. The following algorithm computes as few points on a line as possible so that each segment contains at least one marked point.
	Author : Mosfiqur Rahman(mosfiqur.rahman@drexel.edu)

**/

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment
{
  int start, end;
};

bool myfunction(Segment i, Segment j)
{

	return (i.end < j.end);
}

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
 sort(segments.begin(), segments.end(), myfunction);
 int current = segments[0].end;

 points.push_back(current);
 for(unsigned int i = 0; i < segments.size(); i++)
 {
 	if((current < segments[i].start) || (current > segments[i].end))
	{
		current = segments[i].end;
		points.push_back(current);
	}
 }
  return points;
}

int main()
{
  int n;
  cin >> n;
  vector<Segment> segments(n);

  for (size_t i = 0; i < segments.size(); ++i)
  {
    cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);

  cout << points.size() << "\n";

  for (size_t i = 0; i < points.size(); ++i)
  {
    cout << points[i] << " ";
  }
}

