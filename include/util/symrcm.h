//
// C++ Interface: symrcm
//
// Description:
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_symrcm_HEADER
#define LMT_symrcm_HEADER

#include "GetLinkForOrdering.h"

namespace LMT {

/**
    return sum(local_bandwith**2)
 */
double symrcm_cost(const Vec<Vec<unsigned> > &indices,const Vec<unsigned> &perm);


/**
    start_point is found using lowest degree node
 */
Vec<unsigned> symrcm(const Vec<Vec<unsigned> > &indices_);

template<class TM>
Vec<unsigned> symrcm( const TM &m ) {
    Vec<Vec<unsigned> > ind;
    get_link_for_ordering( ind, m );
    return symrcm( ind );
}


}

#endif // LMT_symrcm_HEADER
