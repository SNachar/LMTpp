#include <iostream>
#include <string>
#include <vector>


using namespace std ;

#include "opdebug.h"
#include "pagecomment.h"
#include "opinternal.h"
#include "visitorcommentitem_is_internal.h"
#include "listtarget.h"


// cette fonction a pour objet de générer une page web à partir de la page "page" dans un futur proche
void OpInternal :: operator()( PageComment* page ) {

    VisitorCommentItem_isInternal v_isInternal;
    int i,n,j,m,k,o ;

    // on cherche pour tous les objets classe/struct/function de la page, si les objets comment contiennent un item du type keyword internal
    n = page->code.list_subType_function.size() ;
    for(i=0;i<n;i++) {
        v_isInternal.setParent( page->code.list_subType_function[i] ) ;
        m = page->code.list_subType_function[i]->listTag.size();
        for(j=0;j<m;j++) {
            o = page->code.list_subType_function[i]->listTag[j]->items.size();
            for(k=0;k<o;k++)
                page->code.list_subType_function[i]->listTag[j]->items[k]->execute_function( &v_isInternal );
        }
    }

}













