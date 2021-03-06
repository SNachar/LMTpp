//
// C++ Interface: matinv
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matinv_HEADER
#define LMT_matinv_HEADER

namespace LMT {

struct SolveException { };

template<class TT,class Str=Gen<>,class Sto=Dense<>,class IO=typename IsMatOp<TT>::T,class AltT=typename Mat<TT,Str,Sto,IO>::T>
class Inv {
public:
    typedef typename Mat<TT,Str,Sto,IO>::T T;
    typedef typename AlternativeOnType< Sto::sparse + 2*Sto::skyline,
        Dense<typename Sto::TO>,
        typename AlternativeOnType<
                    AreSameType<Str,TriUpper<Str::static_nb_rows,Str::static_nb_cols> >::res or
                    AreSameType<Str,TriLower<Str::static_nb_rows,Str::static_nb_cols> >::res,
            SkyLine<typename Sto::TO>,
            SparseLine<typename Sto::TO>
        >::T,
        SkyLine<typename Sto::TO>
    >::T STOF;
    typedef typename AlternativeOnType< Str::need_upper && Str::need_lower,
        Mat<AltT,Str,STOF>,
        std::pair<Mat<AltT,Gen<> >, Vec<unsigned> >
    >::T TF;
    
    Inv() { }
    Inv(const Mat<TT,Str,Sto,IO> &mm):m(&mm) {
        bool res = get_factorization(mm,fact);
        if ( res == false )
            throw SolveException();
    }
    
    const Mat<TT,Str,Sto,IO> *m;
    TF fact;
};

template<class TT, int s>
class Inv<TT,Sym<s>,SparseLine<>,typename IsMatOp<TT>::T,typename Mat<TT,Sym<s>,SparseLine<>,typename IsMatOp<TT>::T>::T> {
public:
    typedef Sym<s> Str;
    typedef SparseLine<> Sto;
    typedef typename IsMatOp<TT>::T IO;
    typedef typename Mat<TT,Str,Sto,IO>::T AltT;
    typedef typename Mat<TT,Str,Sto,IO>::T T;
    typedef SkyLine<typename Sto::TO> STOF;
    typedef std::pair< Mat<AltT,Str,STOF> , Vec<AltT,s> > TF;
    
    Inv() { }
    Inv(const Mat<TT,Str,Sto,IO> &mm):m(&mm) {
        bool res = get_factorization(mm,fact);
        if ( res == false )
            throw SolveException();
    }
    
    const Mat<TT,Str,Sto,IO> *m;
    TF fact;
};

/*! \relates Mat
    Retourne un objet pour inverser un système
    
    L'utilisation standard, c'est "inv( M ) * V" qui est équivalent à M \ V en matlab
    
    Attention, l'opérateur inv n'est pas défini pour toutes les matrices. En l'occurrence Mat<T,Sym<> > n'est pas géré actuellement.
    
    Dans ce cas, on peut par exemple faire
    \code
        Mat<T,Sym<>,SparseLine<> > tmp( M );
        inv( tmp ) * V;
    
*/
template<class T,class Str,class Sto,class IO>
Inv<T,Str,Sto,IO> inv(const Mat<T,Str,Sto,IO> &m) throw(SolveException) {
    return m;
}

/*!

*/
template<class T1,class Str,class Sto,class IO,class T2,int s2,class IO2>
typename TypePromote< Divides, typename Vec<T2,s2,IO2>::template SubType<0>::T,typename Mat<T1,Str,Sto,IO>::T>::T
 solve(const Mat<T1,Str,Sto,IO> &A,const Vec<T2,s2,IO2> &b) throw(SolveException) { return inv(A)*b; }

/*!

*/
template<class T,class Str,class Sto,class IO,class AltT,class TT2,int s2>
Vec<typename TypePromote<Multiplies,AltT,typename Vec<TT2,s2>::template SubType<0>::T>::T> operator*(const Inv<T,Str,Sto,IO,AltT> &i, const Vec<TT2,s2> &b) throw(SolveException) {
    return solve_using_factorization( *i.m, i.fact, b );
}

};

#include "matinvdiag.h"
#include "matinvtri.h"
#include "matinvfull.h"
#include "matinvskyline.h"
#include "matinvsparse.h"

#endif // LMT_matinv_HEADER
