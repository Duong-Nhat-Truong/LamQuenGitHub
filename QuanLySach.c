#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Sach{
    char masach[10];
    char tensach[40];
    char tentacgia[40];
    char nhaxuatban[40];
    int namxuatban;
    float giaban;
    int soluong;
    float thanhtien;
    float thueVAT;
    float thanhtoan;
};

void Xoa_Dau_Xuong_Dong_Trong_C(char xoa[]){
    int n=strlen(xoa);
    if(xoa[n-1] == '\n'){
        xoa[n-1] = '\0';
    }
}

void Nhap_Thong_Tin_Sach(struct Sach *ds){
    printf("Nhap ma sach: "); 
    scanf("%s", &ds->masach);

    printf("Nhap ten sach: "); 
    fflush(stdin); 
    fgets(ds->tensach, sizeof(ds->tensach), stdin); 
    Xoa_Dau_Xuong_Dong_Trong_C(ds->tensach);

    printf("Nhap ten tac gia: "); 
    fflush(stdin); 
    fgets(ds->tentacgia, sizeof(ds->tentacgia), stdin); 
    Xoa_Dau_Xuong_Dong_Trong_C(ds->tentacgia);

    printf("Nhap ten nha xuat ban: "); 
    fflush(stdin); 
    fgets(ds->nhaxuatban, sizeof(ds->nhaxuatban), stdin); 
    Xoa_Dau_Xuong_Dong_Trong_C(ds->nhaxuatban);

    printf("Nhap nam xuat ban: ");
    scanf("%d", &ds->namxuatban);

    printf("Nhap gia moi quyen sach: ");
    scanf("%f", &ds->giaban);

    printf("Nhap so luong: ");
    scanf("%d", &ds->soluong);

    printf("Nhap thue VAT cho quyen sach: ");
    scanf("%f", &ds->thueVAT);
}

void Xuat_Thong_Tin_Sach(struct Sach ds){
    printf("%7s%30s%20s%20s%12d%12.0f%12d%12.2f%16.2f%16.2f\n", ds.masach, ds.tensach, ds.tentacgia, ds.nhaxuatban, ds.namxuatban, ds.giaban, ds.soluong, ds.thueVAT, ds.thanhtien, ds.thanhtoan);
}

void Thanh_Tien(struct Sach *ds){
    ds->thanhtien = ds->soluong * ds->giaban;
}

void Thanh_Toan(struct Sach *ds){
    ds->thanhtoan = ds->thanhtien*(1+ds->thueVAT);
}

void Cap_Nhat_Sach(struct Sach *ds){
    //Luc nay truyen vao dia chi cua bien nen trong may ham o duoi khong can co toan tu &.
    Nhap_Thong_Tin_Sach(ds); 
    Thanh_Tien(ds);
    Thanh_Toan(ds);
}

void Nhap_Danh_Sach_Book(struct Sach ds[], int *n){
    do{
        printf("Nhap so loai sach: ");
        scanf("%d", n);
    }while(*n<0);
    for(int i=0; i<*n; i++){
        printf("\nNhap thong tin quyen sach thu %d:\n", i+1);
        Cap_Nhat_Sach(&ds[i]);
    }
}

void Xuat_Danh_Sach_Book(struct Sach ds[], int n){
    printf("%4s%30s%20s%20s%12s%12s%12s%12s%16s%16s\n", "Ma sach", "Ten sach", "Ten tac gia", "Nha xuat ban", "Nam XB", "Gia ban", "So luong", "Thue VAT", "Thanh Tien", "Thanh Toan");
    for(int i=0; i<n; i++)
        Xuat_Thong_Tin_Sach(ds[i]);
}

void Sap_Xep_Nam_XB(struct Sach ds[100], int n){
    struct Sach temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(ds[j].namxuatban > ds[i].namxuatban){
                temp = ds[j];
                ds[j] = ds[i];
                ds[i] = temp;
            }
        }
    }
}

int Thanh_Tien_Max(struct Sach ds[], int n){
    int pos=0;
    int max=ds[0].thanhtoan;
    for(int i=0; i<n; i++){
        if(ds[i].thanhtoan > max){
            pos = i;
            max = ds[i].thanhtoan;
        }
    }
    return pos;
}

int Tong_So_Luong(struct Sach ds[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum = ds[i].soluong + sum;
    }
    return sum;
}

float Tong_Thanh_Tien(struct Sach ds[], int n){
    float sum=0;
    for(int i=0; i<n; i++){
        sum = ds[i].thanhtien + sum;
    }
    return sum;
}

float Tong_Thanh_Toan(struct Sach ds[], int n){
    float sum=0;
    for(int i=0; i<n; i++){
        sum = ds[i].thanhtoan + sum;
    }
    return sum;
}

void Loc_Theo_VAT(struct Sach ds[], int n, float VAT){
    for(int i=0; i<n; i++){
        if(ds[i].thueVAT >= VAT){
            Xuat_Thong_Tin_Sach(ds[i]);
        }
    }
}

void Them_Sach(struct Sach ds[], int *n){
    *n = *n + 1;
    Cap_Nhat_Sach(&ds[*n-1]);
}

void Xoa_Sach_Theo_Ma(struct Sach ds[], int*n, char ma[]){
    int k=0;
    for(int i=0; i<*n; i++){
        if(strcmp(ds[i].masach, ma) == 0){
            for(int j=i; j<*n-1; j++)
                ds[j] = ds[j+1];
            k++;
        }
    }
    if(k == 1)
        *n = *n - 1;
    else *n=*n;   
}

