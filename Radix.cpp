#include<stdlib.h>
#include<stdio.h>

/*
    O RadixSort é um algoritmo de ordenação que ordena
    do dígito menos significativo para o mais significativo
    usando CountingSort como subrotina
*/

/* 
	O coutingSort é responsável pela veriificação do dígito responsável
	da ordenação, ou seja, fazer a ordenação em etapas baseado pelos dígitos
	em questão: Unidade por Unidade, Dezena por Dezena, Centena por Centena...
*/
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
        printf("%d ",v[i]);
    }
    printf("\n");
}

/*
	A função de achar o maior, como o próprio nome diz é a responsável por achar o maior
	número do vetor, usando isso é capaz de fazer as comparações do método de radix.
*/
int acharMaior(int *v,int n){
    int maior=v[0];
    for(int i=1;i<n;i++){
        if(v[i]>maior){
            maior=v[i];
        }
    }
    return maior;
}
/*
	E finalmente a função radix propriamente dita, responsável pela ordenação final,
	acahndo primeiramente o maior número para ser usado como condição de parada no laço
	for, em cada iteração do for é chamada a função countingSort
*/
void Radix(int *v,int n){
    int maior = acharMaior(v,n);
    int exp;
    for(exp=1;exp<=maior;exp*=10){
        CountingSort(v,n,exp);
    }
}
int main (){
    int v[6]={65055372,65919190,65147145,65892478,65055214,65452870};
    Radix(v,6);
    for(int i=0;i<6;i++){
        printf("%d ",v[i]);
    }
    return 0;
}

