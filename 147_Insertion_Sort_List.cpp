using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;

        ListNode *sorted = head;
        ListNode *cur = sorted->next;

        if( head == nullptr )
            return head;

        while( cur != nullptr )
        {
            if( cur->val < sorted->val )
            {
                ListNode *pre = dummy_head;
                while( pre->next != sorted && pre->next->val <= cur->val )
                    pre = pre->next;
                sorted->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
                pre = cur;
            }
            else
                sorted = sorted->next;

            cur = sorted->next;
        }
        
        head = dummy_head->next;
        delete dummy_head;
        return head;
    }
};