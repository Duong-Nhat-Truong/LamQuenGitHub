//BAI TAP 1: Su dung malloc() - calloc() - realloc() - free()


// #include<stdio.h>
// #include<stdlib.h>

// int main()
// { 
//     int n, *ptr;
//     int sum=0;

//     printf("Nhap so phan tu n: ");
//     scanf("%d", &n);
//     ptr = (int*) malloc(n *sizeof(int));
    
//     //Cau lenh thuc hien cap phat luu tru cho n so nguyen. Ham sizeof(int) tra ve 4 byte. Vay cau lenh thuc hien cap phat luu tru cho 4xn (byte). 
//     //Con tro ptr co gia tri la dia chi cua byte du lieu dau tien trong khoi bo nho vua cap phat. 


//     //Ham calloc se cham hon do phai co them buoc "Khoi tao cac o nho bang 0".
//     //ptr = (int*) calloc(n, sizeof(int));
//     //Cau lenh thuc hien cap phat n o nho lien tiep moi o nho co kich thuoc la so byte cua kieu int (4byte).
//     //Con tro chi den dia chi cua byte dau tien trong khoi bo nho vua cap phat.


//     //Ham realloc() thay doi kich thuoc cua bo nho da duoc cap phat.
//     //ptr = (int*) realloc(ptr, n *sizeof(int));
//     //Cap phat vung nho moi co kich thuoc n cho con tro ptr
//     //Trong truong hop phai doi sang vung nho khac, ham realloc() cung se mang theo gia tri da co o vung nho cu sang vung nho moi va giai phong vung nho cu. Khong the tao vung nho no se tra ve NULL


//     if(ptr == NULL)
//     {
//         printf("Co su co!\nCap phat bo nho khong thanh cong!");
//         exit(0);
//     }

//     //Neu khong the cap phat ham malloc tra ve con tro NULL

//     //Neu i=1 thi phai co lenh nay khong thi se bi thieu phan tu trong mang. Do con tro ptr chi den dia chi cua byte du lieu dau tien trong khoi bo nho vua moi cap phat.
//     /*printf("Phan tu dau tien:");
//     scanf("%d", ptr);*/

//     printf("\nNhap cac phan tu trong mang:\n");
//     for(int i=0; i<n; i++)
//     {
//         scanf("%d", ptr + i);
//         sum = sum + *(ptr+i);
//     }

//     printf("Cac phan tu trong mang:\n"); 
//     for(int i=0; i<n; i++)
//         printf("%d\t", *(ptr+i));

//     printf("\nTong cac phan tu trong mang la: %d\n", sum);

//     //Giai phong vung nho cho con tro. Tranh tran bo nho.
//     free(ptr); //Giai phong vung nho cho con tro.
//     printf("Het chuong trinh");   
// }







//BAI TAP 2: Tong hop cap phat dong cho mang 1 chieu.

// #include<stdio.h>
// #include<stdlib.h> //Thu vien cap phat bo nho dong.

// void Nhap_mang(int *arr, int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         printf("arr[%d] = ", i);
//         scanf("%d", (arr+i));
//     }
// }


// void Xuat_mang(int *arr, int n)
// {
//     for(int i=0; i<n; i++)
//         printf("arr[%d] = %d\n", i, *(arr+i));
// }


// void Them_phan_tu(int *arr, int n, int val, int pos)
// {
//     arr = (int*) realloc(arr, (n+1) *sizeof(int));
//     if(pos < 2)
//         pos = 1;
//     else if(pos > n)
//         pos = n+1;
//     for(int i=n; i>(pos-1); i--)
//         *(arr+i) = *(arr+i-1); //Lay gia tri chuyen qua o nho moi mo cho toi khi gap duoc vi tri cua thang kia thi ko lam nua.
//     *(arr + pos - 1) = val;
//     ++n;
// }


// void Xoa_phan_tu(int *arr, int n, int posd)
// {
//     if(n<1)
//         return;
//     if(posd<2)
//         posd=1;
//     else if(posd >= n)
//         posd=n;
//     for(int i=posd; i<n; i++)
//         arr[i-1]=arr[i]; //Lay dia chi cua thang nay gan cho thang kia.
//     arr = (int*) realloc(arr, (n-1)*sizeof(int));
//     --n;
// }

// int main(){
//     int n, i;
//     int *arr;

//     do
//     {
//     printf("Nhap mang so phan tu trong mang: ");
//     scanf("%d", &n);
//     } 
//     while(n<1);

//     arr = (int*) malloc(n *sizeof(int));

//     if(arr == NULL)
//     {
//         printf("Khong the cap phat!");
//         exit(0);
//     }
//     printf("Nhap cac phan tu trong mang:\n");
//     Nhap_mang(arr, n);
//     printf("Mang vua nhap:\n");
//     Xuat_mang(arr, n);
   
