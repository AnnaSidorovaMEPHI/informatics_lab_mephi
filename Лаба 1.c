#include <stdio.h>
#include <stdlib.h>
struct vector{
    void *data;
    int n;
    int sizeof_elem;
};
struct complex{
    float x;//действительная часть комплексного числа
    float y;//мнимая часть комплексного числа
};
void vvod_int(struct vector *v){
    printf("Enter the number of coordinates of the vector");
    printf("\n");
    scanf("%d", &(v->n));
    v->data=malloc(sizeof(int) * v->n);
    int i;
    printf("Enter the coordinates of the vector");
    printf("\n");
    for(i=0;i<(*v).n;i++){
        scanf("%d",((int*)v->data)+i);
        }
}
void vvod_float(struct vector *v){
    printf("Enter the number of coordinates of the vector");
    printf("\n");
    scanf("%d", &(v->n));
    v->data=malloc(sizeof(float) * v->n);
    int i;
    printf("Enter the coordinates of the vector");
    printf("\n");
    for(i=0;i<(*v).n;i++){
        scanf("%f",((float*)v->data)+i);
    }
}
void vvod_complex_one(struct complex* num){
    scanf("%f %f", &(num->x), &(num->y) );
}
void vvod_complex(struct vector *v){
    printf("Enter the number of coordinates of the vector");
    printf("\n");
    scanf("%d", &(v->n));
    v->data=malloc(sizeof(struct complex) * v->n);
    int i;
    printf("Enter the coordinates of the vector");
    printf("\n");
    for(i=0;i<(*v).n;i++){
        vvod_complex_one( (struct complex*)v->data+i );
    }
}

void print_int(struct vector* v){
    int i;
    for(i=0; i < v->n; i++)
        printf("%d ",  *((int*)v->data + i));
    printf("\n");
}
void print_float(struct vector* v){
    int i;
    for(i=0; i < v->n; i++)
        printf("%f ",  *((float*)v->data + i));
    printf("\n");
}
void print_complex_one(struct complex* num){
    printf("{%3.2f + i*%3.2f} ",  num->x, num->y );
}
void print_complex(struct vector* v){
    int i;
    for(i=0;i<v->n;i++)
        print_complex_one((struct complex*)v->data+i);
}

void sum_int_vectors(struct vector* v1, struct vector* v2, struct vector* v3)
{      if (v1->n!= v2->n){
       printf("ERROR!");
       exit(0);}
       int i;
       printf("the sum of vectors is equal to  ");
       v3->n=v1->n;
       v3->data=malloc(sizeof(int) * v3->n);
       for (i = 0;i<v1->n;i++)
        *(((int*)v3->data)+i)=*(((int*)v1->data)+i) + *(((int*)v2->data)+i);

       //printf("%d ",*(((int*)v1->data)+i) + *(((int*)v2->data)+i));
}
void sum_float_vectors(struct vector* v1, struct vector* v2, struct vector* v3)
{      if (v1->n!= v2->n){
        printf("ERROR!");
        exit(0);}
       int i;
       v3->n=v1->n;
       v3->data=malloc(sizeof(float) * v3->n);
       printf("the sum of vectors is equal to  ");
       for (i = 0;i<v1->n;i++)
        *(((float*)v3->data)+i)=*(((float*)v1->data)+i) + *(((float*)v2->data)+i);
}
void sum_complex_one(struct complex* num1, struct complex* num2, struct complex* num3)
{    num3->x=(num1->x)+(num2->x);
     num3->y=(num1->y)+(num2->y);
}
void sum_complex_vectors(struct vector* v1, struct vector* v2, struct vector* v3)
{  int i;
   if (v1->n!= v2->n){
   printf("ERROR!");
   exit(0);}
   v3->n=v1->n;
   v3->data=malloc(sizeof(struct complex) * v3->n);
   printf("the sum of vectors is equal to  ");
   for(i=0;i<v1->n;i++)
       sum_complex_one((struct complex*)v1->data+i,(struct complex*)v2->data+i,(struct complex*)v3->data+i );
}
void multiplication_int_vectors(struct vector* v1, struct vector* v2, int *M){
     if (v1->n!= v2->n)
       printf("ERROR!");
       int i;
       *M=0;
       printf("the scalar multiplication of vectors is equal to  ");
        for(i=0; i< v1->n; ++i)
        *M += (*((int*)v1->data + i)) * (*((int*)v2->data + i));
      printf("%d ", *M);
}
void multiplication_float_vectors(struct vector* v1, struct vector* v2, float *K){
     if (v1->n!= v2->n)
       printf("ERROR!");
       int i;
       *K=0;
       printf("the scalar multiplication of vectors is equal to  ");
        for(i=0; i< v1->n; ++i)
        *K += (*((float*)v1->data + i)) * (*((float*)v2->data + i));
      printf("%f ",*K);
}
void multiplication_complex_one(struct complex* num1, struct complex* num2)
{    printf("{%3.2f + i*%3.2f} ",  (num1->x)*(num2->x)-(num1->y)*(num2->y), (num1->x)*(num2->y)+(num2->x)*(num1->y));
}
void multiplication_complex_vectors(struct vector* v1, struct vector* v2)
{  int i;
   if (v1->n!= v2->n)
   printf("ERROR!");
   printf("the multiplication of vectors is equal to  ");
   for(i=0;i<v1->n;i++)
       multiplication_complex_one((struct complex*)v1->data+i,(struct complex*)v2->data+i );
}
void test1(struct vector* v1, struct vector* v2, struct vector* v3, int* M){
    printf("Enter the vectors with coordinates (25;39) and (23;89)");
    printf("\n");
    vvod_int(v1);
    vvod_int(v2);
    sum_int_vectors(v1,v2,v3);
    print_int(v3);
    printf("\n");
    printf("Expected a SUMvector with the coordinates (48;128).");
    printf("\n");
    int E=0;
    int i=0;
    int A[2]={48,128};
    for (i = 0;i<v3->n;i++){
        if (*((int*)v3->data + i)!= A[i]){
                printf("%d  ",*((int*)v3-> data+i));
                printf("%d  ", A[i]);
                printf("\n");
                E=5;}
                }
    if (E>0) printf("Test 1.1(SUM) failed.");
    else printf("Test 1.1(SUM) passed. The resulting vector is (48;128).");

        multiplication_int_vectors(v1,v2,M);
        printf("\n");
        printf("Expected dot product M of 4046");
        printf("\n");
    if (*M==4046)
             printf("Test 1.2(DOT PRODUCT) passed. The dot product is 4046.");
    else     printf("Test 1.2(DOT PRODUCT) failed.");
    printf("\n");
    printf("\n");
}

