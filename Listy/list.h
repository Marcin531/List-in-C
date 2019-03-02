#ifndef LIST_H
#define LIST_H

#include "global.h"
#include <stdio.h>
#include <cstdlib>

typedef struct tagListItem
{
	LISTINFO* pInfo; 
	tagListItem* pNext; // wskaznik na kolejny element

}ListItem;
//glowa w liscie oznacza element wskazujacy na piewrszy element, czyli jego wartosc nKey nie ma znaczenia
ListItem* Find( ListItem* pList, LISTINFO* p, ListItem** pPrev, int( *pfunction )( const void* a, const void* b ) );
void InsertFront( ListItem* pList,  LISTINFO* pInfo );   //wstawienie na poczatek
void Insert( ListItem* pAfter,  LISTINFO* pInfo );
void Remove( ListItem* pAfter ); // usuniecie elementow o tych wskaznikach- nie ma przeszukiwac listy
void RemoveFront( ListItem* pList );   // odpowiada pop		- usuwa szczytowy element z listy
ListItem* CreateList(); //-worzy pust¹ listê	  ma zrobic pusty element na poczatku- glowe;
ListItem* Front( ListItem* pList );//odpowiednik funkcji top
void FreeList( ListItem* pList );//czysci liste- zostawia tylko glowe
int isEmpty( ListItem* pList );
void SortList( ListItem* pList, int ( _cdecl *pfunction)( const void* a, const void* b ));// sortuje liste, wstawia wyszukane na minimum na poczatek i zmienia wskazniki pNExt
void PrintList( ListItem list );// drukuje liste
//void DelList( ListItem* pList );// usuwa cala liste
LISTINFO* CreateElement( int nKey );// tworzy element


#endif // !LIST_H
