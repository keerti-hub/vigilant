class Solution {
public:
    int climbStairs(int n) {
        vector<int>v;
        v={1,2};
        func(n,v);
        
        return ctr;
        
    }
    map<int,int>dp;
    int ctr=0;
    
    void func(int n,vector<int>v)
    {
        if(dp.find(n)!=dp.end())
        {
            ctr+=dp[n];
            return ;
            
        }
        
        if(n==0)
        {
            ctr++;
            
            return;
        }
        if(n<0)
        {
            return ;
            
        }
        
        for(int i:v)
        {
            func(n-i,v);
            
            
        }
    dp[n]=ctr;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