void test2(struct vector* v1, struct vector* v2, struct vector* v3, float* K){
    printf("Enter the vectors with coordinates (2.1;0.1) and (10.1;8.2)");
    printf("\n");
    vvod_float(v1);
    vvod_float(v2);
    sum_float_vectors(v1,v2,v3);
    print_float(v3);
    printf("\n");
    printf("Expected a SUMvector with the coordinates (12.2;8.3).");
    printf("\n");
    int E=0;
    int i=0;
    float A[2]={12.2,8.3};
    for (i = 0;i<v3->n;i++){
        if (*((float*)v3->data + i)!= A[i]){
                printf("%f  ",*((float*)v3-> data+i));
                printf("%f  ", A[i]);
                printf("\n");
                E=5;}
                }
    if (E>0) printf("Test 1.1(SUM) failed.");
    else printf("Test 1.1(SUM) passed. The resulting vector is (12.2,8.3).");
        multiplication_float_vectors(v1,v2,K);
        printf("\n");
        printf("Expected dot product K of 22.03");
        printf("\n");
    if (*K==268.7152)
             printf("Test 1.2(DOT PRODUCT) passed. The dot product is 22.03.");
    else     printf("Test 1.2(DOT PRODUCT) failed.");
}



int main(){
    struct vector v1, v2, v3, v4, v5, v6, v7, v8, v9;
    int c, i, k, *M;
    float *K;
    printf("What are you want to do?\n");
    printf("1-to do tests, 2-to work with vectors");
    printf("\n");
    scanf("%d", &k);
    if (k==1){
    //test1(&v1,&v2,&v3,&M);
    test2(&v4,&v5,&v6,&K);
    //test3(&v7,&v8,&v9);
    }
    else{
    printf("The number of what type will contain vectors? ");
    printf("\n");
    printf("Enter 1 if the integer. Enter 2 if real. Enter 3 if complex.");
    printf("\n");
    scanf("%d",&c);
    if (c==1){
        vvod_int(&v1);
        vvod_int(&v2);
        sum_int_vectors(&v1,&v2,&v3);
        print_int(&v3);
        printf("\n");
        multiplication_int_vectors(&v1,&v2,&M);
        free(&v1);
        free(&v2);
        free(&v3);

    }else{
        if (c==2){
            vvod_float(&v1);
            print_float(&v1);
            vvod_float(&v2);
            print_float(&v2);
            sum_float_vectors(&v1,&v2,&v3);
            print_float(&v3);
            printf("\n");
            multiplication_float_vectors(&v1,&v2,&K);
            free(&v1);
            free(&v2);
            free(&v3);
        }else{
            if (c==3){
            vvod_complex(&v1);
            vvod_complex(&v2);
            printf("\n");
            sum_complex_vectors(&v1,&v2,&v3);
            printf("\n");
            print_complex(&v3);
            multiplication_complex_vectors(&v1,&v2);
            free(&v1);
            free(&v2);
            free(&v3);
            }else
                printf("ERROR! You entered does not exist the type of the variables!");
            }
        }
        }
    }






