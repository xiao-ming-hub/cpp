#include <cstdio>
#define f(x) (x * x + x - 1)
#define g(x) (2 * x + 1)
int main() {
    double xi = 1;
    for (int i = 1; getchar(); i++) {
        printf("%2d %.20lf\n", i, xi);
        xi -= f(xi) / g(xi);
    }
    return 0;
}
