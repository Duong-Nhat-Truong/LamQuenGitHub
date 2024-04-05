#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void chuoi(char st[], int n){
    for(int i=0; i<n; i++){
        if(st[i] == ' ')
            st[i]='_';
    }
}

void xuatchuoi(char st[],int n){
    printf("\n\n%s\n\n",st);
}

void xoachuoi(char st[], int *n){
    for(int i=0; i<*n; i++){
        if(st[i] == ' '){
            printf("co lam \n");
             st[i+1]=st[i];
             *n=*n-1;
        }
    }
}

int main(){
    char st[]="xin chao cac ban";
    int n=strlen(st);
    chuoi(st, n);
    xuatchuoi(st, n);
    xoachuoi(st, &n);
    xuatchuoi(st, n);
    printf("%2s%25s%15s%10s%15s%15s%13s%14s%11s\n","ID", "Ho va ten", "Gioi tinh", "Tuoi", "Ngay sinh", "Diem Toan", "Diem Ly", "Diem Hoa", "Ma lop");
    printf("%3s%24s%15s%10s%15s%15s%13s%14s%11s\n","123","Duong Nhat Truong", "Nam", "20", "15/03/2001","9.75","10.00","9.50", "11A1");
    printf("%3s%24s%15s%10s%15s%15s%13s%14s%11s\n","124","Thai Nguyen Mai Hong","Nu","19","16/05/2002","9.75","10.00","9.50", "11A1");
    printf("%3s%24s%15s%10s%15s%15s%13s%14s%11s\n","124","Tran Thi Diem Quynh","Nu","19","16/05/2002","9.75","10.00","9.50", "11A1");
    printf("\n====== Het chuong trinh ======\n");
    system("pause");
    return 0;
}