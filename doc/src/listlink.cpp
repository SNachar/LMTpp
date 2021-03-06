#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "token.h"
#include "op.h"
#include "names.h"
#include "link.h"
#include "listlink.h"

ListLink :: ~ListLink() {

    int  i;

    for(i=0;i<list.size();i++)
        delete list[i] ;
}

Link* ListLink :: isName( string& nom ) {

    int i,n ;
    
    n = list.size() ;
    for(i=0;i<n;i++) 
        if (nom == list[i]->name.name )  return list[i] ;
    return 0 ;
}

Link* ListLink :: isName_Hash( string& nom,unsigned h ) {

    int i,n ;

    n = list.size() ;
    for(i=0;i<n;i++) 
        if ((nom == list[i]->name.name ) && (list[i]->name.hash == h ))  return list[i] ;
    return 0 ;
}

Link* ListLink :: isPrincipalName( string& nom ) {

    int i,n ;
    
    n = list.size() ;
    for(i=0;i<n;i++) 
        if (nom == list[i]->name.principalName )  return list[i] ;
    return 0 ;
}

void ListLink :: setPath( const string& p ) {

    int i,n ;
    
    n = list.size() ;
    for(i=0;i<n;i++) 
        list[i]->path = p ;

}

int ListLink :: number_of_principalName( string& na ) {

    int co,i,n ;

    co = 0 ;
    n = list.size() ;
    for(i=0;i<n;i++) {
        if ( na == list[i]->name.principalName )
            co++ ;
    return co ;
    }

}











