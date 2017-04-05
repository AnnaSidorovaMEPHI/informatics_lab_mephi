#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <stdio.h>
#include "actions.h"

void test1(){
    struct vector v1, v2, v3;
    printf("Test 1\n");
    v1.n =v2.n = 2;
    v1.size=sizeof(int);
    v2.size=sizeof(int);
    int arr1[2]={25,39};
    int arr2[2]={23,89};
    v1.data = malloc(v1.size * v1.n);
    v2.data = malloc(v2.size * v2.n);
    int i;
    for (i=0;i<2;i++){
    *(((int*)v1.data)+i)=arr1[i];
    *(((int*)v2.data)+i)=arr2[i];
    }
    print(&v1,print_int,sizeof(int));
    print(&v2,print_int,sizeof(int));
    sum(&v1,&v2,&v3, sum_int);
    print(&v3,print_int,sizeof(int));
    printf("\n");
    int M=0;
    printf("\n");
    printf("Expected a SUMvector with the coordinates (48;128).\n");
    int E=0;
    i=0;
    int A[2]={48,128};
    for (i = 0;i<v3.n;i++){
        if (*((int*)v3.data + i)!= A[i]){
                printf("%d  ",*((int*)v3.data+i));
                printf("%d  ", A[i]);
                printf("\n");
                E=5;}
                }
    if (E>0) printf("Test 1.1(SUM) failed.\n");
    else printf("Test 1.1(SUM) passed.\n");
            M=0;
            multiplication(&v1,&v2, multiplication_int, &M);
            printf("%d", M);
            printf("\n");
            printf("Expected dot product M of 4046\n");
    if (M==4046)
             printf("Test 1.2(DOT PRODUCT) passed. \n");

    else     printf("Test 1.2(DOT PRODUCT) failed.\n");
    printf("\n");
    printf("\n");
}

void test2(){
    struct vector v1, v2, v3;
    printf("Test 2\n");
    v1.n =v2.n = 2;
    v1.size=sizeof(float);
    v2.size=sizeof(float);
    float arr1[2]={2.1, 0.1};
    float arr2[2]={10.1, 8.2};
    v1.data = malloc(v1.size * v1.n);
    v2.data = malloc(v2.size * v2.n);
    int i;
    for (i=0;i<2;i++){
    *(((float*)v1.data)+i)=arr1[i];
    *(((float*)v2.data)+i)=arr2[i];
    }
    print(&v1,print_float,sizeof(float));
    print(&v2,print_float,sizeof(float));


    sum(&v1,&v2,&v3, sum_float);
    print(&v3,print_float,sizeof(float));
    printf("\n");
    float M=0;
    printf("\n");
    printf("Expected a SUMvector with the coordinates (12.2;8.3).\n");
    int E=0;

    i=0;
    float eps = 0.00001;
    float A[2]={12.2,8.3};
    for (i = 0;i<v3.n;i++){
        if ((abs(*((float*)v3.data + i)- A[i]))<eps){
                printf("%f  ",*((float*)v3.data+i));
                printf("%f  ", A[i]);
                printf("\n");
                E++;}
                }
    if (E!=2) printf("Test 2.1(SUM) failed.\n");
    else printf("Test 2.1(SUM) passed.\n");
            M=0;
            multiplication(&v1,&v2, multiplication_float, &M);
            printf("%f", M);

            printf("\n");
            printf("Expected dot product M of 22.03\n");
    if (abs(M-22.03)<eps)
             printf("Test 2.2(DOT PRODUCT) passed. \n");

    else     printf("Test 2.2(DOT PRODUCT) failed.\n");
    printf("\n");
    printf("\n");

}


#endif // TEST_H_INCLUDED
