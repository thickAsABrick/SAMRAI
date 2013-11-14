/*************************************************************************
 *
 * This file is part of the SAMRAI distribution.  For full copyright
 * information, see COPYRIGHT and COPYING.LESSER.
 *
 * Copyright:     (c) 1997-2013 Lawrence Livermore National Security, LLC
 * Description:   Generator of sequential LocalIds.
 *
 ************************************************************************/

#ifndef included_hier_SequentialLocalIdGenerator
#define included_hier_SequentialLocalIdGenerator

#include "SAMRAI/SAMRAI_config.h"

#include <iostream>

namespace SAMRAI {
namespace hier {

/*!
 * @brief Strategy interface for generating LocalId.
 *
 * This implementation generates new LocalId by increasing the
 * previously generated value by a constant increment (1 by default).
 * It is possible to set both the previously generated valut and the
 * increment.
 */
class SequentialLocalIdGenerator
{

public:
   /*!
    * @brief Default constructor.
    *
    * Construct an object generating sequential values starting with zero.
    */
   SequentialLocalIdGenerator() :
      d_last_value(-1), d_increment(1) {}

   /*!
    * @brief Default constructor.
    *
    * Construct an object with user-defined last value and increment.
    */
   SequentialLocalIdGenerator(
      const LocalId &last_value,
      const LocalId &increment=LocalId(1) ) :
      d_last_value(last_value),
      d_increment(increment) {}

   /*!
    * @brief Destructor.
    */
   ~SequentialLocalIdGenerator() {}

   /*!
    * @brief Return a LocalId that is greater than the previous
    * value by the increment value.
    */
   LocalId nextValue() {
      d_last_value += d_increment;
      return d_last_value;
   }

   /*
    * @brief Reset the last value.
    *
    * @param [in] value
    */
   void setLastValue( const LocalId &last_value ) {
      d_last_value = last_value;
   }

   /*
    * @brief Set the increment value
    *
    * @param [in] increment
    */
   void setIncrement( const LocalId &increment ) {
      d_increment = increment;
   }

private:

   LocalId d_last_value;
   LocalId d_increment;

};

}
}

#endif  // included_hier_SequentialLocalIdGenerator