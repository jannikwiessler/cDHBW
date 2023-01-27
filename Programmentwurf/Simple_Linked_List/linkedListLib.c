#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListLib.h"

listElement *addListElem(listElement *list)
{

    listElement *new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL)
    {
        printf("can't reserve storage.\n");
        return NULL;
    }

    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);
    printf("Please enter first name: \n");
    scanf("%s", new->firstName);
    printf("Please enter age: \n");
    scanf("%d", &(new->age));

    new->nextElem = NULL;

    if(!list) return new;

    listElement *currElem = list;
    while (currElem->nextElem != NULL)
        currElem = currElem->nextElem; // get last elem in list
    currElem->nextElem = new;          // add new to the end of list
}

void printList(const listElement *list)
{

    if (list == NULL)
        printf("List is empty.\n");
    else
    {
        int i = 0;
        const listElement *currElem = list;
        printf("\ncurrent list:\n\n");
        do
        {
            printf("%d", i);
            i++;
            printf("\t last name: %s\n", currElem->lastName);
            printf("\t first name: %s\n", currElem->firstName);
            printf("\t age: %d\n", currElem->age);

            currElem = currElem->nextElem;
        } while (currElem != NULL);
    }
}

listElement *delListElem(listElement *list)
{

    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> delListElem fcn is tbd.\n\n");
}

void delList(listElement *list)
{

    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> getLenOfList fcn is tbd.\n\n");
}

int getLenOfList(const listElement *list)
{ // we use this for save list fcn

    int counter = 0;
    const listElement *currElem = list;
    while (currElem->nextElem != NULL)
    { // get last elem in list
        currElem = currElem->nextElem;
        counter++;
    }
    return counter;
}

void saveList(const listElement *list)
{

    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> saveList fcn is tbd.\n\n");
}

listElement *loadList(listElement *list)
{

    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> loadList fcn is tbd.\n\n");

    printf("loading data will be append to current list...\n");
    printList(list); // show loaded list
}

void exitFcn(const listElement *list)
{

    printf("\n>> exitFcn fcn is tbd.\n\n");
}

listElement *sortList(listElement *list)
{

    printf("\n>>sortList fcn is tbd.\n\n");
}

void stringToLower(char *string)
{

    printf("\n>>stringToLower fcn is tbd.\n\n");
}
