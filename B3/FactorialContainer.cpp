#include "FactorialContainer.hpp"

tikhonov::FactorialContainer::FactorialIterator::FactorialIterator(value_type index, value_type value):
  index_(index),
  value_(value)
{}

tikhonov::FactorialContainer::FactorialIterator::reference tikhonov::FactorialContainer::FactorialIterator::operator*()
{
  return value_;
}

tikhonov::FactorialContainer::FactorialIterator::pointer tikhonov::FactorialContainer::FactorialIterator::operator->()
{
  return &value_;
}

tikhonov::FactorialContainer::FactorialIterator& tikhonov::FactorialContainer::FactorialIterator::operator++()
{
  ++index_;
  value_ *= index_;
  return *this;
}

tikhonov::FactorialContainer::FactorialIterator tikhonov::FactorialContainer::FactorialIterator::operator++(int)
{
  FactorialIterator tmp = *this;
  ++* this;
  return tmp;
}

tikhonov::FactorialContainer::FactorialIterator& tikhonov::FactorialContainer::FactorialIterator::operator--()
{
  if (index_ > 1)
  {
    value_ /= index_;
    index_--;
  }
  return *this;
}

tikhonov::FactorialContainer::FactorialIterator tikhonov::FactorialContainer::FactorialIterator::operator--(int)
{
  FactorialIterator tmp = *this;
  --* this;
  return tmp;
}

bool tikhonov::FactorialContainer::FactorialIterator::operator==(const FactorialIterator& it) const
{
  return (value_ == it.value_);
}

bool tikhonov::FactorialContainer::FactorialIterator::operator!=(const FactorialIterator& it) const
{
  return !(*this == it);
}

tikhonov::FactorialContainer::const_iterator tikhonov::FactorialContainer::cbegin() const
{
  return tikhonov::FactorialContainer::FactorialIterator(MIN_FACTORIAL_NUMBER, MIN_FACTORIAL);
}

tikhonov::FactorialContainer::const_iterator tikhonov::FactorialContainer::cend() const
{
  return tikhonov::FactorialContainer::FactorialIterator(MAX_FACTORIAL_NUMBER, MAX_FACTORIAL);
}

tikhonov::FactorialContainer::const_reverse_iterator tikhonov::FactorialContainer::crbegin()
{
  return std::make_reverse_iterator(cend());
}

tikhonov::FactorialContainer::const_reverse_iterator tikhonov::FactorialContainer::crend()
{
  return std::make_reverse_iterator(cbegin());
}

tikhonov::FactorialContainer::size_type tikhonov::FactorialContainer::size() const noexcept
{
  return MAX_FACTORIAL_NUMBER - MIN_FACTORIAL_NUMBER;
}

tikhonov::FactorialContainer::size_type tikhonov::FactorialContainer::max_size() const noexcept
{
  return MAX_FACTORIAL_NUMBER - MIN_FACTORIAL_NUMBER;
}

bool tikhonov::FactorialContainer::empty() const noexcept
{
  return false;
}

void tikhonov::FactorialContainer::swap(FactorialContainer&) const noexcept
{}
