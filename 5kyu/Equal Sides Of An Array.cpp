#include <vector>

bool sidesAreEqual(const std::vector<int>& numbers, unsigned int index)
{
  int leftSum = 0, rightSum = 0;
  
  for (unsigned int i = 0; i < numbers.size(); ++i)
  {
    if (i < index)
      leftSum += numbers[i];
    else if (i > index)
      rightSum += numbers[i];
  }
  
  return leftSum == rightSum;
}

int find_even_index (const std::vector<int> numbers)
{
  for (unsigned int i = 0; i < numbers.size(); ++i)
    if (sidesAreEqual(numbers, i))
      return i;
  
  return -1;
}
