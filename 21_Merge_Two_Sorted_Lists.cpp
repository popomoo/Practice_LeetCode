using namespace std;

/*Definition for singly-linked list. */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *new_head = new ListNode(0);
        ListNode *head = new_head;

        while( l1 != nullptr || l2 != nullptr )
        {
            if( l1 == nullptr && l2 != nullptr )
            {
                new_head->next = l2;
                l2 = l2->next;
            }
            else if( l1 != nullptr && l2 == nullptr )
            {
                new_head->next = l1;
                l1 = l1->next;
            }
            else
            {
                if( l1->val <= l2->val )
                {
                    new_head->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    new_head->next = l2;
                    l2 = l2->next;
                }
            }
            new_head = new_head->next;
        }

        new_head->next = nullptr;
        new_head = head;
        head = head->next;
        delete new_head;
        return head;
    }
};