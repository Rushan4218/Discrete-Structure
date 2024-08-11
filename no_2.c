#include <stdio.h>

int customFloor(float);
int customCeil(float);

int main()
{
    float a;
    printf("Enter any floating point number: ");
    scanf("%f", &a);

    int floora = customFloor(a);
    int ceila = customCeil(a);

    printf("floor = %d\n", floora);
    printf("ceil = %d\n", ceila);

    return 0;
}

int customFloor(float a)
{
    if(a > 0) return (int)a;
    else return (int)a - 1;
}

int customCeil(float a)
{
    if(a > 0) return (int)a + 1;
    else return (int)a;
}