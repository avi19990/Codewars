#include <map>
#include <string>

class SnakesLadders
{
private:
  std::map<unsigned int, unsigned int> jumpMap;
  unsigned int p1 = 0, p2 = 0;
  bool playerOneTurn = true;
  
public:
  SnakesLadders()
  {
    jumpMap = {{2, 38}, {7, 14}, {8, 31}, {15, 26}, {16, 6}, {21, 42}, 
               {28, 84}, {36, 44}, {46, 25}, {49, 11}, {51, 67}, 
               {62, 19}, {64, 60}, {71, 91}, {74, 53}, {78, 98}, 
               {87, 94}, {89, 68}, {92, 88}, {95, 75}, {99, 80}};
  };
  
  std::string play(int die1, int die2)
  {
    if (p1 == 100 || p2 == 100)
      return "Game over!";
    
    unsigned int newPosition = die1 + die2 + ((playerOneTurn) ? p1 : p2);
    if (newPosition > 100)
      newPosition = 100 - newPosition % 100;
    if (jumpMap.find(newPosition) != jumpMap.end())
      newPosition = jumpMap[newPosition];
    
    if (playerOneTurn)
      p1 = newPosition;
    else
      p2 = newPosition;
    
    std::ostringstream result;
    result << "Player " << ((playerOneTurn) ? "1 " : "2 ");
    if (newPosition == 100)
      result << "Wins!";
    else
      result << "is on square " << std::to_string(newPosition);
    
    if (die1 != die2)
      playerOneTurn = !playerOneTurn;
    
    return result.str();
  };
};
