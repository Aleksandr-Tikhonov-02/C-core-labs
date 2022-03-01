#ifndef _BOOKMARKS_EXCEPTIONS_
#define _BOOKMARKS_EXCEPTIONS_

#include <stdexcept>

namespace tikhonov
{
  class EmptyPhoneBook : public std::exception
  {
  public:
    EmptyPhoneBook(const char* msg = "<EMPTY>"):
      msg_(msg)
    {};
    const char* what() const noexcept override
    {
      return msg_;
    }
  private:
    const char* msg_;
  };

  class InvalidCommand : public std::exception
  {
  public:
    InvalidCommand(const char* msg = "<INVALID COMMAND>"):
      msg_(msg)
    {};
    const char* what() const noexcept override
    {
      return msg_;
    }
  private:
    const char* msg_;
  };

  class InvalidBookmark : public std::exception
  {
  public:
    InvalidBookmark(const char* msg = "<INVALID BOOKMARK>"):
      msg_(msg)
    {};
    const char* what() const noexcept override
    {
      return msg_;
    }
  private:
    const char* msg_;
  };

  class InvalidStep : public std::exception
  {
  public:
    InvalidStep(const char* msg = "<INVALID STEP>"):
      msg_(msg)
    {};
    const char* what() const noexcept override
    {
      return msg_;
    }
  private:
    const char* msg_;
  };
}

#endif
