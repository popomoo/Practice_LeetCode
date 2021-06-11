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
    void reorderList(ListNode* head) {

        if( head == nullptr )
            return;

        ListNode *slow = head;
        ListNode *fast = head;

        while( fast->next != nullptr && fast->next->next != nullptr )
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if( slow == fast )
            return;

        ListNode *mid = slow;

        ListNode *head2 = mid->next;
        mid->next = nullptr;
        ListNode *cur = head2;

        while( head2->next != nullptr )
        {
            ListNode *temp = head2->next->next;
            head2->next->next = cur;
            cur = head2->next;
            head2->next = temp;
        }

        ListNode *l1 = head;
        ListNode *l2 = cur;

        ListNode *dummy_head = new ListNode(0);
        ListNode *temp = dummy_head;

        while( l1 != nullptr && l2 != nullptr )
        {
            temp->next = l1;
            l1 = l1->next;

            temp = temp->next;

            temp->next = l2;
            l2 = l2->next;

            temp = temp->next;
        }

        if( l1 != nullptr )
            temp->next = l1;
        if( l2 != nullptr )
            temp->next = l2;

        head = dummy_head->next;
        delete dummy_head;
        return;
    }
};