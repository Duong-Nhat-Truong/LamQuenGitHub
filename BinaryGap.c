#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void chuyenDoiBinary(int size_binary, char *p, int n);
int tinhGap(int size, char *p);
int xuly(int n);



int main(){
    int n;
    printf("Nhap vao so can tim \"Gap Binary\": ");
    scanf("%d", &n);
    
    printf("\nGia tri Binary Gap: %d", xuly(n));
    
    return 0;
}



void chuyenDoiBinary(int size_binary, char *p, int n){
    int pos = size_binary - 1; // Chuoi/mang la tu trai sang phai nhung bit la tu phai sang trai  VD: "truong" thi arr[2] = u     bit 7 6 5 4 3 2 1 0
    while(n>0){
        if(n%2 == 1){
            p[pos] = '1';
        }
        else p[pos] = '0';
        n=n/2;
        pos=pos-1;
    }
}

int tinhGap(int size, char *p){
    int gap=0, temp_gap=0, trangthai=0;         // So di co "bien trang thai" la de no khong dem so khong 0 dau tien vi du 000010001 neu khong co "bien trang thai" thi gap=4 chu ko phai gap=3 (bang 3 moi dung)
    for(int i=0; i<size; i++){
        if(p[i] == '1'){            // Neu gap so 1 thi tien hanh cap nhat bien gap va rest bien temp_gap de dem tiep
            if(trangthai++){
                if(temp_gap > gap){
                gap = temp_gap;
            }
            else gap=gap;
            
            temp_gap = 0;
            }
        }
        else if(trangthai)
            temp_gap++;
    }
    return gap;
}

int xuly(int n){
    int size_binary = (sizeof(n)*8); // 4*8 = 32 byte
    char *p = (char*)malloc(size_binary);
    if(p == NULL){
        exit(0);
    }

    memset(p, '0', size_binary); // ham tu thu vien string: tao ra mot chuoi voi ky tu '0' co kich thuoc size_binary gan vao con tro p (chuoi p co size_binary phan tu 0)

    chuyenDoiBinary(size_binary, p, n);

    for(int i=0; i<size_binary; i++){
        printf("%c", p[i]);
    }
    return tinhGap(size_binary, p);
}