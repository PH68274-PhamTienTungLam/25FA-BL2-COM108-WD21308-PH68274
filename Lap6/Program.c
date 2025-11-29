#include <stdio.h>
#include <math.h>
void nhapMang1Chieu(int n) {
     int i = 0;
    printf("Moi ban nhap so phan tu trong mang: ");
    scanf("%d", &n);
    int array[100];
    for (i = 0; i < n; i++)
    {
        printf("Moi ban nhap gia tri cua mang a[%d]: ", i);
        scanf("%d", &array[i]);
    }
    printf("Mang ban vua nhap la: \n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, array[i]);
    }


}
void chucNang1() {
    printf("+-----------------------TBC so chia het cho 3 trong mang-------------------------+\n");
    int n, i = 0,dem=0,tong=0;
    printf("Moi ban nhap so phan tu trong mang: ");
    scanf("%d", &n);
    int array[100];
    for (i = 0; i < n; i++)
    {
        printf("Moi ban nhap gia tri cua mang a[%d]: ", i);
        scanf("%d", &array[i]);
    }
    printf("Mang ban vua nhap la: \n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, array[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (array[i] % 3 == 0) {
            dem++;
            tong = tong + array[i];
       }
    }
    printf("trung binh cong cac so chia het cho 3 trong mang la: %d",tong/dem);

    
}
void chucNang2(){
    printf("+-----------------------Tim Min Max-------------------------+\n");
    int n, i = 0, dem = 0, tong = 0;
    printf("Moi ban nhap so phan tu trong mang: ");
    scanf("%d", &n);
    int array[100];
    for (i = 0; i < n; i++)
    {
        printf("Moi ban nhap gia tri cua mang a[%d]: ", i);
        scanf("%d", &array[i]);
    }
    printf("Mang ban vua nhap la: \n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, array[i]);
    }
    int max = array[0];
    int min = array[0];
    for (i = 1; i < n; i++)
    {
        if (array[i] >= max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    printf("phan tu lon nhat trong mang la: %d",max);
    printf("\nphan tu nho nhat trong mang la: %d",min);

}
void chucNang3(){
    printf("+-----------------------sap xep mang-------------------------+\n");
    int n, i = 0, temp;
    printf("Moi ban nhap so phan tu trong mang: ");
    scanf("%d", &n);
    int array[100];
    for (i = 0; i < n; i++)
    {
        printf("Moi ban nhap gia tri cua mang a[%d]: ", i);
        scanf("%d", &array[i]);
    }
    printf("Mang ban vua nhap la: \n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, array[i]);
    }
    //sap xep mang giam dan dung for
    for (i = 0; i < n-1; i++)
    {
        if (array[i] < array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = -1;
        }
    }
    printf("mang da sap xep giam dan la: \n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, array[i]);
    }
    //sap xep mang tang dan dung while
    i = 0;
    while (i < n-1)
    {
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = 0;
        }
        else {
            i++;
        }
    }
    printf("mang da sap xep tang dan la: \n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, array[i]);
    }
}
void chucNang4(){
    printf("Chuc nang Dang bao tri! Xin vui long quay lai sau");
}
void lapChucNang(int check) {
    int checklap = 1;
    while (checklap ==1)
    {
        switch (check)
        {
        case 1:
            system("cls");
            chucNang1();
            break;
        case 2:
            system("cls");
            chucNang2();
            break;
        case 3:
            system("cls");
            chucNang3();
            break;
        case 4:
            system("cls");
            chucNang4();
            break;
        case 0:
            printf("\ncam on ban da su dung chuong trinh! chuc ban mot ngay tot lanh <3\n");
            return;
        default:
            printf("\nban da nhap sai! xin vui long kiem tra lai ( dang quay lai menu trong 1s )\n");
            Sleep(1000);
            system("cls");
            break;
        }
        printf("\nBan co muon tiep tuc dung chac nang nay khong?");
        printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
        scanf("%d", &checklap);
        if (checklap != 1) {
            printf("\nDang quay lai Menu trong 1s...............................\n");
            Sleep(1000);
            system("cls");
        }

    }
}
int main()
{
    int menu;
    int checkSai = 0;
    do
    {
        printf("+-----------------------Lap 6-------------------------+\n");
        printf("| 1. Trung binh cong cac so chia het cho 3 trong mang |\n");
        printf("| 2. Tim Min Max trong mang                           |\n");
        printf("| 3. Bai 3                                            |\n");
        printf("| 4. Bai 4                                            |\n");
        printf("| 0. thoat                                            |\n");
        printf("+-----------------------------------------------------+\n");
        
        if (checkSai == 1) {
            
            printf("\nBan da nhap sai! Xin vui long nhap lai!\n");
            checkSai = 0;
        }
        printf("Moi ban chon(1,2,3,4,0): ");
        if (scanf("%d", &menu) != 1 || menu < 0 || menu >4) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)// xoa bo nho dem tranh xay ra vong lap vo tan || clear buffer
            {
            }
            checkSai = 1;
            //menu = -1;
            system("cls");
            continue;
        }
        lapChucNang(menu);
        
    } while (menu != 0);

}

