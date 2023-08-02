#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void print_matrix(float m[N][N]){
        for(int i=0 ; i<N ; i++){
        printf("\n");
                for(int j=0 ; j<N ; j++){
                        printf("%.2f ", m[i][j]);
                }
        }
printf("\n\n");
}

void matmul(float m1[N][N], float m2[N][N],float res[N][N]){
        for(int i=0 ; i<N ; i++){
                for(int j=0 ; j<N ; j++){
                        for(int k=0; k<N; k++){
                                res[i][j] += m1[i][k] * m2[k][j];
                        }
                }
        }
}

void init_matrix(float m[N][N]){
        for(int i=0 ; i<N ; i++){
                for(int j=0;j<N;j++){
                        m[i][j] = 0;
                }
        }
}

void cl_matmul(float m1[N][N], float m2[N][N],float res[N][N]){
        init_matrix(res);
        for(int i=0 ; i<N ; i++){
                for(int j=0 ; j<N ; j++){
                        for(int k=0; k<N; k++){
                                res[i][j] += m1[i][k] * m2[k][j];
                        }
                }
        }
}

void mat_copy(float m1[N][N],float m2[N][N]){
        /* Copy m2 into m1 */
        for(int i=0; i<N ; i++){
                for(int j=0; j<N; j++){
                        m1[i][j]=m2[i][j];
                }
        }
}

void LUdecompose(float L[N][N],float U[N][N],float A[N][N]) {
        // Kinda works but very ugly add some numerical stability and pivoting


        float L_not[N][N];
        init_matrix(L_not);
       //  Initialize L as an identity matrix
        for(int i=0 ; i<N ; i++){
                L[i][i]=1;
                L_not[i][i]=1;
        }



        for(int j=0 ; j<N ; j++){

 //               printf("L_not\n");
  //              print_matrix(L_not);

                cl_matmul(L_not,U,A);
                mat_copy(U,A);

                init_matrix(L_not);

                for(int i=0 ; i<N ; i++){
                        L_not[i][i]=1;
                }

                print_matrix(L);
                // you need to somehow start over with new L's everytime you do matmul and then store all that stuff in L
                for(int i=j+1 ; i<N ; i++){
                        L[i][j] =  ( U[i][j] / U[j][j] );
                        L_not[i][j] = - ( U[i][j] / U[j][j] );
                }
        }

}

void qsort1(float* arr,int size){
        if(size<2){return;}
        int piv = arr[size>>1];
        int i;
        int j;
        for(i=0,j=size-1; ; i++,j-- ){
                for(;arr[i]<piv;i++){}
                for(;arr[j]>piv;j--){}
                if(i>=j){break;}
                float temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
        }


        qsort1(arr,i);
        qsort1(arr+i,size-i);
        /*
        float* p=arr+((size-1)*sizeof(float));
        float* q=p--;
        for( ; q!=NULL ; q--){
                if(*p>*q){

                }
        } */

}

void _fill_matrix(float m[N][N]){
        for(int i=0 ; i<N ; i++){
                for(int j=0;j<N;j++){
                        m[i][j] = rand() % 100 + 0;
                }
        }
}

