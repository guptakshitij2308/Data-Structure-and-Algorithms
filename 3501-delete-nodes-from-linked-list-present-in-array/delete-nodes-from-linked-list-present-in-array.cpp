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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        unordered_set<int>st;
        for(auto &it:nums) st.insert(it);
        ListNode *prev=dummy,*temp=head;
        while(temp) {
            if(st.find(temp->val)==st.end()) {
                prev->next=temp;
                prev=temp;
            }
            temp=temp->next;
        }
        prev->next=nullptr;
        return dummy->next;
    }
};