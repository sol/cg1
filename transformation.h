//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   transformation.h - (c) 2003 by The Marrowmoon Group                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H


namespace Transformations {
    

//interface for transformations
class Transformation {
public:
     virtual ~Transformation() {}

     virtual void Apply(  ) = 0;
     virtual void InverseApply() = 0;
};


}

#endif
