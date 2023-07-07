class Solution {
public:
    double myPow(double x, int n) {
        long long t=n;
        double ans=1.0;
        if(n<0)
        t=-1*t;
        while(t)
        {
            if(t%2==1)
            {
                ans=ans*x;
                t=t-1;
            }
            else
            {
                x=x*x;
                t=t/2;
            }
        }
        if(n<0)
        return 1/ans;
        return ans;
    }
};


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

    int n=nums.size();
    int maxi=1;
    vector<int>dp(n,1);
    vector<int>cnt(n,1);
    if(n==1)
    return 1;
    for(int i=1;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(nums[i]>nums[prev] && 1+dp[prev]>dp[i])
            {
                dp[i]=1+dp[prev];
                cnt[i]=cnt[prev];
            }
            else if(nums[i]>nums[prev] && 1+dp[prev]==dp[i])
            {
                cnt[i]++;
            }
            
        }
        maxi=max(maxi,dp[i]);
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==maxi)
        ans+=cnt[i];
    }
    return ans;

    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                } 
            
        
        else if(nums[i]>nums[j] && 1+dp[j]==dp[i])
        {
            cnt[i]+=cnt[j];
        }
            }
                maxi=max(maxi,dp[i]);
        }
        
    int nos=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
                nos+=cnt[i];
        
        }
        return nos;
}
        
    
};

