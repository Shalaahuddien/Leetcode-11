class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(dp,amount,coins,0);
    }
    int solve(vector<vector<int>> &dp,int amount,vector<int> &coins,int i)
    {
        if(amount==0) return 1;
        if(coins.size()==0 or i>=coins.size()) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        
            int sum1=0;
            if(coins[i]<=amount)
                sum1=solve(dp,amount-coins[i],coins,i);
            int sum2=solve(dp,amount,coins,i+1);
            dp[i][amount]=sum1+sum2;
        
        return dp[i][amount];
    }
};