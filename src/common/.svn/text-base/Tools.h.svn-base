#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <Base.h>
#include <Define.h>
#include <string>
#include <vector>
#include <Helper.h>
#include <math.h>
#include <Macros.h>

// 辅助工具类
class Tools
{
public:

	// 序列化数组信息
	static void serialize_Array(uint64* arry, uint32 count, char* data);

	// 序列化map信息
	static void serialize_Map(MapUint_Uint& map, char* data);
	
	// 反序列化数组
	static std::vector<uint64> deserialize_Array(char* data, uint32 size);

	// 反序列化Map
	static MapUint_Uint deserialize_Map(char* data, uint32 size);

	// 获取指定长度的数组中的有效数值数目
	static uint32 getValidateNumber(uint64* array, uint32 maxCount);
};

// 将奖励信息写入到指定的内存中
inline void Tools::serialize_Array(uint64* arry, uint32 count, char* data)
{
	Helper::DataBuilder db(data);
	db << count;

	DEBUG_LOG("serialize_Array, count:%u \n", count);

	for (uint32 i = 0; i < count; ++i)
	{
		db << arry[i];
	}
}

// 将Map写入到指定的内存中
inline void Tools::serialize_Map(MapUint_Uint& map, char* data)
{
	Helper::DataBuilder db(data);

	uint32 count = map.size();
	db << count;

	DEBUG_LOG("serialize_Map, count:%u \n", count);

	for (MapUint_Uint::iterator it = map.begin(); it != map.end(); ++it)
	{
		db << it->first << it->second;
	}
}

// 反序列化数组
inline std::vector<uint64> Tools::deserialize_Array(char* data, uint32 size)
{
	std::vector<uint64> vecList;

	Helper::DataBuilder db(data, size);
	uint32 count = 0;
	db >> count;
	for (uint32 i = 0; i < count; ++i)
	{
		uint64 p = 0;
		db >> p;

		vecList.push_back(p);
	}

	return vecList;
}

// 反序列化Map
inline MapUint_Uint Tools::deserialize_Map(char* data, uint32 size)
{
	MapUint_Uint map;

	Helper::DataBuilder db(data, size);
	uint32 count = 0;
	db >> count;
	for (uint32 i = 0; i < count; ++i)
	{
		uint32 key		= 0;
		uint32 value	= 0;

		db >> key >> value;

		map[key] = value;
	}

	return map;
}

// 获取指定长度的数组中的有效数值数目
inline uint32 Tools::getValidateNumber(uint64* array, uint32 maxCount)
{
	uint32 value = 0;
	for (uint32 i = 0; i < maxCount; ++i)
	{
		if (array[i])
		{
			value++;
		}		
	}

	return value;
}

#endif// __TOOLS_H__

