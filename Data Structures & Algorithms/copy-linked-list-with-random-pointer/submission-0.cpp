class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        // Pass 1: Create copies
        while(curr)
        {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        // Pass 2: Connect pointers
        while(curr)
        {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};