#include <algorithm>

int FindOutlier(std::vector<int> arr)
{
  int odd = 0, even = 0;
  for (unsigned int i = 0; i < 3; ++i)
    if (arr[i] % 2 == 0)
      ++even;
    else
      ++odd;
  bool isOddTheOutlier = even > odd;

  std::vector<int>::iterator iter = std::find_if(arr.begin(), arr.end(), [&](int element){ return (element % 2 == isOddTheOutlier || element % 2 == -isOddTheOutlier); });
  
  return *iter;
}
