std::string interpreter(const std::string &code, const std::string &tape)
{
  size_t pointer = 0;
  std::string tempTape(tape);
  
  for (size_t i = 0; i < code.size(); ++i)
  {
    char operation = code[i];
    
    switch (operation)
    {
    case '>':
      ++pointer;
      break;
    case '<':
      --pointer;
      break;
    case '*':
      (tempTape[pointer] == '1') ? tempTape[pointer] = '0' : tempTape[pointer] = '1';
      break;
    case '[':
      if (tempTape[pointer] == '0')
      { 
        size_t depth = 0;
        for (size_t j = i + 1; j < code.size(); ++j)
        {
          if (code[j] == '[')
            ++depth;
          if (code[j] == ']')
          {
            if (depth == 0)
            {
              i = j;
              break;
            }
          else
            --depth;
          }
        }
      }
      break;
    case ']':
      if (tempTape[pointer] != '0')
      {
        size_t depth = 0;
        for (size_t j = i - 1; j >= 0; --j)
        {
          if (code[j] == ']')
            ++depth;
          if (code[j] == '[')
          {
            if (depth == 0)
            {
              i = j;
              break;
            }
            else
              --depth;
          }
        }
      }
      break;
    }
    
    if (pointer < 0 || pointer > tape.size() - 1)
      break;
  }
  
  return tempTape;
}
