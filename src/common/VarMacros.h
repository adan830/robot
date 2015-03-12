/********************************************************************************
 * 文件名：Utils.h
 * 创建人：宋斌
 * 创建时间：2014-8-22
 * 版本：1.0
 * 本文件版本号：1.0
 * 最后更新：
 * 功能说明：
 * 历史修改记录：
 * <author>  <time>           <version >   <desc>
 *********************************************************************************/
#ifndef __NXCORE_VAR_MACROS_H__
#define __NXCORE_VAR_MACROS_H__

#include <Helper.h>
#include <stddef.h>

// 通用解析方法
// varName:		程序中用到的变量名(程序和配置表中的必须保持一致)
// varType:		变量的类型
// seperator:	用于分割的字符串
#define ParseString2List(varName, varType, srcString, seperator)											\
	Helper::ArrayBuffer<varType> abuf##varName;																\
	Helper::splitInto(abuf##varName, srcString, seperator);													\
	for (uint32 i = 0; i < abuf##varName.size(); ++i)														\
	{																										\
		varName.push_back(abuf##varName[i]);																\
	}

#define RewardAssign(a)	PVPRenownReward[a - 1] = PVPreward##a;

#endif//__NXCORE_VAR_MACROS_H__
