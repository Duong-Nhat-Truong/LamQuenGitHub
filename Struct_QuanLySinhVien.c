#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

struct date{
    int ngay;
    int thang;
    int nam;
};

struct SinhVien{
    char id[5];
    char ten[30];
    char gioitinh[5];
    struct date ngaysinh;
    int tuoi;
    float diem1;
    float diem2;
    float diem3;
    float diemtb;
    char hocluc[10];
    char malop[10];
};

void XoaDauXuongDong(char a[]){
    int lenght = strlen(a);
    if(a[lenght-1] == '\n')
        a[lenght-1] = '\0';
}

void NhapSinhVien(struct SinhVien *sv){
    printf("Nhap ID (xxx): "); scanf("%s", &sv->id); //Ham scanf gap '\n' la dung. Khi nay ky tu '\n' bi day xuong.
    
    printf("Nhap ten sinh vien: "); 
    fflush(stdin); //Xoa cai du lieu con thua o phia tren (la ky tu '\n' hay Enter khi nhap xong ID). Neu khong xoa fgets se nhan ky tu Enter luon.
    fgets(sv->ten, sizeof(sv->ten), stdin);
    XoaDauXuongDong(sv->ten); //Ham fgets tinh ca dau Enter vao chuoi neu khong xoa thi do dai chuoi se bi sai.

    printf("Nhap gioi tinh: ");
    fflush(stdin);
    fgets(sv->gioitinh, sizeof(sv->gioitinh), stdin);
    XoaDauXuongDong(sv->gioitinh);

    printf("Nhap ngay sinh (xx xx xxxx): ");
    scanf("%d%d%d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam); //Dung dau mui ten truy cap vao ngay thang nam thi khong duoc.
    
    printf("Nhap diem Toan: ");
    scanf("%f", &sv->diem1);
    printf("Nhap diem Ly: ");
    scanf("%f", &sv->diem2);
    printf("Nhap diem Hoa: ");
    scanf("%f", &sv->diem3);

    printf("Nhap ma lop (xxxx): ");
    scanf("%s", sv->malop);
}

void InSinhVien(struct SinhVien sv){
    printf("%2s%24s%15s%10d%7d/%02d/%d%15.2f%13.2f%14.2f%13.2f%14s%11s\n", sv.id, sv.ten, sv.gioitinh, sv.tuoi, sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam, sv.diem1, sv.diem2, sv.diem3, sv.diemtb, sv.hocluc, sv.malop);
}

void TinhTuoi(struct SinhVien *sv){
    time_t Time = time(0);
    struct tm *Now = localtime(&Time); 
    int NamHienTai = Now->tm_year+1900;
    sv->tuoi = NamHienTai - sv->ngaysinh.nam; 
}

void DiemTrungBinh(struct SinhVien *sv){
    sv->diemtb = (sv->diem1 + sv->diem2 + sv->diem3)/3;
}

void XepLoai(struct SinhVien *sv){
    if(sv->diemtb > 9)
        strcpy(sv->hocluc, "Xuat Sac");
    else if(sv->diemtb > 8)
        strcpy(sv->hocluc, "Gioi");
    else if(sv->diemtb > 7)
        strcpy(sv->hocluc, "Kha");
    else if(sv->diemtb > 6)
        strcpy(sv->hocluc, "TB");
    else strcpy(sv->hocluc, "Yeu");
}

void CapNhatSinhVien(struct SinhVien *sv){
    NhapSinhVien(sv);
    TinhTuoi(sv);
    DiemTrungBinh(sv);
    XepLoai(sv);
}

void NhapDanhSachSinhVien(struct SinhVien DS[], int *n){
    do{
        printf("Nhap so luong sinh vien: ");
        scanf("%d", n);
    }while(n<0);
    for(int i=0; i<*n; i++){
        printf("Nhap vao sinh vien thu %d\n", i+1);
        CapNhatSinhVien(&DS[i]);
    }
}

void XuatDanhSachSinhVien(struct SinhVien DS[], int n){
    printf("\n================================================================ Quan ly sinh vien ================================================================\n");
    printf("\n%3s%24s%15s%10s%15s%15s%13s%14s%13s%14s%11s\n","ID", "Ho va ten", "Gioi tinh", "Tuoi", "Ngay sinh", "Diem Toan", "Diem Ly", "Diem Hoa", "Diem TB", "Xep Loai", "Ma lop");
    for(int i=0; i<n; i++)
        InSinhVien(DS[i]);
}

float TimMaxDiemTrungBinh(struct SinhVien DS[], int n){
    float max_dtb = DS[0].diemtb;
    for(int i=0; i<n; i++){
        if(max_dtb < DS[i].diemtb)
            max_dtb = DS[i].diemtb;
    }
    return max_dtb;
}

int TimMinTuoi(struct SinhVien DS[], int n){
    int min_tuoi = DS[0].tuoi;
    for(int i=0; i<n; i++){
        if(min_tuoi > DS[i].tuoi)
            min_tuoi = DS[i].tuoi;
    }
    return min_tuoi;
}   

void XuatDanhSachSinhVienXepLoaiGioi(struct SinhVien DS[], int n, char xl[]){
    printf("\n\nDanh sach sinh vien xep loai %s:\n", xl);
    printf("\n%3s%24s%15s%10s%15s%15s%13s%14s%13s%14s%11s\n","ID", "Ho va ten", "Gioi tinh", "Tuoi", "Ngay sinh", "Diem Toan", "Diem Ly", "Diem Hoa", "Diem TB", "Xep Loai", "Ma lop");
    for(int i=0; i<n; i++){
        if(strcmp(DS[i].hocluc, xl) == 0)
            InSinhVien(DS[i]);
    }
}

void XuatDanhSachSinhVienTheoLop(struct SinhVien DS[], int n, char lop[]){
    printf("\n\nDanh sach sinh vien cua lop \"%s\":\n", lop);
    printf("\n%3s%24s%15s%10s%15s%15s%13s%14s%13s%14s%11s\n","ID", "Ho va ten", "Gioi tinh", "Tuoi", "Ngay sinh", "Diem Toan", "Diem Ly", "Diem Hoa", "Diem TB", "Xep Loai", "Ma lop");
    for(int i=0; i<n; i++){
        if(strcmp(DS[i].malop, lop) == 0)
            InSinhVien(DS[i]);
    }
}

void TimKiemSinhVien(struct SinhVien ds[], int n, char name[]){
    printf("\n\nDanh sach sinh vien co tu \"%s\" trong ten\n", name);
    printf("\n%3s%24s%15s%10s%15s%15s%13s%14s%13s%14s%11s\n","ID", "Ho va ten", "Gioi tinh", "Tuoi", "Ngay sinh", "Diem Toan", "Diem Ly", "Diem Hoa", "Diem TB", "Xep Loai", "Ma lop");
    for(int i=0; i<n; i++){
        if(strstr(ds[i].ten, name) != NULL)
            InSinhVien(ds[i]);
    }
}

void SapXepSinhVienTheoTen(struct SinhVien ds[], int n){
    struct SinhVien temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(ds[i].ten, ds[j].ten) > 0){
                temp = ds[j];
                ds[j] = ds[i];
                ds[i] = temp;
            }
    
        }
    }
}

