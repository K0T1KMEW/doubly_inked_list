#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"
#pragma warning(disable : 4996)

// ������� ��� ������������� ListEntry
void ListEntry_Init(ListEntry* entry) {
    entry->prev = entry;
    entry->next = entry;
}

// ������� ��� ������� ������ �������� ����� ����������
void ListEntry_InsertAfter(ListEntry* entry, ListEntry* newEntry) {
    newEntry->next = entry->next;
    newEntry->prev = entry;
    entry->next->prev = newEntry;
    entry->next = newEntry;
}

// ������� ��� �������� �������� �� ������
void ListEntry_Remove(ListEntry* entry) {
    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;
}

void ListEntry_Swap(ListEntry* a, ListEntry* b) {
    if (a == b) return;

    ListEntry* aPrev = a->prev;
    ListEntry* aNext = a->next;
    ListEntry* bPrev = b->prev;
    ListEntry* bNext = b->next;

    if (a->next == b) { // ���� �������� ��������  #4
        aPrev->next = b;
        b->prev = aPrev;
        b->next = a;
        a->prev = b;
        a->next = bNext;
        bNext->prev = a;
    }
    else if (b->next == a) { // ���� �������� �������� � �������� �������
        bPrev->next = a;
        a->prev = bPrev;
        a->next = b;
        b->prev = a;
        b->next = aNext;
        aNext->prev = b;
    }
    else { // ���� �������� �� �������� #8
        aPrev->next = b;
        aNext->prev = b;
        bPrev->next = a;
        bNext->prev = a;

        a->prev = bPrev;
        a->next = bNext;
        b->prev = aPrev;
        b->next = aNext;
    }
}

// ������� ��� �������� ������ ���� ������
StringNode* StringNode_Create(const char* data) {
    StringNode* node = (StringNode*)malloc(sizeof(StringNode));
    if (node == NULL) {
        perror("Failed to allocate memory for StringNode");
        exit(EXIT_FAILURE);
    }

    node->data = (char*)malloc(strlen(data) + 1);
    if (node->data == NULL) {
        perror("Failed to allocate memory for string data");
        free(node);
        exit(EXIT_FAILURE);
    }

    strcpy(node->data, data);
    ListEntry_Init(&node->entry);
    return node;
}

// ������� ��� ������������ ������, ������� ����� ������
void StringNode_Destroy(StringNode* node) {
    free(node->data);
    free(node);
}

// ������� ����������� ���������� ��� ����������� ������ �����
void BubbleSortList(ListEntry* head) {
    int swapped;
    ListEntry* ptr;
    ListEntry* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr = head->next;

        while (ptr->next != lptr && ptr->next != head) {
            StringNode* a = (StringNode*)ptr;
            StringNode* b = (StringNode*)ptr->next;

            if (strcmp(a->data, b->data) > 0) {
                ListEntry_Swap(ptr, ptr->next);
                swapped = 1;
                // ptr �������� �� �����, �.�. �������� ���������� �������
            }
            else {
                ptr = ptr->next;
            }
        }
        lptr = ptr;
    } while (swapped);
}

// ������� ��� ������ ������ �����
void PrintList(ListEntry* head) {
    ListEntry* ptr = head->next;
    while (ptr != head) {
        StringNode* node = (StringNode*)ptr;
        printf("%s\n", node->data);
        ptr = ptr->next;
    }
}
