#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//De bai: Nhap vao so n, tinh so so 0 giua 2 so mot lon nhat (16 bit)
//Code don so de hieu cach hoat dong truoc, con them con tro thi de nang cap code sau
void chuyendoiBinary(int n, int kichthuoc, int *p){
    while(n>0){
        if(n%2 == 0)
            p[kichthuoc-1] = 0;
        else p[kichthuoc-1] = 1;
        n = n/2;
        kichthuoc = kichthuoc - 1;
    }
    printf("\nDang o chuyendoibinary()");
}

int tinhGap(int kichthuoc, int *p){
    int gap=0, gaptam=0, trangthaibandau=0;
    for(int i=0; i<kichthuoc; i++){
        //printf("\nSo i = %d", i);
        //printf("\np i trong for = %d", p[i]);
        if(p[i] == 1){
            trangthaibandau = 1;    //bat dau dem
            if(gap < gaptam)
                gap = gaptam;
            else gap = gap;
            gaptam = 0;
            //printf("\nMang i khi bang 1 = %d", p[i]);
        }
        else if(p[i] == 0 && trangthaibandau == 1){
            //printf("\nMang i khi bang 1 = %d", p[i]);
            gaptam++;
        }
    }
    //printf("\nGap = %d", gap);
    printf("\nDang o tinhgap()");
    return gap;
}

int xuly(int n){
    int *p = (int*)malloc(16);      //Buoc phai co buoc nay khong la chuong trinh khong chay
    int kichthuoc = 16;
    for(int i=0; i<kichthuoc; i++){
        p[i] = 0;
    }
    if(p==NULL){
        exit(0);
    }
    chuyendoiBinary(n, kichthuoc, p);
    for(int a=0; a<kichthuoc; a++){
        printf("%d", p[a]);
    }
    printf("\nDang o xuly()");
    printf("Gia tri cua Gap la %d:", tinhGap(kichthuoc, p));
    return tinhGap(kichthuoc, p);
}

int main(){
    int n;
    printf("\nNhap vao so can tinh: ");
    scanf("%d", &n);
    printf("\nGap = %d", xuly(n));
    printf("\nHET CHUONG TRINH");
    return 0;
}