//
// File:	$URL: file:///usr/casc/samrai/repository/SAMRAI/tags/v-2-2-0/source/hierarchy/patches/PatchLevelFactory.h $
// Package:	SAMRAI hierarchy
// Copyright:	(c) 1997-2007 Lawrence Livermore National Security, LLC
// Revision:	$LastChangedRevision: 1704 $
// Modified:	$LastChangedDate: 2007-11-13 16:32:40 -0800 (Tue, 13 Nov 2007) $
// Description:	Abstract factory class for creating patch level objects
//

#ifndef included_hier_PatchLevelFactory
#define included_hier_PatchLevelFactory

#ifndef included_SAMRAI_config
#include "SAMRAI_config.h"
#endif
#ifndef included_hier_GridGeometry
#include "GridGeometry.h"
#endif
#ifndef included_hier_PatchDescriptor
#include "PatchDescriptor.h"
#endif
#ifndef included_hier_PatchFactory
#include "PatchFactory.h"
#endif
#ifndef included_hier_PatchLevel
#include "PatchLevel.h"
#endif
#ifndef included_tbox_Pointer
#include "tbox/Pointer.h"
#endif
#ifndef included_tbox_Database
#include "tbox/Database.h"
#endif
#ifndef included_tbox_DescribedClass
#include "tbox/DescribedClass.h"
#endif


namespace SAMRAI {
    namespace hier {

/**
 * Class PatchLevelFactory<DIM> is a factory object used to create new
 * patch levels.  New types of patch level objects can be introduced into
 * SAMRAI by deriving from PatchLevelFactory<DIM> and re-defining allocate.
 *
 * @see hier::PatchLevel
 */

template<int DIM> class PatchLevelFactory  : public tbox::DescribedClass
{
public:
   /**
    * Construct a patch level factory object.
    */
   PatchLevelFactory();

   /**
    * Virtual destructor for patch level factory objects.
    */
   virtual ~PatchLevelFactory<DIM>();

   /**
    * Allocate a patch level with the specified boxes and processor mappings.
    * Redefine this function to change the method for creating patch levels.
    */
   virtual tbox::Pointer< PatchLevel<DIM> >
   allocate(const BoxArray<DIM>& boxes,
            const ProcessorMapping& mapping,
            const IntVector<DIM>& ratio_to_level_zero,
            const tbox::Pointer< GridGeometry<DIM> > grid_geometry,
            const tbox::Pointer< PatchDescriptor<DIM> > descriptor,
            tbox::Pointer< PatchFactory<DIM> > factory = NULL,
            const bool defer_boundary_box_creation = false) const;

   /**
    * Allocate a patch level using the data from the database to 
    * initialize it.  The component_selector argument is used 
    * to specify which patch data components to allocate and
    * read in from the database.  By default, the component_selector
    * has all its bits set to false so that no patch data components
    * are allocated and read from the database.
    *
    * Redefine this function to change the method for creating 
    * patch levels from a database.
    * 
    */
   virtual tbox::Pointer< PatchLevel<DIM> >
   allocate(tbox::Pointer<tbox::Database> database,
            const tbox::Pointer< GridGeometry<DIM> > grid_geometry,
            const tbox::Pointer< PatchDescriptor<DIM> > descriptor,
            tbox::Pointer< PatchFactory<DIM> > factory = NULL,
            const ComponentSelector component_selector = 
                  ComponentSelector(false),
            const bool defer_boundary_box_creation = false) const;
        
private:
   PatchLevelFactory(const PatchLevelFactory<DIM>&); // not implemented
   void operator=(const PatchLevelFactory<DIM>&);	    // not implemented

};

}
}
#ifndef DEBUG_NO_INLINE
#include "PatchLevelFactory.I"
#endif
#endif

#ifdef INCLUDE_TEMPLATE_IMPLEMENTATION
#include "PatchLevelFactory.C"
#endif