void SapxepSinhVienTheoDTB(struct SinhVien ds[], int n){
    struct SinhVien temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(ds[j].diemtb > ds[i].diemtb){
                temp = ds[j];
                ds[j] = ds[i];
                ds[i] = temp;
            }
    
        }
    }
}

void XoaSinhVienTheoID(struct SinhVien ds[], int *n, char id[]){
    int k=0;
    printf("\n\nDanh sach sau khi xoa sinh vien co ID \"%s\":\n", id);
    for(int i=0; i<*n; i++){
        if(strcmp(ds[i].id, id) == 0){
            for(int j=i; j<*n-1; j++)
                ds[j]=ds[j+1];
                k++;
        }
    }
    if(k == 1)
        *n=*n-1;
    else *n=*n;
}

void ThemSinhVien(struct SinhVien ds[], int *n){
    *n=*n+1;
    CapNhatSinhVien(&ds[*n-1]);
}

int main(){
    struct SinhVien DS[100];
    int n, chon;

    do{
        printf("\n==================== MENU =======================\n");
        printf("\nNhan phim 1: Nhap danh sach sinh vien\n");
        printf("Nhan phim 2: Xuat danh sach sinh vien\n");
        printf("Nhan phim 3: Tim kiem diem trung binh cao nhat\n");
        printf("Nhan phim 4: Tim kiem so tuoi nho nhat\n");
        printf("Nhan phim 5: Danh sach sinh vien theo lop\n");
        printf("Nhan phim 6: Danh sach sinh vien theo hoc luc\n");
        printf("Nhan phim 7: Sinh vien theo diem trung binh\n");
        printf("Nhan phim 8: Sap xep sinh vien theo ten\n");
        printf("Nhan phim 9: Tim kiem sinh vien theo ten\n");
        printf("Nhan phim 10: Xoa sinh vien theo ID\n");
        printf("Nhan phim 11: Them sinh vien vao danh sach\n");
        printf("Nhan phim 0: Thoat\n");
        printf("\n================================================\n");
        scanf("%d", &chon);


        switch(chon){
            case 1:
                NhapDanhSachSinhVien(DS, &n);
                break;
            case 2:
                XuatDanhSachSinhVien(DS, n);
                break;
            case 3:
                printf("\nDiem trung binh cao nhat: %.2f\n", TimMaxDiemTrungBinh(DS, n));
                break;
            case 4:
                printf("\nTuoi thap nhat la: %d\n", TimMinTuoi(DS, n));
                break;
            case 5:
                char lop[10];
                printf("\nNhap ma lop muon xuat danh sach: "); fflush(stdin); fgets(lop, sizeof(lop), stdin); XoaDauXuongDong(lop);
                XuatDanhSachSinhVienTheoLop(DS, n, lop);
                break;
            case 6:
                char xeploai[15];
                printf("\nNhap hoc luc can xuat danh sach (Xuat Sac / Gioi / Kha / TB / Yeu): "); fflush(stdin); fgets(xeploai, sizeof(xeploai), stdin); XoaDauXuongDong(xeploai);
                XuatDanhSachSinhVienXepLoaiGioi(DS, n, xeploai);
                break;
            case 7:
                SapxepSinhVienTheoDTB(DS, n);
                printf("\n\nDanh sach sinh vien theo diem trung binh:\n");
                XuatDanhSachSinhVien(DS, n);
                break;
            case 8:
                SapXepSinhVienTheoTen(DS, n);
                printf("\n\nDanh sach sinh vien theo ten:\n");
                XuatDanhSachSinhVien(DS, n);
                break;
            case 9:
                char tentk[15];
                printf("\nNhap ten sinh vien can tim kiem: "); fflush(stdin); fgets(tentk, sizeof(tentk), stdin); XoaDauXuongDong(tentk);
                TimKiemSinhVien(DS, n, tentk);
                break;
            case 10:
                char id[15];
                printf("\nNhap ID cua sinh vien muon xoa: "); fflush(stdin); fgets(id, sizeof(id), stdin); XoaDauXuongDong(id);
                XoaSinhVienTheoID(DS, &n, id);
                XuatDanhSachSinhVien(DS, n);
                break;
            case 11:
                printf("\nNhap thong tin sinh vien muon them vao danh sach:\n");
                ThemSinhVien(DS, &n);
                break;
        }
    }while(chon!=0);

    printf("\n========== HET CHUONG TRINH ==========\n");
    system("pause");
    return 0;
}