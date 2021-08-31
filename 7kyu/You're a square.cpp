#include <math.h>

bool is_square(int n)
{
  //Test 1: is number negative
  if (n < 0) return false;
  
  //Test 2: is number square
  float rootOfNum = sqrt(n);
  
  return rootOfNum == (int)rootOfNum;
}
