class Solution {
    int M = 1000000007;
public:
    string longestPrefix(string s) {
        // rabin karp string matching algorithm
        int pre = 0, suff = 0, factor = 1;
        int n = s.size(), i = 0, j = n-1, e = -1;
        string ans = "";
        while(i < n-1){
            pre = ((1ll*pre*26)%M + (s[i]-'a'))%M;
            suff = (suff + (1ll*(s[j]-'a')*factor)%M)%M;
            factor = (1ll*factor*26)%M;
            // assuming no collisions
            if(pre == suff){
                e = i;
            }
            i++; j--;
        }
        if(e == -1) return "";
        ans = s.substr(0, e+1);
        return ans;
    }
};