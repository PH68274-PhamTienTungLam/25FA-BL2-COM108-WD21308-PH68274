#define PI 3.14159
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void TinhToanCoBan() {

	//tong hieu 2 so
	double soThuc, soThuc2, Tong, Hieu, Tich, Thuong;

	printf("nhap so Thu nhat: ");
	scanf("%lf", &soThuc);
	/*scanf_s("%d", &a);*/
	printf("nhap so so Thu hai: ");
	scanf("%lf", &soThuc2);
	/*scanf_s("%d", &b);*/
	Tong = soThuc + soThuc2;
	Hieu = soThuc - soThuc2;
	Tich = soThuc * soThuc2;
	printf("Tong 2 so %lf va %lf la: %.2lf", soThuc, soThuc2, Tong);
	printf("\nHieu 2 so %lf va %lf la: %.2lf", soThuc, soThuc2, Hieu);
	printf("\nTich 2 so %lf va %lf la: %.2lf", soThuc, soThuc2, Tich);
	if (soThuc2 == 0) {
		printf("\nkhong the thuc hien phep chia (khong the chia 1 so cho so 0, so chia phai khac 0)");
	}
	else {
		Thuong = soThuc / soThuc2;
		printf("\nThuong 2 so %lf va %lf la: %.2lf", soThuc, soThuc2, Thuong);
	}

}
void TinhHcn() {
	//chu vi dien tich hcn
	double chieuDai, chieuRong, chuVihcn, dienTichHcn;

	printf("\nnhap chieu dai: ");
	scanf("%lf", &chieuDai);
	printf("nhap chieu rong: ");
	scanf("%lf", &chieuRong);
	chuVihcn = (chieuDai + chieuRong) * 2;
	dienTichHcn = chieuDai * chieuRong;
	printf("chu vi hcn la: %.2lf", chuVihcn);
	printf("\ndiet tich hcn la: %.2lf", dienTichHcn);


}
void TinhHt() {
	//chu vi dien tich hinh tron
	double banKinh, Cht, Sht;


	printf("\nnhap ban kinh hinh tron: ");
	scanf("%lf", &banKinh);
	Cht = 2 * PI * banKinh;
	Sht = PI * pow(banKinh, 2);
	printf("chu vi hinh tron la: %.2lf", Cht);
	printf("\ndien tich hinh tron la: %.2lf", Sht);


}
void TinhTrungBinh() {
	//diem trung binh 3 diem toan, van, hoa
	double	Toan, Van, Hoa, Dtb;
	printf("\nnhap diem Toan: "); scanf("%lf", &Toan);
	printf("nhap diem Van: "); scanf("%lf", &Van);
	printf("nhap diem Anh: "); scanf("%lf", &Hoa);
	Dtb = ((Toan * 3) + (Van * 2) + (Hoa * 1)) / 3;
	printf("diem trung binh la: %.2lf", Dtb);
}
void checkSoNguyen() {
	int so;

	printf("moi nhap vao so de kiem tra: ");
	scanf("%d", &so);
	if (so % 2 == 0) {
		printf("so %d la so chan\n", so);
	}
	else {
		printf("so %d la so le\n", so);
	}


	/*if (so & 1 == 1) {
		printf("so %d la so le\n", so);
	}
	else {
		printf("so %d la so chan\n", so);
	}*/
}
void bangCuuChuong() {
	int i, k = 1;
	for (i = 0; i <= 10; i++) {
		if (i == 0) {
			continue;
		}
		printf("%d x %d = %d\n", i, k, k * i);
		if (k < 9 && i == 10) {
			k++;
			i = 0;
		}
	}
}
void inBangCuuChuong39() {
	int i, k = 3;
	for (i = 0; i <= 10; i++) {
		if (i == 0) {
			continue;
		}
		printf("%d x %d = %d\n", i, k, k * i);
		if (k < 9 && i == 10) {
			k += 6;
			i = 0;
		}
	}

}
void demoMang1Chieu() {
	int n, i = 0;
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
void minMaxMang1chieu() {
	int n, i = 0, min, max;
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
	min = array[0];
	max = array[0];
	for (i = 0; i < n; i++)
	{
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}
	printf("so lon nhat trong mang la: %d\n", max);
	printf("so nho nhat trong mang la: %d", min);

}
void sapXepMang1chieu() {
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

	for (i = 0; i < n - 1; i++)
	{
		if (array[i] > array[i + 1]) {
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i = -1;
		}
	}
	printf("Mang ban vua sap xep tang dan la: \n");
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n", i, array[i]);
	}
	printf("Mang ban vua sap xep giam dan la: \n");
	for (i = n - 1; i > -1; i--)
	{
		printf("a[%d] = %d\n", i, array[i]);
	}
}
void demoMang2Chieu() {
	int n, m, i = 0, j = 0;
	printf("Moi ban nhap so dong trong mang: ");
	scanf("%d", &n);
	printf("Moi ban nhap so cot trong mang: ");
	scanf("%d", &m);
	int array[100][100];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("Moi ban nhap gia tri cua mang array[%d][%d]: ", i, j);
			scanf("%d", &array[i][j]);
		}
	}
	printf("Mang ban vua nhap la: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}

}
void hinhMang2Chieu() {
	int n, i = 0, j = 0;
	printf("Moi ban nhap chieu cao: ");
	scanf("%d", &n);

	int array[100][100];

	//tam giac vuong goc trai
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("* ");

		}
		printf("\n");
	}
	//tam giac vuong goc phai
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			printf("  ");  //2 khoang cach
		}
		for (j = 0; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	//tam giac can cong thuc 2*i-1
	printf("\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++) {
			printf(" ");
		}
		for (j = 1; j <= 2 * i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	//tam giac can 1 khoang cach
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			printf(" ");  //2 khoang cach
		}
		for (j = 0; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	


}
void demoMangKyTu() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);   // xoa ky tu con thua
	char mangKyTu[50];
	printf("Nhap 1 dong: ");
	fgets(mangKyTu, sizeof(mangKyTu), stdin); // đọc cả khoảng trắng
	// Loại bỏ ký tự newline nếu có
	size_t len = strlen(mangKyTu);
	if (len > 0 && mangKyTu[len - 1] == '\n') {
		mangKyTu[len - 1] = '\0';
	}
	printf("Ban vua nhap: %s", mangKyTu);
}
void lapChucNang(int check) {
	int i = 1;
	while (i == 1) {
		switch (check) {
		case 1:
			/*int check;
			do
			{
				system("cls");
				TinhToanCoBan();
				printf("\nBan co muon tiep tuc dung chac nang nay khong?");
				printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
				scanf("%d", &check);
			} while (check == 1);*/
			system("cls");
			TinhToanCoBan();

			break;
		case 2:
			/*int check;
			do
			{
				system("cls");
				TinhHcn();
				printf("\nBan co muon tiep tuc dung chac nang nay khong?");
				printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
				scanf("%d", &check);
			} while (check == 1);*/
			system("cls");
			TinhHcn();

			break;
		case 3:
			/*int check;
			do
			{
				system("cls");
				TinhHt();
				printf("\nBan co muon tiep tuc dung chac nang nay khong?");
				printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
				scanf("%d", &check);
			} while (check == 1);*/
			system("cls");
			TinhHt();
			break;
		case 4:
			/*int check;
			do
			{
				system("cls");
				TinhTrungBinh();
				printf("\nBan co muon tiep tuc dung chac nang nay khong?");
				printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
				scanf("%d", &check);
			} while (check == 1);*/
			system("cls");
			TinhTrungBinh();
			break;
		case 5:
			/*int check;
			do
			{
				system("cls");
				checkSoNguyen();
				printf("\nBan co muon tiep tuc dung chac nang nay khong?");
				printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
				scanf("%d", &check);
			} while (check == 1);*/
			system("cls");
			checkSoNguyen();
			break;
		case 6:
			/*int check;
			do
			{
				system("cls");
				checkSoNguyen();
				printf("\nBan co muon tiep tuc dung chac nang nay khong?");
				printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
				scanf("%d", &check);
			} while (check == 1);*/
			system("cls");
			bangCuuChuong();
			break;
		case 7:
			/*int check;
			do
			{
				system("cls");
				checkSoNguyen();
				printf("\nBan co muon tiep tuc dung chac nang nay khong?");
				printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
				scanf("%d", &check);
			} while (check == 1);*/
			system("cls");
			inBangCuuChuong39();
			break;
		case 8:
			system("cls");
			demoMang1Chieu();
			break;
		case 9:
			system("cls");
			minMaxMang1chieu();
			break;
		case 10:
			system("cls");
			sapXepMang1chieu();
			break;
		case 11:
			system("cls");
			demoMang2Chieu();
			break;
		case 12:
			system("cls");
			hinhMang2Chieu();
			break;
		case 13:
			system("cls");
			demoMangKyTu();
			break;
		case 0:
			printf("Cam on ban da su dung chuong trinh, tam biet va chuc ban mot ngay tot lanh!");
			exit(1);
			break;
			//return;
			//exit(1);
		default:
			printf("Ban nhap sai, xin vui kiem tra lai\n");
			break;
		}
		printf("\nBan co muon tiep tuc dung chac nang nay khong?");
		printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
		scanf("%d", &i);
		system("cls");
	}
}

