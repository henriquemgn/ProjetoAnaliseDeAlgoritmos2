#include <stdio.h>
#include <stdbool.h>

//Exercicio 3
bool subsequencia(int s[], int j, int a[], int k){
    int veri = 0;
    int n = 0;
   
    for(int i = 0; i < j; i++){
        for(int f = n; f < k; f++){
            if(s[i]==a[f]){
                veri +=1;
                n = f;
            }
        }
    }
    if(veri == j) return true;
    else return false;
}

//Exercicio 4
bool segmento(int s[], int j, int a[], int k){
    int i = 0, f = 0;
    while (i < j && f < k){
        if(s[i] == a[f]){
            i++;
            f++;
        }else if(i!=0){
            return false;
        }else{
            f++;
        }
    }
    return i==j;
    
}

//exercicio 5
int qtdSubsequencia(int s[], int j, int aux){
    int *subVetor = &s[1];

    if (j==0){
        return 0;
    }
    if (j == 1 && aux != s[0]){
        return qtdSubsequencia(subVetor,j-1,s[0]);
    }
    if (s[0] != s[1]){
        return 1 + qtdSubsequencia(subVetor,j-1,s[0]);
    }
    else{
        return qtdSubsequencia(subVetor,j-1,s[0]);
    }
}

int main()
{
    int s[] = {5,3};
    int a[] = {1,5,3,2};
    int test[] = {1,1,1,1,2,2,2,3,3,4,4,5,7};
    if(segmento(s,2,a,4) == 0){
        printf("S nao e segmento de k.\n");
    }else{
        printf("S e segmento de k.\n");
    }
    
    if(subsequencia(s,2,a,4) == 0){
        printf("S nao e subsequencia de k.\n");
    }else{
        printf("S e subsequencia de k.\n");
    }
    
    printf("Quantidade de subsequencias = %d", qtdSubsequencia(test,14,0));
   
    return 0;
}