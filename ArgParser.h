#include <algorithm>
#include <string>
#include <unordered_map>

/*
 * Simple argv parser. Can only parse --double-dash=string format.
 */
namespace {
class ArgParser {
 private:
  std::unordered_map<std::string, const char *> ml;

 public:
  ArgParser() {}
  virtual ~ArgParser() {}

  const char *&define_str(const char *s) { return ml[s]; }
  void parse(int argc, const char *const *argv) {
    parse(argv + 1, argv + argc);
  }
  const char *const *parse(const char *const *first, const char *const *last) {
    for (const char *const *arg = first; arg != last; ++arg) {
      if (!std::equal(*arg, *arg + 2, "--")) return arg;
      const char *i = *arg + 2;
      while (*i && *i != '=') ++i;
      if (i == *arg + 3) return ++arg;
      ml[std::string(*arg + 2, i)] = *i ? i + 1 : i;
    }
    return last;
  }
};
}  // namespace
