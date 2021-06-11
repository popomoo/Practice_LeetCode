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
    bool isPalindrome(ListNode* head) {

        if( head == nullptr )
            return true;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while( fast != nullptr )
        {
            slow = slow->next;
            fast = fast->next;
            if( fast != nullptr )
                fast = fast->next;
        }

        ListNode *head2 = slow;
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

        while( l1 != nullptr && l2 != nullptr )
        {
            if( l1->val != l2->val )
                return false;

            l1 = l1->next;
            l2 = l2->next;
        }
        
        return true;
    }
};