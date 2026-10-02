class MyHashMap {
    static const int SIZE = 10007;

    struct Node {
        int key, value;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    Node* buckets[SIZE];

public:
    MyHashMap() {
        for (int i = 0; i < SIZE; i++)
            buckets[i] = nullptr;
    }

    int hash(int key) {
        return key % SIZE;
    }

    void put(int key, int value) {
        int idx = hash(key);
        Node* curr = buckets[idx];

        while (curr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }

        Node* node = new Node(key, value);
        node->next = buckets[idx];
        buckets[idx] = node;
    }

    int get(int key) {
        int idx = hash(key);
        Node* curr = buckets[idx];

        while (curr) {
            if (curr->key == key)
                return curr->value;

            curr = curr->next;
        }

        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        Node* curr = buckets[idx];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev)
                    prev->next = curr->next;
                else
                    buckets[idx] = curr->next;

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */