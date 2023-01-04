class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0;
        // unordered_map<char, int> mp;
        vector<int> freq(3, 0);
        int cnt = 0;
        int i = 0, j = 0;
        while(j < n){
            if(s[j] == 'a'){
                freq[0]++;
                if(freq[0] == 1) cnt++;
            }
            else if(s[j] == 'b'){
                freq[1]++;
                if(freq[1] == 1) cnt++;
            }
            else{
                freq[2]++;
                if(freq[2] == 1) cnt++;
            }
            while(cnt == 3 && freq[s[i]-'a'] > 1){
                if(s[i] == 'a'){
                    freq[0]--;
                    if(freq[0] == 0) cnt--;
                }
                else if(s[i] == 'b'){
                    freq[1]--;
                    if(freq[1] == 0) cnt--;
                }
                else{
                    freq[2]--;
                    if(freq[2] == 0) cnt--;
                }
                i++;
            }
            if(cnt == 3){
                ans += (1 + i);
            }
            j++;
        }
        return ans;
    }
};