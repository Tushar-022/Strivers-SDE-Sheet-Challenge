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
1)//Kth smallest
class Solution {
public:

    int ans;
    int ind;
    void solve(TreeNode* root,int &k)
    {
        if(root==NULL)
        return ;
        
        solve(root->left,k);
        ind++;
        if(ind==k)
        {
            ans=root->val;
            return;
        }
        
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        ind=0;
         solve(root,k);
         return ans;
    }
};

2)//
 public:
    
    int size,ind,ans;
    
    
    void solve1(Node* root)
    {
        if(root==NULL)
        return;
        if(root->left)
        solve1(root->left);
        size++;
        if(root->right)
        solve1(root->right);
    }
    void solve(Node *root, int k)
    {
       if(root==NULL)
       return;
       if(root->left)
       solve(root->left,k);
       ind++;
       if(ind==k)
       {
           ans=root->data;
           
           return ;
       }
       
       solve(root->right,k);
    }
    int kthLargest(Node *root, int k)
    {
        size=0;
        ans=0;
        ind=0;
        Node* curr=root;
        solve1(curr);
        curr=root;
        //cout<<size<<endl;
        k=size-k+1;
       // cout<<k<<endl;
        solve(curr,k);
        return ans;

        3)//BST Itearator

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

    void pushAll(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

4)//Serialize and Deserialize Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node)
            ans+=to_string(node->val)+",";
            else
            ans+="#,";
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.size()==0)
        return NULL;
        stringstream p(s);// allows to iterate over string as objects
        string ans;
        getline(p,ans,',');
        TreeNode* root=new TreeNode(stoi(ans));
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            getline(p,ans,',');

            if(ans=="#")
            node->left=NULL;
            else
            {
                TreeNode* leftNode=new TreeNode(stoi(ans));
                node->left=leftNode;
                q.push(leftNode);
            }

             getline(p,ans,',');

            if(ans=="#")
            node->right=NULL;
            else
            {
                TreeNode* rightNode=new TreeNode(stoi(ans));
                node->right=rightNode;
                q.push(rightNode);
            }

        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

5)//Floor in a bst
 int ans;
    void solve(Node* root,int x)
    {
     if(root==NULL)
     return;
     
     if(root->data==x)
     {
         ans=root->data;
         return;
     }
     if(root->data<x)
     {
         ans=root->data;
         solve(root->right,x);
     }
     else
     solve(root->left,x);
    }
int floor(Node* root, int x) {
    ans=-1;
    solve(root,x);
    return ans;
}

6)//ceil in a bst
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
        int ceil=-1;
    while(root!=NULL)
    {
        if(root->data==input)
        {
            ceil=root->data;
        return ceil;
        }
        else if(root->data>input)
        {
            ceil=root->data;
            root=root->left;
        }
        else
        root=root->right;
    }
    return ceil;

    7)// Binary Tree Cam

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
// Always start applying cam from the bottom
//1 means doent need any camera to be installed as not a valid node or a mid node
//2 means cam needs to be installed here
//0 leaf node so covered by cam
    int solve(TreeNode* root,int &cam)
    {
        if(root==NULL)
        return 1;
        int left=solve(root->left,cam);
        int right=solve(root->right,cam);
        if(left==0 || right==0)  // parent of a leaf node
        {
            cam++;
            return 2;
        }
        else if(left==2 || right==2)
        return 1;
        return 0;// means its a leaf node
    }
    int minCameraCover(TreeNode* root) {
        int cam=0;
        int ans= solve(root,cam);
        if(ans==0)
        cam++;
        return cam;
    }
};


