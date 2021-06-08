
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if( head == nullptr )
            return head;

        ListNode *pre = nullptr;
        ListNode *cur = head;
        int count = 1;

        while( count < left )
        {
            pre = cur;
            cur = cur->next;
            count++;
        }

        ListNode *r = cur;
        while( count < right && cur->next != nullptr)
        {
            ListNode *temp = cur->next->next;
            cur->next->next = r;
            r = cur->next;
            cur->next = temp;
            count++;
        }

        if( pre != nullptr )
        {
            pre->next = r;
            return head;
        }
        else
            return r;
    }
};