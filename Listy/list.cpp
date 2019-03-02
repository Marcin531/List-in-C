#include"list.h"




ListItem* CreateList()
{
	ListItem* p = ( ListItem * ) calloc( 1, sizeof( ListItem ) ); // dwa callocki
	LISTINFO* n = ( LISTINFO* ) calloc( 1, sizeof( LISTINFO ) );
	if( p && n )
	{

	p->pInfo = n;
	p->pNext = NULL;
	return p;

	}
	printf( "Nie udalo sie utworzyc listy" );
	return NULL;
}

void InsertFront( ListItem* pList, LISTINFO* pInfo )
{
	Insert( pList, pInfo );
}

void Insert( ListItem* pAfter, LISTINFO* pInfo )
{
	//calloc na stworzenie elementu

	ListItem* p = ( ListItem* ) calloc( 1, sizeof( ListItem ) );
	if( p )
	{
		p->pNext = pAfter->pNext;
		p->pInfo = pInfo;
		pAfter->pNext = p;
	}
	else
		perror( "Nie mozna wlozyc elementu" );
}

ListItem* Front( ListItem* pList )
{
	return pList->pNext;
}


void Remove( ListItem* pAfter )
{
	if( pAfter->pNext  )
	{
	    ListItem* p = pAfter->pNext;
		pAfter->pNext = p->pNext;
		free( p );
		// free 
	}
	else
		perror( "Nie mozna usunac elementu" );
}

void RemoveFront( ListItem* pList )
{
	Remove( pList );
}



void FreeList( ListItem* pList )
{
	while( !isEmpty( pList ) )
	{
		RemoveFront( pList );
	}
}

int isEmpty( ListItem* pList )
{

	return !( pList->pNext );

}

void SortList( ListItem* pList, int( __cdecl *pfunction )( const void* a, const void* b ) )// wstawia minimum na poczatek
{
	/*-Sortowanie ma byc przez przewiazywanie elementow list - aby to zrobic :
	Lista jest z glow¹ oraz ma element pusty.potrzebuje wskaznik pStart - pokazujacy od ktorego miejsca mam szukac najmniejszego elementu
		a jak go znajde to mam go przewiazac
		drugi wskaznik wskazujacy na minimalny( wczesniej niz minimalny ) pMin
		pMin porównuje z pNext z Klucz pMin->pNext->Key
		p->pNext->Key
		jak trafie na mniejszy to pMin ustawiam na p a p jedzie dalej
		potem nalezy podstawic go na pStart*/

	ListItem* pStart = pList;

	while( pStart->pNext )
	{

		ListItem* pPrevMin = pStart;
		ListItem* p = pStart->pNext;
			
		while( p->pNext )
		{
			if( pfunction(  pPrevMin->pNext->pInfo,  p->pNext->pInfo ) == 1 )
			{
				pPrevMin = p;
			}
			p = p->pNext;

		}
		if( pPrevMin != pStart )
		{
			p = pPrevMin->pNext;
			pPrevMin->pNext = pPrevMin->pNext->pNext;
			p->pNext = pStart->pNext;
			pStart->pNext = p;
			

		}
	
		pStart = pStart->pNext;

	}


}



ListItem* Find( ListItem* pList, LISTINFO* pFind, ListItem** pPrev, int( _cdecl *pFCompare )( const void* a, const void* b ) )
{

	*pPrev = pList;// ustawia poprzedni wyraz jako pierwszy 
	while( ( *pPrev )->pNext )// dopoki istnieje to iterujemy
	{
		if( !pFCompare( ( const void* ) pFind, ( const void* ) ( ( *pPrev )->pNext->pInfo ) ) )// porownuje pNext czyli wyraz kolejny po pPrev z szukanym
			return (*pPrev)->pNext;//jesli znalazlo zwraca wyraz poprzedni
		*pPrev = ( *pPrev )->pNext;// przeniesienie na na nastepny wyraz
	}
	return *pPrev = NULL;// jesli nie znalazlo zwraca null

}




LISTINFO* CreateElement( int nKey )
{
	LISTINFO* n = ( LISTINFO* ) malloc( sizeof( LISTINFO ) );
	if( n )
	{
		n->nKey = nKey;
		return n;
	}
	else
		perror( "Nie udalo sie utworzyc elementu" );
	return 0;
}

/*
void DelList(ListItem* pList)
{
	FreeList( pList );
	pList->pInfo=NULL;
}
*/
void PrintList( ListItem list )
{
	ListItem *p = list.pNext;
	if( isEmpty( &list ) )
		printf( "Lista jest pusta" );
	else
	{
		while( p )
		{
			printf( "%d ", *( p->pInfo ) );
			p = p->pNext;
		}
	}
	printf( "\n" );
}
