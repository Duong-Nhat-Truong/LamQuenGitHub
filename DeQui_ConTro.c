#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



//Fibonacci - Bai tap 1
int Fibonacci(int i)
{
    if(i==0)
        return 0;
    if(i==1)
        return 1;
    return Fibonacci(i-1) + Fibonacci(i-2);
}



//Ham tinh Tong - Bai tap 2
int Tong(int i)
{   
    int sum = 0;
    if(i==1)
        return 1;
    else
        sum = i + Tong(i-1);
    return sum;
}



//Ham chuyen thap Ha Noi - Bai tap 3.
void Tower(int n, char a, char b, char c)
{
    if(n==1)
    {
        printf("%c ---------> %c\n", a, c);
        return;
    }
    Tower(n-1, a,c,b);
    Tower(1, a,b,c);
    Tower(n-1, b,a,c);
}



//ham tinh giai thua - Bai tap 4.
int Giai_thua(int a)
{
    int gt;

    if(a==1)
        return 1;
    gt = a*Giai_thua(a-1);
    return gt;
}



//Ham trao doi hai so dung con tro
void Trao_doi(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    //Sau khi kha bao p1 la con tro (gia tri cua p1 la dia chi), *p1 la gia tri cua o nho ma con tro chi toi.
}


int main()
{   
    //DE QUI
    //Bai tap 1: Chuoi Fiboncci dung de qui. 
    /*int n,i ;

    printf("Nhap so phan tu trong chuoi Fibonacci: ");
    scanf("%d", &n);

    printf("Chuoi Fibonacci co dang:\n");
    for(i=0; i<n; i++)
        printf("%d  ", Fibonacci(i));

    printf("\nHet chuong trinh!");*/



    //Bai toan 2: Tinh tong n so dung de qui.
    /*int n, i;

    printf("Nhap so n: ");
    scanf("%d", &n);

    printf("Tong cua cac so tu 1 den %d la %d.", n, Tong(n));
    printf("\nHet chuong trinh!");*/



    //Bai toan 3: Thap Ha Noi.
    /*int n;
    char a='A', b='B', c='C';
    printf("Nhap tang can chuyen: ");
    scanf("%d", &n);

    Tower(n,a,b,c);
    printf("\nHet chuong trinh");*/



    //Bai toan 4: Tinh giai thua.
    /*int a;

    printf("Nhap vao so a: ");
    scanf("%d", &a);

    printf("Giai thua cua %d la: %d", a, Giai_thua(a));
    printf("\nHet chuong trinh");*/



    //CON TRO
    //Bai tap 1: Cong hai so su dung con tro.
    /*int *ptr1, *ptr2; //Khai bao con tro.
    int a=5, b=10;
    int sum=0;

    ptr1 = &a; //Con tro "ptr1" chi toi dia chi cua o nho "a".
    ptr2 = &b; //Tuong duong voi khai bao: int *ptr = &c
    sum = *ptr1 + *ptr2; //*ptr1 lay gia tri cua o nho ma con tro chi toi.

    printf("Dia chi a va b la luot la %p\t%p", ptr1, ptr2); //%p dia chi con tro.
    printf("\nTong a va b la: %d", sum);
    printf("\nHet chuong trinh!");*/



    //Bai tao 2: Trao doi hai gia tri su dung con tro.
    /*int a, b;

    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);

    Trao_doi(&a, &b);

    printf("Sau khi trao doi:");
    printf("\nSo thu nhat: %d", a);
    printf("\nSo thu hai: %d", b);
    printf("\nHet chuong trinh!");*/



    //Bai tap 3: Tinh tong cac phan tu trong mang su dung con tro.
    /*int arr[10];
    int i, n, sum=0;
    int *ptr;

    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    printf("Nhap mang:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Mang co dang:\n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    
    //ptr = arr; //Cho con tro chi vao mang. Ta cung co the gan: ptr = &arr[0]
    ptr = &arr[0];

    for(i=0; i<n; i++)
    {
        sum = sum + *ptr;
        ptr++;
    }

    printf("\n%p %p %p\n", (ptr-1), (ptr-2), (ptr-3));
    printf("\n%d %d %d\n", *(ptr-1), *(ptr-2), *(ptr-3));
    printf("Tong cac phan tu trong mang la: %d", sum);
    printf("\nHet chuong trinh");*/



    //Cau truc Struct.
    
    
    system("pause");
    return 0;
}