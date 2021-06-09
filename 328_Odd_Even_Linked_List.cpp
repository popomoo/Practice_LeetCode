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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* dummy_odd = new ListNode(0);
        ListNode* odd = dummy_odd;
        ListNode* dummy_even = new ListNode(0);
        ListNode* even = dummy_even;
        int count = 1;

        while( head != nullptr )
        {
            if( count%2 != 0 )
            {
                odd->next = head;
                odd = odd->next;
            }
            else
            {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            count++;
        }

        even->next = nullptr;
        odd->next = dummy_even->next;

        head = dummy_odd->next;

        delete dummy_odd;
        delete dummy_even;

        return head;
    }
};