#include <cstdio>
#include <ctime>
#include <cstdlib>
int main(const int argc, const char **argv) {
  int n = 10;
  if (argc == 2) n = std::atoi(argv[1]);
  std::srand(std::time(nullptr));
  while (n--) {
    char c = 0;
    do c = std::rand() & 0x7f;
    while (('a' > c || c > 'z') && ('A' > c || c > 'Z'));
    std::putchar(c);
  }
  return std::puts(""), 0;
}
