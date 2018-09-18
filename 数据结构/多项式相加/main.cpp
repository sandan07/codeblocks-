#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode *Polynomial;
void Attach(int c, int e, Polynomial *pRear);
Polynomial ReadPoly();
void PrintPoly(Polynomial P);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);

struct PolyNode
{
    int coef;
    int expon;
    Polynomial link;
};

int main()
{
    Polynomial P1,P2,PP,PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1,P2);
    PrintPoly(PP);
    PS = Add(P1,P2);
    PrintPoly(PS);

    return 0;
}

void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

Polynomial ReadPoly()
{
    Polynomial P, Rear, t;
    int N;
    scanf("%d", &N);
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    int c, e;
    while(N--)
    {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    t = P;P = P->link; free(t);
    return P;
}

void PrintPoly(Polynomial P)
{
    int flag = 0;

    if(!P) {printf("0 0\n"); return;}

    while(P)
    {
        if(!flag)
        {
            flag = 1;
        }else
        {
            printf(" ");
        }
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
    Polynomial rear, P, t1, t2, t;
    t1 = P1; t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    rear = P;
    while(t1 && t2)
    {
        if(t1->expon == t2->expon)
        {
            if(t1->coef + t2->coef)
            {
                Attach(t1->coef + t2->coef , t1->expon, &rear);
            }
            t1 = t1->link;
            t2 = t2->link;
        }else if(t1->expon > t2->expon)
        {
            Attach(t1->coef, t1->expon, &rear);
            t1 = t1->link;
        }else
        {
            Attach(t2->coef, t2->expon, &rear);
            t2 = t2->link;
        }
    }
    while(t1)
    {
        Attach(t1->coef, t1->expon, &rear);
        t1 = t1->link;
    }
    while(t2)
    {
        Attach(t2->coef, t2->expon, &rear);
        t2 = t2->link;
    }
    rear->link = NULL;
    t = P;
    P = P->link;
    free(t);
    return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
    Polynomial rear, P, t1, t2, t;
    int c, e;

    if(!P1 || !P2) return NULL;

    t1 = P1; t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    rear = P;
    while(t2)
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon, &rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1)
    {
        t2 = P2; rear = P;
        while(t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while(rear->link && rear->link->expon > e)
                rear = rear->link;
            if (rear->link && rear->link->expon == e)
            {
                if(rear->link->coef + c)
                {
                    rear->link->coef += c;
                }else
                {
                    t = rear->link;
                    rear->link = t->link;
                    free(t);
                }
            }else
            {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c; t->expon = e;
                t->link = rear->link;
                rear->link = t;
                rear = rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;
    P = P->link;
    free(t2);

    return P;
}
