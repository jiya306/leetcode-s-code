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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (count == n) {
            return head->next;
        }

        temp = head;

        for (int i = 1; i < count - n; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};