#ifndef _SORT_
#define _SORT_

#include <utility>
#include "direction.hpp"

namespace tikhonov
{
  template<template<typename> class Tool, typename Type>
  void sort(Type& array, Direction direction)
  {
    for (typename Tool<Type>::IterableType i = Tool<Type>::begin(array); i != Tool<Type>::end(array); ++i)
    {
      for (typename Tool<Type>::IterableType j = i; j != Tool<Type>::end(array); ++j)
      {
        if (((direction == Direction::ASCENDING) && (Tool<Type>::getValue(array, i) > Tool<Type>::getValue(array, j))) ||
            ((direction == Direction::DESCENDING) && (Tool<Type>::getValue(array, i) < Tool<Type>::getValue(array, j))))
        {
          std::swap(Tool<Type>::getValue(array, i), Tool<Type>::getValue(array, j));
        }
      }
    }
  }
}

#endif
