class Solution {
public:
typedef pair<int,pair<int,int>>pi;

    struct compare{

        bool operator()(pi &a,pi &b){
            return a.first>b.first;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int n1=nums1.size();
        int n2=nums2.size();
        priority_queue<pi,vector<pi>,compare>pq;
        set<pair<int, int>> s;

        s.insert({0,0});
        pq.push({nums1[0]+nums2[0],{0,0}});

        vector<vector<int>>ans;
        while(k--)
        {
            if (pq.empty())
                break;
            auto it=pq.top();
            pq.pop();
            int ind1=it.second.first;
            int ind2=it.second.second;
            ans.push_back({nums1[ind1],nums2[ind2]});


            cout<<nums1[ind1]<<" "<<nums2[ind2]<<endl;

            if(ind1+1<n1 && ind2<n2 && s.find({ind1+1,ind2})==s.end())
            {
                pq.push({nums1[ind1+1]+nums2[ind2],{ind1+1,ind2}});
                s.insert({ind1+1,ind2});
            }
            if(ind1<n1 && ind2+1<n2 && s.find({ind1,ind2+1})==s.end())
            {
                pq.push({nums1[ind1]+nums2[ind2+1],{ind1,ind2+1}});
                s.insert({ind1,ind2+1});
            }

        }
        return ans;

    }
};


2)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:

    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll( TreeNode* root){
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
    }

};



 3)/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 class Solution {
public:
    typedef long long ll;

    ll fcost(vector<int>& nums, vector<int>& cost,int target)
    {
        ll ans=0;
        for(int i=0;i<cost.size();i++)
        {
            ans+=(ll)abs(nums[i]-target)*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        ll ans=INT_MAX;
         ll  low=*min_element(nums.begin(),nums.end());
         ll  high=*max_element(begin(nums),end(nums));
        while(high>=low)
        {
             ll  mid=low+(high-low)/2;
             ll  cost1=fcost(nums,cost,mid);
             ll  cost2=fcost(nums,cost,mid+1);
            ans=min(cost1,cost2);
            if(cost1>cost2)
            {
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};

4)
 bool isfeasible(vector<int> &stalls,int k,int mid,int n)
    {
        int cnt=1;
        int low=stalls[0];
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-low>=mid)
            {
                cnt++;
                low=stalls[i];
            }
        }
        if(cnt<k)
        return false;
        return true;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
    sort(stalls.begin(),stalls.end());
    int low=1,res=1;
    int high=stalls[n-1];
    while(high>=low)
    {
        int mid=low+(high-low)/2;
        if(isfeasible(stalls,k,mid,n))
        {
            res=max(res,mid);
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return res;
    }