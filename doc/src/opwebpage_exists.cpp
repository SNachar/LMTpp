#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std ;

#include "pagecomment.h"
#include "opwebpage_exists.h"
#include "visitorcommentitem_webpage_exists.h"


// cette fonction a pour objet de générer une page web à partir de la page "page" dans un futur proche
void OpWebPage_exists :: operator()( PageComment* page ) {

    VisitorCommentItem_webpage_exists visor ;
    int k,N,i,n ;

    visor.init( false,name ) ;
    N = page->listComment.size() ;
    for(k=0;k<N;k++) {
        n = page->listComment[k]->items.size() ;
        for(i=0;i<n;i++)
            page->listComment[k]->items[i]->execute_function( &visor ) ;
    }
    if (visor.exists)
        exists = visor.exists ;
}













