class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<vector<int>> st;
        // coordinates of resultant rectangle
        int x = INT_MAX, y = INT_MAX, a = INT_MIN, b = INT_MIN;
        long long combinedArea = 0;
        
        vector<int> br(2, 0), bl(2, 0), tr(2, 0), tl(2, 0);
        for(auto &r: rectangles){
            x = min(x, r[0]); y = min(y, r[1]); a = max(a, r[2]); b = max(b, r[3]);
            // b-bottom, l-left, r-right, t-top 
            bl[0] = r[0]; bl[1] = r[1];
            tr[0] = r[2]; tr[1] = r[3];
            br[0] = r[2]; br[1] = r[1];
            tl[0] = r[0]; tl[1] = r[3];
            
            combinedArea += (r[2]-r[0])*1LL*(r[3]-r[1]);
            
            // corner points should appear only once and internal points should appear even times
            if(!st.count(bl)) st.insert(bl);
            else st.erase(bl); // it must be internal point
            
            if(!st.count(br)) st.insert(br);
            else st.erase(br); // it must be internal point
            
            if(!st.count(tl)) st.insert(tl);
            else st.erase(tl); // it must be internal point
            
            if(!st.count(tr)) st.insert(tr);
            else st.erase(tr); // it must be internal point
        }
        if(!st.count({x, y}) || !st.count({a, b}) || !st.count({a, y}) || !st.count({x, b}) || st.size() != 4)
            return false;
        return combinedArea == (a-x)*1LL*(b-y);
    }
};