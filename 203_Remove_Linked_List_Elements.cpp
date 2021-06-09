using namespace std;

/*** Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if( head == nullptr )
            return head;

        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        head = dummy_head;

        while( head->next != nullptr )
        {
            if( head->next->val == val )
            {
                ListNode *temp = head->next;
                head->next = temp->next;
                delete temp;
            }
            else
                head = head->next;
        }

        head = dummy_head->next;
        delete dummy_head;
        return head;
    }

    ListNode* removeElements1(ListNode* head, int val) {

        if( head == nullptr )
            return head;

        head->next = removeElements( head->next, val );
        return ((head->val == val) ? head->next : head);
    }
};