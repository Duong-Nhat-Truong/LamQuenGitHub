#include<stdio.h>
#include<string.h>

int main()
{
    char chuoi[50], tu[10];
    int i=0, j=0, n=0;
    printf("Nhap Chuoi: ");
    gets(chuoi);
    printf("Chuoi vua nhap: ");
    puts(chuoi);


    printf("Nhap tu can tim: ");
    gets(tu);
    printf("Chuoi vua nhap: ");
    puts(tu);

    while(chuoi[i] != '\0')
    {
        if(chuoi[i] == tu[j])
        {
            while(chuoi[i] == tu[j] && chuoi[i] != '\0' && j != strlen(tu))
            {
                i++;
                j++;
                printf("\ni trong while %d", i);
            }
            if(j == strlen(tu))
            {
                printf("Hello");
                n++;
            }
        }
        i = i-j;    //Tru de lay lai vi tri dang xet chuoi ban dau, tranh truong hop tu can tim dung lien tiep nhau
        printf("\ni ngoai while %d", i);
        i++;
        j=0;
    }

    printf("\nSo lan xuat hien: %d", n);

    // int gap=0, gaptemp=0, trangthai=0;
    // char chuoi[]="0000000001";
    // printf("Chuoi: ");
    // puts(chuoi);

    // for(int i=0; i<10; i++){
    //     if(chuoi[i]=='1'){
    //         trangthai=1;
    //         if(gaptemp > gap){
    //             gap = gaptemp;
    //         }
    //         else gap = gap;
    //         gaptemp=0;
    //     }
    //     else if(trangthai==1){
    //         gaptemp++;
    //         printf("gaptemp = %d\n", gaptemp);
    //     }
    //     printf("i = %d\n", i);
    // }

    // printf("Gap = %d\n", gap);

    return 0;
}