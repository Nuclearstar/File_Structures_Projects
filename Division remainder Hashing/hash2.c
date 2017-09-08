#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 void main() {
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n, v, c, count=0;
    int temp, hash, h;
    printf("\nEnter the number of values whose hashing has to be done:");
    scanf("%d", &n);
    do {
        count+=1;
        printf("\n\nEnter the hash value");
        scanf("%d", &v);
        if(v==0||v==1||v==2||v==3||v==4||v==5||v==6||v==7||v==8||v==9)  {
            v+=10;
        }
        hash = v % 10;
        h=hash;
        if (a[hash] == hash) {
            a[hash] = v;
            printf("\nThe value is stored in a[%d]", hash);
        }
        else {
            for (hash++; hash < 10; hash++) {
                if (a[hash] == 0) {
                    printf("Space is allocated give other value");
                    a[hash] = v;
                    printf("\n a[%d]the value %d is stored here", hash, v);
                }
            }
           for (hash = h+1; hash < 10; hash++) {
              if (a[hash] == h+1) {
                  printf("Space is allocated give other value");
                   a[hash] = v;
                  printf("\nThe value %d is stored in a[%d]", v, hash);
              }
          }
            printf("\n\nERROR\n");
            printf("\nEnter '0' and press 'Enter key' twice to exit");
        }
         } while (count<n);
        exit(0);
    }
