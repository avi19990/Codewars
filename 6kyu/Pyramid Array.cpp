#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> pyramid(std::size_t n)
{
  std::vector<std::vector<int>> result(n);
  
  for (unsigned int i = 0; i < n; ++i)
  {
    result[i] = std::vector<int>(i + 1, 1);
  }
  
  return result;
}
