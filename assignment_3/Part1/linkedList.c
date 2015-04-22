#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link */
struct DLink
{
    TYPE value;
    struct DLink * next;
    struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList
{
    int size;
    struct DLink *firstLink;
    struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
 */

void _initList (struct linkedList *lst)
{
    
    // allocate space for new front list (link) and make sure it works
    lst->firstLink = malloc(sizeof(struct DLink));
    assert(lst->firstLink != 0);
    
    // allocate space for new back list (link) and make sure it works
    lst->lastLink = malloc(sizeof(struct DLink));
    assert(lst->lastLink != 0);
    
    /* set front list next to back list, back list previos to front list,
     and set size to 0 */
    lst->firstLink->next = lst->lastLink;
    lst->lastLink->prev = lst->firstLink;
    lst->size = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
    struct linkedList *newList = malloc(sizeof(struct linkedList));
    _initList(newList);
    return(newList);
}

/*
	_addLinkBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
 */

/* Creates and adds a new link before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
    // make sure we are not trying to insert before the first link
    assert(l != lst->firstLink);
    
    // allocate space for the new link
    struct DLink *newLink = (struct DLink *) malloc(sizeof(struct DLink));
    
    /* set the new link value, and next and previous to the link ahead and
     behind, respectively */
    newLink->value = v;
    newLink->next = l;
    newLink->prev = l->prev;
    
    // set the previous link next to new link and previous of link to new link
    l->prev->next = newLink;
    l->prev = newLink;
    
    // increase linked list size
    lst->size++;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
 */
void _removeLink(struct linkedList *lst, struct DLink *l)
{
    // make sure lst isn't NULL, and l isn't NULL
    assert(lst != 0);
    assert(l != 0);
    
    /* connect the previous link's next to the link after l, and connect the next
     link's previous to the link before l */
    l->prev->next = l->next;
    l->next->prev = l->prev;
    
    // free the memory allocated for the link being removed, and decrease list size
    free(l);
    lst->size--;
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
 */
int isEmptyList(struct linkedList *lst)
{
    // make sure list is not NULL
    assert(lst != 0);
    
    // returns 1 if size = 0, 0 if not
    return(lst->size == 0);
}

/* De-allocate all links of the list
 
	param: 	lst		pointer to the linked list
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
 */
void freeLinkedList(struct linkedList *lst)
{
    while(!isEmptyList(lst))
    {
        /* remove the link right after the first sentinel */
        _removeLink(lst, lst->firstLink->next);
    }
    
    /* remove the first and last sentinels */
    free(lst->firstLink);
    free(lst->lastLink);
}

/* 	Deallocate all the links and the linked list itself.
 
	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
 */
void deleteLinkedList(struct linkedList *lst)
{
    assert (lst != 0);
    freeLinkedList(lst);
    free(lst);
}


/* Function to print list
 Pre: lst is not null
 */
void printList(struct linkedList* lst)
{
    // make a place to store the index number for later
    int ind = 0;
    
    // make sure the list isn't NULL or empty
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    // point to the first link with a value (first link after the sentinel)
    struct DLink *index = lst->firstLink->next;
    
    // ensure it initalized properly
    assert(index != 0);
    
    // loop through the links, and print them
    while(index != lst->lastLink)
    {
        printf("Index: %d\tValue: %d\n", ind, index->value);
        index = index->next;
        ind++;
    }
}

/* ************************************************************************
	Deque Interface Functions
 ************************************************************************ */

/*
	addfrontLink
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
 */
void addfrontLink(struct linkedList *lst, TYPE e)
{
    // make sure the list isn't NULL
    assert(lst != 0);
    
    // add the link after the first link
    _addLinkBefore(lst, lst->firstLink->next, e);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
 */
void addBackList(struct linkedList *lst, TYPE e)
{
    // make sure the list isn't NULL
    assert(lst != 0);
    
    // add the link before the last link
    _addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontLink
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
 */
TYPE frontLink (struct linkedList *lst)
{
    // make sure the list isn't NULL or empty
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    // return the value of the next link after the first link
    return(lst->firstLink->next->value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
 */
TYPE backList(struct linkedList *lst)
{
    // make sure the list isn't NULL or empty
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    //return the value of the previous link before the last link
    return(lst->lastLink->prev->value);
}



/*
	removefrontLink
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
 */
void removefrontLink(struct linkedList *lst)
{
    // make sure the list isn't NULL or empty
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    // remove the link at first link next
    _removeLink(lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
 */
void removeBackList(struct linkedList *lst)
{
    // make sure the list isn't NULL or empty
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    // remove the link at last link previous
    _removeLink(lst, lst->lastLink->prev);
}


/* ************************************************************************
	Stack Interface Functions
 ************************************************************************ */

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
    // make sure the list isn't NULL
    assert(lst != 0);
    
    // add the link to the back of the list
    addBackList(lst, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0
 
	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
 */
int containsList (struct linkedList *lst, TYPE e)
{
    // make sure the list isn't NULL or empty
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    // point to the first link with a value (first link after the sentinel)
    struct DLink *index = lst->firstLink->next;
    
    // ensure it initialized properly
    assert(index != 0);
    
    // loop through the linked list and see if we can find e, return 1 if we do
    while(index != lst->lastLink)
    {
        if(index->value == e)
        {
            return 1;
        }
        index = index->next;
    }
    
    // return 0 if e isn't found
    return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs
 
	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
 */
void removeList (struct linkedList *lst, TYPE e)
{
    // make sure the list isn't NULL or empty
    assert(lst != 0);
    assert(!isEmptyList(lst));
    
    // point to the first link with a value (first link after the sentinel)
    struct DLink *index = lst->firstLink->next;
    
    // ensure it initialized properly
    assert(index != 0);
    
    // loop through the linked list and see if we can find e, remove first instance
    while(index != lst->lastLink)
    {
        if(index->value == e)
        {
            _removeLink(lst, index);
            break; // break to ensure we only remove the first instanc with the value e
        }
        index = index->next;
    }
}