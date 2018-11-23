#define STACK_INT "I"
#define STACK_DOUBLE "D"
#define STACK_CHAR "C"

struct stack
{
    void *data;
    int sp;
    void (*pop)();
    void (*push)(void);
};

struct stack stack_new(char *str);
struct stack stack_del();
