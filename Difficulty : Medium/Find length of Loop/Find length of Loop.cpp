class Solution {
public:
    int lengthOfLoop(Node* head) {
        Node *s = head, *f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next; 
            if (s == f) {
                int cnt = 1;
                while (s->next != f) s = s->next, cnt++;
                return cnt;  
            } 
        } 
        return 0;
    }
};
