#include <string>
#include <sstream>

std::string decodeMorse(std::string morseCode)
{
  //Truncate white spaces from start and end
  morseCode = morseCode.substr(morseCode.find_first_not_of(' '), morseCode.find_last_not_of(' ') - morseCode.find_first_not_of(' ') + 1);
  
  std::istringstream stream(morseCode);
  std::string token;
  
  std::string decoded;
  
  //Parse words and add to solution
  while (std::getline(stream, token, ' '))
  {
    if (token.empty())
    {
      decoded += ' ';
      stream.get();
    }
    
    decoded += MORSE_CODE[token];
  }
  
  return decoded;
}
