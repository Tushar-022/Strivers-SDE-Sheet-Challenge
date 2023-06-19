1)//Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
                
            }
            ans.push_back(v);
        }
        return ans;
    }
};

2)//Depth
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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

3)//Diameter
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

    int solve(TreeNode* root,int& maxi)
    {
        if(root==NULL)
        return 0;
        int lh=solve(root->left,maxi);
        int rh=solve(root->right,maxi);
        maxi=max(maxi,lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        int maxi=0;
         solve(root,maxi);
        return maxi;
    }
};

4)// Lca 
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

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
        return NULL;
        if(root==p || root==q)
        return root;
        TreeNode* leftans=solve(root->left,p,q);
        TreeNode* rightans=solve(root->right,p,q);
        if(leftans==NULL && rightans==NULL)
        return NULL;
       else if(leftans!=NULL && rightans==NULL)
        
            return leftans;
            else if(leftans==NULL && rightans!=NULL)
            return rightans;  
       else if(leftans!=NULL && rightans!=NULL)
        return root;
        else
         return NULL;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};

5)//isSameTree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        return true;
        if((p==NULL && q!=NULL) ||(p!=NULL && q==NULL))
        return false;
        if(p->val!=q->val)
        return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

6)//Zigzag order
/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
         vector<int>v;
        while(!s1.empty() || !s2.empty())
        {
           
            while(!s1.empty())
            {
                TreeNode* temp=s1.top();
                s1.pop();
                v.push_back(temp->val);
                if(temp->left)
                s2.push(temp->left);
                if(temp->right)
                s2.push(temp->right);
            }
            if(v.size()!=0)
            ans.push_back(v);
            v.clear();

            while(!s2.empty())
            {
                TreeNode* temp=s2.top();
                s2.pop();
                v.push_back(temp->val);
                if(temp->right)
                s1.push(temp->right);
                if(temp->left)
                s1.push(temp->left);
            }
            if(v.size()!=0)
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};

7)Height Balanced
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
    int solve(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int lh=solve(root->left);
        if(lh==-1)
        return -1;
        int rh=solve(root->right);
        if(rh==-1)
        return -1;
        if(abs(lh-rh)>1)
        return -1;
       return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
         if(root==NULL)
          return 1;
        return solve(root)!=-1;
       
    }
};

8)//Boundary
 bool checkLeaf(Node* root)
    {
        return root->left==NULL && root->right==NULL;
    }
    
    void rbnd(Node*root,vector<int>&ans)
    {
        Node*curr=root;
        vector<int>temp;
        while(curr!=NULL)
        {
            if(!checkLeaf(curr))
            temp.push_back(curr->data);
            if(curr->right)
            curr=curr->right;
            else
            curr=curr->left;
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        ans.push_back(temp[i]);
    }
    
    void leaf(Node* root,vector<int>&ans)
    {
        if(checkLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left)
        leaf(root->left,ans);
        
        if(root->right)
        leaf(root->right,ans);
    }
    
    void lbnd(Node* root,vector<int>& ans)
    {
        Node*curr=root;
        while(curr!=NULL)
        {
            if(!checkLeaf(curr))
            ans.push_back(curr->data);
            if(curr->left)
            curr=curr->left;
            else
            curr=curr->right;
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
        return ans;
       // ans.push_back(root->data);
       if(!checkLeaf(root))
       ans.push_back(root->data);
        
        lbnd(root->left,ans);
        leaf(root,ans); // from left to right
        rbnd(root->right,ans);
        return ans;
        
    }


