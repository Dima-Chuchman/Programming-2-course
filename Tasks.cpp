#include <stdio.h>
#include <Math.h>
#include <stdint.h>



void Task1() {
    unsigned char n;
    scanf_s("%hhu", &n);
    unsigned long long m = 1 < n;
    printf("%llu", m);
}


void Task2() {
    int n;
    unsigned k;
    scanf_s("%d", &n);
    scanf_s("%u", &k);
    printf("%d", n | (1 << k));
}


void Task3() {
    unsigned char n;
    scanf_s("%hhu", &n);
    unsigned long long m;
    scanf_s("%llu", &m);
    printf("%llu", m & ~(1 << n));
}


void Task4() {
    unsigned n, b1, b2, b3, b4, m;
    scanf_s("%u", &n);
    b1 = n & 0xFF; // n&255
    b2 = n >> 8 & 0xFF;
    b3 = n >> 16 & 0xFF;
    b4 = n >> 24;
    m = (b1 << 24) | (b3 << 16) | (b2 << 8) | b4;
    printf("%u", m);
    printf("%x", m);
}


void Task5() {
    int n;
    unsigned cnt = 0;
    printf("n = ");
    scanf_s("%d", &n);
    unsigned max_count = 0;
    while (n & 1) {
        n >>= 1;
        cnt++;
    }
    n >>= 1;
    if (max_count < cnt) {
        max_count = cnt;
    }
    printf("%u", max_count);

}
void Task7() {

    unsigned num = 0x123445678;
    char* byte = (char*)&num;

    if (byte[0] == 0x12)
        printf("It`s Big endian");
    else if (byte[0] == 0x78)
        printf("It`s Little endian");
    else {
        printf("It`s another endian");
    }
}

int main() {
    
    //Task1();
    //Task2();
    //Task3();
    //Task4();
    //Task5();
    //Task7();

}

    


