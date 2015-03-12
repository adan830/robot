/********************************************************************************
 * �ļ�����Common_Utility.h
 * �����ˣ��α�
 * ����ʱ�䣺2014-8-19
 * �汾��1.0
 * ���ļ��汾�ţ�1.0
 * �����£�
 * ����˵����
 * ��ʷ�޸ļ�¼��
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

    // �ж��Ƿ�v1������v2��
    template<class T>
    static bool IsVectorInRange(std::vector<T>& v1, std::vector<T>& v2)
    {
        int size1 = v1.size();
        int size2 = v2.size();

        // ���v1����v2����϶�������
        if (size1 > size2)
        {
            return false;
        }

		for (typename std::vector<T>::iterator i = v1.begin(); i != v1.end(); ++i)
		{
			// ����Ƿ������v2��
			if (!IsExist(v2, *i))
			{
				return false;
			}
		}

        return true;
    }

	// ɾ����һ���ҵ���Ŀ�����
	template<class T>
	inline void Remove(std::vector<T*>& vec, T* p)
	{
		typename std::vector<T*>::iterator it = find(vec.begin(), vec.end(), p);

		if (it != vec.end())
		{
			vec.erase(it);
		}
	}

	// ɾ����һ���ҵ���Ŀ�����
	template<class T>
	inline void Remove(std::vector<T>& vec, T p)
	{
		typename std::vector<T>::iterator it = find(vec.begin(), vec.end(), p);

		if (it != vec.end())
		{
			vec.erase(it);
		}
	}

	// ɾ����һ���ҵ���Ŀ�����
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

	// ѭ��ɾ������Դ��ָ������
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

	// ѭ��ɾ������Դ��ָ������
	template<class T>
	static void RemoveAll(std::vector<T>& vec, T p)
	{
		// ȥ������Ŀո�
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

	// ͨ����ֵɾ��
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

	// ��ȡ�����Ԫ�ض���
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

				// �Ƴ���Ӧ��Ԫ��
				Common::Remove(vecList, vecList[index]);
			}
		}

		return list;
	}

	// ��ȡ�����Ԫ�ض���
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

				// �Ƴ���Ӧ��Ԫ��
				Common::Remove(vecList, vecList[index]);
			}
		}

		return list;
	}

	template<class T>
	static std::vector<T> TransToValueVector(std::string c, std::string strSeparator)
	{
		std::vector<T> list;

		// ��ȡ������Ӧ�Ĺؿ�Id
		ParseString2List(list, T, c, strSeparator);

		return list;
	}

	//���ַ����и��vector
	inline std::vector<std::string> TransToStringVector(std::string c, std::string strSeparator)
	{
		return TransToValueVector<std::string>(c, strSeparator);
	}

	//ȥ���ַ�����β�ո�
	inline void Trim(std::string& str)
	{
		static const std::string delims = " \t\r";
		str.erase(str.find_last_not_of(delims) + 1); // trim right
		str.erase(0, str.find_first_not_of(delims)); // trim left
	}
}

#endif //__COMMON_UTILITY_H__
