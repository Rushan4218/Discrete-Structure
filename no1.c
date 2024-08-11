#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* createSet(int n) {
    int* set = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    return set;
}

int* findUnion(int setA[], int sizeA, int setB[], int sizeB, int* unionSize) {
    int maxSize = sizeA + sizeB;
    int* result = (int*)malloc(maxSize * sizeof(int));
    for (int i = 0; i < sizeA; i++) {
        result[i] = setA[i];
    }
    int resultSize = sizeA;

    for (int i = 0; i < sizeB; i++) {
        bool exists = false;
        for (int j = 0; j < sizeA; j++) {
            if (setB[i] == setA[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            result[resultSize] = setB[i];
            resultSize++;
        }
    }
    *unionSize = resultSize;

    return result;
}
int* findDifference(int setA[], int sizeA, int setB[], int sizeB, int* differenceSize) {
    *differenceSize = 0;
    int* result = (int*)malloc(sizeA * sizeof(int));
    for (int i = 0; i < sizeA; i++) {
        bool exists = false;
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            result[*differenceSize] = setA[i];
            (*differenceSize)++;
        }
    }
    return result;
}
int* findIntersection(int setA[], int sizeA, int setB[], int sizeB, int* intersectionSize) {
    *intersectionSize = 0;
    int maxSize = (sizeA < sizeB) ? sizeA : sizeB;
    int* result = (int*)malloc(maxSize * sizeof(int));
    for (int i = 0; i < sizeB; i++) {
        for (int j = 0; j < sizeA; j++) {
            if (setB[i] == setA[j]) {
                result[*intersectionSize] = setB[i];
                (*intersectionSize)++;
                break;
            }
        }
    }
    return result;
}

void printSet(int set[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i != size - 1) printf(", ");
    }
    printf("}");
}

void printCartesianProduct(int setA[], int sizeA, int setB[], int sizeB) {
    printf("{");
    for(int i = 0; i < sizeA; i++)
    {
        for(int j = 0; j < sizeB; j++)
        {
            printf("{%d, %d}", setA[i], setB[j]);
            if(i < sizeA - 1 && j < sizeB - 1)
                printf(",");
        }
    }
    printf("}");
}
int main() {
    int sizeA, sizeB, unionSize, intersectionSize, differenceSize;
    printf("Enter the size of the first set: ");
    scanf("%d", &sizeA);
    int* setA = createSet(sizeA);
    printf("Enter the size of the second set: ");
    scanf("%d", &sizeB);
    int* setB = createSet(sizeB);
    int* setUnion = findUnion(setA, sizeA, setB, sizeB, &unionSize);
    printf("UNION\n");
    printSet(setUnion, unionSize);
    int* setIntersection = findIntersection(setA, sizeA, setB, sizeB, &intersectionSize);
    printf("\nINTERSECTION\n");
    printSet(setIntersection, intersectionSize);
    int* setDifference = findDifference(setA, sizeA, setB, sizeB, &differenceSize);
    printf("\nDIFFERENCE\n");
    printSet(setDifference, differenceSize);
    printf("\nCARTESIAN PRODUCT\n");
    printCartesianProduct(setA, sizeA, setB, sizeB);
    return 0;
}