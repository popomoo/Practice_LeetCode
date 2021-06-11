using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if( head == nullptr )
            return head;

        ListNode *cnt = head;
        int len = 0;
        while( cnt != nullptr )
        {
            len++;
            cnt = cnt->next;
        }

        k = k % len;
        if( k == 0 )
            return head;

        ListNode *tail = head;
        ListNode *new_tail = head;

        for( int i = 0; i < k && tail != nullptr; i++ )
            tail = tail->next;

        while( tail->next != nullptr )
        {
            new_tail = new_tail->next;
            tail = tail->next;
        }

        ListNode *new_head = new_tail->next;
        new_tail->next = nullptr;
        tail->next = head;
        head = new_head;
        
        return head;
    }
};