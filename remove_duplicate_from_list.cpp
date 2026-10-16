
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution s;
    head = s.deleteDuplicates(head);

    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }

    return 0;
}
