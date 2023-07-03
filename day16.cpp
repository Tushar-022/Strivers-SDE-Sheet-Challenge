//Recursion
1) // All subsets
class Solution {
public:

    void solve(int ind,vector<int>&nums,vector<vector<int>>&ans,int n,vector<int>&v)
    {
        if(ind>n)
        {
            ans.push_back(v);
            return;
        }

        solve(ind+1,nums,ans,n,v);

        v.push_back(nums[ind]);
        solve(ind+1,nums,ans,n,v);
       
        v.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>>ans;
     vector<int>v;
     int n=nums.size();
      solve(0,nums,ans,n-1,v);   
      return ans;
    }
};

2)// Unique Subsets
class Solution {
public:

    void solve(int ind,vector<int>&nums,vector<vector<int>>&ans,int n,vector<int>&v)
    {
        for(auto it:v)
        cout<<it<<" ";
        cout<<endl;
        ans.push_back(v);
        for(int i=ind;i<n;i++)// generating each level subset
        {
            if(i!=ind && nums[i]==nums[i-1])// 
            continue;

            v.push_back(nums[i]);
            solve(i+1,nums,ans,n,v);
            v.pop_back();
        }
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<vector<int>>ans;
     vector<int>v;
     int n=nums.size();
     sort(nums.begin(),nums.end());// because we want duplicates to be together
     solve(0,nums,ans,n,v);   
     return ans;
    }
};


                            // 1        i=0,ind=0
                            // /
                            // 1,2(i=1,ind=1) i=2,ind=1 and check i!=ind && nums[i]==nums[i-1] so continue 
                            // /\
                            // 1,2,2(i=2,ind=2)

3)// Subset Sum
    int sum=0;
    void solve(int ind,vector<int>&arr, int n,vector<int>&ans)
    {
        // ans.push_back(sum);
            if(ind>=n)
            {
                ans.push_back(sum);
                return;
            }
            solve(ind+1,arr,n,ans);
        
            sum+=arr[ind];
            solve(ind+1,arr,n,ans);
            sum-=arr[ind];
    }
        
    vector<int> subsetSums(vector<int> arr, int n)
    {
       vector<int>ans;
       solve(0,arr,n,ans);
       return ans;
    }
};

4)//Permutation
class Solution {
public:

    void solve(int ind,vector<int>&nums, vector<vector<int>>&ans,int n)
    {
        if(ind==n)
        {
            ans.push_back(nums);
            return;
        }
        // since here we need to pick all ements of array so no skip waali condition required.
        for(int i=ind;i<n;i++)
        {
            swap(nums[i],nums[ind]);
            solve(ind+1,nums,ans,n);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

     int n=nums.size();
     vector<vector<int>>ans;
     solve(0,nums,ans,n); 
     return ans;  
    }
};

5)
class Solution {
public:

    void solve(int ind,vector<vector<int>>&ans,vector<int>& candt, int tgt,int n,vector<int>&v)
    {
        if(tgt==0)
        {
            ans.push_back(v);
            return;
        }

        if(tgt<0 || ind==n)
        return;
        
        //ntake
        solve(ind+1,ans,candt,tgt,n,v);

        //take
        if(tgt>=candt[ind])
        {
            v.push_back(candt[ind]);
            solve(ind,ans,candt,tgt-candt[ind],n,v);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candt, int tgt) {
        vector<vector<int>>ans;
        int n=candt.size();
        vector<int>v;
        solve(0,ans,candt,tgt,n,v);
        return ans;
    }
};

6)
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(i);

        for (int i = 1; i < k; i++) {
            next_permutation(s.begin(), s.end());
        }
        
        return s;
    }
};

7)//Combination Sum2
class Solution {
public:

   
    void solve(int ind,vector<vector<int>>&ans,vector<int>& candt, int tgt,int n,vector<int>&v)
    {
        if(tgt==0)
        {
            ans.push_back(v);
            return;
        }
        if(tgt<0 || ind>=n)
        return;

      for(int i=ind;i<n;i++)
      {
          if(i!=ind && candt[i]==candt[i-1])
          continue;

            if(tgt>=candt[i])           
              {
                  v.push_back(candt[i]);
                  solve(i+1,ans,candt,tgt-candt[i],n,v);
                    v.pop_back();
              }
          
          
      }  

    }
    vector<vector<int>> combinationSum2(vector<int>& candt, int tgt) {

        int n=candt.size();
        vector<vector<int>>ans;
        vector<int>v;
        sort(candt.begin(),candt.end());
        solve(0,ans,candt,tgt,n,v); 
        return ans;  
    }
};

class Solution {
public:
    bool checkPalindrome(string str, int startIndex, int lastIndex){
        while(startIndex <= lastIndex){
            if(str[startIndex] != str[lastIndex])
                return false;
            startIndex++;
            lastIndex--;
        }
        return true;
    }
    void palindromePartition(int index, vector<string>& ds, vector<vector<string>>& output, string str){
        if(index == str.length()){
            output.push_back(ds);
            return;
        }
        for(int i = index; i < str.length(); i++){
            if(checkPalindrome(str, index, i)){
                ds.push_back(str.substr(index, i - index + 1));
                palindromePartition(i+1, ds, output, str);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> ds;
        palindromePartition(0, ds, output, s);
        return output;
    }
};