int main()
{
	//TinhToanCoBan();
	//TinhHcn();
	//TinhHt();
	//TinhTrungBinh();
	//checkSoNguyen();
	int menu;
	int checkSai = 0;
	do {
		printf("+----------------------------------------------+\n");
		printf("|  1.  Tinh toan co ban                        |\n");
		printf("|  2.  Tinh chu vi dien tich hinh chu nhat     |\n");
		printf("|  3.  tinh chu vi dien tich hinh tron         |\n");
		printf("|  4.  Tinh trung binh                         |\n");
		printf("|  5.  kiem tra so chan, so le                 |\n");
		printf("|  6.  Bang Cuu Chuong                         |\n");
		printf("|  7.  Bang Cuu Chuong 3 va 9                  |\n");
		printf("|  8.  Demo mang 1 chieu                       |\n");
		printf("|  9.  tim min max mang 1 chieu                |\n");
		printf("|  10. sap xep mang 1 chieu                    |\n");
		printf("|  11. Demo mang 2 chieu                       |\n");
		printf("|  12. Hinh mang 2 chieu                       |\n");
		printf("|  13. Demo mang ky tu                         |\n");
		printf("|  0. thoat                                    |\n");
		printf("+----------------------------------------------+\n");
		if (checkSai == 1) {
			printf("Ban da nhap sai! Xin vui long nhap lai!\n");
			checkSai = 0;
		}
		printf("Moi ban chon (1,2,3,4,5,6,7,8,9,10,11,12,13,0): ");
		if (scanf("%d", &menu) != 1 || menu < 0 || menu >13) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF)// xoa bo nho dem tranh xay ra vong lap vo tan || clear buffer
			{
			}
			checkSai = 1;
			//menu = -1;
			continue;
		}
		system("cls");
		lapChucNang(menu);
	} while (menu != 0);
	return 0;
}

