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
    void flatten(TreeNode* root) {
        if(root==NULL)
        return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node=st.top();
            st.pop();
            if(node->right)
            st.push(node->right);
            if(node->left)
            st.push(node->left);

            if (!st.empty()) 
            node -> right = st.top();

            node->left=NULL;
            
        }
    }
};

 2) //Mirror of Tree
 class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void solve(Node*root)
    {
        if(root==NULL)
        return ;
        solve(root->left);
        solve(root->right);
        swap(root->left,root->right);
        
    }
    void mirror(Node* node) {
        
        solve(node);
    }
};

3)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

     TreeNode* solve(TreeNode *root, int n1, int n2)
    {
        if(root==NULL)
        return NULL;
        if((n1>root->val)&&(n2>root->val))
        return solve(root->right,n1,n2);
        
        if((n1<root->val)&&(n2<root->val))
        return solve(root->left,n1,n2);
        
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p->val,q->val);
    }
};

4) // Validate a BST
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

    bool solve(TreeNode* root,long maxi,long mini)
    {
          if(root==NULL)
          return true;
          long d=root->val;
          if(d>=maxi || d<=mini)
          return false;
          return solve(root->left,d,mini) && solve(root->right,maxi,d);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MAX,LONG_MIN);
    }
};

5)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2!=0)
            nums[i]=1;
            else
            nums[i]=0;
        }
        map<int,int>m;
        m[0]=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(m.find(sum-k)!=m.end())
            cnt+=m[sum-k];

            m[sum]++;
        }
        
        return cnt;
        


    }
};

6)

class DisjointSet{
    public:
    vector<int>rank,par;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int findPar(int node)
    {
        if(par[node]==node)
        return node;
        return par[node]=findPar(par[node]);
    }
    void UnionbyRank(int u,int v)
    {
        int p1=findPar(u);
        int p2=findPar(v);
        if(p1==p2)
        return;
        if(rank[p1]>rank[p2])
        par[p2]=p1;
        else if(rank[p2]>rank[p1])
        par[p1]=p2;
        else
        {
            rank[p1]++;
            par[p2]=p1;
        }
        
    }
};
class Solution {
  public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int cntextras=0;
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)==ds.findPar(v))
            cntextras++;
            else
            ds.UnionbyRank(u,v);
        }
        int comp=0;
        for(int i=0;i<n;i++)
        {
            if(ds.par[i]==i)
            comp++;
        }
        int ans=comp-1;
        if(cntextras>=ans)
        return ans;
        
        return -1;
        
        
    }
};