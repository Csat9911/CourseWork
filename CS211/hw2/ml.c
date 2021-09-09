/* 
 * 
 * This code calculates the house price of a house by learing from
 * training data. It uses pseudo inverse of a given matrix to find the 
 * weight of different features.
 * 
 * Predicted Price : Y = W0 + W1*x1 + W2*X2 + W3*X3 + W4*X4
 * Weight Matrix : W = pseudoInv(X)*Y
 * pseudoInv(X) = inverse(transpose(X)*X) * transpose(X)  
 * 
 * weight(w) = pseudoInv(X) * Y
 * 			where	X = Input data matrix
 * 					Y = Target vector
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>

// all methods declarations
double** multiplyMatrix(double** arr1, double** arr2,int r1, int c1, int r2, int c2);
double** transposeMatrix(double** mat,int row, int col);
double** inverseMatrix(double **matA, int dimension);
void freeMatrix(double** matrix, int rowNum);
void freeALL(double** x, double** y,double** test,double** transX,double** multi1,double** inverseX,double** multi2,double** w,double** final, int trainEx, int attr, int testEx);
void print(int r, int c, double** matrix);

// main method starts here
int main (int argc, char** argv){

    FILE* fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("error");
    }
    
    FILE* fp2 = fopen(argv[2], "r");

    if(fp2 == NULL){
        printf("error");
    }
    
    int attr = 0; //attr = attributes
    int trainEx = 0; //trainEx = train houses
    int testEx = 0; // testEx = test houses
    
    fscanf(fp, "%d", &attr);
    fscanf(fp, "%d", &trainEx);
    fscanf(fp2, "%d", &testEx);


    //init first three file mats trainMat, price, testMat
    double** x = (double **) malloc(sizeof(double*) *trainEx); 
    for (int i = 0; i <trainEx; i++) {
        x[i] = (double*) malloc((attr + 1) * sizeof(double));
    }

    double** y = (double **) malloc(sizeof(double*) *trainEx);
    for (int i = 0; i <trainEx; i++) {
        y[i] = (double*) malloc(sizeof(double));
    }

    double** test = (double**) malloc(testEx * sizeof(double*));
    for (int i = 0; i < testEx; i++) {
        test[i] = (double*) malloc((attr+1) * sizeof(double));
    }
    //*************** Train file pop
    //populate col with 1
    for(int i=0;i<trainEx;i++){
        x[i][0] = 1.0;
    }

    double temp = 0.0;
    for (int i = 0; i <trainEx; i++) {
        for (int j = 0; j <=(attr + 1); j++) { 
            if (j == (attr+1)) { 
                //j will equal the last col which will be price not by comma
                fscanf(fp, "%lf", &temp);
                y[i][0] = temp;
            } else if(j!=0){ 
                //everything is seperated by commas
                fscanf(fp, "%lf,",&temp);
                x[i][j] = temp;
            }
        }
    }
    //************* Test file pop
    for(int i=0;i<testEx;i++){
        test[i][0] = 1.0;
    }

    double temp1 = 0.0;
    for (int i = 0; i <testEx; i++) {
        for (int j = 0; j <(attr+1); j++) {
            if(j!=0){
                fscanf(fp2, "%lf,", &temp1);
                test[i][j] = temp1;
                }
        }
    }
    //print(testEx,attr+1,test);
    fclose(fp);
    fclose(fp2);

    //Calculation start
    double** transX = transposeMatrix(x,trainEx, (attr+1));
    double** multi1 = multiplyMatrix(transX, x, (attr+1),trainEx,trainEx, (attr+1));
    //print((attr+1),(attr+1),multi1);
    double** inverseX = inverseMatrix(multi1,attr+1);
    double** multi2 = multiplyMatrix(inverseX,transX,(attr+1), (attr+1), (attr+1),trainEx);
    double** w = multiplyMatrix(multi2,y,(attr+1),trainEx,trainEx, 1);
    double** final = multiplyMatrix(test,w,testEx, (attr+1), (attr+1), 1);
    //calculation end
    //print the final matrix
    print(testEx, 1, final);
    //function to free all matrix in one line
    freeALL(x,y,test,transX,multi1,inverseX,multi2,w,final,trainEx,(attr+1), testEx);
    
    return 0;
}


void print(int r, int c, double** matrix) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%0.0lf\t", matrix[i][j]);//0.0lf <-- not 0.01lf
        }
        printf("\n");
    }
}


double** multiplyMatrix(double** matA,double** matB,int r1, int c1, int r2, int c2) {

    double temp = 0.0;
    //allocate
    double** result = (double**) malloc(sizeof(double*) * r1);
    for (int i = 0; i < r1; i++) {
        result[i] = (double*) malloc(sizeof(double) * c2);
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < r2; k++) {
                temp += matA[i][k] * matB[k][j]; // sum bucket
            }
            result[i][j] = temp;
            temp = 0.0; //reset bucket
        }
    }
    return result;
}

double** transposeMatrix(double** mat,int row, int col) {

    //allocate
    double** matTran  = (double**) malloc(sizeof(double*) * col);
    for (int i = 0; i < col; i++) {
        matTran[i] = (double*) malloc(sizeof(double) * row);
    }
    //swaps value at [i][j] and making them return matrix [j][i] since we swap row/cols
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matTran[j][i] = mat[i][j];
        }
    }
    return matTran;
}

double** inverseMatrix(double **matA, int dimension) {

   double** matI = (double**) malloc(dimension * sizeof(double*));
    //responsible for filling identity mat
    for (int i = 0; i < dimension; i++) {
        matI[i] = (double*) malloc(dimension * sizeof(double));
    }
    //fills identity mat with diag 1's and 0's for everything else
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (i!=j) {
                matI[i][j] = 0.0;
            } else {
                matI[i][i] = 1.0;
            }
        }
    }
 //begin peusdocode inverse
 //i==p,j==i, k needs to be used to go through and divide/subtract in peusdo
    for(int i=0;i<dimension;i++){
        for(int j=i;j<dimension;j++){
            if(i==j){
                    double temp = matA[j][i];
                    for(int k=0;k<dimension;k++){
                        matA[j][k] = matA[j][k]/temp;
                        matI[j][k] = matI[j][k]/temp;
                    }
                }
            else{
                double temp1 = matA[j][i];
                for(int k=0;k<dimension;k++){
                    matA[j][k] = matA[j][k] - (temp1*matA[i][k]);
                    matI[j][k] = matI[j][k] - (temp1*matI[i][k]);
                }
            }
        }
    }
    for(int i=dimension-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            if(i==j){
                double temp = matA[j][i];
                matA[j][i] = matA[j][i]/temp;
                matI[j][i] = matI[j][i]/temp;
            }
            else{
                double temp = matA[j][i];
                for(int k=0;k<dimension;k++){
                    matA[j][k] = matA[j][k] - (matA[i][k])*temp;
                    matI[j][k] = matI[j][k] - (matI[i][k])*temp;

                }
            }
        }
    }
    return matI;
}

void freeMatrix(double** matrix, int row){
    for(int i=0;i<row;i++){
        free(matrix[i]);
    }
    free(matrix);
}   

void freeALL(double** x, double** y,double** test,double** transX,double** multi1,double** inverseX,double** multi2,double** w,double** final, int trainEx, int attr, int testEx){
    freeMatrix(x,trainEx);
    freeMatrix(y,trainEx);
    freeMatrix(test,testEx);
    //free Transpose
    freeMatrix(transX,(attr));
    //free first multiply
    freeMatrix(multi1,(attr));
    //free inverse
    freeMatrix(inverseX,(attr));
    //second multiply
    freeMatrix(multi2,(attr));
    //third multiply
    freeMatrix(w,(attr));
    //final multiply
    freeMatrix(final,testEx);
}