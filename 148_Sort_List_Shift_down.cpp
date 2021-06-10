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
    ListNode* sortList(ListNode* head) {
        return MSort( head, nullptr );
    }

    ListNode* MSort( ListNode *head, ListNode *tail )
    {
        if( head == nullptr )
            return head;

        if( head->next == tail )
        {
            head->next = nullptr;
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while( fast != tail )
        {
            slow = slow->next;
            fast = fast->next;
            if( fast != tail )
                fast = fast->next;
        }
        ListNode *mid = slow;

        ListNode *l1 = MSort( head, mid );
        ListNode *l2 = MSort( mid, tail );
        ListNode *m = Merge( l1, l2 );
        return m;
    }

    ListNode* Merge( ListNode *l1, ListNode *l2 )
    {
        ListNode *dummy_head = new ListNode(0);
        ListNode *p = dummy_head;

        while( l1 != nullptr ||  l2 != nullptr )
        {
            if( l1 != nullptr && l2 != nullptr )
            {
                if( l1->val <= l2->val )
                {
                    p->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            else if( l1 != nullptr && l2 == nullptr )
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        ListNode *ret = dummy_head->next;
        delete dummy_head;
        return ret;
    }
};