#ifndef HA03_LINKEDLISTLIB_H_
#define HA03_LINKEDLISTLIB_H_
/** 
    \STRUCT: listElement
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: definition of struct to create nodes from for the simple linked list 
*/
struct listElem{
    char lastName[50];
    char firstName[50];
    int age;
    struct listElem *nextElem;
};
typedef struct listElem listElement;

/** 
    \FUNCTION: addListElem
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: adds new entity of listElement to current list
 
    \param[in]  pointer to start element of current list              
*/
void addListElem(listElement *);

/** 
    \FUNCTION: printList
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: prints whole list to terminal
 
    \param[in]  pointer to start element of current list              
*/
void printList(listElement *);

/** 
    \FUNCTION: delListElem
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: deletes specific list element and free its memory
 
    \param[in]  pointer to start element of current list              
*/
void delListElem(listElement *);

/** 
    \FUNCTION: delList
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: deletes whole list and free its memory
 
    \param[in]  pointer to start element of current list              
*/
void delList(listElement *);

/** 
    \FUNCTION: getLenOfList
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: calculates the lenght of current list
 
    \param[in]  pointer to start element of current list        

    \param[out] lenght of current list
*/
int getLenOfList(listElement *);

/** 
    \FUNCTION: saveList
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: save current list to *.txt file which will be specified by the user.
 
    \param[in]  pointer to start element of current list        
*/
void saveList(listElement *);

/** 
    \FUNCTION: loadList
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: load a saved list from a *.txt file which will be specified by the user.
 
    \param[in]  pointer to start element of current list        
*/
void loadList(listElement *);

/** 
    \FUNCTION: exitFcn
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: asks user if the current list should be saved before program ends.
 
    \param[in]  pointer to start element of current list        
*/
void exitFcn(listElement *);

/** 
    \FUNCTION: sortList
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: sorts the list by fistName, lastName, or age. actual sorting criteria will be specified by the user.
 
    \param[in]  pointer to start element of current list        
*/
void sortList(listElement *);

/** 
    \FUNCTION: stringToLower
 
    \AUTHOR: jannik wiessler

    \DATE: 2020-05-21

    \DESCRIPTION: transforms any capital letters in a string to lower cases

    \param[in]  pointer to start element of current list        
*/
void stringToLower(char *); 

#endif