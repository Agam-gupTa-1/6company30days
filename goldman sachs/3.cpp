/*
Figure out number of 10's in a number
Also 10 = 5x2, means find out number of 5x2 pairs
number of 2's will be more than number of 5's because every even number will give atleast one 2
Ultimately, number of 5's will decide the number of 2x5 pairs i, e; number of 10s
5 -> contribute 1 5s
10 -> 1 5s
15 -> 1 5s
20 -> 1 5s
25 -> 2 5s --> 25 = 5x5 
example -> 25x26x28 how many 0's it will produce 5x5(25)x 2x13(26) x 2x14(28)
two 5x2 pairs are obtained i.e;  2 trailling 0s
simply number of 5s in 25x26x28, which are 2, so the answer is also 2.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n){
            cnt += n/5;
            n /= 5;
        }
        return cnt;
    }
};