#include <cstdio>
int c2i(const char c) {
  if (c > '9') return c - 'a' + 10;
  return c - 48;
}
int main(const int argc, const char **argv) {
  int bg = 0, fg;
  if (argc != 2) return 1;
  for (int i = 0; i < 6; i++) {
    if (i) bg <<= 4;
    bg += c2i(argv[1][i]);
  }
  fg = bg ^ 0xffffff;
  std::printf(
    "\033["
    "38;2;%d;%d;%d;"
    "48;2;%d;%d;%d"
    "m0x%06X\033[m\n",
    fg >> 16, (fg >> 8) & 0xff, fg & 0xff,
    bg >> 16, (bg >> 8) & 0xff, bg & 0xff,
    bg
  );
  return 0;
}
