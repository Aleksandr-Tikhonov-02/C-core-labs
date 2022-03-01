#ifndef _SORT_TOOLS_
#define _SORT_TOOLS_

namespace tikhonov
{
  template<typename Container>
  class Index
  {
  public:
    using IterableType = typename Container::size_type;

    static IterableType begin(Container&)
    {
      return 0;
    }

    static IterableType end(Container& container)
    {
      return container.size();
    }

    static typename Container::value_type& getValue(Container& container, IterableType index)
    {
      return container[index];
    }
  };

  template<typename Container>
  class At
  {
  public:
    using IterableType = typename Container::size_type;

    static IterableType begin(Container&)
    {
      return 0;
    }

    static IterableType end(Container& container)
    {
      return container.size();
    }

    static typename Container::value_type& getValue(Container& container, IterableType index)
    {
      return container.at(index);
    }
  };

  template<typename Container>
  class Iterator
  {
  public:
    using IterableType = typename Container::iterator;

    static IterableType begin(Container& container)
    {
      return container.begin();
    }

    static IterableType end(Container& container)
    {
      return container.end();
    }

    static typename Container::value_type& getValue(Container&, IterableType iterator)
    {
      return *iterator;
    }
  };
}

#endif
