#ifndef _FACTORIAL_CONTAINER_
#define _FACTORIAL_CONTAINER_

#include <iterator>

namespace tikhonov
{
  constexpr unsigned int getFactorial(size_t index)
  {
    return index == 1 ? 1 : getFactorial(index - 1) * index;
  }
  class FactorialContainer
  {
  public:
    class FactorialIterator;
    using size_type = unsigned int;
    using value_type = unsigned int;
    using reference = unsigned int&;
    using const_reference = const unsigned int&;
    using const_iterator = FactorialIterator;
    using difference_type = std::ptrdiff_t;
    using const_reverse_iterator = std::reverse_iterator<FactorialIterator>;

    class FactorialIterator : public std::iterator<std::bidirectional_iterator_tag,
      value_type>
    {
    public:
      FactorialIterator(value_type index, value_type value);
      reference operator *();
      pointer operator ->();
      FactorialIterator& operator ++();
      FactorialIterator operator ++(int);
      FactorialIterator& operator --();
      FactorialIterator operator --(int);
      bool operator ==(const FactorialIterator& it) const;
      bool operator !=(const FactorialIterator& it) const;
    private:
      value_type index_;
      value_type value_;
    };

    const_iterator cbegin() const;
    const_iterator cend() const;
    const_reverse_iterator crbegin();
    const_reverse_iterator crend();
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    bool empty() const noexcept;
    void swap(FactorialContainer&) const noexcept;
  private:
    static constexpr value_type MAX_FACTORIAL_NUMBER = 11;
    static constexpr value_type MIN_FACTORIAL_NUMBER = 1;
    static constexpr value_type MIN_FACTORIAL = getFactorial(MIN_FACTORIAL_NUMBER);
    static constexpr value_type MAX_FACTORIAL = getFactorial(MAX_FACTORIAL_NUMBER);
  };
}

#endif
