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

    void solve(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int>ans; 
     solve(root,ans);
     return ans;  
    }
};

//iteratively could be done using stack

2)
class Solution {
public:
vector<int> solve(TreeNode *root,vector<int>&ans)
{
    if(root!=NULL)
    {
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
    return ans;
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        return solve(root,ans);
    }
};

3)
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

    void solve(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        solve(root->left,ans);
        solve(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};

4)//Left View
 void solve(Node *root,vector<int>&ans,int clvl)
    {
        if(root==NULL)
        return;
        if(clvl>ans.size())
        ans.push_back(root->data);
        solve(root->left,ans,clvl+1);
        solve(root->right,ans,clvl+1);
        
    }
    
vector<int> leftView(Node *root)
{
   vector<int>ans;
   if(root==NULL)
   return ans;
   ans.push_back(root->data);
   int clvl=1;
    solve(root,ans,clvl);
    return ans;

5)
//Function to return a list containing the bottom view of the given tree.

  void solve(Node *root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        map<int,int>m; //hd is the key
        queue<pair<Node*,int>>q; // node,hd
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int hd=it.second;
           // if(m.find(hd)==m.end())
            //{
                m[hd]=node->data;
            //}
                if(node->left!=NULL)
                q.push({node->left,hd-1});
                if(node->right!=NULL)
                q.push({node->right,hd+1});
        }
        for(auto it:m)
        ans.push_back(it.second);
    }
       
  
    vector <int> bottomView(Node *root) {
        vector<int>ans;
         solve(root,ans);
         return ans;

    }

6)// Top View
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void solve(Node *root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        map<int,int>m; //hd is the key
        queue<pair<Node*,int>>q; // node,hd
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int hd=it.second;
            if(m.find(hd)==m.end())
            {
                m[hd]=node->data;
            }
                if(node->left!=NULL)
                q.push({node->left,hd-1});
                if(node->right!=NULL)
                q.push({node->right,hd+1});
        }
        for(auto it:m)
        ans.push_back(it.second);
        
    }
    vector<int> topView(Node *root)
    {
        vector<int>ans;
         solve(root,ans);
         return ans;
    }

};

7)//vertical order
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m; //hd->vd->multiple valued set
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>ans;
        q.push({root,{0,0}});// node->{hd,vd}
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int hd=it.second.first;
            int vd=it.second.second;
            m[hd][vd].insert(node->val);
            if(node->left)
            q.push({node->left,{hd-1,vd+1}});
            if(node->right)
            q.push({node->right,{hd+1,vd+1}});

        }
        for(auto it:m)
        {
            vector<int>v;
            for(auto x:it.second)
            {
                for(auto k:x.second)
                {
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;

    }
};

8)Morris inorder
//Morris Inorder
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL && prev->right!=curr)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }

            }
        }
        return ans;
    }
};

9) Morris Preorder
//Morris Inorder
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL && prev->right!=curr)
                {
                    prev->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    
                    curr=curr->right;
                }

            }
        }
        return ans;
    }
};

