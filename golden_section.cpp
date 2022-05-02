#include <cstdio>
#define f(x) (x * x + x - 1)
#define g(x) (2 * x + 1)
int main() {
    double xi = 1;
    char c;
    for (int i = 1; true; i++) {
        xi -= f(xi) / g(xi);
        std::printf("%2d %.20lf ", i, xi);
        std::fflush(stdout);
        do c = std::getchar(); while(c != '\n' && c != EOF);
        if (c == EOF) break;
    }
    return std::puts(""), 0;
}
