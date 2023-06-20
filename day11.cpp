1)/**
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
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val==(root->left->val+root->right->val);
    }
};

2)// Maximum Path Sum
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
class Solution {
public:

    int solve(TreeNode* root,int &maxi)
    {
        if(root==NULL)
        return 0;
        int left=max(0,solve(root->left,maxi));
        int right=max(0,solve(root->right,maxi));
        maxi=max(maxi,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
        return 0;
        int maxi=INT_MIN;
        
       solve(root,maxi);
        return maxi;
       
    }
};

3)//Symmetric Tree
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
class Solution {
public:

    bool solve(TreeNode* left,TreeNode* right)
    {
        if(left==NULL|| right==NULL)
        return left==right;
        if(left->val!=right->val)
        return false;
        return solve(left->left,right->right) && solve(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL||solve(root->left,root->right);
    }
};

4)
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
class Solution {
public:

    TreeNode* solve(vector<int>&pre,int preStart,int preEnd,vector<int>&in,int inStart,int inEnd,map<int,int>&m)
    {
        if(preStart>preEnd || inStart>inEnd)
        return NULL;
        TreeNode* root=new TreeNode(pre[preStart]);/// root toh bna loh
        int findroot=m[root->val];  // locate the root
        int numsleft=findroot-inStart; // root->left mai itne nodes 
        root->left=solve(pre,preStart+1,preStart+numsleft,in,inStart,findroot-1,m);
        root->right=solve(pre,preStart+numsleft+1,preEnd,in,findroot+1,inEnd,m);
        return root;

    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int,int>m;
        int n=pre.size();
        for(int i=0;i<n;i++)
        {
            m[in[i]]=i;
        }
        return solve(pre,0,n-1,in,0,n-1,m);
    }
};

5)
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    sort(A.begin(),A.end());
sort(B.begin(),B.end());
priority_queue<pair<int,pair<int,int>>>pq;
int n = A.size();
vector<int> ans;
for(int i = 0; i < n; i++)
pq.push({A[i]+B[n-1],{i,n-1}});
while(!pq.empty() && C--)
{
pair<int,pair<int,int>> tp = pq.top();
int vl = tp.first;
int x = tp.second.first, y = tp.second.second;
pq.pop();
ans.push_back(vl);
if(y != 0)
pq.push({A[x]+B[y-1],{x, y-1}});
}
return ans;
}

6)
class Solution {
public:

    typedef pair<int,int>pi;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;

        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(auto it:m)
        {
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k)
            pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};

7)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            pq.pop();
        }
        return pq.top();
        
    }
};

