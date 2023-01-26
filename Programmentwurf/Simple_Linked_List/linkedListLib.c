#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"

void addListElem(listElement *start) {
    listElement *new = malloc(sizeof(listElement));

    if (new == NULL) {
        printf("can't reserve storage.\n");
        return;
    }

    listElement *currElem = start;

    while (currElem->nextElem != NULL) {
        currElem = currElem->nextElem;      // get last elem in list
    }

    currElem->nextElem = new;               // add new to the end of list
    new->nextElem = NULL;

    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);

    printf("Please enter first name: \n");
    scanf("%s", new->firstName);

    printf("Please enter age: \n");
    scanf("%d", &(new->age));
}

void printList(const listElement *list) {
    if (list->nextElem == NULL) {
        printf("List is empty.\n");
        return;
    }

    list = list->nextElem;

    printf("\ncurrent list:\n\n");

    int index = 0;
    while (list) {
        printf("%d.", ++index);
        printf("\t last name: %s\n", list->lastName);
        printf("\t first name: %s\n", list->firstName);
        printf("\t age: %d\n", list->age);

        list = list->nextElem;
    }
}

void delListElem(listElement *start) {
    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> delListElem fcn is tbd.\n\n");
}

void delList(listElement *start) {
    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> getLenOfList fcn is tbd.\n\n");
}

int getLenOfList(listElement *start) { // we use this for save list fcn
    int counter = 0;
    listElement *currElem = start;
    while (currElem->nextElem != NULL) { // get last elem in list
        currElem = currElem->nextElem;
        counter++;
    }
    return counter;
}

void saveList(listElement *start) {
    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> saveList fcn is tbd.\n\n");
}

void loadList(listElement *start) {
    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> loadList fcn is tbd.\n\n");

    printf("loading data will be append to current list...\n");
    printList(start); // show loaded list
}

void exitFcn(listElement *start) {
    printf("\n>> exitFcn fcn is tbd.\n\n");
}

void sortList(listElement *start) {
    printf("\n>>sortList fcn is tbd.\n\n");
}

void stringToLower(char *string) {
    printf("\n>>stringToLower fcn is tbd.\n\n");
}
