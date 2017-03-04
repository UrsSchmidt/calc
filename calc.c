// fputs, getchar, printf, putchar, stderr, fopen/fseek/fclose/etc
#include <stdio.h>
// atoi, exit, int32_t
#include <stdlib.h>

#define STACK_SIZE 1024
#define HEAP_SIZE 32

typedef int32_t elem;
#define error(s) do{fputs(s"\n",stderr);exit(EXIT_FAILURE);}while(0)

/*** STACK ***/
elem stack[STACK_SIZE];
int sp = 0;
#define has(x) do{if(sp<x)error("Stack was empty");}while(0)
void push(elem x) {stack[sp++] = x;}
elem pop() {has(1); return stack[--sp];}
elem peek() {has(1); return stack[sp-1];}
#define op1(c) do{push(c(pop()));}while(0)
#define op2(c) do{has(2);push((pop())c(pop()));}while(0)
#define div0() do{has(2);if(!stack[sp-2])error("Division by zero");}while(0)

/*** HEAP ***/
elem heap[HEAP_SIZE];

#define in(a,b,c) (((a)<=(b))&&((b)<=(c)))
#define ill(c) (!in(0x01,(c),0x7F))

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

char* load(const char* filename) {
    char* buffer = 0;
    long length;
    FILE* f = fopen(filename, "rb");
    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer) fread(buffer, 1, length, f);
        fclose(f);
    }
    return buffer;
}

int main(int argc, char* argv[]) {
    if (argc<2) error("Usage: calc <src> {initial stack elements}");
    const char* prog = load(argv[1]);
    if (!prog) error("Error reading file");
    for (int i=2; i<argc; i++) push(atoi(argv[i]));
    for (int i=0;;) {
        char c = prog[i++];
        if (ill(c)) goto end;
        if (in('0', c, '9')) push(10 * pop() + c - '0');
        else if (in('A', c, 'Z')) push(c - 'A');
        else
            switch (c) {
            case '!': op1(!); break;
            case '"': pushf('"'); break;
            case '#': push(0); break;
            case '$': pop(); break;
            case '%': div0(); op2(%); break;
            case '&': op2(&); break;
            case'\'': pushf('\''); break;
            case '(': { if (!peek()) gof('(', ')'); } break;
            case ')': break; // end if
            case '*': op2(*); break;
            case '+': op2(+); break;
            case ',': push(heap[pop()]); break;
            case '-': op2(-); break;
            case '.': heap[pop()] = pop(); break;
            case '/': div0(); op2(/); break;
            case ':': { const elem e = pop(); push(e); push(e); } break;
            case ';': { const elem e = pop(); has(e+1); push(stack[sp-e-1]); } break;
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
            case '`': { const elem e1 = pop(); has(e1+1); const elem e2 = pop(); for (int j = 0; j < e2; j++) pop(); push(e2); } break;
            case 'a': putchar('\a'); break;
            case 'b': putchar('\b'); break;
            case 'c': sp = 0; break;
            case 'd': push(pop() - 1); break;
            // TODO case 'e': break;
            case 'f': putchar('\f'); break;
            case 'g': push(getchar()); break;
            case 'h': goto end;
            case 'i': push(pop() + 1); break;
            // TODO case 'j': break;
            // TODO case 'k': break;
            // TODO case 'l': break;
            // TODO case 'm': break;
            case 'n': putchar('\n'); break;
            case 'o': printf("%d\n", peek()); break;
            case 'p': putchar(pop()); break;
            case 'q': { for (int j = 0; j < sp; j++) { printf("%i\n", stack[j]); } } break;
            case 'r': putchar('\r'); break;
            case 's': { const elem e = pop(); push(e * e); } break;
            case 't': putchar('\t'); break;
            // TODO case 'u': break;
            case 'v': putchar('\v'); break;
            // TODO case 'w': break;
            case 'x': { const elem e = pop(); push(i); i = e; } break;
            // TODO case 'y': break;
            case 'z': push(sp); break;
            case '{': { push(i); gof('{', '}'); } break;
            case '|': op2(|); break;
            case '}': i = pop(); break;
            case '~': op1(~); break;
            default: { if (in('!',c,'~')) error("Unexpected character"); } break;
            }
    }
end:
    return sp>0?pop():0;
}
