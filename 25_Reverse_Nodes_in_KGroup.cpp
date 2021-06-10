using namespace std;

/*Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        
        ListNode *pre = dummy_head;
        ListNode *last = pre;

        while( head != nullptr )
        {
            for( int i = 0; i < k; i++ )
            {
                last = last->next;
                if( last == nullptr )
                {
                    ListNode *ret = dummy_head->next;
                    delete dummy_head;
                    return ret;
                }
            }

            ListNode *grp_end = last->next;
            ListNode *cur = head;
            
            while( head->next != grp_end )
            {
                ListNode *temp = head->next->next;
                head->next->next = cur;
                cur = head->next;
                head->next = temp;
            }

            pre->next = last;
            pre = head;
            last = pre;
            head = head->next;
        }

        ListNode *ret = dummy_head->next;
        delete dummy_head;
        return ret;
    }
};