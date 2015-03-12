/********************************************************************************
 * 文件名：Common_Utility.h
 * 创建人：宋斌
 * 创建时间：2014-8-19
 * 版本：1.0
 * 本文件版本号：1.0
 * 最后更新：
 * 功能说明：
 * 历史修改记录：
 * <author>  <time>           <version >   <desc>
 *********************************************************************************/
#ifndef __COMMON_UTILITY_H__
#define __COMMON_UTILITY_H__

#include <vector>
#include <set>
#include <string>
#include <VarMacros.h>

namespace Common
{
    template<class T>
    static bool IsExist(std::vector<T>& vec, T& vl)
    {
		for (typename std::vector<T>::iterator i = vec.begin(); i != vec.end(); ++i)
		{
			if (*i == vl)
			{
				return true;
			}
		}

        return false;
    }

    template<class T>
    static bool IsExist(std::vector<T*>& vec, T* vl)
    {
		for (typename std::vector<T*>::iterator i = vec.begin(); i != vec.end(); ++i)
		{
			if (*i == vl)
			{
				return true;
			}
		}

        return false;
    }

	template<class T1, class T2>
	static bool IsExist(std::map<T1, T2>& map, T1& p)
	{
		typename std::map<T1, T2>::iterator it = map.begin();
		for (; it != map.end(); ++it)
		{
			if (it->first == p)
			{
				return true;
			}
		}

		return false;
	}

    // 判断是否v1包含于v2中
    template<class T>
    static bool IsVectorInRange(std::vector<T>& v1, std::vector<T>& v2)
    {
        int size1 = v1.size();
        int size2 = v2.size();

        // 如果v1大于v2，则肯定不包含
        if (size1 > size2)
        {
            return false;
        }

		for (typename std::vector<T>::iterator i = v1.begin(); i != v1.end(); ++i)
		{
			// 检查是否存在于v2中
			if (!IsExist(v2, *i))
			{
				return false;
			}
		}

        return true;
    }

	// 删除第一个找到的目标对象
	template<class T>
	inline void Remove(std::vector<T*>& vec, T* p)
	{
		typename std::vector<T*>::iterator it = find(vec.begin(), vec.end(), p);

		if (it != vec.end())
		{
			vec.erase(it);
		}
	}

	// 删除第一个找到的目标对象
	template<class T>
	inline void Remove(std::vector<T>& vec, T p)
	{
		typename std::vector<T>::iterator it = find(vec.begin(), vec.end(), p);

		if (it != vec.end())
		{
			vec.erase(it);
		}
	}

	// 删除第一个找到的目标对象
	template<class T1, class T2>
	inline void Remove(std::vector<T1>& vec, const T2* p)
	{
		for(typename std::vector<T1>::iterator it = vec.begin(); it != vec.end();)
		{
			if ((*it).target == p)
			{
				it = vec.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	// 循环删除数据源中指定对象
	template<class T>
	static void RemoveAll(std::vector<T*>& vec, T* p)
	{
		for (typename std::vector<T*>::iterator it = vec.begin(); it != vec.end();)
		{
			if (*it == p)
			{
				it = vec.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	// 循环删除数据源中指定对象
	template<class T>
	static void RemoveAll(std::vector<T>& vec, T p)
	{
		// 去掉多余的空格
		typename std::vector<T>::iterator iter = vec.begin();
		while (iter != vec.end())
		{
			if (*iter == p)
			{
				iter = vec.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}

	// 通过键值删除
	template<class T1, class T2>
	inline void Remove(std::map<T1, T2>& map, T1 p)
	{
		typename std::map<T1, T2>::iterator it = map.begin();
		for (; it != map.end(); ++it)
		{
			if (it->first == p)
			{
				map.erase(it);
			}
		}
	}

	template<class T>
	static void AddRange(std::vector<T*>& vec1, std::vector<T*> vec2)
	{
		for (typename std::vector<T*>::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{
			vec1.push_back(*it);
		}
	}

	template<class T>
	static void AddRange(std::vector<T>& vec1, std::vector<T> vec2)
	{
		for (typename std::vector<T>::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{
			vec1.push_back(*it);
		}
	}

	template<class T>
	static void AddRangeMutex(std::vector<T>& vec1, std::vector<T> vec2)
	{
		for (typename std::vector<T>::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{
			if (!IsExist(vec1, *it))
			{
				vec1.push_back(*it);
			}
		}
	}

	template<class T>
	static void RemoveRange(std::vector<T*>& vec1, std::vector<T*> vec2)
	{
		for (typename std::vector<T*>::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{
			Remove(vec1, *it);
		}
	}

	template<class T>
	static void RemoveRange(std::vector<T*>& vec1, std::set<T*> vec2)
	{
		for (typename std::set<T*>::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{
			Remove(vec1, *it);
		}
	}

	// 获取随机的元素对象
	template<class T>
	static std::vector<T*> getRandomList(std::vector<T*>& vecList, uint32 maxCount)
	{
		std::vector<T*> list;
		if (vecList.size() <= maxCount)
		{
			list = vecList;
		}
		else
		{
			for (uint32 i = 0; i < maxCount; ++i)
			{
				uint32 index = Helper::randBetween(0, vecList.size() - 1);
				list.push_back(vecList[index]);

				// 移除对应的元素
				Common::Remove(vecList, vecList[index]);
			}
		}

		return list;
	}

	// 获取随机的元素对象
	template<class T>
	static std::vector<T> getRandomList(std::vector<T>& vecList, uint32 maxCount)
	{
		std::vector<T> list;
		if (vecList.size() <= maxCount)
		{
			list = vecList;
		}
		else
		{
			for (uint32 i = 0; i < maxCount; ++i)
			{
				uint32 index = Helper::randBetween(0, vecList.size() - 1);
				list.push_back(vecList[index]);

				// 移除对应的元素
				Common::Remove(vecList, vecList[index]);
			}
		}

		return list;
	}

	template<class T>
	static std::vector<T> TransToValueVector(std::string c, std::string strSeparator)
	{
		std::vector<T> list;

		// 获取副本对应的关卡Id
		ParseString2List(list, T, c, strSeparator);

		return list;
	}

	//将字符串切割成vector
	inline std::vector<std::string> TransToStringVector(std::string c, std::string strSeparator)
	{
		return TransToValueVector<std::string>(c, strSeparator);
	}

	//去除字符串首尾空格
	inline void Trim(std::string& str)
	{
		static const std::string delims = " \t\r";
		str.erase(str.find_last_not_of(delims) + 1); // trim right
		str.erase(0, str.find_first_not_of(delims)); // trim left
	}
}

#endif //__COMMON_UTILITY_H__
