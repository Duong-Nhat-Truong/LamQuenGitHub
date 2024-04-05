#include<stdio.h>
#include<stdlib.h>

void NhapMang(int mang[], int *n){
    do{
        printf("\nNhap so luong phan tu: ");
        scanf("%d", n);
    }
    while(n<0);
    
    for(int i=0; i<*n; i++){
        printf("Nhap phan tu x[%d] = ", i);
        scanf("%d", &mang[i]);
    }
}

void XuatMang(int mang[], int n){
    printf("\nCac Phan tu trong mang:\n");
    for(int i=0; i<n; i++){
        printf("Phan tu x[%d] = %d\n", i, mang[i]); 
    }
}

void Write_File(int mang[], int n, char TenFile[]){
    FILE *f;

    f = fopen(TenFile, "w");
    if(f == NULL){
        printf("\nLoi mo file\n");
        return;
    }

  
    fprintf(f, "%d\n", n);
    for(int i=0; i<n; i++){
        fprintf(f, "%d\n", mang[i]); //Xuat don gian
        //fprintf(f, "Phan tu x[%d] = %d\n", i, mang[i]);
    }

    fclose(f);
}

void Read_File(int mang[], int *n, char TenFile[]){
    FILE *f;
    f = fopen(TenFile, "r");
    if(f == NULL){
        printf("\nLoi mo File");
        return;
    }

    fscanf(f, "%d", n);
    for(int i=0; i<*n; i++){
        fscanf(f, "%d", &mang[i]);
    }

    fclose(f);
}

void Read_File_Den_Chet(int mang[], int *n, char TenFile[]){
    FILE *f;
    f = fopen(TenFile, "r");
    if(f == NULL){
        printf("\nLoi mo File");
        return;
    }

    int i=0;
    while(!feof(f)){
        fscanf(f, "%d", &mang[i]);
        i++;
    }

    *n=i-1; //Do ham nhap File co khoang trang o dong cuoi nen khong ghi gia tri nay vao chuoi.

    fclose(f);
}

int main(){
    int mang[100];
    int n;
    // NhapMang(mang, &n);
    // XuatMang(mang, n);

    // Write_File(mang, n, "GhivsDocMang_FileVanBan.txt");

    // Read_File(mang, &n, "GhivsDocMang_FileVanBan.txt");
    // XuatMang(mang, n);
   
    Read_File_Den_Chet(mang, &n, "GhivsDocMang_FileVanBan.txt");
    XuatMang(mang, n);

    printf("\nHet chuong trinh\n");

    system("pause");
    return 0;
}