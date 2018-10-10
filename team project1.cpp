// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose
//______________________________________________


void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];

}
//_____________________________________________

int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {1,2,3,4,5,6,7,8,0};
  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3;
  createMatrix (4, 2, data1, mat1);
  createMatrix (3, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);

////______________________________________________
    cout << "MAT1+MAT2 \n" << mat1 << endl;
    cout << "MAT1-MAT2 \n" <<mat2 << endl;
    cout << "MAT1*MAT2 \n" <<mat3 << endl;
    cout << "MAT1 - MAT3 \n" ;
    cout << (mat1 - mat3) << endl << endl;
    cout << "MAT3 + MAT3 \n" << (mat3 + mat3) << endl << endl;
    cout << "MAT1 * MAT2 \n" << (mat1 * mat2) << endl << endl;
////__________________________________________________________________


  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat3 << endl;


//____________________________________________________________________
//
 cout << "mat1 == mat2\n" << (mat1 == mat2) << endl ;
 cout << "mat1 != mat2\n" << (mat1 != mat2) << endl ;
 cout << "Symetric \n" << isSymetric(mat1) <<endl ;
 cout << "Square\n"<< isSquare(mat1) <<endl ;
 cout << "Identity\n" <<isIdentity(mat1) << endl ;
 cout << "transpose\n" <<transpose(mat1) << endl ;



  return 0;
}
//_____________________________________________________________________

istream& operator>> (istream& in, matrix& mat)
{
    for(int i =0; i < mat.row ;i++){
        for(int j = 0; j < mat.col; j++){
            in >> mat.data[i][j];
        }
    }
    cout<<endl;
    return in;
}
//_______________________________________________________________________

ostream& operator<< (ostream& out, matrix mat){
    for ( int i = 0; i < mat.row ; i++) {
        for (int j=0; j < mat.col ; j++){
            cout << mat.data[i][j] ;
            cout << " " ;
        }
        cout << endl ;
    }
    return out;
}
//______________________________________________________________________________________________________________________

// student1: Rahma Ramadan Ahmed   ID:20170103

matrix operator+  (matrix mat1, matrix mat2) // Add if same dimensions
{
    matrix mat ;
    int data [] = {} ;
    createMatrix(mat1.row,mat1.col,data,mat); //new matrix to store data
    if((mat1.row == mat2.row) && (mat1.col == mat2.col))
    {
        cout<<"same dimensions" <<endl ;
        for (int i=0 ; i<mat1.row ; i++ )
        {
            for (int j=0; j<mat1.col ; j++)
            {
                mat.data[i][j] = mat1.data[i][j] + mat2.data[i][j] ;
            }

        }
        return mat ;
    }
    else
    {
        cout<< "Not same dimensions"<<endl;
    }

}
//____________________________________________________________________________


matrix operator-  (matrix mat1, matrix mat2) // Sub if same dimensions
{
    matrix mat ;
    int data[] = {} ;
    createMatrix(mat1.row,mat1.col,data,mat); //new matrix to store data
    if((mat1.row == mat2.row) && (mat1.col == mat2.col))
    {
        for (int i=0 ; i<mat1.row ; i++ )
        {
            for (int j=0; j<mat1.col ; j++)
            {
                mat.data[i][j] = mat1.data[i][j] - mat2.data[i][j] ;
            }
        }
    }

        return mat ;
}
//______________________________________________________________________________

matrix operator*  (matrix mat1, matrix mat2) // Multi if col1 == row2
{
    matrix mat ;
    int data[] = {} ;
    createMatrix(mat1.row,mat2.col,data,mat); //new matrix to store data
    if (mat1.col == mat2.row)
    {
        for (int i=0 ; i<mat2.row ; i++ )
        {

            for (int j=0; j<mat1.col ; j++)
            {
                if (j == 0) mat.data[i][j] = 0;
                mat.data[i][j] = mat.data[i][j] + (mat1.data[i][j] * mat2.data[j][i]) ;
            }

        }
        return mat ;
    }
    else
    {
        cout <<" col1 not equal to row2"<<endl ;
    }
}
//________________________________________________________________________________

matrix operator+  (matrix mat1, int scalar) // Add a scalar
{
    cout<<"Enter Number : ";
    cin>>scalar;
    matrix mat ;
    for (int i=0 ; i<mat1.row ; i++ )
    {
        for (int j=0; j<mat1.col ; j++)
        {
            mat.data[i][j] = mat1.data[i][j] + scalar ;
        }

    }
    return mat ;
}

//___________________________________________________________________________

matrix operator-  (matrix mat1, int scalar) // Subtract a scalar
{
    cout<<"Enter Number : ";
    cin>>scalar;
    matrix mat ;
    for (int i=0 ; i<mat1.row ; i++ )
    {
        for (int j=0; j<mat1.col ; j++)
        {
            mat.data[i][j] = mat1.data[i][j] - scalar ;
        }

    }
    return mat ;
}
//______________________________________________________________________________

matrix operator*  (matrix mat1, int scalar)  // Multiplelar

{
    cout<<"Enter Number : ";
    cin>>scalar;
    matrix mat ;
    cin>>scalar ;
    for (int i=0 ; i<mat1.row ; i++ )
    {
        for (int j=0; j<mat1.col ; j++)
        {
            mat.data[i][j] = mat1.data[i][j] * scalar ;
        }

    }
    return mat ;
}
//____________________________________________________________________________________________________________________


