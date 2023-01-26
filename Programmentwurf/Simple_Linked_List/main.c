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
int main(){

    listElement *start;
    start = (listElement *)malloc(sizeof(listElement));
    if (start == NULL) {
        printf("can't reserve storage.\n"); 
        return -1;
        }
    start->nextElem = NULL;

    int FLAGG = 1;
    while (FLAGG){
    
        printf("1... print list\n");
        printf("2... add element\n");
        printf("3... delete element\n");
        printf("4... delete list\n");
		printf("5... save list\n");
		printf("6... load list\n");
		printf("7... sort list\n");
        printf("0... quit\n");
        scanf("%d",&FLAGG);
        system("cls"); // clear for mac/linux


        switch (FLAGG){
            case 1: printList(start); break;
            case 2: addListElem(start); break;
            case 3: delListElem(start); break;
            case 4: delList(start); break;
			case 5: saveList(start); break;
			case 6: loadList(start); break;
            case 7: sortList(start); break;
            case 0: FLAGG = 0; exitFcn(start); break;
            default: printf("invalid choice\n"); break;
        }
    }
    return 0;
}

