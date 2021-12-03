#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024
#define HEAP_SIZE 32

typedef int32_t elem;
#define error(s) do{fprintf(stderr,"%s\n",(s));exit(EXIT_FAILURE);}while(0)
#define in(a,b,c) (((a)<=(b))&&((b)<=(c)))
#define ill(c) (!in(0x01,(c),0x7F))

/* stack */
elem stack[STACK_SIZE];
int sp = 0;
#define has(x) do{if(sp<(x))error("Error: Too few elements");}while(0)
void push(elem x) {stack[sp++] = x;}
elem pop() {has(1); return stack[--sp];}
elem peek() {has(1); return stack[sp-1];}
#define op1(c) do{push(c(pop()));}while(0)
#define op2(c) do{has(2);push((pop())c(pop()));}while(0)
#define div0() do{has(2);if(!stack[sp-2])error("Error: Division by zero");}while(0)

/* heap */
elem heap[HEAP_SIZE];

#define putcf(to) do{while((c=prog[i++])!=(to))putchar(c);}while(0)
#define pushf(to) do{while((c=prog[i++])!=(to))push(c);}while(0)
#define skipf(to) do{while((c=prog[i++])!=(to));}while(0)
#define skipb(to) do{while((c=prog[--i])!=(to));}while(0)
#define gof(from,to) do { \
    int d = 1; \
    while (d) { \
        c = prog[i++]; \
        if (ill(c)) goto end; \
        switch (c) { \
        case '"': skipf('"'); break; \
        case '\'': skipf('\''); break; \
        case from: d++; break; \
        case to: d--; break; \
        } \
    } \
} while(0)
#define gob(to,from) do { \
    int d = 1; \
    i--; \
    while (d) { \
        c = prog[--i]; \
        if (ill(c)) goto end; \
        switch (c) { \
        case '"': skipb('"'); break; \
        case '\'': skipb('\''); break; \
        case to: d--; break; \
        case from: d++; break; \
        } \
    } \
} while(0)

char *load(const char *filename) {
    char *buffer = NULL;
    long length;
    FILE *file = fopen(filename, "rb");
    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer) {
            if (fread(buffer, 1, length, file) != length)
                buffer = NULL;
        }
        fclose(file);
    }
    return buffer;
}

int main(int argc, char **argv) {
    const bool emode = argc < 2 ? false : !strcmp(argv[1], "-e");
    const int offset = emode ? 3 : 2;
    if (argc < offset) error("Usage: calc [-e] src [STACK ...]");
    char *prog = emode ? argv[2] : load(argv[1]);
    if (!prog) error("Error: Reading file failed");
    for (int i = offset; i < argc; i++) push(atoi(argv[i]));
    for (int i = 0;;) {
        char c = prog[i++];
        if (ill(c)) goto end;
        if (in('0', c, '9')) push(10 * pop() + c - '0');
        else if (in('A', c, 'Z')) push(c - 'A');
        else switch (c) {
            case '!': op1(!); break;
            case '"': putcf('"'); break;
            case '#': push(0); break;
            case '$': pop(); break;
            case '%': div0(); op2(%); break;
            case '&': op2(&); break;
            case'\'': pushf('\''); break;
            case '(': { if (!pop()) gof('(', ')'); } break;
            case ')': /* end if */ break;
            case '*': op2(*); break;
            case '+': op2(+); break;
            case ',': push(heap[pop()]); break;
            case '-': op2(-); break;
            case '.': heap[pop()] = pop(); break;
            case '/': div0(); op2(/); break;
            case ':': push(peek()); break;
            case ';': { const elem e = pop(); has(e + 1); push(stack[sp - e - 1]); } break;
            case '<': op2(<); break;
            case '=': op2(==); break;
            case '>': op2(>); break;
            case '?': { const elem e1 = pop(); const elem e2 = pop(); const elem e3 = pop(); push(e1 ? e2 : e3); } break;
            case '@': { const elem e1 = pop(); const elem e2 = pop(); const elem e3 = pop(); push(e2); push(e1); push(e3); } break;
            case '[': { if (!peek()) gof('[', ']'); } break;
            case'\\': { const elem e1 = pop(); const elem e2 = pop(); push(e1); push(e2); } break;
            case ']': { if (peek()) gob('[', ']'); } break;
            case '^': op2(^); break;
            case '_': op1(-); break;
            case '`': { const elem e1 = pop(); has(e1 + 1); const elem e2 = pop(); for (int j = 0; j < e1; j++) pop(); push(e2); } break;
    /* TODO case 'a': break; */
            case 'b': putchar('\b'); break;
            case 'c': sp = 0; break;
            case 'd': push(pop() - 1); break;
    /* TODO case 'e': break; */
            case 'f': putchar('\f'); break;
            case 'g': push(getchar()); break;
            case 'h': goto end;
            case 'i': push(pop() + 1); break;
    /* TODO case 'j': break; */
    /* TODO case 'k': break; */
    /* TODO case 'l': break; */
            case 'm': { int d; scanf("%d", &d); push((elem) d); } break;
            case 'n': putchar('\n'); break;
            case 'o': printf("%d\n", peek()); break;
            case 'p': putchar(pop()); break;
            case 'q': { for (int j = 0; j < sp; j++) printf("%d\n", stack[j]); } break;
            case 'r': putchar('\r'); break;
            case 's': { const elem e = pop(); push(e * e); } break;
            case 't': putchar('\t'); break;
    /* TODO case 'u': break; */
            case 'v': putchar('\v'); break;
            case 'w': printf("%d", pop()); break;
            case 'x': { const elem e = pop(); push(i); i = e; } break;
    /* TODO case 'y': break; */
            case 'z': push(sp); break;
            case '{': { push(i); gof('{', '}'); } break;
            case '|': op2(|); break;
            case '}': i = pop(); break;
            case '~': op1(~); break;
            default: { if (in('!', c, '~')) error("Error: Unexpected character"); }
        }
    }
end:
    if (!emode) free(prog);
    return sp > 0 ? pop() : EXIT_SUCCESS;
}
