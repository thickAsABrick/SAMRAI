//
// File:	$URL: file:///usr/casc/samrai/repository/SAMRAI/tags/v-2-2-0/source/geometry/skeleton/patch_geom/SkeletonPatchGeometry.h $
// Package:	SAMRAI geometry package
// Copyright:	(c) 1997-2007 Lawrence Livermore National Security, LLC
// Revision:	$LastChangedRevision: 1704 $
// Modified:	$LastChangedDate: 2007-11-13 16:32:40 -0800 (Tue, 13 Nov 2007) $
// Description: Simple Skeleton grid geometry for an AMR hierarchy.
//

#ifndef included_geom_SkeletonPatchGeometry
#define included_geom_SkeletonPatchGeometry

#ifndef included_SAMRAI_config
#include "SAMRAI_config.h"
#endif
#ifndef included_hier_IntVector
#include "IntVector.h"
#endif
#ifndef included_hier_Patch
#include "Patch.h"
#endif
#ifndef included_hier_PatchGeometry
#include "PatchGeometry.h"
#endif

namespace SAMRAI {
    namespace geom {

/**
 * Class SkeletonPatchGeometry implements geometry management 
 * for a single patch in an AMR hierarchy with no information about
 * the physical characteristics of the problem.  This is intended for
 * use in an application that will manage the physical geometry in
 * user-defined code.
 * 
 * The grid data is set by SkeletonGridGeometry class.  This patch
 * geometry class is derived from hier::PatchGeometry<DIM> base class.
 *
 * @see hier::BoundaryBox
 * @see hier::PatchGeometry
 * @see geom::SkeletonGridGeometry
 */

template<int DIM> class SkeletonPatchGeometry 
: public hier::PatchGeometry<DIM>
{
public:

   /**
    * Constructor for SkeletonPatchGeometry class.  It simply passes 
    * patch boundary information and the ratio to the coarsest level to
    * hier::PatchGeometry constructor.
    */
   SkeletonPatchGeometry<DIM>(
      const hier::IntVector<DIM>& ratio_to_level_zero,
      const tbox::Array< tbox::Array<bool> >& touches_regular_bdry,
      const tbox::Array< tbox::Array<bool> >& touches_periodic_bdry);

   /**
    * Destructor for SkeletonPatchGeometry.
    */
   ~SkeletonPatchGeometry<DIM>();

   /**
    * Print SkeletonPatchGeometry class data.
    */
   virtual void printClassData(std::ostream& os) const;

private:
   // These are not implemented. 
   SkeletonPatchGeometry(const SkeletonPatchGeometry<DIM>&); 
   void operator=(const SkeletonPatchGeometry<DIM>&);

};

}
}

#endif

#ifdef INCLUDE_TEMPLATE_IMPLEMENTATION
#include "SkeletonPatchGeometry.C"
#endif
