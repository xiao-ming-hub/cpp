#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
void to_mono(const char *s) {
  for (int i = 0; s[i]; i++) {
    if (islower(s[i])) wprintf(L"%lc", s[i] + 0x1D68A - 'a');
    else if (isupper(s[i])) wprintf(L"%lc", s[i] + 0x1D670 - 'A');
    else wprintf(L"%c", s[i]);
  }
  wprintf(L"\n");
}
void to_italic(const char *s) {
  for (int i = 0; s[i]; i++) {
    if (islower(s[i])) wprintf(L"%lc", s[i] + 0x1D44E - 'a');
    else if (isupper(s[i])) wprintf(L"%lc", s[i] + 0x1D434 - 'A');
    else wprintf(L"%c", s[i]);
  }
  wprintf(L"\n");
}
int main(const int argc, const char **argv) {
  if (argc < 3) return -1;
  setlocale(LC_ALL, "zh_CN.UTF-8");
  if (!strcmp(argv[1], "mono")) to_mono(argv[2]);
  else if (!strcmp(argv[1], "italic")) to_italic(argv[2]);
  return 0;
}