void Ghi_Vao_File(struct Sach ds[], int n){
    char tenfile[30];
    printf("\nNhap ten FILE: ");
    fflush(stdin);
    fgets(tenfile, sizeof(tenfile), stdin);
    Xoa_Dau_Xuong_Dong_Trong_C(tenfile);


    FILE *fptr;
    fptr = fopen(tenfile, "wb");
    if(fptr == NULL){
        printf("\n****** LOI TAO HOAC MO FILE ******\n");
        return;
    }
    fwrite(&n, sizeof(n), 1, fptr);
    for(int i=0; i<n; i++){
        fwrite(&ds[i], sizeof(struct Sach), 1, fptr);
    }
    fclose(fptr);
}

void Doc_Tu_File(struct Sach ds[], int *n){
    char tenfile[30];
    printf("\nNhap ten FILE: ");
    fflush(stdin);
    fgets(tenfile, sizeof(tenfile), stdin);
    Xoa_Dau_Xuong_Dong_Trong_C(tenfile);

    FILE *fptr;
    fptr = fopen(tenfile, "rb");
    if(fptr == NULL){
        printf("\n****** KHONG THE MO FILE ******\n");
        return;
    }
    fread(n, sizeof(*n), 1, fptr);
    for(int i=0; i<*n; i++){
        fread(&ds[i], sizeof(struct Sach), 1, fptr);
    }
    fclose(fptr);
}

int main(){
    struct Sach book[100];
    int n, chon;
    float VAT;
    char masach[10];

    do{
        printf("\n\n================= MENU =================\n");
        printf(" 1. Nhap thong tin sach\n");
        printf(" 2. Hien thi thong tin sach\n");
        printf(" 3. Tong thanh tien truoc thue\n");
        printf(" 4. Tong tien can thanh toan\n");
        printf(" 5. Sap xep sach theo nam xuat ban\n");
        printf(" 6. Thong tin sach co thanh toan lon nhat\n");
        printf(" 7. Hien thi tong so luong sach\n");
        printf(" 8. Loc danh sach sach theo thue VAT\n");
        printf(" 9. Them loai sach vao danh sach\n");
        printf("10. Xoa loai sach ra khoi danh sach\n");
        printf("11. Luu thong tin sach vao File\n");
        printf("12. Doc thong tin sach tu File\n");
        printf(" 0. Thoat\n");
        printf("========================================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);


        switch (chon)
        {
        case 1:
            Nhap_Danh_Sach_Book(book, &n);
            break;
        case 2:
            Xuat_Danh_Sach_Book(book, n);
            break;
        case 3:
            printf("Tong thanh tien truoc thue: %.2f", Tong_Thanh_Tien(book, n));
            break;
        case 4:
            printf("Tong tien can thanh toan: %.2f", Tong_Thanh_Toan(book, n));
            break;
        case 5:
            Sap_Xep_Nam_XB(book, n);
            Xuat_Danh_Sach_Book(book, n); 
            break;
        case 6:
            printf("Thong tin sach co thanh tien cao nhat:\n");
            printf("%4s%30s%20s%20s%12s%12s%12s%12s%16s%16s\n", "Ma sach", "Ten sach", "Ten tac gia", "Nha xuat ban", "Nam XB", "Gia ban", "So luong", "Thue VAT", "Thanh Tien", "Thanh Toan");
            Xuat_Thong_Tin_Sach(book[Thanh_Tien_Max(book, n)]);
            break;
        case 7:
            printf("Tong so luong cac quyen sach: %d", Tong_So_Luong(book, n));
            break;
        case 8:
            printf("Nhap thue VAT can loc: ");
            scanf("%f", &VAT);
            printf("%4s%30s%20s%20s%12s%12s%12s%12s%16s%16s\n", "Ma sach", "Ten sach", "Ten tac gia", "Nha xuat ban", "Nam XB", "Gia ban", "So luong", "Thue VAT", "Thanh Tien", "Thanh Toan");
            Loc_Theo_VAT(book, n, VAT);
            break;
        case 9:
            printf("Nhap thong tin sach muon them:\n");
            Them_Sach(book, &n);
            break;
        case 10:
            printf("Nhap ma sach can xoa: "); 
            fflush(stdin);
            fgets(masach, sizeof(masach), stdin);
            Xoa_Dau_Xuong_Dong_Trong_C(masach);
            Xoa_Sach_Theo_Ma(book, &n, masach);
            break;
        case 11: 
            Ghi_Vao_File(book, n);
            break;
        case 12:
            Doc_Tu_File(book, &n);
            break;
        }
    }while(chon != 0);

    printf("\n======== HET CHUONG TRINH ========\n");
    system("pause");
    return 0;
}

/*
QUI TAC CHUNG CUA BAI TAP QUAN LY
1. Viet struct khai bao tat ca cac thuoc tinh cua doi tuong.
2. Viet ham nhap tung thuoc tinh cua 1 doi tuong.
3. Viet ham xuat tung thuoc tinh cua 1 doi tuong.
4. Viet ham tinh toan thuoc tinh lien quan toi nhau cua doi tuong ma khong the nhap tu ban phim.
5. Viet ham cap nhat thuoc tinh cua 1 doi tuong.
6. Viet ham nhap danh sach cua nhieu doi tuong thong qua viec cap nhat tung doi tuong.
7. Viet ham xuat danh sach cua nhieu doi tuong sau khi da cap nhat tung doi tuong.
8. Viet them ham gi do tu bo du lieu danh sach thi viet.
9. Viet menu cho bai toan.
*/