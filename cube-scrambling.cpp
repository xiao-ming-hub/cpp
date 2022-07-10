#include <cstdio>
#include <ctime>
#include <cstdlib>
bool check(int now, int last, int ll) {
  if (last == -1) return false;
  if (now / 3 == last / 3) return true;
  if (-~ll && now / 6 == last / 6 && now / 3 == ll / 3) return true;
  return false;
}
int main() {
  const int step = 20;
  const char *letter[]{
    "U", "U\'", "U2", "D", "D\'", "D2",
    "F", "F\'", "F2", "B", "B\'", "B2",
    "L", "L\'", "L2", "R", "R\'", "R2",
  };
  int move, lastmove = -1, llm = -1;
  std::srand(std::time(nullptr));
  for (int i = 0; i < step; i++) {
    llm = lastmove;
    lastmove = move;
    do move = std::rand() % 18;
    while (check(move, lastmove, llm));
    std::printf("%s ", letter[move]);
  }
  return std::puts("");
}
