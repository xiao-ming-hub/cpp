#include <cstdio>
#include <exception>
#include <map>
#include <queue>
struct btn {
    int val;
    btn *l, *r;
};
struct cmp {
    bool operator()(const btn *a, const btn *b) {
        return a->val > b->val;
    }
};
std::priority_queue<btn*, std::vector<btn*>, cmp> forest;
std::map<btn*, char> name;
std::map<char, int> ans;
void dfs(int path, btn *hed) {
    if (hed->l == nullptr) {
        ans[name[hed]] = path;
        return;
    }
    dfs(path << 1, hed->l);
    dfs((path << 1) + 1, hed->r);
}
int main() {
    int i;
    char c;
    while (scanf("%c%d", &c, &i) != EOF) {
        btn *t = new btn;
        *t = {i, nullptr, nullptr};
        name[t] = c;
        forest.push(t);
    }
    while (forest.size() > 1) {
        btn *t1, *t2, *t = new btn;
        t1 = forest.top();
        forest.pop();
        t2 = forest.top();
        forest.pop();
        *t = {t1->val + t2->val, t1, t2};
    }
    dfs(1,forest.top());
    for (std::map<char, int>::iterator it = ans.begin(); it != ans.end(); it++) {
        std::vector<char> num;
        putchar(it->first);
        putchar(' ');
        for (int t = it->second; t != 1; t >>= 1)
            num.push_back("01"[i & 1]);
        for (int i = num.size() - 1; i >= 0; i--)
            putchar(num[i]);
        puts("");
    }
    return 0;
}
