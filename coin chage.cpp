class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        if(amount==0)
            return 1;
        if(coins.size()==0)
            return 0;
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        
        int n=amount;
        int m=coins.size();
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[0][i]=0;
            
        }
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j-coins[i-1]>=0)
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
                
               // cout<<dp[i][j];
                    
            }
        }
        return dp[m][n];
        
        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        int amount = stringToInteger(line);
        getline(cin, line);
        vector<int> coins = stringToIntegerVector(line);
        
        int ret = Solution().change(amount, coins);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
