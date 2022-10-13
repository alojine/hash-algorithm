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

## Testu rezultatai

### Avalanche

|     Input     | Output(hash)                                                    |
|-------------- | ----------------------------------------------------------------|
| lietuva       | 451101b2005d18080b122400c11000cb240a0c380e113406248002220122500 |
| lietuve       | 81200053648100580342902c080022204221211c85891020b00100e0a252249 |
| lietuva!      | 02000199c0201180640010430c84004320518000884022194ca040604800951 |

- Hash algoritmas visada yra *64 simboliu hex* ilgio kodas
- Hash algoritmas visada yra *deterministinis*

### Hash algoritmo greitis

![alt text](https://github.com/alojine/blockchain/blob/master/Hash%20speed.png)

###
