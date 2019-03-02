
// Implementacja struktury listy z glowa
// Implementation of the list structure with head

#include "pch.h"
#include <stdio.h>
#include "list.h"

int __cdecl Compare( const void * first, const void * second );


int main()
{
	ListItem list;
	list=*CreateList();

	
	LISTINFO * a = CreateElement( 5 );
	printf( "Wstawienie elementu na poczatek: \n" );

	InsertFront( &list, a );
	PrintList( list );
	
	LISTINFO *b = CreateElement( 7 );
	
	printf( "Wstawienie elementu na drugie miejsce: \n" );

	Insert( list.pNext, b );
	PrintList( list );

	LISTINFO *c = CreateElement( 1 );
	LISTINFO *d = CreateElement( 2 );
	LISTINFO *e = CreateElement( 3 );
	LISTINFO *f = CreateElement( 4 );
	printf( "Wstawienie 4 elementow: \n" );
	Insert( &list, c );
	Insert( &list, d );
	InsertFront( &list, e );
	Insert( list.pNext, f );
	PrintList( list );

	printf( "Czy 4 znajduje sie na liscie? \n" );
	ListItem** pPrev = (ListItem**)calloc(1,sizeof( ListItem*));
	if( !pPrev )
	{
		perror( "Nie udalo sie utworzyc elementu" );
	}
	if( Find( &list, f, pPrev, Compare ) )
		printf( "Tak\n" );
	else
		printf( "Nie\n" );

	printf( "Czy 8 znajduje sie na liscie? \n" );
	if( Find( &list, CreateElement(8), pPrev, Compare ) )
		printf( "Tak\n" );
	else
		printf( "Nie\n" );


	printf( "Posortowanie: \n" );
	SortList(&list,Compare);
	PrintList( list );

	printf( "Wstawienie elementu na poczatek\n" );

	InsertFront( &list, Front( &list )->pInfo );
	PrintList( list );

	printf( "Usuniecie 2 elementow z poczatku listy: \n" );
	RemoveFront( &list );
	RemoveFront( &list );
	PrintList( list );

	printf( "Usuniecie 4 elementu listy: \n" );
	Remove( list.pNext->pNext->pNext );
	PrintList( list );

	printf( "Wyczyszczenie listy: \n" );
	FreeList( &list );
	PrintList( list );
	//PrintList( list );
}

int __cdecl Compare( const void * first, const void * second )
{
	if( ((LISTINFO*)first)->nKey < ( ( LISTINFO* ) second )->nKey ) return -1;
	else if( ( ( LISTINFO* ) first )->nKey == ( ( LISTINFO* ) second )->nKey ) return 0;
	else return 1;
}