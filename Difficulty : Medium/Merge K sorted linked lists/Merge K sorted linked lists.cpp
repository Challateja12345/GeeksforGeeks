class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        auto cmp = [](Node* a, Node* b) { return a->data > b->data; };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        
        for (Node* head : arr) if (head) pq.push(head);
        
        Node dummy(-1), *tail = &dummy;
        while (!pq.empty()) {
            Node* node = pq.top(); pq.pop();
            tail->next = node; tail = node;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};
