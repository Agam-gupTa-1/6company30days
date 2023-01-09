class Solution {
    int getLength(vector<int> &a, vector<int> &b){
        int x = b[0]-a[0];
        int y = b[1]-a[1];
        return x*x + y*y;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> mp;
        mp[getLength(p1, p2)]++;
        mp[getLength(p1, p3)]++;
        mp[getLength(p1, p4)]++;
        mp[getLength(p2, p3)]++;
        mp[getLength(p2, p4)]++;
        mp[getLength(p3, p4)]++;
        if(mp.size() != 2) return false;
        
        bool four = false, two = false;
        for(auto &m: mp){
            if(m.first == 0) return false;
            if(m.second == 4) four = true;
            if(m.second == 2) two = true;
        }
        return four && two;
    }
};