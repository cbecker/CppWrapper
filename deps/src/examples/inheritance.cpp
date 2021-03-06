#include <string>

#include <cpp_wrapper.hpp>

struct A
{
  virtual std::string message() = 0;
};

struct B : A
{
  virtual std::string message()
  {
    return "B";
  }
};

struct AWrapper
{
  template<typename T>
  void operator()(T& wrapped)
  {

  }
};

struct BWrapper
{
  template<typename T>
  void operator()(T& wrapped)
  {
  }
};

JULIA_CPP_MODULE_BEGIN(registry)
  cpp_wrapper::Module& types = registry.create_module("CppInheritance");
  types.add_abstract<A>("A").method("message", &A::message);
  types.add_type<B>("B", cpp_wrapper::julia_type<A>());
JULIA_CPP_MODULE_END
