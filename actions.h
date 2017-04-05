#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>

struct vector{
    void *data;
    int n;
    int size;
};
struct complex{
    float x;//действительная часть комплексного числа
    float y;//мнимая часть комплексного числа
};
void vvod(struct vector* v, void (*f)(struct vector*,int), int mass){
    v->size=mass;
    printf("Enter the number of coordinates of the vector");
    printf("\n");
    scanf("%d", &(v->n));
    v->data=malloc(v->size * v->n);
    printf("Enter the coordinates of the vector");
    printf("\n");
    int i;
    for(i=0;i<(*v).n;i++)
        f(v,i);
    printf("\n%d\n",v->n);
}
void vvod_int(struct vector *v, int i){
        scanf("%d",((int*)v->data)+i);
}
void vvod_float(struct vector *v,int i){
        scanf("%f",((float*)v->data)+i);
}
void vvod_complex(struct vector *v, int i){
        scanf("%f %f",&(((struct complex*)v->data+i)->x), &(((struct complex*)v->data+i)->y));
}
void print(struct vector* v,void (*f)(struct vector*,int),int mass){
    v->size=mass;
    int i;
    for(i=0; i < v->n; i++)
                f(v,i);
    printf("\n");
}
void print_int(struct vector *v, int i){
        printf("%d ",  *((int*)v->data + i));
}
void print_float(struct vector *v, int i){
        printf("%f ",  *((float*)v->data + i));
}
void print_complex(struct vector *v, int i){
    printf("%f %f",(((struct complex*)v->data+i)->x) , (((struct complex*)v->data+i)->y));
}

void sum(struct vector* v1, struct vector* v2, struct vector* v3, void (*f)(struct vector*, struct vector*, struct vector*,int i))
{
     if (v1->n!= v2->n){
       ("%d", &(v1->n));
       ("%d", &(v2->n));
       printf("ERROR!");
       exit(0);}
       int i;
       printf("the sum of vectors is equal to  ");
       v3->n=v1->n;
       v3->data=malloc(sizeof(int) * v3->n);
       for (i = 0;i<v1->n;i++)
               f(v1,v2,v3,i);
}
void sum_int(struct vector* v1, struct vector* v2, struct vector* v3, int i)
{
     *(((int*)v3->data)+i)=*(((int*)v1->data)+i) + *(((int*)v2->data)+i);
}

void sum_float(struct vector* v1, struct vector* v2, struct vector* v3, int i)
{
     *(((float*)v3->data)+i)=*(((float*)v1->data)+i) + *(((float*)v2->data)+i);
}
void sum_complex(struct vector* v1, struct vector* v2, struct vector* v3, int i)
{
      ((struct complex*)v3->data+i)->x=((struct complex*)v1->data+i)->x+((struct complex*)v2->data+i)->x;
    ((struct complex*)v3->data+i)->y=((struct complex*)v1->data+i)->y+((struct complex*)v2->data+i)->y;}

void multiplication(struct vector* v1, struct vector* v2, void (*f)(struct vector*, struct vector*, void*, int ), void* M){

 if (v1->n!= v2->n){
       printf("ERROR!");
 }else{

       int i;
        printf("the scalar multiplication of vectors is equal to  ");
        for(i=0; i< v1->n; ++i)
          f(v1,v2,M,i);
 }

}
void multiplication_int(struct vector* v1, struct vector* v2, int *M, int i){
    *M += (*((int*)v1->data + i)) * (*((int*)v2->data + i));
}
void multiplication_float(struct vector* v1, struct vector* v2, float *M, int i){
    *M += (*((float*)v1->data + i)) * (*((float*)v2->data + i));
}
void multiplication_complex(struct vector* v1, struct vector* v2, struct complex *M, int i)
{
       float x1=(((struct complex*)v1->data+i)->x);
    float y1=(((struct complex*)v1->data+i)->y);
    float x2=(((struct complex*)v2->data+i)->x);
    float y2=(((struct complex*)v2->data+i)->y);
    M->x+=x1*x2 - y1*y2;
    M->y+=x1*y2 + x2*y1;
}
#endif // ACTIONS_H_INCLUDED
