#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "引数の個数が正しくありません\n");
        return 1;
    }

    char *p = argv[1]; // 2番目の引数の最初の文字のポインタ

    // printf("*argv: %s\n", *argv);
    // printf("*argv: %s\n", *(argv+1));
    // printf("*argv: %d\n", **(argv+1));

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf("  mov rax, %ld\n", strtol(p, &p, 10));
    // happy new year

    while (*p) {
        if (*p == '+') {
            p++;
            // printf("p: %s\n", p); // 引数が"5+2-4"のとき，"2-4"
            printf("  add rax, %ld\n", strtol(p, &p, 10)); // 2が出力され，"-4"の'-'へのポインタがpに格納される．
            continue;
        }

        if (*p == '-') {
            p++;
            printf("  sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "予期しない文字です: '%c'\n", *p);
        return 1;
    }


    printf("  ret\n");
    return 0;
}
