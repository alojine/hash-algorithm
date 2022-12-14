# Hash-algorithm for custom blockchain

## Pseudocode
```
function Hash{

  string givenString
  
  CHARACTERS = [1-9 + A-Z + a-z]
  string newGeneratedString
  
  for(from 0 to givenString){
    random_index = random(seed) % CHARACTERS.length()
    random_rotated_index = rotate(random_index by random_index - 1)
    newGeneratedString += random_index + random_rotated_index + CHARACTERS[random_index] + CHARACTERS[random_rotated_index]
  }
  
  string binary
  for(from 0 to newGeneratedString.size):
    char front = newGeneratedString[from0]
    char back = newGeneratedString[fromSize]
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

- Hash algoritmas visada yra **64 simboliu hex** ilgio kodas
- Hash algoritmas visada yra **deterministinis**

### Hash algorithm speed

![alt text](https://github.com/alojine/hash-algorithm/blob/master/Hash%20speed.png)

### Collision test

Atliktas kolizijos testas **Hash** algoritmui
- Sugeneruojami 4 failai po 25000 eilu??i??, kuriuose yra dvi poros kuriu ilgiai: *10* / *100* / *500* / *1000*

|     Input       | Hash time  |  Collision | 
|-----------------| -----------| -----------|
| poros10.txt     | 10.0739 s  | 0          |
| poros100.txt    | 13.3767 s  | 0          |
| poros500.txt    | 26.0261 s  | 0          |
| poros1000.txt   | 41.8003 s  | 0          |

### Avalanche test

- Sugeneruotos 50000 stringu poru 15hex ilgio

|     Sutapimai   | Procentai  |
|-----------------| -----------|
| Didziausias     | 28.00%     |
| Maziausias      | 0.00%      |
| Vidutinis       | 7.99%      |


### Results And Conclusions

#### Strengths
- Algoritmas yra atsparus kolizijai ir yra gaunamas geras avalanche efektas, daugiausiai 28%
- Minimalus pasikeitimai u??tikrina, jog gaunamas skirtingas hashas

#### Weaknesses
- Algoritmas u??ima daug laiko, skaitant, jog hashuojamas didelis kiekis input'u
