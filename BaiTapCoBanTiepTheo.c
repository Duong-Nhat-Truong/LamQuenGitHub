#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*double khai_can(int a)
{
    double i, pre=0.0000001;
    for(i=1; i*i<a; i++);
    for(--i; i*i<a; i=i+pre);
    return i;
}*/

int main()
{
    //Bai tap 1: Kiem tra so Armstrong (153 = 1*1*1 + 5*5*5 + 3*3*3)
    /*int a=0, c;

    printf("Nhap so can kiem tra: ");
    scanf("%d", &a);
    int b=a;
    int sum=0;

    while(b != 0)
    {
        c = b%10;
        b = b/10;
        sum = sum + c*c*c;
    }

    if(sum==a)
        printf("\n%d la so Armstrong!", sum);
    else
        printf("\n%d khong phai la so Armstrong!", a);*/



    //Bai tap 2: Kiem tra so nguyen to.
    /*int a, i=1;
    int k=0;

    printf("Nhap so can kiem tra: ");
    scanf("%d", &a);

    while(i <= a)
    {
        if(a%i == 0)
            {
                k++;
                i++;
            }
        else i++;
    }
    if(k>3)
        printf("%d khong phai la so nguyen to!", a);
    else
        printf("%d la so nguyen to!", a);*/



    //Bai tap 3: Tinh giai thua.
    /*int a, gt=1;

    printf("Nhap so can tinh giai thua: ");
    scanf("%d", &a);

    for(int i=1; i<=a; i++)
    {
        gt = gt*i;
    }

    printf("Giai thua cua %d la %d", a, gt);*/



    //Bai tap 4: Xuat ra day Fibonacci (khong dung de qui).
    /*int a;
    int s[20];

    printf("Nhap so phan tu trong day Fibonacci: ");
    scanf("%d", &a);

    s[0] = 1;
    s[1] = 1;

    for(int i=0; i<a-2; i++)
    {
        s[i+2] = s[i] + s[i+1];
    }

    printf("Day Fibonacci %d phan tu:\n", a);
    for(int i=0; i<a; i++)
        printf("%d  ", s[i]);
    printf("\nHet chuong trinh");*/



    //Bai tap 5: Tim can bac 2.
    /*int a;

    printf("Nhap so can khai can: ");
    scanf("%d", &a);

    printf("Can bac 2 cua %d la %f.", a, khai_can(a));*/



    //Bai tap 6: Tim UCLC va BCNN.
    int a, b;
    int i=1, UCLN = 1;
    int BCNN, max, step;

    printf("Nhap vao so a nguyen duong: ");
    scanf("%d", &a);
    printf("Nhap vao so b nguyen duong: ");
    scanf("%d", &b);

    while(i<a || i<b)
    {
        if(a%i == 0 && b%i == 0)
        {
            UCLN = i;
            i++;
        }
        else
            i++;
    }    
    if(a>b)
        max=step=a;
    else max=step=b;

    while(1)
    {
        if(max%a ==0 && max%b == 0)
        {
            BCNN = max;
            break;
        }
        else
            max=max+step;
    }

    printf("Uoc chung lon nhat la: %d\n", UCLN);
    printf("Het chuong trinh");
    printf("Boi chung nho nhat la: %d\n", BCNN);

    system("pause");
    return 0;
}
