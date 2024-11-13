#define _CRT_SECURE_NO_WARNINGS//解决scanf编译错误
#include <stdio.h>

//1.变量
void variable(){
 int a = 3;
}
//2.常量
#define PI 6//符号常量PI

void test0(){
    printf("Hello, World!\n");
    printf("%d",PI);
    int i;
    scanf("%d", &i);
    printf("%d", i);

}

void test1(){
    int j;
    char c;
    scanf("%d", &j);
    printf("j = %d\n", j);
    scanf("%c", &c);//这里不会阻塞，会读到j后面的空格
    printf("c = %c\n", c);
}
void circulation(){//scanf的循环读取
    int i;
    while (scanf("%d", &i) != EOF){
        printf("i = %d\n", i);
    }
}

int main() {
    //test0();
    //test1();
    circulation();
    return 0;
}