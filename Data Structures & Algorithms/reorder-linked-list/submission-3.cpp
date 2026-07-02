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
    void reorderList(ListNode* head) {
        
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while(curr)
        {
            nodes.push_back(curr);
            curr=curr->next;
        }

        int left=0, right = nodes.size()-1;

        while(left<right)
        {
            nodes[left]->next = nodes[right];
            left++;

            if(left==right) continue;

            nodes[right]->next = nodes[left];
            right--;
        }
        
        nodes[left]->next = nullptr;
    }
};
