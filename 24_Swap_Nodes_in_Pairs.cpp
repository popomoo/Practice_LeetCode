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
    ListNode* swapPairs(ListNode* head) {

        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;

        ListNode *p = dummy_head;

        while( p->next != nullptr && p->next->next != nullptr )
        {
            ListNode *node1 = p->next;
            ListNode *node2 = node1->next;
            ListNode *next = node2->next;

            node2->next = node1;
            node1->next = next;
            p->next = node2;

            p = node1;
        }

        head = dummy_head->next;
        delete dummy_head;
        return head;
    }
};