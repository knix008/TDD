#ifndef __VECTORUTIL_H__
#define __VECTORUTIL_H__

#include <vector>
#include <functional>
#include <algorithm>

template <typename TFrom, typename TTo>
std::vector<TTo> Collect(
    const std::vector<TFrom> &source,
    std::function<TTo(TFrom)> func)
{
   std::vector<TTo> results;
   std::transform(source.begin(), source.end(), std::back_inserter(results), func);
   return results;
}

#endif