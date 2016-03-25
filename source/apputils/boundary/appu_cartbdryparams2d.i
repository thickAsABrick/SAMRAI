c
c  File:        $URL: file:///usr/casc/samrai/repository/SAMRAI/tags/v-2-2-0/source/apputils/boundary/appu_cartbdryparams2d.i $
c  Package:     SAMRAI application utilities
c  Copyright:   (c) 1997-2007 Lawrence Livermore National Security, LLC
c  Revision:    $LastChangedRevision: 1704 $
c  Modified:    $LastChangedDate: 2007-11-13 16:32:40 -0800 (Tue, 13 Nov 2007) $
c  Description: m4 include file for 2d boundary constant common blocks
c
      common/cartbdrylocparams2d/
     &  XLEFT,XRIGHT,YLEFT,YRIGHT,
     &  X0Y0,X1Y0,X0Y1,X1Y1
      integer
     &  XLEFT,XRIGHT,YLEFT,YRIGHT,
     &  X0Y0,X1Y0,X0Y1,X1Y1
c
c
      common/cartbdrycondparams2d/
     &  FLOW,XFLOW,YFLOW,
     &  REFLECT,XREFLECT,YREFLECT,
     &  DIRICHLET,XDIRICHLET,YDIRICHLET,
     &  NEUMANN,XNEUMANN,YNEUMANN
      integer
     &  FLOW,XFLOW,YFLOW,
     &  REFLECT,XREFLECT,YREFLECT,
     &  DIRICHLET,XDIRICHLET,YDIRICHLET,
     &  NEUMANN,XNEUMANN,YNEUMANN
