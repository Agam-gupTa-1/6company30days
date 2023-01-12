class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = 1e9;
        unordered_map<int, int> mp;
        for(int i = 0; i < cards.size(); i++){
            if(mp.find(cards[i]) == mp.end()){
                mp[cards[i]] = i;
            }
            else{
                ans = min(ans, i-mp[cards[i]]+1);
                mp[cards[i]] = i;// update with latest occurance to ensure min. picks
            }
        }
        return ans == 1e9? -1:ans;
    }
};