1) 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        int n=nums.size();
        for (int i = 0; i < n-3; i++){
            
            for(int j = i+1; j <n-2; j++){
                
                int k = j + 1;
                int l = n- 1;
                while (k < l) {

                    long long  sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if (sum == target) {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    }
                     else if (sum < target) 
                     {
                        k++;
                    }
                     else {
                        l--;
                    }
                }
            }
        }
        for(auto it : s)
            ans.push_back(it);
        return ans;
    }
};

2)//Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else
            m[nums[i]]=i;
        }
        return ans;
    }
};

3)//Larget Subaaray with sum 0
class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        unordered_map<long long,long long>m;
        long long sum=0,maxlen=0;
        m[sum]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            
            if(m.find(sum)!=m.end())
            {
                long long len=i-m[sum];
                maxlen=max(len,maxlen);
            }
            else
            m[sum]=i;
            
        }
        
        return (int) (maxlen);
    }
};

4)//Longest Non Repeating Substring

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int i=0,j=0;
        int n=s.length();
        int ans=0;
        while(j<n )
        {
            if(set.find(s[j])==set.end())
            {
                set.insert(s[j]);
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                set.erase(s[i]);
                i++;
            }
            
        }
        return ans;
    }
};

5//) xor as k
int Solution::solve(vector<int> &nums, int b) {
    int n = nums.size();
    int xr = 0; 
    int cnt = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        xr=xr^nums[i];
        int x=xr^b;
        if(m.find(x)!=m.end())
        cnt+=m[x];
        
        m[xr]++;
    }
        
    return cnt;
}

6)//Longest COnsecutive seq.
M-1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        sort(nums.begin(),nums.end());
        
        int ans=1;
        int prev=nums[0];
        int curr=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-prev==1)
            {
                curr++;
                prev=nums[i];
                ans=max(ans,curr);
            }
            else if(nums[i]!=prev)
            {
                prev=nums[i];
                curr=1;
            }
            
        }
        return ans;
    }
};

M-2
 Using set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        int ans=1;
        for(auto it:s)
        {   
            if(s.find(it-1)==s.end())
            {
                int num=it;
                int cnt=1;
                while(s.find(num+1)!=s.end())
                {
                    cnt++;
                    num=num+1;
                    ans=max(cnt,ans);
                }
                

            }
        }
        return ans;
    }
};