// student1: Radwa Ahmed Mahmoud   ID:20170104


matrix operator+= (matrix& mat1, matrix mat3)
{
    if (mat1.row==mat3.row&&mat1.col==mat3.col){
        for (int i=0;i<mat3.row;i++){
            for(int j=0; j<mat3.col;j++){
                mat1.data[i][j]=mat1.data[i][j]+mat3.data[i][j];
            }
        }
    }
    else
    {
        cout<<"The two matrices have different dimensions"<<endl;

    }
    return mat1;
}

//_________________________________________________________________________________

matrix operator-= (matrix& mat1, matrix mat3)
{
    if(mat1.row==mat3.row&&mat1.col==mat3.col){
         for (int i=0;i<mat3.row;i++){
            for(int j=0; j<mat3.col;j++){
                    if(mat3.data[i][j]>mat1.data[i][j]){
                        mat1.data[i][j]=mat3.data[i][j]-mat1.data[i][j];
                    }
                    else {
                        mat1.data[i][j]=mat1.data[i][j]-mat3.data[i][j];
                    }

            }
    }
}
else {
    cout<<"The two matrices have different dimensions"<<endl;
}
return mat1;
}

//___________________________________________________________________________________

matrix operator+= (matrix& mat1, int scalar)
{
    for(int i=0 ;i<mat1.row;i++){
        for (int j=0 ;j<mat1.col;j++){
            mat1.data[i][j]=mat1.data[i][j]+scalar;
        }
    }
}

//___________________________________________________________________________________

matrix operator-= (matrix& mat1 , int scalar)
{
    for(int i=0;i<mat1.row;i++){
        for (int j=0;j<mat1.col;j++){
            mat1.data[i][j]=mat1.data[i][j]-scalar;
        }
    }
    return mat1;
}

//___________________________________________________________________________________

void operator++ (matrix& mat)
{
    for(int i=0;i<mat.row;i++){
        for (int j=0;j<mat.col;j++){
            mat.data[i][j]=mat.data[i][j]+1;
        }
    }

}
//___________________________________________________________________________________

void operator-- (matrix& mat1)
{
    for(int i=0;i<mat1.row;i++){
        for(int j=0;j<mat1.col;j++){
            mat1.data[i][j]=mat1.data[i][j]-1;
        }
    }
}

//________________________________________________________________________________________________________________

// student: Sara Adel Ali   ID:20170108


bool   operator== (matrix mat1, matrix mat2) {                        // checking equality  of two matrix
      if ( mat1.row == mat2.row && mat1.col == mat2.col ) {           // The two conditions must be applied
         for ( int i=0; i< mat1.row ; i++) {                          // looping the data inside
            for ( int j=0; j<mat1.col ; j++) {
                if ( mat1.data[i][j]== mat2.data[i][j]) {             // If the data identical!!
               }
            }
         }
         return true;                                                // True if identical
      }
      else
        return false;
}
//________________________________________________________________

bool   operator!= (matrix mat1, matrix mat2) {                    // checking if the two matrix are not same
      if ( mat1.row!= mat2.row && mat1.col!= mat2.col) {          // The two conditions must be applied
         for ( int i=0; i< mat1.row ; i++) {                      // looping the data inside
            for ( int j=0; j<mat1.col ; j++) {
                if ( mat1.data[i][j]!= mat2.data[i][j]) {         // If the data is not same!!
               }
            }
         }
            return true; }                                         //true if not same
            else
                return false;
}
//___________________________________________________________________

bool   isSquare   (matrix mat) {                             // checking if row and column are equal
    if ( mat.row == mat.col) {

    return true; }                                          // true if square matrix

    else
        return false;
}

//___________________________________________________________________

bool   isSymetric (matrix mat) {                          // checking the symmetry of matrix
   if ( mat.row == mat.col) {                             // the matrix must be square
    for ( int i=0; i< mat.row ; i++) {                    // looping the data inside
        for ( int j=0; j<mat.col ; j++){
   if (  mat.data[i][j]== mat.data[j][i]) {               // if the data is symmetric!!
   }

   }
 }
    return true;                                         // true if square and symmetric
     }

    else
        return false;
}
//__________________________________________________________________________

bool   isIdentity (matrix mat) {                             // checking the identity of matrix
  if ( mat.row == mat.col) {                                 // the matrix must be square
    for ( int i=0; i< mat.row ; i++) {                       // looping the data inside
            for ( int j=0; j<mat.col ; j++) {
  if ( (mat.data[i][j]== mat.data[j][i]==0 ) && (mat.data[i][i] == mat.data[j][j]==1) )  //the principal diagonal must be 1 and the rest is zero
    {
  }
  }
    }

 return true;                                               // true if square and identity
 }
    else
        return false;
}

//____________________________________________________________________________

matrix transpose(matrix mat) {                          // making transpose of matrix


    int rows = mat.row ;
    int cols = mat.col ;
    matrix mat2 ;
    int data[] = {} ;
    createMatrix (mat.col, mat.row , data, mat2);

    for(int i=0 ; i< rows ; i++)
    {
        for(int j=0 ; j < cols ; j++ )
        {
            mat2.data[j][i] = mat.data[i][j] ;
        }
    }

    return mat2 ;



}













































