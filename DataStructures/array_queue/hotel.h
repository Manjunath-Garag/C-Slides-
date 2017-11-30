#ifndef HOTEL_H
#define HOTEL_H

typedef struct resturant
{
	char name[30];
	char loc[30];
	int tables;
	int capacity;
	struct resturant *next;
}rest;

#endif
