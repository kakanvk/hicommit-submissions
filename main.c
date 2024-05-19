#include <stdio.h>
#include <math.h>

int a;

int soNguyenTo(int soA)
{
    if (soA < 2)    
        return 0;

    for (int i = 2; i <= sqrt(soA); i ++)
    {
        if (soA%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main() {

    scanf("%d", &a);

    if(soNguyenTo(a))
      printf("Yes");
    else printf("No");
    
    return 0;
}