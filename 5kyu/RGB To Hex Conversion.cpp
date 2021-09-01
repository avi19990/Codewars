#include <string>

union RGB
{
  struct
  {
    unsigned char r, g, b;
  } values;
  
  struct
  {
    unsigned char signr2 : 4;
    unsigned char signr1 : 4;
    unsigned char signg2 : 4;
    unsigned char signg1 : 4;
    unsigned char signb2 : 4;
    unsigned char signb1 : 4;
  } raw;
};

class RGBToHex
{
public:
  static char bitToHex(unsigned int num)
  {
    if (num < 10)
      return num + '0';
    else
      switch (num)
      {
      case 10:
        return 'A';
        break;
      case 11:
        return 'B';
        break;
      case 12:
        return 'C';
        break;
      case 13:
        return 'D';
        break;
      case 14:
        return 'E';
        break;
      case 15:
        return 'F';
        break;
      }
    
    return 0;
  }
  
  static std::string rgb(int r, int g, int b)
  {
    if (r < 0) r = 0;
    else if (r > 255) r = 255;
    if (g < 0) g = 0;
    else if (g > 255) g = 255;
    if (b < 0) b = 0;
    else if (b > 255) b = 255;
    
    RGB val;
    val.values.r = r;
    val.values.g = g;
    val.values.b = b;
    
    std::ostringstream result;
    result << bitToHex(val.raw.signr1) << bitToHex(val.raw.signr2) << bitToHex(val.raw.signg1) <<
              bitToHex(val.raw.signg2) << bitToHex(val.raw.signb1) << bitToHex(val.raw.signb2);
    
    return result.str();
  }
};
