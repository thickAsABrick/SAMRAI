//
// File:	$URL: file:///usr/casc/samrai/repository/SAMRAI/tags/v-2-2-0/source/geometry/cartesian/operators/cell/CartesianCellDoubleConservativeLinearRefine.h $
// Package:	SAMRAI geometry
// Copyright:   (c) 1997-2007 Lawrence Livermore National Security, LLC
// Revision:	$LastChangedRevision: 1704 $
// Modified:	$LastChangedDate: 2007-11-13 16:32:40 -0800 (Tue, 13 Nov 2007) $
// Description: Conservative linear refine operator for cell-centered 
//              double data on a Cartesian mesh.
//

#ifndef included_geom_CartesianCellDoubleConservativeLinearRefine
#define included_geom_CartesianCellDoubleConservativeLinearRefine

#ifndef included_SAMRAI_config
#include "SAMRAI_config.h"
#endif
#ifndef included_hier_Box
#include "Box.h"
#endif
#ifndef included_hier_IntVector
#include "IntVector.h"
#endif
#ifndef included_hier_Patch
#include "Patch.h"
#endif
#ifndef included_tbox_Pointer
#include "tbox/Pointer.h"
#endif
#ifndef included_String
#include <string>
#define included_String
#endif
#ifndef included_xfer_RefineOperator
#include "RefineOperator.h"
#endif

namespace SAMRAI {
    namespace geom {

/**
 * Class CartesianCellDoubleConservativeLinearRefine implements
 * conservative linear interpolation for cell-centered double patch data 
 * defined over a Cartesian mesh.  It is derived from the base class 
 * xfer::RefineOperator<DIM>.  The numerical operations for the interpolation 
 * use FORTRAN numerical routines.
 *
 * The findRefineOperator() operator function returns true if the input 
 * variable is cell-centered double, and the string is 
 * "CONSERVATIVE_LINEAR_REFINE".
 * 
 * @see xfer::RefineOperator
 */

template<int DIM> class CartesianCellDoubleConservativeLinearRefine 
: public xfer::RefineOperator<DIM>
{
public:
   /**
    * Uninteresting default constructor.
    */
   CartesianCellDoubleConservativeLinearRefine();

   /**
    * Uninteresting virtual destructor.
    */
   virtual ~CartesianCellDoubleConservativeLinearRefine<DIM>();

   /**
    * Return true if the variable and name string match cell-centered 
    * double conservative linear interpolation; otherwise, return false.
    */
   bool findRefineOperator(const tbox::Pointer< hier::Variable<DIM> >& var,
                           const std::string &op_name) const; 

   /**
    * Return name string identifier of this refinement operator.
    */
   const std::string& getOperatorName() const;

   /**
    * The priority of cell-centered double conservative linear is 0.
    * It will be performed before any user-defined interpolation operations. 
    */
   int getOperatorPriority() const;

   /**
    * The stencil width of the conservative linear interpolation operator is 
    * the vector of ones.
    */
   hier::IntVector<DIM> getStencilWidth() const;

   /**
    * Refine the source component on the coarse patch to the destination
    * component on the fine patch using the cell-centered double conservative
    * linear interpolation operator.  Interpolation is performed on the 
    * intersection of the destination patch and the fine box.   It is assumed 
    * that the coarse patch contains sufficient data for the stencil width of 
    * the refinement operator.
    */
   void refine(hier::Patch<DIM>& fine,
               const hier::Patch<DIM>& coarse,
               const int dst_component,
               const int src_component,
               const hier::Box<DIM>& fine_box,
               const hier::IntVector<DIM>& ratio) const;

private:
   std::string d_name_id;

};

}
}
#endif

#ifdef INCLUDE_TEMPLATE_IMPLEMENTATION
#include "CartesianCellDoubleConservativeLinearRefine.C"
#endif
