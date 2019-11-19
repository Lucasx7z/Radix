#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void CountingSort(int *v,int n, int exp);
int acharMaior(int *v,int n);
void Radix(int *v,int n);
int *criarVetor(int *vet, int tam);

void CountingSort(int *v,int n, int exp){
    int output[n], count[10]={0};
    int i;

    for (i=0;i<n;i++){
        count[(v[i]/exp)%10]++;
    }
    for(i=1;i<n;i++){
        count[i]+=count[i-1];
    }

    for(i=n-1;i>=0;i--){
        output[count[(v[i]/exp)%10]-1]=v[i];
        count[(v[i]/exp)%10]--;
    }

    for(i=0;i<n;i++){
        v[i]=output[i];
        printf("%d\n",v[i]);
    }
    printf("\n");
}

int acharMaior(int *v,int n){
    int maior=v[0];
    for(int i=1;i<n;i++){
        if(v[i]>maior){
            maior=v[i];
        }
    }
    return maior;
}

void Radix(int *v,int n){
    int maior = acharMaior(v,n);
    int exp;
    for(exp=1;exp<=maior;exp*=10){
        CountingSort(v,n,exp);
    }
}

int *criarVetor(int *vet, int tam){
    srand(time(NULL));
    vet = (int*)malloc(tam*sizeof(int));
    for(int i=0;i<tam;i++){
        vet[i] = rand() % 99999;
    }
    return vet;
}
