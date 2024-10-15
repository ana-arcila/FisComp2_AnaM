#include <iostream>
#include <cmath>
using namespace std;

//Dot
/*
int main(){
    int i, j;
    float R[3], R2[3];
    float V1[3] = {1, 2, 3};
    float V2[3] = {3, 2, 1};

    for (i=0; i<=2; i++){
        R[i] = V1[i] * V2[i];
        cout << R[i] << endl;
    }

    for (j=0; j<=2; j++){
        float Vabs = sqrt(pow(V1[0], 2) + pow(V1[1], 2) + pow(V1[2],2));
        R2[i] = V1[i] / Vabs;
        cout << R2[i] << endl;
    }
    
    return 0;
}
*/

//Cross
int main(){
    int i, j, R[3][3];
    int M1[3][3] = {{1, 2, 3}, {2, 3, 1}, {3, 1, 2}};
    int M2[3][3] = {{4, 5, 6}, {5, 6, 4}, {6, 4, 5}};

    for (i=0; i<=2; i++){
        for (j=0; j<=2; j++){
            R[i][j] = M1[i][0] * M2[0][j] + M1[i][1] * M2[1][j] + M1[i][2] * M2[2][j];
        }
        //cout <<R[i][0]<< " "<< R[i][1] << " " << R[i][2]<< endl;
    }

    int s1[2][2] = {{0, 1}, {1, 0}};
    int s3[2][2] = {{1, 0}, {0, -1}};
    int R2[2][2];

    for (i=0; i<=1; i++){
        for (j=0; j<=1; j++){
            R2[i][j] = s1[i][0] * s3[0][j] + s1[i][1] * s3[1][j] - (s3[i][0] * s1[0][j] + s3[i][1] * s1[1][j]);
        }
    cout <<R2[i][0]<<" "<<R2[i][1]<< endl;
    }

    return 0;
}