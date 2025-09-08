class Solution {
public:
    // --- Added to satisfy problems that expect reverse() ---
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* cur  = head;
        while (cur) {
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    // --- Your function (now adjacency-safe) ---
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // count length
        int n = 0;
        for (Node* t = head; t; t = t->next) ++n;

        // invalid k or same node (middle in odd length)
        if (k > n || 2*k - 1 == n) return head;

        // find k-th from start: x (prev px)
        Node *x = head, *px = nullptr;
        for (int i = 1; i < k; ++i) { px = x; x = x->next; }

        // find k-th from end: y (prev py)
        Node *y = head, *py = nullptr;
        for (int i = 1; i < n - k + 1; ++i) { py = y; y = y->next; }

        if (x == y) return head; // already handled above, but safe
        // Handle adjacency carefully
        if (py == x) { // x before y (adjacent)
            if (px) px->next = y; else head = y;
            x->next = y->next;
            y->next = x;
        } else if (px == y) { // y before x (adjacent)
            if (py) py->next = x; else head = x;
            y->next = x->next;
            x->next = y;
        } else { // non-adjacent
            if (px) px->next = y; else head = y;
            if (py) py->next = x; else head = x;
            Node* tmp = x->next;
            x->next = y->next;
            y->next = tmp;
        }
        return head;
    }

    // --- Adapters for common GFG signatures ---
    Node* swapKthNode(Node* head, int K) { return swapKth(head, K); }
    Node* swapkthnode(Node* head, int num, int K) { (void)num; return swapKth(head, K); }
};
