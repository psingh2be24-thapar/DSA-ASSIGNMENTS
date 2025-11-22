
#include <stdio.h>

void func(int(*arr)[3][3])
{
    printf("\nIn function\n");
    for(int i=0; i<3; i++)
    {
        for (int j = 0; j < 3; ++j)
        {
            (*arr)[i][j] = (*arr)[i][j]+10;
            printf("%d ",(*arr)[i][j]);
        }

        printf("\n");
    }
}
int main()
{
    int a[3][3] = { {2,1,1},{3,3,5} };
    func(&a);

 return 0;
}
