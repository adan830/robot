#ifndef __LOCAL_ALGORITHM_H__
#define __LOCAL_ALGORITHM_H__

#include <vector>
#include "Base.h"
void StrToLower(char * str)
{
    char * s = str;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z')
            *s += 32;
        s++;
    }
}

// 计算字符串 Hash 值
uint64 strhash(const char * const str)
{
    uint64 hash = 0;
    const char * p = str;
    while (*p) {
        hash = (hash << 4) + *p;
        ++p;
    }
    return hash;
}

// 计算是否需要整点刷新
bool NeedUpdate(int clock, int currtime, int prevtime)
{
    if (currtime < prevtime)
        return false;

    if (currtime - prevtime > 86400)
        return true;

    static int OFFSET[24] = {0,     3600,  7200,  10800, 14400, 18000,
                             21600, 25200, 28800, 32400, 36000, 39600,
                             43200, 46800, 50400, 54000, 57600, 61200,
                             64800, 68400, 72000, 75600, 79200, 82800};
    
    int offset = OFFSET[clock];
    int todayclock = currtime - (currtime % 86400 + 28800) + offset;
    int prevclock  = prevtime - (prevtime % 86400 + 28800) + offset;

    if (prevtime < prevclock && prevclock < currtime)
        return true;

    if (prevtime < todayclock && todayclock < currtime)
        return true;

    return false;
}

// 按范围取值
int RangeValue(int val, int min, int max)
{
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

void randelem(std::vector<int>& vect, int m, int n, int seed)
{
    if (n > m) {
        n = m;
    }

    int r = 0, i = 0;
    srand(seed);
    while (n > 0) {
        r = rand() % m + 1;
        if (r <= n) {
            vect.push_back(i);
            n--;
        }
        i++;
        m--;
    }
}

#endif


