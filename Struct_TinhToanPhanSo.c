#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>



/*Bai tap 1: Cong tru nhan chia phan so dung Struct.
----------------------********----------------------*/


//========== PHAN KHAI BAO TEN HAM ==========
//Dinh nghia cau truc (khai bao kieu du lieu struct) co ten la "Phanso", Trong cau truc gom 2 thanh phan la "tuso" va "mauso" co kieu du lieu int. 
struct Phanso 
{
    int tuso;
    int mauso;
};

int UCLN(int a, int b); //Muc dich cua ham de tim UCLN rut gon tu mau.
void NhapPhanSo(struct Phanso *ps);
void InPhanSo(struct Phanso ps);
void RutGonPhanSo(struct Phanso *ps);
struct Phanso TongPhanSo(struct Phanso ps1, struct Phanso ps2);
struct Phanso HieuPhanSo(struct Phanso ps1, struct Phanso ps2);
struct Phanso TichPhanSo(struct Phanso ps1, struct Phanso ps2);
struct Phanso ThuongPhanSo(struct Phanso ps1, struct Phanso ps2);

//========== CHUONG TRINH CHINH ==========
int main()
{
    struct Phanso ps1, ps2;
    printf("===== Khai bao phan so thu nhat =====\n");
    NhapPhanSo(&ps1); //Neu ham dinh nghia dau vao la con tro thi khi truyen tham so vao no phai la dia chi.
    printf("\n===== Khai bao phan so thu hai =====\n");
    NhapPhanSo(&ps2);
    printf("\nPhan so thu nhat co dang: ");
    InPhanSo(ps1);
    printf("Phan so thu hai co dang: ");
    InPhanSo(ps2);
    printf("\n===== TINH TOAN PHAN SO =====\n");
    printf("Tong hai phan so la: ");
    InPhanSo(TongPhanSo(ps1, ps2));
    printf("Hieu hai phan so la: ");
    InPhanSo(HieuPhanSo(ps1, ps2));
    printf("Tich hai phan so la: ");
    InPhanSo(TichPhanSo(ps1, ps2));
    printf("Thuong hai phan so la: ");
    InPhanSo(ThuongPhanSo(ps1, ps2));
   
    printf("\n===== HET CHUONG TRINH =====\n");
    system("pause");
    return 0;
}

//========== DINH NGHIA HAM ==========
int UCLN(int a, int b) //Muc dich cua ham de tim UCLN rut gon tu mau.
{
    //Cach 1:
    a=abs(a);
    b=abs(b);
    while(a*b != 0)
    {
        if(a>b)
            a=a%b;
        else
            b=b%a;
    }
    return a+b;

    //Cach 2:
    /*int UCLN=1;
    int i=1;
    while(i<a || i<b)
    {
        if(a%i == 0 && b%i == 0)
        {
            UCLN = i;
            i++;
        }
        else i++;
    }
    return UCLN;*/

}

//Con tro muon truy cap vao cac phan tu trong struct dung dau mui ten, khong phai con tro dung dau cham.
void NhapPhanSo(struct Phanso *ps)
{
    printf("Nhap vao tu so: ");
    scanf("%d", &ps->tuso); 
    do
    {
        printf("Nhap vao mau so: ");
        scanf("%d", &ps->mauso);
    }while(ps->mauso == 0);
}

void InPhanSo(struct Phanso ps)
{
    if(ps.mauso < 0)
    {
        ps.tuso *= -1;
        ps.mauso *= -1;
    }
    RutGonPhanSo(&ps);
    if(ps.mauso == 1)
        printf("%d\n", ps.tuso);
    else
        printf("%d/%d\n", ps.tuso, ps.mauso);
}

void RutGonPhanSo(struct Phanso *ps)
{
    int a = UCLN(ps->tuso, ps->mauso);
    ps->tuso /= a;
    ps->mauso /= a;
}

struct Phanso TongPhanSo(struct Phanso ps1, struct Phanso ps2)
{
    struct Phanso Tong;
    Tong.tuso = ps1.tuso*ps2.mauso + ps2.tuso*ps1.mauso;
    Tong.mauso = ps1.mauso*ps2.mauso;
    return Tong;
}

struct Phanso HieuPhanSo(struct Phanso ps1, struct Phanso ps2)
{
    struct Phanso Hieu;
    Hieu.tuso = ps1.tuso*ps2.mauso - ps2.tuso*ps1.mauso;
    Hieu.mauso = ps1.mauso*ps2.mauso;
    return Hieu;
}

struct Phanso TichPhanSo(struct Phanso ps1, struct Phanso ps2)
{
    struct Phanso Tich;
    Tich.tuso = ps1.tuso*ps2.tuso;
    Tich.mauso = ps1.mauso*ps2.mauso;
    return Tich;
}

struct Phanso ThuongPhanSo(struct Phanso ps1, struct Phanso ps2)
{
    struct Phanso Thuong;
    Thuong.tuso = ps1.tuso*ps2.mauso;
    Thuong.mauso = ps1.mauso*ps2.tuso;
    return Thuong;
}
