#include "ArgParser.h"

#include <cassert>
#include <iterator>

namespace {

void test_all() {
  ArgParser a;
  const char*& foo = a.define_str("foo");
  const char*& baz = a.define_str("baz");
  const char*& nonexistent = a.define_str("nonexistent");

  static const char* argv[] = {"--foo=bar", "--baz", "--", "arg1"};
  const char* const* arg = a.parse(std::begin(argv), std::end(argv));

  assert(foo && std::string(foo) == "bar");
  assert(baz && std::string(baz) == "");
  assert(nonexistent == nullptr);
  assert(*arg && std::string(*arg) == "arg1");
}

}  // namespace

int main() {
  test_all();
  return 0;
}
