/********************************************************************************
 * �ļ�����Utils.h
 * �����ˣ��α�
 * ����ʱ�䣺2014-8-22
 * �汾��1.0
 * ���ļ��汾�ţ�1.0
 * �����£�
 * ����˵����
 * ��ʷ�޸ļ�¼��
 * <author>  <time>           <version >   <desc>
 *********************************************************************************/
#ifndef __NXCORE_VAR_MACROS_H__
#define __NXCORE_VAR_MACROS_H__

#include <Helper.h>
#include <stddef.h>

// ͨ�ý�������
// varName:		�������õ��ı�����(��������ñ��еı��뱣��һ��)
// varType:		����������
// seperator:	���ڷָ���ַ���
#define ParseString2List(varName, varType, srcString, seperator)											\
	Helper::ArrayBuffer<varType> abuf##varName;																\
	Helper::splitInto(abuf##varName, srcString, seperator);													\
	for (uint32 i = 0; i < abuf##varName.size(); ++i)														\
	{																										\
		varName.push_back(abuf##varName[i]);																\
	}

#define RewardAssign(a)	PVPRenownReward[a - 1] = PVPreward##a;

#endif//__NXCORE_VAR_MACROS_H__
