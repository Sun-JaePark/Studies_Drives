#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void selectionSort(int A[], int n);
void bubbleSort(int B[], int n);
void insertionSort(int C[], int n);
void shellSort(int D[],int n);
void quickSort(int E[], int start, int end);
int partition(int A[], int start, int end);
int temp_arr[30000];
void mergeSort(int F[], int p, int r);
void merge(int A[], int p, int q, int r);
void algorithmsEval(int A[],int B[], int C[], int D[],int E[], int F[],int n);

int main() {
    int A[30000],B[30000],C[30000],D[30000],E[30000],F[30000],i,n;
    for (i=0;i<30000;i++){
        A[i]=rand()%100;
    }
    for (i=0;i<30000;i++){
        B[i]=rand()%100;
    }
    for (i=0;i<30000;i++){
        C[i]=rand()%100;
    }
    for (i=0;i<30000;i++){
        D[i]=rand()%100;
    }
    for (i=0;i<30000;i++){
        E[i]=rand()%100;
    }
    for (i=0;i<30000;i++){
        F[i]=rand()%100;
        
    n= sizeof(A)/sizeof(int);
    
    }

    algorithmsEval(A,B,C,D,E,F,n);

    return 0;
}

void selectionSort(int A[], int n){
    int i,j,small;
    int temp=0;
    for (i=0; i<n-1;i++){
        small = i;
        for (j=i+1; j<n;j++){
            if (A[j]<A[small]){
                small = j;
            }
        }
        temp=A[i];
        A[i]=A[small];
        A[small]=temp;
    }
}

void bubbleSort(int B[], int n){
    int i , j;
    int temp =0;

    for (i=0;i<n-1;i++){
        for (j=n-1;j>i;j--){
            if (B[j]<B[j-1]){
                temp=B[j];
                B[j]=B[j-1];
                B[j-1]=temp;
            }
        }
    }
}

void insertionSort(int C[], int n){
    int i,j;
    int temp=0;

    for(i=1;i<n;i++){
        j=i-1;
        temp=C[i];
        while ((j>=0)&&(temp<C[j])){
            C[j+1]=C[j];
            j=j-1;
        }
        C[j+1]=temp;
    }
}

void shellSort(int D[],int n){
    int inter,temp,i,j;
    inter = n/2;

    while(inter>=1){
        for(i=inter;i<n;i++){
            temp=D[i];
            j = i - inter;
            while ((j>=0) && (D[j]>temp)){
                D[j+inter]=D[j];
                j=j-inter;
                D[j+inter] = temp;
            }
        }
        inter = inter/2;
    }
}

void quickSort(int E[], int start, int end){
    int pivot;

    if (start < end){
        pivot = partition(E,start,end);
        quickSort(E,start,pivot-1);
        quickSort(E,pivot+1,end);
    }
}

int partition(int E[], int start, int end){
    int pivot,i,j,temp1,temp2;
    pivot = E[end];
    i = start -1;
    for (j=start;j<end;j++){
        if (E[j]<pivot){
            i=i+1;
            temp1=E[i];
            E[i]=E[j];
            E[j]=temp1;
        }
    }
    temp2=E[i+1];
    E[i+1]=E[end];
    E[end]=temp2;
    return i+1;
}

void mergeSort(int F[], int p, int r) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(F, p , q);
        mergeSort(F, q+1, r);
        merge(F, p, q, r);
    }
}

void merge(int F[], int p, int q, int r) {
    int i = p, j = q+1, k = p;
    while(i<=q && j<=r) {
        if(F[i] <= F[j]) temp_arr[k++] = F[i++];
        else temp_arr[k++] = F[j++];
    }
    while(i<=q) temp_arr[k++] = F[i++];
    while(j<=r) temp_arr[k++] = F[j++];
    for(int a = p; a<=r; a++) F[a] = temp_arr[a];
}
    
    
void algorithmsEval(int A[],int B[], int C[], int D[],int E[], int F[],int n){
    time_t start, end;
    double result;
    
    start = time(NULL); //시간 측정 시작
    selectionSort(A,n);
    end = time(NULL); // 시간 측정 끝
    result = (double)(end - start);
    printf("선택 정렬: %f초", result); //결과 출력
    printf("\n");
    
    start = time(NULL); //시간 측정 시작
    bubbleSort(B,n);
    end = time(NULL); // 시간 측정 끝
    result = (double)(end - start);
    printf("버블 정렬: %f초", result); //결과 출력
    printf("\n");
    
    start = time(NULL); //시간 측정 시작
    insertionSort(C,n);
    end = time(NULL); // 시간 측정 끝
    result = (double)(end - start);
    printf("삽입 정렬: %f초", result); //결과 출력
    printf("\n");
    
    start = time(NULL); //시간 측정 시작
    shellSort(D,n);
    end = time(NULL); // 시간 측정 끝
    result = (double)(end - start);
    printf("쉘 정렬: %f초", result); //결과 출력
    printf("\n");
    
    start = time(NULL); //시간 측정 시작
    quickSort(E,0,4);
    end = time(NULL); // 시간 측정 끝
    result = (double)(end - start);
    printf("퀵 정렬: %f초", result); //결과 출력
    printf("\n");
    
    start = time(NULL); //시간 측정 시작
    mergeSort(F,0,4);
    end = time(NULL); // 시간 측정 끝
    result = (double)(end - start);
    printf("병합 정렬: %f초", result); //결과 출력
    printf("\n");
}