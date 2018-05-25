#include <iostream>
#include <climits>

using namespace std;

double mat[10][10];
int aux[10][10];
double arr[10];

int min (int a, int b){
if(a<b)
    return a;
else
    return b;
}



int main()
{
    int nodos;
    double prob;

    cin>>nodos;

   // fin=nodos+1;

    for(int i=0; i<nodos; i++){
        mat[i][i]=aux[i][i]=0;
        cin>>prob;
        prob=prob/100;
        mat[i][i+1]=arr[i]=prob;
        aux[i][i+1]=i+1;

    }

   int j;
    for(int x=2; x<=nodos; x++){
        for(int i=0; i<=(nodos-x); i++){
            j=i+x;
            mat[i][j]=INT_MAX;
            for(int k=i; k<j; k++){
                    //llena la matriz aux con k ganadorrr
                if(mat[i][k]+mat[k+1][j]< mat[i][j]){
                    aux[i][j]=k+1;
                }

                mat[i][j]=min(mat[i][j], mat[i][k]+mat[k+1][j]);


            }
            //sumatoria de prob
          for(int y=i; y<j;y++){
            mat[i][j]=mat[i][j]+arr[y];
          }
        }
    }

    cout<<mat[0][nodos]<<" " << aux[0][nodos]<< endl;
}
