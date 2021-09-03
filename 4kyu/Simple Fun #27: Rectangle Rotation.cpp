#include <math.h>

long long rectangle_rotation(int a, int b)
{
  const float SECTION_LENGTH = sqrt(2) / 2;
  
  int aSections = (int)((float)a / 2 / SECTION_LENGTH) * 2;
  int bSections = (int)((float)b / 2 / SECTION_LENGTH) * 2;
  int maxPointsInBSection = bSections / 2 + 1;
  
  bool isHalfOfASectionsOdd = (aSections / 2) % 2;
  bool isHalfOfBSectionsOdd = (bSections / 2) % 2;
  
  int result = 0;
  if (isHalfOfASectionsOdd ^ isHalfOfBSectionsOdd)
    result = aSections / 2 * maxPointsInBSection + (aSections / 2 + 1) * (maxPointsInBSection - 1);
  else
    result = (aSections / 2 + 1) * maxPointsInBSection + aSections / 2 * (maxPointsInBSection - 1);
  
  return result;
}
