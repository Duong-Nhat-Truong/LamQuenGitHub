#include<stdio.h>
#include<stdlib.h>


//DOC - GHI DU LIEU DANG VAN BAN

int main(){
    int n;
    // FILE *fptr1;
    // //Chua co File thi tao, co File roi thi mo
    // fptr1 = fopen("ThaoTacVoiFile.txt", "w"); //Mo File de ghi gia tri vao
    // if(fptr1 == NULL){
    //     printf("Loi tao hoac mo File");
    //     exit(1);
    // }
    // //Ghi vao File
    // printf("Nhap vao n: "); scanf("%d", &n);
    // fprintf(fptr1, "%d\n", n);
    // //Mo xong luong phai nho dong file
    // fclose(fptr1);

    FILE *fptr2;
    //Chua co File thi tao, co File roi thi mo
    fptr2 = fopen("ThaoTacVoiFile.txt", "r"); //Mo File de doc gia tri
    if(fptr2 == NULL){
        printf("Loi tao hoac mo File");
        exit(1);
    }
    //Doc gia tri
    fscanf(fptr2, "%d", &n);
    printf("Gia tri cua m trong read: %d\n", n);

    //Mo xong luong phai nho dong file
    fclose(fptr2);

    printf("\nHet chuong trinh\n");
    return 0;
}


/*
//DOC GHI DU LIEU DANG NHI PHAN

struct NgaySinh{
    int ngay;
    int thang;
    int nam;
};

int main(){
    FILE *fptr1, *fptr2;
    struct NgaySinh day1;
    day1.ngay=15;
    day1.thang=03;
    day1.nam=2001;
    //Tao - mo file Binary
    fptr1 = fopen("ThaoTacVoiFile_NhiPhan.bin", "wb");
    if(fptr1 == NULL){
        printf("Loi tao hoac mo File");
        exit(1);
    }

    fwrite(&day1, sizeof(struct NgaySinh), 1, fptr1);

    //Dong File
    fclose(fptr1);

    fptr2= fopen("ThaoTacVoiFile_NhiPhan.bin", "rb");
    if(fptr2 == NULL){
        printf("Loi tao hoac mo File");
        exit(1);
    }

    fread(&day1, sizeof(struct NgaySinh), 1, fptr2);
    printf("Ban Truong sinh vao ngay %d thang %d nam %d", day1.ngay, day1.thang, day1.nam);

    fclose(fptr2);

    printf("\nHet chuong trinh\n");
    return 0;
}
*/
