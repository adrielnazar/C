#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct List {
    int data[MAX_SIZE];
    int size;
} List;

List*createList() {
    List* newList = (List*)malloc(sizeof(List));
    newList->size = 0;
    return newList;
}

void insert (List* list, int data) {
    if (list->size == MAX_SIZE) {
        printf("List is full\n");
        return;
    }
    list->data[list->size++] = data;
}

void removeElement(List* list, int index) {
    int i;
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    for (i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

int isEmpty(List* list) {
    return list->size == 0;
}

void printList (List*list) {
    int i;
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }
    for (i = 0; i < list->size; i++) {
        printf("%d", list->data[i]);
    }
    printf("\n");
}

int main() {
    List* myList = createList();
    insert(myList, 4);
    insert(myList, 7);
    insert(myList, 8);
    insert(myList, 10);
    printList (myList);
    removeElement(myList, 2);
    printList(myList);

    return 0;
}