//     printf("\n========== THEM PHAN TU ==========\n");
//     int val, pos;
//     printf("Nhap gia tri so can them: ");
//     scanf("%d", &val);
//     printf("\nNhap vi tri muon them vao mang (vi tri dau tien vi tri thu nhat): ");
//     scanf("%d", &pos);
//     Them_phan_tu(arr, n, val, pos);
//     printf("\nMang sau khi them phan tu:\n");
//     Xuat_mang(arr, n+1);

//     printf("\n========== XOA PHAN TU ==========\n");
//     int pos_del;
//     printf("Nhap vi tri muon xoa trong mang (vi tri dau tien trong mang la vi tri thu 1): ");
//     scanf("%d", &pos_del);
//     Xoa_phan_tu(arr, n+1, pos_del);
//     printf("Mang sau khi xoa:\n");
//     Xuat_mang(arr, n);

//     free(arr);
//     printf("\n=== Het chuong trinh! ===\n");

//     system("pause");
//     return 0;
// }






// BAI TAP 3: DUNG CON TRO VA CAP PHAT BO NHO DONG DE COPY - DAO NGUOC MANG 1 CHIEU

// #include<stdio.h>
// #include<stdlib.h>

// int main(){
//     int n, i;
//     do{
//         printf("Nhap vao so phan tu trong mang: ");
//         scanf("%d", &n);
//     }while(n<0);

//     int *p1;
//     p1 = (int*) malloc(n *sizeof(int));
//     if(p1 == NULL){
//         printf("\n---- Khong the cap phat bo nho dong ----\n");
//         exit(0);
//     }
    
//     printf("Nhap cac phan tu trong mang:\n");
//     for(int i=0; i<n; i++){
//         scanf("%d", (p1+i));
//     }

//     printf("Mang co dang:\n");
//         for(int i=n-1; i>=0; i--){
//             printf("%d\n", *(p1+i));
//         }
//     free(p1);
//     return 0;
// }






// BAI TAP 4: Sap xep cac phan tu trong mang

// #include<stdio.h>
// #include<stdlib.h>

// int main(){
//     int n;
//     do{
//         printf("Nhap so luong phan tu: ");
//         scanf("%d", &n);
//     }while(n<0);

//     int *arr;
//     arr = (int*) calloc(n, sizeof(int));
//     if(arr == NULL){
//         printf("--- Khong the cap phat bo nho dong ---");
//         exit(1);
//     }

//     printf("Nhap phan tu trong mang\n");
//     for(int i=0; i<n; i++){
//         scanf("%d", (arr+i));
//     }

//     printf("1. Sap xep mang tang dan\n");
//     printf("2. Sap xep mang giam dan\n");
//     int luachon;
//     do{
//         printf("Nhap lua chon cua ban: ");
//         scanf("%d", &luachon);
//     }while(luachon!=1 && luachon!=2);

//     switch (luachon)
//     {
//     case 1:
//         for(int i=0; i<n-1; i++){
//             for(int j=i; j<n; j++){
//                 if(*(arr+i) > *(arr+j)){
//                     int temp = *(arr+j);
//                     *(arr+j) = *(arr+i);
//                     *(arr+i) = temp;
//                 }
//             }
//         }
//         printf("Mang theo gia tri tang dan:\n");
//         for(int i=0; i<n; i++){
//             printf("%d\t", *(arr+i));
//         }
//         break;
    
//     case 2:
//         for(int i=0; i<n-1; i++){
//             for(int j=i; j<n; j++){
//                 if(*(arr+i) < *(arr+j)){
//                     int temp = *(arr+j);
//                     *(arr+j) = *(arr+i);
//                     *(arr+i) = temp;
//                 }
//             }
//         }
//         printf("Mang theo gia tri tang dan:\n");
//         for(int i=0; i<n; i++){
//             printf("%d\t", *(arr+i));
//         }
//         break;
//     }

//     free(arr);
//     return 0;
// }






// BAI TAP 5: Tinh tong n so

// #include<stdio.h>
// #include<stdlib.h>

// int main(){
//     int n;
//     do{
//         printf("Enter the number of elements in the array: ");
//         scanf("%d", &n);
//     }while(n<1);

//     printf("Enter the elements in the array\n");
//     int *p;
//     p = (int*) malloc(n *sizeof(int));
//     for(int i=0; i<n; i++){
//         scanf("%d", (p+i));
//     }

//     int sum=0;
//     for(int i=0; i<n; i++){
//         sum = sum + *(p+i);
//     }

//     printf("Sum of elements in the array = %d", sum);
//     free(p);
//     return 0;
// }







// BAI TAP 6: Tao mang 2 chieu

// #include<stdio.h>
// #include<stdlib.h>

// int main(){
//     printf("Enter the number of columns of the array: ");
//     int col;
//     scanf("%d", &col);
//     printf("Enter the number of rows of the array: ");
//     int row;
//     scanf("%d", &row);
    
//     printf("Enter the elements of array:\n");
//     int *p;
//     p = (int*) malloc((row*col)*sizeof(int));
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             scanf("%d", (p + i + j));
//         }
//     }

//     printf("2D array:\n");
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             printf("%5d", *(p + i + j));
//         }
//         printf("\n");
//     }
//     free(p);
//     return 0;
// }