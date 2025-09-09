class Solution {
public:
    Node *mergeSort(Node *h) {
        if (!h || !h->next) return h;
        Node *s = h, *f = h->next;
        while (f && f->next) s = s->next, f = f->next->next;
        Node *r = s->next;
        s->next = nullptr;
        return merge(mergeSort(h), mergeSort(r));
    }
    
    Node *merge(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
};
