
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
    ListNode* reverseList(ListNode* head) {

        ListNode *pre = nullptr;
        ListNode *cur = head;

        while( cur != nullptr )
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseList2(ListNode* head) {

        if( head == nullptr || head->next == nullptr )
            return head;

        ListNode *ret = reverseList( head->next );
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }

    ListNode* reverseList3(ListNode* head) {

        if( head == nullptr )
            return head;

        ListNode *cur = head;

        while( head->next != nullptr )
        {
            ListNode *t = head->next->next;
            head->next->next = cur;
            cur = head->next;
            head->next = t;
        }
        return cur;
    }
};