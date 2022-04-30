#include <cstdio>
struct Node {
    unsigned char data;
    Node *pre, *next;
    Node(unsigned char d = 0, Node *p = nullptr, Node *n = nullptr) {
        data = d;
        pre = p;
        next = n;
    }
} * memory, *source;
Node *left(Node **nd) {
    if ((*nd)->pre != nullptr) (*nd) = (*nd)->pre;
    return *nd;
}
Node *right(Node **nd) {
    if ((*nd)->next == nullptr) {
        Node *t = new Node;
        (*nd)->next = t;
        t->pre = *nd;
    }
    (*nd) = (*nd)->next;
    return *nd;
}
int init_code(FILE *code) {
    char c;
    source = new Node;
    while (1) {
        bool flag = 1;
        do {
            const char *cmd = "+-<>,.[]";
            c = fgetc(code);
            if (c == EOF) break;
            for (int idx = 0; idx < 8; idx++)
                if (c == cmd[idx]) {
                    flag = 0;
                    break;
                }
        } while (flag);
        if (c == EOF) break;
        right(&source);
        source->data = c;
    }
    while (source->data)
        left(&source);
    return 0;
}
int run() {
    bool err = 0;
    memory = new Node;
    while (1) {
        if (source->next == nullptr) break;
        right(&source);
        char c = source->data;
        switch (c) {
        case '+':
            memory->data++;
            break;
        case '-':
            memory->data--;
            break;
        case '<':
            if (memory->pre == nullptr) {
                err = 1;
                break;
            }
            left(&memory);
            break;
        case '>':
            right(&memory);
            break;
        case ',':
            memory->data = getchar();
            break;
        case '.':
            putchar(memory->data);
            break;
        case '[':
            if (memory->data == 0) {
                int le = 1;
                while (source->next != nullptr) {
                    right(&source);
                    if (source->data == '[') le++;
                    if (source->data == ']') le--;
                    if (!le) break;
                }
                if (le) err = 1;
            }
            break;
        case ']':
            if (memory->data) {
                int ri = 1;
                while (source->pre != nullptr) {
                    left(&source);
                    if (source->data == '[') ri--;
                    if (source->data == ']') ri++;
                    if (!ri) break;
                }
                if (ri) err = 1;
            }
            break;
        default:
            break;
        }
        if (err) break;
    }
    if (err) {
        puts("Runtime Error!");
        return -1;
    }
    return 0;
}
int main(const int argc, const char **argv) {
    FILE *code;
    if (argc - 2) return -1;
    code = fopen(argv[1], "r");
    if (code == nullptr) return -1;
    return init_code(code) + run();
}
