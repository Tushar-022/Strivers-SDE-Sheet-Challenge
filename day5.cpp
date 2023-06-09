1)//buy and sell stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxprofit=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            int cost=prices[i]-mini;
            maxprofit=max(maxprofit,cost);
            mini=min(mini,prices[i]);
        }
        return maxprofit;
    }
};

2)//Kadanes Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=nums[0];
        int osum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(csum>=0)
            csum+=nums[i];
            else
            csum=nums[i];
            if(csum>osum)
            osum=csum;
        }
        return osum;
    }
};

3)//Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int n=nums.size();
     int ind=-1;
     for(int i=n-2;i>=0;i--)
     {
         if(nums[i+1]>nums[i])
         {
             ind=i;
             break;
         }
     }

         if(ind==-1)
          {
              reverse(nums.begin(),nums.end());
                return;
          }

         for(int i=n-1;i>ind;i--)
         {
             if(nums[i]>nums[ind])
             {
                 swap(nums[i],nums[ind]);
                 break;
             }
         }
         reverse(nums.begin()+ind+1,nums.end());  
    }
};

4)//Sort 0s,1s and 2s

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(high>=mid)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
           else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

5)//Pascal Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    { 
        vector<vector<int>>ans;
        vector<int>temp ={1};
        ans.emplace_back(temp);
        for(int i =1;i<numRows;i++)
        {
            vector<int>v={1};
            int res =1;
            for(int j =0;j<i;j++)
            {
               res *=(i-j);
               res/=(j+1);
               v.push_back(res);
            }
            ans.emplace_back(v);
        }
        return ans;
    }
};

6)Set Matrix zeros
class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col0=1;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            col0=0;
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=1;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;
                
            }
            if(col0==0)
            matrix[i][0]=0;
        }

    }
};





