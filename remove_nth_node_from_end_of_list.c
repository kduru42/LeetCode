#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};
 


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* iter;
    struct ListNode* to_free;
    int i = 1;
    iter = head;
    while (iter->next != NULL)
    {
        iter = iter->next;
        i++;
    }
    iter = head;
    if (n == i)
    {
        head = head->next;
        free(iter);
        return(head);
    }
    else if (i == 1)
    {
        free(iter);
        return(NULL);
    }
    iter = head;
    for (int j = 0; j < i - n - 1; j++)
        iter = iter->next;
    to_free = iter->next;
    if (iter->next->next == NULL)
        iter->next = NULL;
    else
        iter->next = iter->next->next;
    free(to_free);
    return (head);
}