//
//  list.h
//  cbhandler
//
//  Created by Sumir Kumar Jha on 12/08/19.
//  Copyright © 2019 Sumir Kumar Jha. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


#define CAR_NAME_SIZE 32

/**
 * A node structure which link a previous
 * as well as a next node in a chain of
 * nodes
 */

struct wv_list {
    /** Previous list element */
    struct wv_list *prev;
    /** Next list element */
    struct wv_list *next;
};


/**
 * @note
 * A wrapper directive which will find
 * the pointer of parent structure by passing \
 * it a pointer of any member.
 *
 * @param ptr pointer to member of the structure
 * @param sample a null pointer of structure type \
 * this will hold the final pointer of needed
 * structure.
 * @param member name of the member, which is
 * pointed by ptr
 */

#define wv_container_of(ptr, sample, member)                \
    (void *)((char *)(ptr)    -                        \
    ((char *)&(sample)->member - (char *)(sample)))


/**
 * @note
 * foreach loop, which iterate through each node
 * of list, at each iteration pos will hold the
 * pointer to current node.
 *
 * @param pos pointer to current node in interation
 * @param head pointer to list itself
 * @param member name of the member of wv_list type
 */

#define wv_list_for_each(pos, head, member)\
    for (pos = wv_container_of((head)->next, pos, member);  \
        &pos->member != (head); \
        pos = wv_container_of(pos->member.next, pos, member))


/**
 * @note
 * Same as above, but loop will run in reverse order
 */

#define wv_list_for_each_reverse(pos, head, member) \
    for (pos = wv_container_of((head)->prev, pos, member);  \
        &pos->member != (head); \
        pos = wv_container_of(pos->member.prev, pos, member))



//--------- Some list manupulation function --------


/**
 * @note
 * Initialize the list, this function must be called first
 * and once at the time of creation of list.
 * @param list pointer to list
 */
void wv_list_init(struct wv_list *list);

/**
 * @note
 * Insert a node into the list
 * @param list pointer to list
 * @param elm pointer of node to be inserted
 */
void wv_list_insert(struct wv_list *list, struct wv_list *elm);

/**
 * @note
 * Remove a node from the list
 * @param elm pointer of node to be removed
 */
void wv_list_remove(struct wv_list *elm);

/**
 * @note
 * Check if list is empty or not
 * @param list pointer to list
 * @return True if empty otherwise False
 */
bool wv_list_empty(struct wv_list *list);

/**
 * @note
 * Find length of list
 * @param list pointer to list
 * @return Number of elements in the list
 */
int wv_list_length(struct wv_list *list);


/**
 * @note
 * A sample structure to show the working example of list
 *
 * A side note : Any structure which want to become a node
 * in the list must contain a member of type \struct wv_list
 * in this case, link is that member.
 */
struct car
{
    struct wv_list link;
    uint8_t company[CAR_NAME_SIZE];
    float speed;    //Kmph
    float engineCC; //in CC
    float tankCapacity; //Litres
    uint32_t colorCode;
};


#endif /* list_h */
