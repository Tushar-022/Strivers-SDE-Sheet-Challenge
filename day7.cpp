1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
2)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
          sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans = {intervals[0]};
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>ans.back()[1]) // intervals can't be merged
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1],intervals[i][1]); // intervals can be merged
        }
        return ans;
    }
};

3)
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
        
    }
};

4)// Reverse Nodes of Size k

struct node *reverse (struct node *head, int k)
    { 
        if(head==NULL)
        return NULL;
        
        struct node* curr=head;
        struct node* prev=NULL;
        struct node* next=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(prev!=NULL)
        cout<<prev->data<<endl;
        if(next!=NULL)
        head->next=reverse(next,k);
        
        return prev;
    }

    5)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

ListNode* getmid(ListNode*head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while( fast!=NULL && fast->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
    
    ListNode* rev(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return  prev;
    }
    
    bool isPalindrome(ListNode *head)
    {
     ListNode* mid=getmid(head); 
     ListNode* temp=mid->next;
     mid->next=rev(temp);
     ListNode* p1=head;
     ListNode* p2=mid->next;
     while(p2!=NULL)
     {
         if(p1->val!=p2->val)
         return false;
         p1=p1->next;
         p2=p2->next;
     }
     return true;
    }
};
   
   6)//Intersection of Linked List
     Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        
              if(head1==NULL || head2==NULL) return NULL;
    
        unordered_map<int,int>hash;
        
        while(head2){
            
            hash[head2->data]++;
            
            head2=head2->next;
        }
        Node *temp=new Node(-1);
        Node* temp2=temp;
        
        
        while(head1){
            
            if(hash.find(head1->data)!=hash.end()) {
                
               
                temp2->next=new Node(head1->data);
                temp2=temp2->next;
                
            }
            
            head1=head1->next;
            
        }
        
        return temp->next;
    
    }
