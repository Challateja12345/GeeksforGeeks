class Solution {
public:
    Node* segregate(Node* head) {
        if (!head) return head;
        Node* zero = nullptr, *one = nullptr, *two = nullptr;
        Node* zeroTail = nullptr, *oneTail = nullptr, *twoTail = nullptr;
        
        while (head) {
            Node* next = head->next;
            head->next = nullptr;
            
            if (head->data == 0) {
                if (!zero) zero = zeroTail = head;
                else zeroTail = zeroTail->next = head;
            } else if (head->data == 1) {
                if (!one) one = oneTail = head;
                else oneTail = oneTail->next = head;
            } else {
                if (!two) two = twoTail = head;
                else twoTail = twoTail->next = head;
            }
            head = next;
        }
        
        if (zeroTail) {
            head = zero;
            zeroTail->next = one ? one : two;
            if (oneTail) oneTail->next = two;
        } else if (oneTail) {
            head = one;
            oneTail->next = two;
        } else {
            head = two;
        }
        
        return head;
    }
};
