#pragma once

typedef struct ListEntry {
    struct ListEntry* prev;
    struct ListEntry* next;
} ListEntry;

typedef struct StringNode {
    ListEntry entry;
    char* data;
} StringNode;

void ListEntry_Init(ListEntry* entry);

void ListEntry_InsertAfter(ListEntry* entry, ListEntry* newEntry);

void ListEntry_Remove(ListEntry* entry);

void ListEntry_Swap(ListEntry* a, ListEntry* b);

StringNode* StringNode_Create(const char* data);

void StringNode_Destroy(StringNode* node);

void BubbleSortList(ListEntry* head);

void PrintList(ListEntry* head);