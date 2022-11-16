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
        int mn = 1, mx = n;
        while(mn <= mx)
        {
            int mid = mn + (mx - mn)/2, currentGuess = guess(mid);
            
            if(currentGuess == 0)return mid;
            if(currentGuess == 1)mn = mid + 1;
            if(currentGuess == -1)mx = mid - 1;
        }
        return -1;
    }
};