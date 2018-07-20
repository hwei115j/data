#include <stdio.h>
#define ABSO(x) ((x >= 0)?(x):(-(x)))
#define MAX 300
#define T_MAX 1024

void func(int *, int *, int, int);
void restr(char *);
void tocode(int , int , char *);
void coding(int *, int *, char (*)[10]);
void decode(char *, char (*)[10], char *);
void file_out(char (*)[10], FILE *, FILE *, FILE *);        //編碼並寫入文件
void file_decode(FILE *, char (*)[10], FILE *);
void read_dic(char (*)[10], FILE *);
void push_bu(uint8_t, uint8_t *, int *, int);
int squa(int);
int compar(const void *, const void *);
int file_in(int *, int *, FILE *);
int fdecode(char *, char (*)[10], uint8_t);

