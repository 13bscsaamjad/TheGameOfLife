#include<cstdlib>
#include<string.h>
#include<stdint.h>
#include<iostream>

using namespace std;
int bactFind(int rowindex, int colindex, char** c, int rows, int columns);
void matrixprint(char**c,int row,int col);
int main()
{
    int rows,cols;
    char temp,option;
    char filename[50];
    FILE*fileptr;
    cout<<"Welcome to a simulation of the lifecycle of a bacteria colony.\nCells (X) live and die by the following rules:\n- A cell with 1 or fewer neighbors dies.\n- Locations with 2 neighbors remain stable.\n- Locations with 3 neighbors will create life.\n- A cell with 4 or more neighbors dies.\nPlease enter grid input file name:";
    gets(filename);
    fileptr=fopen(filename,"r");       
    if (fileptr == NULL)
    {
        printf("Unable to open the file\n");
    }
    fscanf(fileptr,"%d\n%d\n",&rows,&cols);
  

    char** matrix = new char*[rows];     //Allocating memory for my 2D character array 
    for (int i = 0; i < rows; i++)
  {
    matrix[i] = new char[cols];
  }


    int** arraycount = new int*[rows];      //Allocating memory for my 2D integer array where I will store the number of neighbours of each element  
    for (int i = 0; i < rows; i++)
  {
    arraycount[i] = new int[cols];
  }
    fflush(stdin);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)          
        {
            fscanf(fileptr,"%c",&matrix[i][j]);           //Reading from the file
        }
        fscanf(fileptr,"%c",&temp);                  //storing /n in a temporary char variable
    }

for(int i=0;i<rows;i++)
    {
        cout<<"\n";
        for(int j=0;j<cols;j++)
        {
            cout<<matrix[i][j];
        }
        }
cout<<"\n\nt)ick,  q)uit ";

    while(1)
{
scanf("%c",&option);
switch(option)
{
case 't':
    for (int p = 0; p<rows; p++)
    {
        for (int q = 0; q<cols; q++)
            arraycount[p][q] = bactFind(p, q, matrix, rows, cols);   //Calling the neighbour counting function and storing the number of arrays in an integer array
    }
 
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            if (arraycount[i][j] <= 1||arraycount[i][j] >= 4)
                matrix[i][j] = '-';
else
            if (arraycount[i][j] == 3)
                matrix[i][j] = 'X';
        }
    }
matrixprint(matrix,rows,cols);
break;
case'q':
return 0;
}
}
    for (int i = 0; i < rows; i++)
    {
    delete (matrix[i]);
  }
delete matrix;      //Freeeing the memory function for character array
    
    for (int i = 0; i < rows; i++) {          //Freeeing the memory function for integer array
        delete (arraycount[i]);
    }
    delete arraycount;
 
   
    return 0;
}






int bactFind(int rowindex, int colindex, char** c, int rows, int columns)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        if ((rowindex + i) >= 0 && (rowindex + i) < rows)
        {
            for (int j = -1; j <= 1; j++)
            {
                if ((colindex + j) >= 0 && (colindex + j) < columns){
                    if (i == 0 && j == 0)
                        continue;
                    {
                        if (c[rowindex + i][colindex + j] == 'X')
                            ++count;
                    }
                }

            }
        }
    }
    return count;
}


void matrixprint(char**c,int row,int col)
{
for(int i=0;i<row;i++)
    {
        cout<<"\n";
        for(int j=0;j<col;j++)
        {
            cout<<c[i][j];
        }
        }
cout<<"\n\nt)ick,  q)uit ";
}