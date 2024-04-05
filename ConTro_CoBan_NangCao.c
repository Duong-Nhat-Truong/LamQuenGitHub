// NHAP XUAT - XOA THEM MANG DUNG CON TRO
// MANG THI TOAN SO - CHUOI THI TOAN KY TU
// TRONG C KHONG CO THAM CHIEU & VI VAY NEN TAO PROJECT C++ ROI CODE BANG C (KHONG NEN)

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void NhapMang(int* p, int n){
    for(int i=0; i<n; i++){
        printf("Phantu[%d]: ", i);
        scanf("%d", &p[i]);
    }
}

// p <=> &p[0]
// p++ <=> &p[1]
// p[i] <=> *(p + i)

void XuatMang(int* p, int n){
    for(int i=0; i<n; i++){
        printf("%d\t", p[i]);
    }
}

int main(){
    int n;
    do{
        printf("Nhap vao so luong phan tu: ");
        scanf("%d", &n);
    }while(n<0);

    //int* p; // KHAI BAO
    int* p = NULL; // KHUYEN KHICH SU DUNG (KHOI TAO)
    p = (int*) malloc(n *sizeof(int)); // CAP PHAT DONG O VUNG NHO HEAP

    NhapMang(p, n);
    XuatMang(p, n);

    if(p = NULL)
        free(p);
    getch();
    // system("pause");
    // return 0;
}