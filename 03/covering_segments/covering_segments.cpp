#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int last_point = -1;

  // Safe move - pick point with minimum end coordinate
  // So, sorting points in asc order 

  auto sort_by_end = [](Segment const& a, Segment const& b) { return a.end < b.end; };

  std::sort(segments.begin(), segments.end(), sort_by_end);

  for (auto segment : segments) {
    if (segment.start <= last_point) {
      continue;
    } else {
      last_point = segment.end;
      points.push_back(last_point);
    }
  }
  

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  
  vector<int> points = optimal_points(segments);
  
  std::cout << points.size() << "\n";
  
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
