#include <cstdio>
#include <ctime>
#include <cstdlib>
int main(const int argc, const char **argv) {
    int n = 10;
    if (argc == 2) n = atoi(argv[1]);
    srand(time(nullptr));
    while (n--) {
        char c = 0;
        do c = rand() & 0x7f;
        while (('a' > c || c > 'z') && ('A' > c || c > 'Z'));
        putchar(c);
    }
    return puts(""), 0;
}
