#include "func.h"
int main() {
    ListEntry head;
    ListEntry_Init(&head);
    StringNode* node1 = StringNode_Create("banana");
    ListEntry_InsertAfter(&head, &node1->entry);
    printf("Before sorting:\n");
    PrintList(&head);
    BubbleSortList(&head);
    printf("After sorting:\n");
    PrintList(&head);
    ListEntry_Remove(&node1->entry);
    StringNode_Destroy(node1);
    return 0;
}