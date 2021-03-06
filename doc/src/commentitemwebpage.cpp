#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "commentitemwebpage.h"
#include "token.h"
#include "util2html.h"

CommentItemWebPage :: CommentItemWebPage( string& parametre) {

    string stmp;
    int pos,suite;
    int n = parametre.size();
    char c;

    id = NOT_ID; // ce NOT_ID signifie que la pageweb html qui sera produite ne sera pas indéxée. 

    //cerr << " puet e  parametre =|" << parametre << "|" << endl;
    if ((pos = extraire_token(&suite,&c," \n",parametre,n,0)) >= 0) {
        //cerr << " ort" << endl;
        stmp = parametre.substr(pos,suite-pos);
        stmp = french2webID( stmp );
        //cerr << " stmp = " << stmp << endl;
        name.name = "webpage_" + stmp; /// nom de la page web
        
        if ((pos = extraire_token(&suite,&c,"",parametre,n,suite)) >= 0) {
            name.principalName = parametre.substr(pos,suite-pos); /// titre de la page web 
        } else {
            name.principalName = stmp;
            return; 
        }
    } else {
        name.principalName = "unknow_web_page";
        name.name = "webpage_unknow_web_page";
        return;
    }

/*
 if (chercher_motif(parametre,"[",&pos,n,0)) {
    if (chercher_motif(parametre,"]",&pos2,n,pos+1)) {
        name.principalName = parametre.substr(pos+1,pos2-pos-1);
        if (chercher_motif(parametre,"{",&pos,n,pos2+1)) {
            if (chercher_motif(parametre,"}",&pos2,n,pos+1)) {
                name.name = "webpage_" + parametre.substr(pos+1,pos2-pos-1);
            }
            else {
                name.name = "webpage_" + french2webID( name.principalName );
            // erreur de syntaxe! Par défaut on génère automatiquement un nom de page web.
            }
        } 
        else {
        // il n' y a pas de page web indiquée donc on génère automatiquement un nom de page web. 
        name.name = "webpage_" + french2webID( name.principalName );
        }
    }


 }*/
    //cout << " titre =" << titre <<  "|" << endl;
    //cout << " nomHtml =" << nomHtml << "|"  << endl;     
}

string CommentItemWebPage :: getTitle() {
 return name.name;
}


string CommentItemWebPage :: getNameHtml() {
 return name.principalName ;
}



void CommentItemWebPage :: display( std::ostream &os ) {

    int i,n;

    n = items.size();
    os << "CommentItemWebPage" << endl;
    os << " titre =" << name.principalName << endl;
    os << " nomHtml =" << name.name << endl;
    os << " nombre d'items = " << n << endl;

    for(i=0;i<n;i++) {
        os  << *items[i] << endl;
    }
    os << "fin CommentItemWebPage" << endl; 
}


