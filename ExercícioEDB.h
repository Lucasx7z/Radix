#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void CountingSort(int *v,int n, int exp);
int acharMaior(int *v,int n);
void Radix(int *v,int n);
int *criarVetor(int *vet, int tam);
int *atualizarVetor(int *vet, int tam);
void quicksort(int *v, int left, int right);

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
        //printf("%d\n",v[i]);
    }
    //printf("\n");
}

int acharMaior(int *v,int n){
    int maior=v[0], i;
    for(i=1;i<n;i++){
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
	int i;
	srand(time(NULL));
	vet = (int*)calloc(tam,sizeof(int));
    for(i=0;i<tam;i++){
        vet[i] = rand() % 99999;
    }
    return vet;
}

int *atualizarVetor(int *vet, int tam){
	int i;
    for(i=0;i<tam;i++){
        vet[i] = rand() % 99999;
    }
    return vet;
}

void quicksort(int *v, int left, int right) {
    int i, j;
	int pivo;
	i = left; j = right;
	pivo = v[(left+right)/2];
	do {
		while ((v[i] < pivo) && (i < right))
			i++;
		while (v[j] > pivo && j > left)
			j--;
		if (i <= j) {
			int x = v[i];
			v[i]  = v[j];
			v[j] = x;
			i++; j--;
		}
	}while(i<=j);

	if (left < j) {
		quicksort(v, left, j);
	}
	if (right > i){
		quicksort(v, i, right);
	}
}
