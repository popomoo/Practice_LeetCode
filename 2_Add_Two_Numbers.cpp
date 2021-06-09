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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if( l1 == nullptr && l2 == nullptr )
            return nullptr;

        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int carry = 0;

        while( l1 != nullptr || l2 != nullptr )
        {
            int sum = 0;
            if( l1 == nullptr && l2 != nullptr )
            {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else if( l2 == nullptr && l1 != nullptr )
            {
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else
            {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            tail->next = new ListNode( sum % 10 );
            tail = tail->next;
            carry = sum / 10;
        }

        if( carry != 0 )
            tail->next = new ListNode( carry );

        return head->next;
    }
};