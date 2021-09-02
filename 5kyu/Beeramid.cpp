int beeramid(int bonus, double price)
{
  int numberOfCans = bonus / price;
  
  int layersBuilt = 0;
  while (numberOfCans > 0)
  {
    int layer = (layersBuilt + 1) * (layersBuilt + 1);
    
    if (numberOfCans >= layer)
      ++layersBuilt;
    
    numberOfCans -= layer;
  }
  
  return layersBuilt;
}
