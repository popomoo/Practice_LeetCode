using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if( head == nullptr )
            return head;

        ListNode *pre = nullptr;
        ListNode *cur = head;
        int tag = 1;

        while( cur != nullptr && cur->val < x )
        {
            pre = cur;
            cur = cur->next;
            tag++;
        }
        
        if( cur == nullptr )
            return head;

        ListNode *p = nullptr;
        ListNode *q = head;
        int count = 1;

        while( q != nullptr )
        {
            if( q->val < x && count > tag )
            {
                p->next = q->next;
                q->next = cur;
                if( pre != nullptr )
                    pre->next = q;
                else
                    head = q;
                pre = q;
                q = p->next;
            }
            else if( q->val >= x && count < tag )
            {
                p->next = q->next;
                q->next = cur->next;
                cur->next = q;
                q = p->next;
            }
            else
            {
                p = q;
                q = q->next;
                count++;
            }
        }
        return head;
    }

    ListNode* partition1(ListNode* head, int x) {

        if( head == nullptr )
            return head;

        ListNode *dummy_small = new ListNode(0);
        ListNode *small = dummy_small;
        ListNode *dummy_big = new ListNode(0);
        ListNode *big = dummy_big;

        while( head != nullptr )
        {
            if( head->val < x )
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }

        big->next = nullptr;
        small->next = dummy_big->next;
        head = dummy_small->next;
        delete dummy_small;
        delete dummy_big;
        return head;
    }
};