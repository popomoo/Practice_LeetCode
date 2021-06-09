using namespace std;

/** Definition for singly-linked list. **/

 struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *cur = dummy_head;

        while( cur->next != nullptr && cur->next->next != nullptr )
        {
            if( cur->next->next->val != cur->next->val )
                cur = cur->next;
            else
            {
                int val = cur->next->val;
                while( cur->next != nullptr && cur->next->val == val )
                {
                    ListNode *temp = cur->next;
                    cur->next = temp->next;
                    delete temp;
                }
            }
        }

        head = dummy_head->next;
        delete dummy_head;
        return head;
    }
};