//
//  Cpp_intro.cpp
//
//  Simple example for use in M368 class
//
//  Created by Richard Tsai on 2/4/15.
//
//

//The following lines allows you to use some functions needed in this class
#include <iostream>     //this allows you to read inputs and create outputs to files or terminal
#include <math.h>         //this will allow you to use math funcitons, such as fabs(), sin()


//For the purposee of this class, always put your function definitions before the function'main()'
void initialize_1d_array(double* B, int size_of_B)
{
    for (int i=0; i<size_of_B; i++) {
        B[i]=4.0;
    }
}

void initialize_2d_array(double** T, int S1, int S2, double init_value)
{
    std::cout<<"From initialize_2d_array:  T["<<S1-1<<", "<<S2-1<<"]="<<T[S1-1][S2-1]<<std::endl<<std::endl;
    
    for(int i=0; i<S1; i++)
    {
        for(int j=0; j<S2; j++)
        {
            T[i][j]=init_value;
        }
    }
}

//second version of initialize_2d_array
void initialize_array(double *T, int S1, int S2, double init_val)
{
    
    for(int i=0; i<S1; i++)
    {
        for(int j=0; j<S2; j++)
        {
            T[i*S2+j]=init_val;
        }
    }

}







using namespace std;

int main(void)
{
    cout<<"Some quick comments:"<<endl;
    cout<<"1. You always need to declare the variables that you want to use, BEFORE you use them."<<endl<<endl;
    cout<<"2. ALWAYS terminate each line/ step by a semi-colon. Check the code."<<endl;
    
    
    int N,M;  //declaring two variables that will store information about integers
    
    N=100;
    M=200;
    
    cout<<"Declaring dynamical arrays with the sizes specified by N and M."<<endl;
    
    double *b = new double[N];      //This creates a one dimensional array of size N
    
    //The following two lines a two dimensional array of size NxM.
    double **A= new double* [N];
    for (int i=0; i<N; i++) {
        A[i]=new double [M];
    }
    
    cout<<"!!! The first element of an array starts with index 0 !!!"<<endl;
    b[0] = 10.0;
    cout<< "b[0]="<<b[0]<<endl;
    cout<< "b itself has an integer value which tells the computer where to look for the location where the array data is stored."<<endl;
    cout<<"So is it udnerstand as an address."<<endl;
    
    initialize_1d_array(b, N);
    cout<<"the function initialize_1d_array() resets the values stored in b"<<endl;
    cout<<"b[0]="<<b[0]<<", b[5]="<<b[5]<<endl<<endl;
    

    delete b; //this will destroy the memory allocated for the vector b.
    
    //one can reallocate b to be an array of different size
    b= new double[N*M];
    cout<<"Use the newly allocated 1d array as a 2D array as follows"<<endl;
    cout<<"b[i][j] will be b[j*N+i]."<<endl;
    
    int I=20, J=2;
    cout<<" b["<<I<<"], "<<J<<"]="<<b[J*N+I]<<endl;
    cout<<" b="<<b<<endl;
    
    double * C=new double[N*M];
    cout<<"You can access your 1d array as a 2d array with a different ordering:"<<endl;
    cout<<"b[i][j] will be b[i*M+j]."<<endl;
    cout<<"\nBut this will have different implications ";
    cout<<"in nested for-loops: loop over i in the outsie anf j in the inside??"<<endl;
    
    A[N-1][M-1]=-1230000000.11111;
    cout<<"A[99,199]="<<A[99][199]<<endl;
    
    initialize_2d_array(A, N,M,3.1415926);
    
    cout<<"A[3,5]="<<A[3][5]<<endl;
    cout<<"A[99,199] is reset by initialize_2d_array() to be "<<A[99][199]<<endl<<endl;
    
    initialize_array(C, N,M,-3.1415926);
    cout<<"C[3,5]="<<C[3*M+5]<<endl;
    
    return 0;

}