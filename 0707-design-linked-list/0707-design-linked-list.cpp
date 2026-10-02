class MyLinkedList {
    struct Node {
        int val;
        Node* prev;
        Node* next;

        Node(int x) {
            val = x;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int sz;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    int get(int index) {
        if (index < 0 || index >= sz)
            return -1;

        Node* curr;

        if (index < sz / 2) {
            curr = head;
            for (int i = 0; i < index; i++)
                curr = curr->next;
        } else {
            curr = tail;
            for (int i = sz - 1; i > index; i--)
                curr = curr->prev;
        }

        return curr->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);

        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        sz++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);

        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        sz++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0)
            index = 0;

        if (index > sz)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == sz) {
            addAtTail(val);
            return;
        }

        Node* curr = head;

        if (index < sz / 2) {
            for (int i = 0; i < index; i++)
                curr = curr->next;
        } else {
            curr = tail;
            for (int i = sz - 1; i > index; i--)
                curr = curr->prev;
        }

        Node* node = new Node(val);

        node->prev = curr->prev;
        node->next = curr;
        curr->prev->next = node;
        curr->prev = node;

        sz++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz)
            return;

        Node* curr;

        if (index < sz / 2) {
            curr = head;
            for (int i = 0; i < index; i++)
                curr = curr->next;
        } else {
            curr = tail;
            for (int i = sz - 1; i > index; i--)
                curr = curr->prev;
        }

        if (curr->prev)
            curr->prev->next = curr->next;
        else
            head = curr->next;

        if (curr->next)
            curr->next->prev = curr->prev;
        else
            tail = curr->prev;

        delete curr;
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */