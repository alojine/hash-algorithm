# blockchain
repository for blockchain projects

## Pseudocode
```
function Hash{

  string givenString
  string binary
  for(from 0 to givenString.size):
    char front = givenString[from0]
    char back = givenString[fromSize]
    binary += bits<8>(front) + bits<8>(back)
   
   if(binary < 512):
     binary += add 1 + spaceLeft * 0
   else:
     binary = binary - spaceOver
  
  for(from 0 to binary.size):
     bits<16> front = binary[from0].subtract().rotate().logicOperations()
     bits<16> back = binary[fromSize].subtract().rotate().logicOperations()
     bits<16> connected = (front XOR back).rotate()
     mixed += connected
  
  int uniqueValue = givenString.intValue()
  random(seed -> uniqueValue)
  for(from 0 to 512):
      randomIndex = random() % 512
      mixed[from0] = mixed[from0] + mixed[randomIndex] - (mixed[randomIndex] = mixed[from0])
  
  s = convertBinaryToHex(mixed)
  return s;
}
```