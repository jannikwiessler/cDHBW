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

    listElement *list = NULL;

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
            case 1: printList(list); break;
            case 2: list = addListElem(list); break;
            case 3: list = delListElem(list); break;
            case 4: delList(list); list = NULL; break;
			case 5: saveList(list); break;
			case 6: list = loadList(list); break;
            case 7: list = sortList(list); break;
            case 0: FLAGG = 0; exitFcn(list); break;
            default: printf("invalid choice\n"); break;
        }
    }
    return 0;
}

