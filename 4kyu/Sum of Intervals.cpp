#include <vector>
#include <utility>
#include <algorithm>

int sum_intervals(std::vector<std::pair<int, int>> intervals)
{
  std::sort(intervals.begin(), intervals.end(), 
            [&](const std::pair<int, int> &a, const std::pair<int, int> &b)
            {
              return a.first < b.first;
            });
  
  std::vector<std::pair<int, int>> intervalStack;
  for (const std::pair<int, int> &interval : intervals)
  {
    if (intervalStack.empty())
      intervalStack.push_back(interval);
    else
      if (intervalStack.back().second > interval.first)
      {
        if (intervalStack.back().second < interval.second)
          intervalStack.back().second = interval.second;
      }
      else
        intervalStack.push_back(interval);
  }
  
  int result = 0;
  for (const std::pair<int, int> &interval : intervalStack)
    result += interval.second - interval.first;
  
  return result;
}
