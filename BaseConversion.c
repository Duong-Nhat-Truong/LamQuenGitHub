// TAO RA BO CHUYEN DOI GIUA CAC HE

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){

    // DEM ---> BINARY

    // int dec;
    // printf("Enter the Decimal: ");
    // scanf("%d", &dec);

    // //int *p;
    // //p = (int*) malloc(8*sizeof(int)); // MOt SO INT CHIEM 4 BYTE DU LIEU BO NHO, MANG CO 8 PHAN TU KIEU INT VD 0000 0000 (SO 0 NAY LA KIEU INT CAN 4 BYTE DE BIEU DIEN)
    
    // // char *p;
    // // p = (char*) malloc(32*sizeof(char)); // TAO RA CHUOI VD 00000000 00000000 00000000 00000000 CHUOI NAY CAN CAP PHAT DONG 32BYTE BO NHO (TRONG CHUOI THI 0 LA KY TU CA)

    // // TOI UU NHAT
    // int size_binary;
    // size_binary = 8*sizeof(dec); // TAO MOT BIEN KICH THUOC CO 32 BYTE 
    // // KIEU INT (4 BYTE) BIEU DIEN DUOC SO TU -2.147.483.648 DEN 2.147.283.647 (2^31 = 2.147.483.648 MOT BIT BIEU DIEN DAU)
    // // KIEU CHAR CAN 1 BYTE DE BIEU DIEN
    // char *p = (char*) malloc(size_binary); // CAP PHAT DONG MOT CHUOI KY TU CO 32 BYTE (MOI CHAR MOT BYTE)

    // for(int i=0; i<size_binary; i++){
    //     // p[i] = '0';
    //     *(p+i) = '0';
    // }

    // // for(int i=0; i<size_binary; i++){
    // //     // printf("%c", p[i]);
    // //     printf("%c", *(p+i));
    // // }


    // // CACH 1: DE HIEU HOI TON TAI NGUYEN VI PHAI CHAY HET 32 LAN TRONG VONG LAP FOR
    // // int count = 0;
    // // for(int i=size_binary-1; i>=0; i--){
    // //     if(dec%2 != 0){
    // //         p[i] = '1';
    // //     }
    // //     dec = dec/2;
    // //     count = count + 1;
    // // }


    // // CACH 2: HIEU QUA HON
    // int count = 0;
    // int pos = size_binary-1; // CHUOI THI TU TRAI QUA PHAI VD: "TRUONG" PHAN TU THU 2 TRONG CHUOI LA R, VOI BIT THI TU PHAI SAO TRAI 8 BIT DUOC BIEU DIEN VD: 0000 1000 BIT THU 3 LA 1 
    // while(dec>0){
    //     if(dec%2 == 1){
    //         p[pos] = '1';
    //     }
    //     dec = dec/2;
    //     pos = pos - 1;
    //     count = count + 1;
    // }


    // for(int i=0; i<size_binary; i++){
    //     printf("%c", p[i]);
    //     // printf("%c", *(p+i));
    // }

    // printf("\nNumber of times performed: %d", count);
    // free(p);



    // BINARY ---> DEM
    
    // int Dem=0;
    // char *p = (char*) malloc(32*sizeof(char));
    // printf("Enter the Binary: ");
    // gets(p);

    // int lenght = strlen(p); 

    // for(int i=lenght; i>0; i--){
    //     if(p[i-1]%2 == 1){
    //         Dem = Dem + pow(2, lenght-i);
    //     }
    //     else Dem = Dem;
    //     printf("%d %d\n", lenght, i);
    // }

    // printf("Decimal is: %d", Dem);
    // free(p);


    // HEX ---> BIN

    // char *p = (char*) malloc(8*sizeof(char)); // 1 CHU SO HEX CAN 4 SO BINARY DE BIEU DIEN (NAY LAM VIEC 32 BYTE BINARY THOI CHO NHE)
    // printf("Enter the Hexadecimal: ");
    // // scanf("%s", p); // GAP SPACE HAY ENFTER LA DUNG
    // gets(p);

    // int len = strlen(p);

    // printf("Binary is:\n");
    // for(int i=0; i<len; i++){
    //     switch (p[i])
    //     {
    //     case '0':
    //         printf("0000");
    //         break;
    //     case '1':
    //         printf("0001");
    //         break;
    //     case '2':
    //         printf("0010");
    //         break;
    //     case '3':
    //         printf("0011");
    //         break;
    //     case '4':
    //         printf("0100");
    //         break;
    //     case '5':
    //         printf("0101");
    //         break;
    //     case '6':
    //         printf("0110");
    //         break;
    //     case '7':
    //         printf("0111");
    //         break;
    //     case '8':
    //         printf("1000");
    //         break;
    //     case '9':
    //         printf("1001");
    //         break;
    //     case 'A':
    //     case 'a':
    //         printf("1010");
    //         break;
    //     case 'B':
    //     case 'b':
    //         printf("1011");
    //         break;
    //     case 'C':
    //     case 'c':
    //         printf("1100");
    //         break;
    //     case 'D':
    //     case 'd':
    //         printf("1101");
    //         break;
    //     case 'E':
    //     case 'e':
    //         printf("1110");
    //         break;
    //     case 'F':
    //     case 'f':
    //         printf("1111");
    //         break;
    //     case '.':
    //         printf(".");
    //         break;
    //     default:
    //         printf("Binary is: %c\n", p[i]); /// PHONG TRUONG HOP KHONG NHAP GI, NEU NHAP KY TU KHAC THI NO IN RA KY TU DO LUON
    //     }
    // }
    // free(p);


    // BIN ---> HEX

    // THUAT TOAN NAY HIEN TAI PHAI NHAP SO BINARY CO SO PHAN TU CHIA HET CHO 4 THUAT TOAN MOI DUNG

    char *p = (char*) malloc(32*sizeof(char));
    printf("Enter the Binary: ");
    scanf("%s", p);   


    return 0;
}
