#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4



void matmul(float m1[N][N], float m2[N][N],float res[N][N]){
        for(int i=0 ; i<N ; i++){
                for(int j=0 ; j<N ; j++){
                        for(int k=0; k<N; k++){
                                res[i][j] += m1[i][k] * m2[k][j];
                        }
                }
        }

}

void _fill_matrix(float m[N][N]){
        for(int i=0 ; i<N ; i++){
                for(int j=0;j<N;j++){
                        m[i][j] = rand() % 100 + 0;
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



void print_matrix(float m[N][N]){
        for(int i=0 ; i<N ; i++){
        printf("\n");
                for(int j=0 ; j<N ; j++){
                        printf("%.2f ", m[i][j]);
                }
        }
printf("\n\n");
}




int main(int argc,char **argv){

        srand(time(NULL)); /* Seed the RNG */

        // rand() % range + min;



        printf("Hello World!\n");
        float m1[N][N];
        float m2[N][N];
        float res[N][N];
        _fill_matrix(m1);
        _fill_matrix(m2);
        print_matrix(m1);
        print_matrix(m2);
        init_matrix(res);
        print_matrix(res);
        matmul(m1,m2,res);

        print_matrix(res);


        return 0;
}
