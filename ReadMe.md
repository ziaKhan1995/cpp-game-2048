About Game 2048 :
Initially there is borad of 4x4 arrray on which there will be empty tiles.
When you start the gane there will be two tiles displayed on grid , each contain
2 or 4.
When user hit the arrow key there wil generate more rabdom numbers and 
when two same tiles face each other they will merg into one by adding 
i.e 2+2=4 ans so on. 


Game Based :
language used : c++
IDE/Tool used : visual studio 2019 pr0fessional conatain diagnostic tool
User interface : Black console 
version  : student version

Goals:
(1) The goal of the game is to create a tile 2048 from the randon tiles created on board.
(2)Provide a good and user friendly interaface.
(3) There are options for restarting, quit the agme 2048


### How to play the game? ###

(1)Use the keyboard directional arrow keys  to the tiles in a certain direction.
(2)Press end key to exit the game
(3) press escape key to restart the game
(4) when two same tiles face each other , they merge into one and give new number i.e by addition


Algorithm:
I chose to store the field in a two-dimensional array called board that is 4×4.
```diff
1=[2][0][8][2]          [2][4][8][4]
2=[0][4][0][2]  press   [4][8][4][4]
3=[4][0][2][2]  up key  [0][0][0][0]
4=[0][8][2][2]          [0][0][0][0]
````
The algorithm can also be explained as 

 => To take a search over the two dimensional array   from the first to the last number
  => In the array  for each original number in the array that is not zero
     look backwards for a target position that does not contain a zero //unless it is position zero
      => if the target position does not contain the original number use the next position
    => if the target position is different from the original position
      - add the number to the number on the target position
      















  
