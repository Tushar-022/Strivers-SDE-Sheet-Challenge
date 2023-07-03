class Solution {
public:

/// TC(NLogK)
    int furthestBuilding(vector<int>& ht, int bricks, int ladders) {
        
        int ans=0,n=ht.size();
        for(int i=1;i<n;i++)
        {
            int d=ht[i]-ht[i-1];
            if(d>0)
            pq.push(d);
            if(pq.size()>ladders)
            bricks-=pq.pop();
            if(bricks<0)
            return i;

        }
        return n-1;
    }
};




        class StockSpanner {
public:
stack<pair<int,int>>st; 
int i;
    StockSpanner() {
        i=1;
    }
    
    int next(int price) {
        int ans=0;
        if(st.size()==0)
        {
            ans=i;
        }
        else if(st.size()>0 && st.top().first>price)
        {
            ans=i-st.top().second;
        }
        else if(st.size()>0 && st.top().first<=price)
        {
            while(st.size()>0 && st.top().first<=price)
            {
                st.pop();
            }
            if(st.size()==0)
            {
                ans=i;
            }
            else{
                ans=i-st.top().second;
            }
        } 
        st.push({price,i});
        i++;
        return ans;
        
    }
};

 // Partition the List
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr1 = new ListNode(-1);
        ListNode* temp1 = curr1;
        ListNode* curr2 = new ListNode(-1);
        ListNode* temp2 = curr2;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (curr->val < x) {
                temp1->next = curr;
                temp1 = temp1->next;
            } else {
                temp2->next = curr;
                temp2 = temp2->next;
            }
            curr = curr->next;
        }
        
        temp2->next = nullptr; // Set next pointer to NULL for the last node in curr2
        temp1->next = curr2->next; // Connect the two partitions
        
        ListNode* ans = curr1->next;
        delete curr1; // Free the memory allocated for the dummy node
        
        return ans;
    }
};
