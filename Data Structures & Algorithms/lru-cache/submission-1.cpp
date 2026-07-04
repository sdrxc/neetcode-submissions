class LRUCache {
private:

    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Remove a node from the linked list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert a node before tail (Most Recently Used)
    void insert(Node* node) {
        Node* prevNode = tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = tail;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {

        cap = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Move to MRU position
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        // Cache full
        if(mp.size() == cap) {

            Node* lru = head->next;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);

        insert(node);

        mp[key] = node;
    }
};