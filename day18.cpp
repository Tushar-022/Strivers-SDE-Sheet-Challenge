class Solution {
public:
// since the integer is in the range 1 to n

    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0];
        int fast=nums[0];
        slow=nums[slow];
        fast=nums[nums[fast]];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

2)//Missing Number

IN TC:O(N) and SC:O(1)

 long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

3)//Insert Intervals
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>>ans;
        int i=0;
        //step1: us interval tak aate hai jha se merge krna pd skta hai
        while(i<n && intervals[i][1]<newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1])
        {
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

4)
 int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),comp);// so that min length meeting could take place
        
        int cnt=1;
        int last=v[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(v[i].first>last)
            {
                cnt++;
                last=v[i].second;
            }
                
        }
        return cnt;
        
5)
	int solve(int* coins,int index,int v,vector<vector<int>>&dp)
	{
	    if(index==0 )
	    {
	        if(v%coins[0]==0)
	        return v/coins[0];
	        else
	        return 1e9;
	    }
	    if(dp[index][v]!=-1)
	    return dp[index][v];
	    int notpick=solve(coins,index-1,v,dp);
	    int pick=INT_MAX;
	    if(coins[index]<=v)
	    {
	        pick=1+solve(coins,index,v-coins[index],dp);
	    }
	    return dp[index][v]= min(pick,notpick);
	    
	}
	
	
	int minCoins(int coins[], int n, int v) 
	{ 
	    vector<vector<int>>dp(n,vector<int>(v+1,-1));
	    int ans= solve(coins,n-1,v,dp);
	    if(ans>=1e9)
	    return -1;
	    else
	    return ans;
	} 
	  

      6)	int solve(int* coins,int index,int v,vector<vector<int>>&dp)
	{
	    if(index==0 )
	    {
	        if(v%coins[0]==0)
	        return v/coins[0];
	        else
	        return 1e9;
	    }
	    if(dp[index][v]!=-1)
	    return dp[index][v];
	    int notpick=solve(coins,index-1,v,dp);
	    int pick=INT_MAX;
	    if(coins[index]<=v)
	    {
	        pick=1+solve(coins,index,v-coins[index],dp);
	    }
	    return dp[index][v]= min(pick,notpick);
	    
	}
	
	
	int minCoins(int coins[], int n, int v) 
	{ 
	    vector<vector<int>>dp(n,vector<int>(v+1,-1));
	    int ans= solve(coins,n-1,v,dp);
	    if(ans>=1e9)
	    return -1;
	    else
	    return ans;
	} 
	  

      7)
      //N meetings in one room
        bool comp(pair<int,int>a,pair<int,int>b)
    {
        return a.second<b.second;
    }
class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),comp);// so that min length meeting could take place
        
        int cnt=1;
        int last=v[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(v[i].first>last)
            {
                cnt++;
                last=v[i].second;
            }
                
        }
        return cnt;
        
    }
};

8)
public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool comparison(Job a,Job b)
    {
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //vector<int>ans;
        
        sort(arr,arr+n,comparison);
        
        int maxi=arr[0].dead;
        
        for(int i=1;i<n;i++)
        maxi=max(maxi,arr[i].dead);
        
        int cntjobs=0;
        vector<int>slot(maxi+1,-1);
        int profit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    slot[j]=i;
                    profit+=arr[i].profit;
                    cntjobs++;
                    break;
                }
            }
        }
        vector<int>ans(2,0);
        ans[0]=cntjobs;
        ans[1]=profit;
        return ans;