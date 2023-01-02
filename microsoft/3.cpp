class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> f1(10, 0), f2(10, 0);
        
        int b = 0, c = 0;
        for(int i = 0; i < guess.size(); i++){
            if(guess[i] == secret[i])
                b++;
            else{
                f1[guess[i]-'0']++;
                f2[secret[i]-'0']++;
                
            }
        }
        for(int i = 0; i <= 9; i++)
        {
            c += min(f1[i], f2[i]);
        }
        string ans = to_string(b)+'A'+to_string(c)+'B';
        return ans;
            
    }
};