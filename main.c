#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "actions.h"

int main(){
    struct vector v1, v2, v3, v4, v5, v6, v7, v8, v9;
    int c, i, k;
    printf("What are you want to do?\n");
    printf("1-to do tests, 2-to work with vectors");
    printf("\n");
    scanf("%d", &k);
    if (k==1){
    void *M;
    test1(&v1,&v2,&v3,&M);
    test2(&v4,&v5,&v6,&M);
    }    else{
        printf("The number of what type will contain vectors? ");
        printf("\n");
        printf("Enter 1 if the integer. Enter 2 if real. Enter 3 if complex.");
        printf("\n");
        scanf("%d",&c);
        if (c==1){
            vvod(&v1,vvod_int,sizeof(int));
            print(&v1,print_int,sizeof(int));
            vvod(&v2,vvod_int,sizeof(int));
            print(&v2,print_int,sizeof(int));
            sum(&v1,&v2,&v3, sum_int);
            print(&v3,print_int,sizeof(int));
            printf("\n");
            int *M;
            M=0;
            multiplication(&v1,&v2, multiplication_int, &M);
            printf("%d", M);
                free(&v1);
                free(&v2);
                free(&v3);
            }
           else if (c==2){
                vvod(&v1,vvod_float,sizeof(float));
                print(&v1,print_float,sizeof(float));
                vvod(&v2,vvod_float,sizeof(float));
                print(&v2,print_float,sizeof(float));
                sum(&v1,&v2,&v3, sum_float);
                print(&v3,print_float,sizeof(float));
                printf("\n");
                float M;
                M=0;
                multiplication(&v1,&v2,multiplication_float, &M);
                printf("%f", M);
                free(&v1);
                free(&v2);
                free(&v3);
            }else if (c==3){
                vvod(&v1,vvod_complex,sizeof(float));
                print(&v1,print_complex,sizeof(float));
                vvod(&v2,vvod_complex,sizeof(float));
                print(&v2,print_complex,sizeof(float));
                sum(&v1,&v2,&v3, sum_complex);
                print(&v3,print_complex,sizeof(float));
                printf("\n");
                struct complex M;
                M.x=0;
                M.y=0;
                multiplication(&v1,&v2,multiplication_complex, &M);
                printf("{ %f +i*%f}", M.x, M.y);
                free(&v1);
                free(&v2);
                free(&v3);
            }else
                    printf("ERROR! You entered does not exist the type of the variables!");
                }
    return 0;

}






