/********************************************************************************
 * 文件名：Utils.h
 * 创建人：宋斌
 * 创建时间：2014-8-19
 * 版本：1.0
 * 本文件版本号：1.0
 * 最后更新：
 * 功能说明：
 * 历史修改记录：
 * <author>  <time>           <version >   <desc>
 *********************************************************************************/
#ifndef __UTILS_H__
#define __UTILS_H__

#include <math.h>

namespace MATH
{
    const double PI         = 3.14159f;
    const double EPSINON    = 0.00001;

    inline static bool FloatEqual(double a, double b)
    {
        if (fabs(a - b) > MATH::EPSINON)
        {
            return false;
        }

        return true;
    }
}


#define MATH_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MATH_MAX(a, b) (((a) > (b)) ? (a) : (b))

// 限定最小值和最大值
#define MATH_RANGE(value, value_Min, value_Max) MATH_MIN(MATH_MAX(value, value_Min), value_Max)

#endif // __UTILS_H__
