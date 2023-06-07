1) //KNAPSACK 
int solve(int w,int* wt,int* val,int ind,vector<vector<int>>&dp)
    {
        if(w==0)
        return 0;
        if(ind==0)
        {
            if(w>=wt[0])
            return val[0];
            return 0;
        }
        if(dp[ind][w]!=-1)
        return dp[ind][w];
        if(w>=wt[ind])
        {
            return dp[ind][w]=max(val[ind]+solve(w-wt[ind],wt,val,ind-1,dp),solve(w,wt,val,ind-1,dp));
            
        }
        else 
        return dp[ind][w]=solve(w,wt,val,ind-1,dp);
        
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
       return solve(w,wt,val,n-1,dp);
    }

    2)//EDIT DISTANCE
    class Solution {
public:

    int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0)
        return j+1;
        if(j<0)
        return i+1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(word1[i]==word2[j])
        {
           return dp[i][j]=solve(word1,word2,i-1,j-1,dp);
        }
        else
        {
            int op1=1+solve(word1,word2,i,j-1,dp);
            int op2=1+solve(word1,word2,i-1,j,dp);
            int op3=1+solve(word1,word2,i-1,j-1,dp);
            return dp[i][j]=min(op1,min(op2,op3));
        }
        return 0;

    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(word1,word2,m-1,n-1,dp);
    }
};

3)//LIS
class Solution {
public:

    int solve(int n,vector<int>& nums,int prev,int ind,vector<vector<int>>&dp)
    {
        if(ind==n)
        return 0;
        if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
        int len=solve(n,nums,prev,ind+1,dp);
        if(prev==-1|| nums[ind]>nums[prev])
       len=max(len,1+solve(n,nums,ind,ind+1,dp));

        return dp[ind][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,nums,-1,0,dp);
    }
};

4) MCM
class Solution{
public:

    int solve(int i,int j,int*arr,vector<vector<int>>&dp)
    {
        if(i>=j)
        return 0;
        int steps=INT_MAX;
        if(dp[i][j]!=-1)
        return dp[i][j];
        for(int k=i;k<j;k++)
        {
            int ans=solve(i,k,arr,dp)+solve(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
            steps=min(steps,ans);
        }
        return dp[i][j]=steps;
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        if(n==1)
        return 0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n-1,arr,dp);
    }
};

5)// LCS
class Solution {
public:

    // int solve(string &s1,string& s2,int i,int j,vector<vector<int>>&dp)
    // {
    //     if(i<0 ||j<0)
    //     return 0;
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     if(s1[i]==s2[j])
    //     return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);
    //     else
    //     return dp[i][j]= max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));

        
    // }
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        //return solve(s1,s2,m-1,n-1,dp);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
               if(s1[i-1]==s2[j-1])
               dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

6)Max product
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int cprod=1;
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            cprod*=nums[i];
            ans=max(ans,cprod);
            if(cprod==0) // 2 3 -1 0 2 4 -1 -2 0 0 2 3 4 -4 ans will be 2*4*-1*-2=16
            cprod=1;

        }
        cprod=1;
        for(int i=n-1;i>=0;i--)
    {
        cprod*=nums[i];
        ans=max(ans,cprod);
        if(cprod==0)
        cprod=1;
    }
    return ans;
    }
};

7)	public:
	int solve(int arr[],int ind , int prev, int n,vector<vector<int>>& dp){
	    if(ind==n){
	        return 0;
	    }
	    if(dp[ind][prev+1]!=-1){
	        return dp[ind][prev+1];
	    }
	    int nottake = 0 + solve(arr,ind+1,prev,n,dp);
	    int take = 0;
	    if(prev==-1 || arr[ind]>arr[prev]){
	        take=arr[ind] + solve(arr,ind+1,ind,n,dp);
	    }
	    return dp[ind][prev+1]=max(take,nottake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	    return solve(arr,0,-1,n,dp);
	}  
};