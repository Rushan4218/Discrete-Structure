#include <stdio.h>
#include <stdlib.h>

int** meet(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols])
{
    int** mat3;
    mat3 = (int**) malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        mat3[i] = (int*) malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++)    
        {
            mat3[i][j] = mat1[i][j] && mat2[i][j];
        }
    }

    return mat3;
}

int** join(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols])
{
    int** mat3;
    mat3 = (int**) malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        mat3[i] = (int*) malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++)
        {
            mat3[i][j] = mat1[i][j] || mat2[i][j];
        }
    }
    return mat3;
}

int main()
{
    int rows, cols = 3;
    printf("Enter the dimension of the matrices: \n");
    scanf("%d%d", &rows, &cols);

    int mat1[rows][cols], mat2[rows][cols];

    //for mat1
    printf("Enter the elements of first matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    //for mat2
    printf("Enter the elements of second matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    int** joinMat = join(rows, cols, mat1, mat2);
    int** meetMat = meet(rows, cols, mat1, mat2);

    printf("Join\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", joinMat[i][j]);
        }
		printf("\n");
    }
    printf("Meet\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", meetMat[i][j]);
        }
		printf("\n");
    }   
    return 0;
}