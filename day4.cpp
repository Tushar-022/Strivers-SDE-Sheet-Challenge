1)//Reverse a LinkedList
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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=curr;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

2)//Middle of a Linked List
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

3)Remove Nth node from End 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
        return NULL;
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        temp=head;
        int k=cnt-n;
        if(k==0)
        return head->next;
        for(int i=1;i<k;i++)
        {
            temp=temp->next;
        }
        ListNode* curr=temp->next;
       // cout<<curr->data;
        temp->next=curr->next;
        delete curr;
        return head;



    }
};

4) Add two numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int sum=0,carry=0;
        while(curr1!=NULL || curr2!=NULL ||carry)
        {
            sum=0;
            if(curr1!=NULL)
            {
                sum+=curr1->val;
                curr1=curr1->next;
            }
            if(curr2!=NULL)
            {
                sum+=curr2->val;
                curr2=curr2->next;

            }
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode();
            node->val=sum;
            temp->next=node;
            temp=temp->next;

        }
        return dummy->next;
    }
};

5)//Merge Two Sorted List
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* dummy=new ListNode(-1);
    ListNode*temp=dummy;
    ListNode* curr1=head1;
    ListNode* curr2=head2;
    while(curr1!=NULL &&  curr2!=NULL)
    {
        if(curr1->val>curr2->val)
        {
            temp->next=curr2;
            temp=curr2;
            curr2=curr2->next;
        }
        else
        {
            temp->next=curr1;
            temp=curr1;
            curr1=curr1->next;
        }
        
    }
    while(curr1!=NULL)
    {
        temp->next=curr1;
        temp=curr1;
        curr1=curr1->next;
    }
    
    while(curr2!=NULL)
    {
        temp->next=curr2;
        temp=curr2;
        curr2=curr2->next;
    }
    dummy=dummy->next;
    return dummy;
    }
};

6)//Delete Node in Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;

    }
};
