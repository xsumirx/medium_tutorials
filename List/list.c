//
//  list.c
//  Example of List
//
//  Created by Sumir Kumar Jha on 12/08/19.
//  Copyright © 2019 Sumir Kumar Jha. All rights reserved.
//

#include "list.h"


void wv_list_init(struct wv_list *list)
{
    list->next = list;
    list->prev = list;
}


void wv_list_insert(struct wv_list *list, struct wv_list *elm)
{
    elm->prev = list;
    elm->next = list->next;
    list->next->prev = elm;
    list->next = elm;
}

void wv_list_remove(struct wv_list *elm)
{
    elm->next->prev = elm->prev;
    elm->prev->next = elm->next;
    elm->next = NULL;
    elm->prev = NULL;
}

bool wv_list_empty(struct wv_list *list)
{
    return list->next == list;
}

int wv_list_length(struct wv_list *list)
{
    int count = 0;
    for(struct wv_list *head = list->next;
        head != list;
        head = head->next)
        count++;
    return count;
}


int main()
{
    struct wv_list carList;
    wv_list_init(&carList);
    
    //Sample 1
    struct car *car1 =
        (struct car *)calloc(1, sizeof(struct car));
    snprintf((char *)car1->company, CAR_NAME_SIZE, "Maserati");
    car1->colorCode = 0xFF000F00;
    car1->engineCC = 2987;
    car1->speed = 300;
    car1->tankCapacity = 60;
    
    //Sample 2
    struct car *car2 =
    (struct car *)calloc(1, sizeof(struct car));
    snprintf((char *)car2->company, CAR_NAME_SIZE, "BMW 820d");
    car2->colorCode = 0xFF000D00;
    car2->engineCC = 2993;
    car2->speed = 250;
    car2->tankCapacity = 55;
    
    //How to insert into list
    wv_list_insert(&carList, &car1->link);
    wv_list_insert(&carList, &car2->link);
    
    //How to interate over list
    struct car *tempCar = NULL;
    wv_list_for_each(tempCar, &carList, link)
    {
        printf("Car Manufacture : %s\n", tempCar->company);
        printf("Max Speed       : %.2f Kmph\n", tempCar->speed);
        printf("Tank Capacity   : %.2f Litres\n", tempCar->tankCapacity);
        printf("Color Code      : %8x\n", tempCar->colorCode);
        printf("\n\n");
    }
    
    
    
    //Clean Resource
    wv_list_remove(&car1->link);
    free(car1);
    
    wv_list_remove(&car2->link);
    free(car2);
    
    return 0;
}



