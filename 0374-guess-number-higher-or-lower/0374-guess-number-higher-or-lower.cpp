/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        //int prev = n + 2;
        //bool e = false;
      for(int i = n ; i > 0; i--)  
      {
          if(guess(i) == 0)
          {
              return i;
              //else e = true;
          }
      }
        return -1;
    }
};