using namespace std;

/*Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (head == nullptr) {
            return head;
        }

        int len = 0;
        ListNode* p = head;
        while (p != nullptr) {
            len++;
            p = p->next;
        }

        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;

        for (int i = 1; i < len; i *= 2) {
            ListNode *pre = dummy_head;
            ListNode *cur = dummy_head->next;

            while (cur != nullptr) {

                ListNode* l1 = cur;
                for (int j = 1; j < i && cur->next != nullptr; j++) 
                    cur = cur->next;

                ListNode *l2 = cur->next;
                cur->next = nullptr;
                cur = l2;
                for (int j = 1; j < i && cur != nullptr && cur->next != nullptr; j++) 
                    cur = cur->next;

                ListNode *next_node = nullptr;
                if (cur != nullptr) {
                    next_node = cur->next;
                    cur->next = nullptr;
                }

                ListNode* m = Merge(l1, l2);
                pre->next = m;
                while (pre->next != nullptr) 
                    pre = pre->next;

                cur = next_node;
            }
        }

        head = dummy_head->next;
        delete dummy_head;
        return head;
    }

    ListNode* Merge(ListNode* l1, ListNode* l2) {

        ListNode* dummy_head = new ListNode(0);
        ListNode *p = dummy_head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) 
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

        if ( l1 != nullptr )
            p->next = l1;
        else if (l2 != nullptr)
            p->next = l2;

        ListNode *ret = dummy_head->next;
        delete dummy_head;
        return ret;
    }
};