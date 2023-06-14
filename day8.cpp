1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0;
        int cnt=0,maxi=0;
        while(j<nums.size())
        {
            if(nums[j]==1)
            {   
                cnt++;
            }
            else
            {
                cnt=0;
            }
             maxi=max(maxi,cnt);
             j++;
        }
    return maxi;
    }
};

2)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxl[n],maxr[n];
        maxl[0]=height[0];
        for(int i=1;i<n;i++)
        maxl[i]=max(maxl[i-1],height[i]);

        maxr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxr[i]=max(maxr[i+1],height[i]);
        }
       
        vector<int>v;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            v.push_back(min(maxr[i],maxl[i])-height[i]);
        }
        for(int i=0;i<n;i++)
        {
            ans+=v[i];
        }
        return ans;

    }
};

3)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans={};
        //int target=0;
        //set<vector<int>>s;
        int n=nums.size(),j=0,k=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]>0)
            break;
            if(i != 0 && (nums[i] == nums[i-1])) continue;
            j=i+1;
            k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    //bina set use kare agr krna chahe toh
                    while(k>j && nums[j]==nums[j-1])
                    j++;
                    while(k>j && nums[k]==nums[k+1])
                    k--;
                }
                else if(sum>0)
                k--;
                else
                j++;
            }      
        }
        
        return ans;
    }
};

4) //Intersection of 2LIs
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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int cnt1=0;
        while(curr1!=NULL)
        {
            curr1=curr1->next;
            cnt1++;
        }
        cout<<cnt1<<endl;
        curr1=l1;
        int cnt2=0;
        while(curr2!=NULL)
        {
            curr2=curr2->next;
            cnt2++;
        }
        cout<<cnt2<<endl;
        curr2=l2;
        int cnt=0;
        if(cnt1>cnt2)
        {
            cnt=cnt1-cnt2;
            while(cnt!=0)
            {
                curr1=curr1->next;
                cnt--;
            }
        }
        else if(cnt2>cnt1)
        {
            cnt=cnt2-cnt1;
            while(cnt!=0)
            {
                curr2=curr2->next;
                cnt--;
            }
        }
        else 
        {
            while(l1!=NULL)
            {
                if(l1==l2)
                return l1;
                l1=l1->next;
            }
        }

        while(curr1!=NULL)
        {
            if(curr1==curr2)
            return curr1;
            curr1=curr1->next;
            curr2=curr2->next;
            
        }
        return NULL;
        
    }
};

5)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
//create the copy
    Node* copyRandomList(Node* head) {
        Node* it=head;
        Node* next=head;

        while(it!=NULL)
        {
            next=it->next;
            Node* copy=new Node(it->val);
            it->next=copy;
            copy->next=next;
            it=next;
        }

        it=head;
        while(it!=NULL)
        {
            if(it->random!=NULL)
            {
                it->next->random=it->random->next;
            }
            it=it->next->next;
        }
        it=head;
        //next=head;
        Node* dummy=new Node(-1);
        Node *temp=dummy;
        while(it!=NULL)
        {
            next=it->next->next;
           temp->next=it->next;
           it->next=next;
           temp=temp->next;
           it=next;
           
        }
        return dummy->next;


    }
};

6)Rotate a Linked List 
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
        return NULL;
        ListNode* curr=head;
        int cnt=1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            cnt++;
        }
        
        curr->next=head;
        k=k%cnt; //itne times rotate krna

        k=cnt-k; //head hoga cnt-k wala
        while(k--)
        {
            curr=curr->next;
        }
        head=curr->next;
        curr->next=nullptr;
        return head;

    }
};