#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Reverse linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    // Find middle
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* second = reverse(slow->next);

    // Compare both halves
    struct ListNode* first = head;
    while (second != NULL) {
        if (first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}