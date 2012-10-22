//
//  TIMERS_CONVERSION_HEADER.h
//  IOUSBFamily
//
//  Created by EMlyDinEsHMG on 8/31/12.
//
//

#ifndef IOUSBFamily_TIMERS_CONVERSION_HEADER_h
#define IOUSBFamily_TIMERS_CONVERSION__HEADER_h

#define AbsoluteTime_to_scalar(x)    (*(uint64_t *)(x))

 #define CMP_ABSOLUTETIME(t1, t2)                \
 (AbsoluteTime_to_scalar(t1) >                \
    AbsoluteTime_to_scalar(t2)? (int)+1 :    \
    (AbsoluteTime_to_scalar(t1) <                \
      < AbsoluteTime_to_scalar(t2)? (int)-1 : 0))

 /* t1 += t2 */
 #define ADD_ABSOLUTETIME(t1, t2)                \
 (AbsoluteTime_to_scalar(t1) +=                \
    AbsoluteTime_to_scalar(t2))

 /* t1 -= t2 */
 #define SUB_ABSOLUTETIME(t1, t2)                \
 (AbsoluteTime_to_scalar(t1) -=                \
    AbsoluteTime_to_scalar(t2))
 
#define ADD_ABSOLUTETIME_TICKS(t1, ticks)        \
 (AbsoluteTime_to_scalar(t1) +=                \
    (int32_t)(ticks))

/************/
/* #include "xnu/xnu-2050.7.9/libkern/libkern/OSBase.h"
   #include "../../xnu/xnu-2050.7.9/iokit/IOkit/IOHibernatePrivate.h"
 clock_get_uptime(&xxx); --> clock_get_uptime((uint64_t *)&xxx);
 
 clock_get_uptime(&XXX);
 -->   clock_get_uptime(__OSAbsoluteTimePtr(&XXX));
 
 nanoseconds_to_absolutetime(XXX, &XXX); 
 -->   nanoseconds_to_absolutetime(XXX, (uint64_t *)&XXX);
 
 absolutetime_to_nanoseconds(XXX, &XXX);
 --->   absolutetime_to_nanoseconds(*((uint64_t *)&XXX), &XXX);
     
 *************/

#endif
