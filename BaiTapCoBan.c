#include<stdio.h>
#include<string.h>

//Ham dao ky tu trong tu.
void ham_dao_chuoi(char str[]) //Ham void khong tra ve gia tri. Ham int tra ve gia tri trong pham vi int.
{
    char daoxong[50];
    int i=0;
    int j=0;
    int n=0;

    n = strlen(str);
    j = n;
    //printf("\nHello %d",j);

    for(i=0; i<n; i++)
    {
        daoxong[j-1] = str[i];
        j=j-1;
    }
    daoxong[n]='\0';
    printf("\n%s",daoxong);
    //printf("\nHet ham");
}

 struct data{
        int nam;
        char s[16];
        float nu;
    }testsize;

int main()
{
    //struct data test;
    //printf("%d", sizeof(testsize));
    //Bai tap 1: Bai tap ve chuoi (khong su dung ham).
    //1. In mot chuoi - Tim do dai chuoi.
    /*char chuoi[30];
    int i=0;

    printf("Nhap chuoi: ");
    gets(chuoi);
    printf("Chuoi vua nhap: ");
    puts(chuoi);
    printf("Chuoi vua nhap: %s", chuoi);

    while(chuoi[i] != '\0')
        i++;
    printf("\nDo dai cua chuoi \"%s\" khong tinh ky tu ket thuc null la: %d", chuoi, i);*/



    //2. Dem so lan xuat hien ky tu trong chuoi - Dem phu am, nguyen am.
    /*char chuoi[30];
    int i=0;
    int n=0;
    int m=0;
    int j=0;
    char kytu = 'a';

    printf("Nhap chuoi: ");
    gets(chuoi);
    printf("Chuoi vua nhap: ");
    puts(chuoi);
    printf("Chuoi vua nhap: %s", chuoi);

    while(chuoi[i] != '\0')
    {
        if(chuoi[i] == kytu)
            n++;
        if(chuoi[i]=='u' || chuoi[i]=='e' || chuoi[i]=='o' || chuoi[i]=='a' || chuoi[i]=='i')
            m++;
        else j++;
        i++;
    }
    printf("\nKy tu %c xuat hien %d lan", kytu, n);
    printf("\nTrong chuoi co %d nguyen am.", m);
    printf("\nTrong chuoi co %d phu am.", j);*/



    //3. Sap xep chuoi theo bang chu cai dung ham strlen.
    /*char chuoi[30];
    char temp;
    int i, j, n;

    printf("Nhap chuoi: ");
    gets(chuoi);
    printf("Chuoi vua nhap: ");
    puts(chuoi);
    printf("Chuoi vua nhap: %s", chuoi);

    n = strlen(chuoi);
    for(i=0; i<n-1; i++) //Phan tu cuoi khong can so sanh.
    {
        for(j=i+1; j<n; j++) //Cac phan tu duoc sap xep roi se nam phia sau (ben trai), nen khong can so sanh nua.
            if(chuoi[i] > chuoi[j])  //Trong C cac ky tu se duoc qui dinh mot gia tri khac nhau Vd: ABCDEF roi moi toi abcdef
        {
            printf("\n%d - %d",chuoi[i],chuoi[j]);
            temp = chuoi[i];
            chuoi[i] = chuoi[j];
            chuoi[j] = temp;
        }
    }

    printf("\nChuoi sau khi duoc sap xep:");
    printf("%s", chuoi);*/



    //4. Sao chep chuoi - Dao nguoc chuoi.
    /*char chuoi[30];
    char saochep[30];
    char daonguoc[30];
    int i=0, j=0, n=0;

    printf("Nhap chuoi: ");
    gets(chuoi);
    printf("Chuoi vua nhap: ");
    puts(chuoi);
    printf("Chuoi vua nhap: %s", chuoi);


    while(chuoi[i] != '\0')
    {
        saochep[i] = chuoi[i];
        j++;
        i++;
    }
    saochep[i]='\0';

    while(chuoi[n] != '\0')
    {
        daonguoc[j-1] = chuoi[n]; //Cho nay phai la j-1 vi luc nay j dang o ky tu ket thuc. Phai offset no vo thi moi dung duoc.
        j--;
        n++;
    }
     daonguoc[n]='\0';

    printf("\nChuoi sao chep: %s",saochep);
    printf("\nChuoi dao nguoc: %s",daonguoc);*/



    //5. Dem xem tu xuat hien bao nhieu lan trong chuoi.
    // char chuoi[50];
    // char tim[50];
    // int i=0, j=0, n=0;

    // printf("Nhap chuoi: ");
    // gets(chuoi);
    // printf("Chuoi vua nhap: ");
    // puts(chuoi);
    // printf("Chuoi vua nhap: %s", chuoi);

    // printf("\nNhap chuoi can tim: ");
    // gets(tim);
    // printf("Chuoi can tim vua nhap: ");
    // puts(tim);
    // printf("Chuoi can tim vua nhap: %s", tim);

    // int leng = strlen(tim);

    // printf("\nDo dai chuoi can tim: %d", leng);

    // while(chuoi[i] != '\0')
    // {
    //     if(chuoi[i] == tim[j]) //Kiem tra ky tu dau co giong nhau khong.
    //     {
    //         while(chuoi[i] == tim[j] && chuoi[i] != '\0') //Neu dung tiep tuc kiem tra
    //         {
    //             i++;
    //             j++;
    //             printf("\n%d %d",i,j);
    //         }
    //         if(j==leng && (chuoi[i]=='\0' || chuoi[i]==' '))
    //         {
    //             n++;
    //             printf("\n%d", n);
    //         }
    //     }
    //     else 
    //     {
    //         while(chuoi[i] != ' ')
    //         {
    //             i++;
    //             if(chuoi[i]=='\0')
    //                 break;
    //         }
    //     }
    //     i++;
    //     j=0;
    // }

    // printf("\nChuoi \"%s\" xuat hien %d lan",tim, n);
    // printf("\nHet chuong trinh");



    //6. Kiem tra chuoi Anagram(co cung so ky tu va cac ky tu giong nha, vi tri co the khac nhau)
    /*char chuoi1[50], chuoi2[50];

    //Xuat nhap chuoi
    printf("Nhap chuoi dau tien: ");
    gets(chuoi1);
    printf("Chuoi vua nhap: ");
    puts(chuoi1);

    printf("Nhap chuoi thu hai: ");
    gets(chuoi2);
    printf("Chuoi vua nhap: ");
    puts(chuoi2);

    //Sap xep chuoi
    int n = strlen(chuoi1);
    int m = strlen(chuoi2);

    if(n != m)
    {
        printf("Hai chuoi khong la Anagram!");
        return 0;
        //Trong vong if neu khong co break hay return thi chuong trinh se bi treo.
    }

    char temp1, temp2;
    int i, j;

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(chuoi1[i] > chuoi1[j])
            {
                temp1 = chuoi1[j];
                chuoi1[j] = chuoi1[i];
                chuoi1[i] = temp1;
            }
        }
    }

    for(i=0; i<m-1; i++)
    {
        for(j=i+1; j<m; j++)
        {
            if(chuoi2[i] > chuoi2[j])
            {
                temp2 = chuoi2[j];
                chuoi2[j] = chuoi2[i];
                chuoi2[i] = temp2;
            }
        }
    }

    //So sanh hai chuoi sau khi sap xep
    for(i=0; i<n; i++)
    {
        if(chuoi1[i] != chuoi2[i])
        {
            printf("Hai chuoi nay khong phai la Anagram!");
            return 0;
        }
    }

    printf("%s  %s", chuoi1, chuoi2);
    printf("\nHai chuoi la Anagram!");*/



    //7. Dao nguoc ky tu cua tung tu trong mot chuoi dai.
    /*char chuoi[50];
    char daonguoc[50]="";
    char temp[50];
    int i=0, j=0, n=0;

    printf("Nhap chuoi: ");
    gets(chuoi);                //Khong khuyen khich dung gets vi no de gay tran bo nho. Dung scanf thi khong in duoc chuoi co dau cach. Dung fgets nho phai co ham xoa dau xuong dong va lenh fflush(stdin) vi no nhan ca dau enter(\n) vao chuoi.
    printf("Chuoi vua nhap: ");
    puts(chuoi);

    n=strlen(chuoi);

    for(i=0; i<n; i++)
    {
        for(j=0; i<n && chuoi[i] != ' '; j++, i++)
            temp[j] = chuoi[i];
        temp[j]='\0';
        ham_dao_chuoi(temp); //Duoc viet truoc ham int main()
        strcat(daonguoc,temp);
        strcat(daonguoc," ");
    }
    printf("Do dai chuoi tren: %d",n);
    printf("\n%s",daonguoc);
    printf("\nHet chuong trinh");*/
    //Chua chay duoc.



    //8. Dao nguoc thu tu tu trong mot chuoi dai.

 

    //Chuoi co ban nhat:
    // char BasicString[]="Toi ten la Duong Nhat Truong";
    // printf("Chuoi don gian: %s\n", BasicString);
    // printf("Ky tu thu 5 trong chuoi: %c\n", BasicString[4]);
    // BasicString[4] = 's';
    // printf("Ky tu do bay gio la: %c\n", BasicString[4]);
    int arr[5];
    for(int i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int a=0; a<4; a++){
        for(int b=a; b<5; b++){
            if(arr[b] < arr[a]){
                int temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
            }
        }
    }
    printf("\nMang sau khi sap xep tang dan:\n");
    for(int i=0; i<5; i++){
        printf("%d\t", arr[i]);
    }
    //system("pause");
    return 0;
}


// Sua thu File tren GitHub
// Co y tao conflict trong File tren GitHub
