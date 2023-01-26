#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListLib.h"

/*******************************************************
* NAME: main.c (main) 
*
* AUTHOR: jannik wiessler
*
* DATE: 2020-05-21
*
* DESCRIPTION:  Implementation of a simple linked list programm.
*               UI-menu containing the following options:
*                   >> print list
*                   >> add element
*                   >> delete specific element
*                   >> delete whole list
*                   >> save current list to *.txt file
*                   >> load a stored list from *.txt file
*                   >> sort current list by user defined cirteria
*                   >> dlg for saving current list by exiting the program
*
* DEPENDENCIES: 
*   >> HA03_listL.c
*   >> myFunction.h
*
* INFO: For DHBW use only.
*   >> Typdef of struct
*   >> Practice of simple linked list
*
**/

void cli(listElement *list) {
    while (1) {
        int FLAG = 1;

        printf("1... print list\n");
        printf("2... add element\n");
        printf("3... delete element\n");
        printf("4... delete list\n");
        printf("5... save list\n");
        printf("6... load list\n");
        printf("7... sort list\n");
        printf("0... quit\n");
        scanf("%d", &FLAG);
        system("cls"); // clear for mac/linux

        switch (FLAG) {
            case 1:
                printList(list);
                break;
            case 2:
                addListElem(list);
                break;
            case 3:
                delListElem(list);
                break;
            case 4:
                delList(list);
                break;
            case 5:
                saveList(list);
                break;
            case 6:
                loadList(list);
                break;
            case 7:
                sortList(list);
                break;
            case 0:
                return;
            default:
                printf("invalid choice\n");
                break;
        }
    }
}

int main() {
    listElement *list = malloc(sizeof(listElement));

    if (list == NULL) {
        printf("can't reserve storage.\n");
        return -1;
    }

    list->nextElem = NULL;

    cli(list);
    exitFcn(list);
}

