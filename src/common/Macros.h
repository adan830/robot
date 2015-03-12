/********************************************************************************
 * �ļ�����Macros.h
 * �����ˣ��α�
 * ����ʱ�䣺2014-9-18
 * �汾��1.0
 * ���ļ��汾�ţ�1.0
 * �����£�
 * ����˵����
 * ��ʷ�޸ļ�¼��
 * <author>  <time>           <version >   <desc>
 *********************************************************************************/
#ifndef __NXCORE_MACROS_H__
#define __NXCORE_MACROS_H__

#include <Helper.h>
#include <stddef.h>
#include <map>
#include <vector>
#include <Base.h>

typedef std::map<uint32, uint32>		MapUint_Uint;

typedef std::map<std::string, uint64>	MapString_Int;

typedef std::pair<uint32, uint32>		PairUint_Uint;

typedef std::vector<uint32>				Vec32;

#endif//__NXCORE_MACROS_H__
