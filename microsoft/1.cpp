class Solution {
    long long evaluate(long long &a, long long &b, string &op){
        if(op == "+")
            return a+b;
        else if(op == "-")
            return a-b;
        else if(op == "*")
            return a*b;
        return a/b;
    }
    bool isNumber(string &token){
        if(token.size() == 1 && !(token[0]-'0' >= 0))
            return false;
        return true;
    }
    int giveNumber(string &t){
        // 0th index can be +, -
        int n = 0;
        
        for(int i = 0; i < t.size(); i++){
            if(t[i]-'0' < 0) continue;
            n = (n*10) + t[i]-'0';
            
        }
        if(t[0] == '-')
            n *= -1;
        return n;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(auto &t: tokens){
            // check for integer
            if(isNumber(t)){
                s.push(giveNumber(t));
            }
            else{
                // operator
                long long b = s.top(); s.pop();
                long long a = s.top(); s.pop();
                s.push(evaluate(a, b, t));
            }
        }
        return s.top();
    }
};