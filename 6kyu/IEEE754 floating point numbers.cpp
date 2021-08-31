std::string fp32_to_ieee754(float num)
{
  int temp = * (int*) &num;
  
  std::string result;
  unsigned int mask = 1 << 31;
  for (unsigned int i = 0; i < 32; ++i)
  {
    if (temp & mask)
      result += '1';
    else
      result += '0';
    
    mask >>= 1;
    
    if (i == 0 || i == 8)
      result += ' ';
  }
  
  return result;
}

std::string fp64_to_ieee754(double num)
{
  long int temp = * (long int*) &num;
  
  std::string result;
  unsigned long int mask = (unsigned long int)1 << 63;
  for (unsigned int i = 0; i < 64; ++i)
  {
    if (temp & mask)
      result += '1';
    else
      result += '0';
    
    mask >>= 1;
    
    if (i == 0 || i == 11)
      result += ' ';
  }
  
  return result;
}
