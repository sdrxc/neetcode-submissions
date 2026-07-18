class Solution {
public:

    ListNode* getKth(ListNode* curr, int k)
    {
        while(curr && k--)
            curr = curr->next;

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while(true)
        {
            ListNode* kth = getKth(groupPrev, k);

            if(kth == nullptr)
                break;

            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect group
            ListNode* temp = groupPrev->next;

            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }
};