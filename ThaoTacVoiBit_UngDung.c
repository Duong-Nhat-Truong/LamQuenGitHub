#include<stdio.h>
#include<stdlib.h>

int Tim_So_Xuat_Hien_Mot_Lan(int arr[], int n){
    int XOR=arr[0];
    for(int i=1; i<n; i++){     // A^A=0, B^0=B => A^B^A=B
        XOR=XOR^arr[i];         //arr[0]^arr[1]^arr[2]^arr[3]arr[4]^arr[n-1]
    }
    return XOR;
}

int main(){
    //Neu bieu dien 8 bit thi thu tu cua cac bit la: 7 6 5 4 3 2 1 0
/*  int a=9; // 0000 1001
    int b=30; // 0001 1110
    int i;
    //Thao tac: cho tung day bit bieu dien moi so nam theo "hang ngang - hang", vay nen vi tri thu tu cac bit cua tung day bit duoc nam theo "hang doc - cot" 
    printf("Phep OR giua a va b = %d\n", a|b);          // Cach nho: Trong mot cot co it nhat mot bit 1 thi OR cho ket qua bang 1, con lai bang 0
    printf("Phep AND giua a va b = %d\n", a&b);         //           Trong mot cot tat ca cac bit là 1 thi AND cho ket qua bang 1, con lai bang 0
    printf("Phep XOR giua a va b = %d\n", a^b);         //           Trong mot cot co le bit 1 thi XOR cho ket qua bang 1, con lai bang 0

    //Tinh chat dac biet cua phep XOR: PHAI NHO
    //A ^ A = 0
    //A ^ 0 = A
   
    printf("Phep toan NOT a = %d\n", ~a);       // dao 0 thanh 1, 1 thanh 0
    for(int i=0; i<3; i++)
        printf("Dich sang phai %d bit: %d\n", i, a>>i);     //Dich bao nhieu bit thi them bay nhieu so 0 o ben trai hoac phai tuy vao dich ben nao, 0110 dich sang trai 2 bit -> suy nghi them hai so 0 o ben phai 011000 lay 4 bit cuoi -> ket qua 1000
    for(int i=0; i<3; i++)
        printf("Dich sang trai %d bit: %d\n", i, b<<i);
*/


    //CAC BAI TAP NAY VO CUNG DAC TRUNG HAY NHO LAY
    //BAI TAP 1: KIEM TRA TINH CHAN LE CUA SO NGUYEN
    // So chan thi bit cuoi la 0 nguoc lai neu le thi bit cuoi la 1
/*  int n;
    printf("Nhap vao so nguyen can kiem tra: ");
    scanf("%d", &n);
    if(n&1 == 1)
        printf("%d la so le!\n", n);
    else printf("%d la so chan!\n", n);
*/



    //BAI TAP 2: TIM SO NGUYEN XUAT HIEN DUNG 1 LAN TRONG MANG SO NGUYEN XUAT HIEN 2 LAN
/*  Thực hiện XOR tất cả các phần tử với nhau: 
        2 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4 
    <=> 2 ^ 3 ^ 3 ^ 4 ^ 4 ^ 5 ^ 5 (đổi vị trí cho dễ nhìn) 
    <=> 2 ^ 0 ^ 0 ^ 0 (sử dụng tính chất A ^ A = 0) 
    <=> 2 (sử dụng tính chất A ^ 0 = A)
    <=> hoac A & A = A (phai viet lach them nhieu)
*/
/*  int arr[]={2, 3, 80, 4, 5, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]); //Tinh so phan tu trong mang
    printf("So chi xuat hien 1 lan trong mang la: %d\n", Tim_So_Xuat_Hien_Mot_Lan(arr, n));
*/



    //BAI TAP 3: TRUY CAP BIT
    //Truy cap bit thu i cua so nguyen A.
    //Lay A dich i bit roi dem ket qua AND voi 1, khi do ta se thu duoc gia tri la 0 hoac 1.

    //MINH HOA:   A: 1010 0010  Truy cap bit thu 4
    //Buoc 1: Dich sang phai 4 bit   0000 1010
    //Buoc 2: Cho AND voi 1 (0000 0001) => KQ 0000 0000

    //for(int i=0; i<8; i++)
        //printf("Gia tri cua bit thu %d cua so 10 la %d\n", i, (12>>i)&1);



    //BAI TAP 4: BAT TAT BIT THU N CUA SO NGUYEN A 
    //BAT BIT: Tao mot so voi bit thu i bang 1 sau do OR voi so nguyen A (PHAI NHO: "1 OR voi so nao cung bang 1")

    //MINH HOA: A - 1010 1110 bat bit so 4
    //Buoc 1: Tao ra so co bit 1 o vi tri thu 4: 0001 0000
    //Buoc 2: Cho OR voi A => KQ 1011 1110

    for(int i=0; i<8; i++)
    printf("Bat bit thu %d cua 8 cho ket qua: %d\n", i, (1<<i)|8);


    //TAT BIT: Tao ra so co bit thu i bang 1, sau do phu dinh de tao ra so co bit so 0 o vi tri thu i. Sau do AND voi so A. (PHAI NHO: "0 AND voi so nao cung bang 0")
    
    //MINH HOA: A - 1110 1110 tat bit so 5
    //Buoc 1: Tao so co bit thu 1 o vi tri so 5: 0010 0000
    //Buoc 2: Dao bit de tao ra so co bit 0 o vi tri so 5: 1101 1111
    //Buoc 3: AND voi so A => KQ 1100 1110
    
    for(int i=0; i<8; i++)
        printf("Tat bit thu %d cua 8 cho ket qua: %d\n", i, (~(1<<i))&10);



    //BAI TAP 5: KIEM TRA BIT BAT HAY TAT
    //Tao ra so nguyen co bit 1 o vi tri bit can kiem tra. Sau do AND voi A (bit dang bat thi ket qua khac 0 nguoc lai = 0)

    //MINH HOA: A - 1010 1111 kiem tra bit so 3 la bat hay tat.
    //Buoc 1: Tao ra so co bit 1 o vi tri thu 3: 0000 1000
    //Buoc 2: AND voi so A => 0000 1000 khac 0 (Bat)
    for(int n=0; n<8; n++)
    {
        int a = 10&(1<<n);
        if(a != 0)
            printf("Bit thu %d dang bat\n", n);
        else 
            printf("Bit thu %d dang tat\n", n);
    }



    //BAI TAP 6: LAT BIT (Khong can biet bit do la 0 hay 1)

    //MINH HOA: A 1001 1110 lat bit thu 3
    //Buoc 1: Tao ra so co bit 1 o vi tri thu 3: 0000 1000
    //Buoc 2: XOR voi A => KQ 1001 0110

    for(int i=0; i<8; i++)
        printf("Lat bit thu %d cua 10 ta duoc ket qua: %d\n", i, (1<<i)^10);

    printf("\n=== HET CHUONG TRINH ===\n");
    system("pause");
    return 0;
}