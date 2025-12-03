#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h>
int kiemTraSoNguyen(double a) {

	if (a == (int)a) {

		return 0;
	}
	else {
		return 1;
	}

}
int kiemTraSoNguyenTo(int x) {
	int i = 0, dem = 0;
	for (i = 2; i <= (x / 2); i++) {
		if (x % i == 0) {
			dem = 1;
			break;
		}
	}
	if (x < 2) {
		dem = 1;
	}
	return dem;
}
int kiemTraSoChinhPhuong(int x) {
	int i = 0, dem = 1;

	for (i = 1; i < x; i++) {
		if (i * i == x) {
			dem = 0;
			break;
		}
		else {
			dem++;
		}
	}
	return dem;
}
void chucNangSo1() {
	int i = 1;
	double a; //khoi tao ktra so nguyen
	int b; //khoi tao bien chua so nguyen sau khu kiem tra
	printf("+--------------Kiem Tra So Nguyen-----------------+\n");
	printf("Moi ban nhap so: ");
	scanf("%lf", &a);
	//ktra so nguyen
	if (kiemTraSoNguyen(a) == 0) {
		printf("\n%.2lf la so nguyen.\n", a);
		int b = (int)a;
		//ktra SNT
		if (kiemTraSoNguyenTo(b) == 0) {
			printf("so %d la so nguyen to\n", b);
		}
		else {
			printf("so %d khong phai la so nguyen to\n", b);
		}
		//ktra SCP
		if (kiemTraSoChinhPhuong(b) == 0) {
			printf("so %d la so chinh phuong", b);
		}
		else {
			printf("so %d khong phai la so chinh phuong", b);
		}
	}
	else {
		printf("\n%.2lf khong phai la so nguyen\n", a);
		printf("vi so ban vua ban khong phai la so nguyen nen kh the check SNT va SCP!");
	}
}
int timUCLN(int a, int b) {
	/*a = abs(a);
	b = abs(b);*/
	int temp;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void timBCNN(int a, int b) {
	if (a == 0 && b == 0) {
		printf("BCNN cua 2 so %d va %d la Khong xac dinh duoc\n", a, b);
	}
	else if (a == 0 || b == 0) {
		printf("BCNN cua 2 so %d va %d la: 0\n", a, b);
	}
	else {
		printf("BCNN cua 2 so %d va %d la: %d\n", a, b, abs(a * b) / timUCLN(a, b));
	}

}
void chucNangSo2() {
	double soA, soB;
	int a, b, check = 1;
	printf("+--------------UCLN & BCNN-----------------+\n");
	printf("Moi ban nhap so thu nhat: ");
	scanf("%lf", &soA);
	while (kiemTraSoNguyen(soA) == 1) {
		if (check > 3) {
			printf("Ban da nhap sai qua 3 lan!");
			return;
		}
		printf("so ban vua nhap khong phai la so nguyen(sai lan %d)! xin vui long nhap lai: ", check);
		scanf("%lf", &soA);
		check++;

	}
	printf("Moi ban nhap so thu hai: ");
	scanf("%lf", &soB);
	check = 1;
	while (kiemTraSoNguyen(soB) == 1) {
		if (check > 3) {
			printf("Ban da nhap sai qua 3 lan!");
			return;
		}
		printf("so ban vua nhap khong phai la so nguyen(sai lan %d)! xin vui long nhap lai: ", check);
		scanf("%lf", &soB);
		check++;
	}
	a = (int)soA;
	b = (int)soB;
	printf("UCLN cua 2 so %d va %d la: %d\n", a, b, timUCLN(a, b));
	timBCNN(a, b);
}
void chucNangSo2_1() {
	int soA, soB;
	double a, b;
	printf("+--------------UCLN & BCNN-----------------+\n");
	printf("Moi ban nhap so thu nhat: ");
	scanf("%lf", &a);

	printf("Moi ban nhap so thu hai: ");
	scanf("%lf", &b);

	if (kiemTraSoNguyen(a) == 1 || kiemTraSoNguyen(b) == 1) {
		printf("so ban nhap khong phai la so nguyen! Nen kh tinh toan duoc!");
	}
	if (kiemTraSoNguyen(a) == 0 && kiemTraSoNguyen(b) == 0) {
		soA = (int)a;
		soB = (int)b;
		printf("UCLN cua 2 so %d va %d la: %d\n", soA, soB, timUCLN(soA, soB));
		timBCNN(soA, soB);
	}


}
float chuyenDoiGio(int gio, int phut) {
	return gio + (phut / 60.0);
}
float tongTienKaraoke(float gioStart, float gioEnd) {
	const float giaTien1h = 150000, sale30 = 0.7, sale10 = 0.9, gioKhongSale = 3; //cac bien co dinh! sau chu quan muon thay doi gia chi can thay cac bien nay!
	float giaTienSale30 = giaTien1h * sale30;    // 1 gio sau khi sale!
	float tongTien = 0, tongGio;
	tongGio = gioEnd - gioStart;
	if (tongGio <= gioKhongSale) {
		tongTien = tongGio * giaTien1h;
	}
	else {
		tongTien = (gioKhongSale * giaTien1h) + ((tongGio - gioKhongSale) * giaTienSale30);
	}
	if (tongGio >= 14 && tongGio <= 17) {
		tongTien = tongGio * sale10;
	}
	return tongTien;

}
void tinhTienKaraoke() {
	//nhap gio
	int gioStart, phutStart, gioEnd, phutEnd, check = 1;

	printf("+=======================Tinh tien karaoke=======================+\n");
	printf("Moi ban nhap gio bat dau: "); scanf("%d", &gioStart);
	while (gioStart < 12 || gioStart > 23)
	{
		if (check > 3) {
			printf("Ban da nhap sai qua 3 lan!");
			return;
		}
		printf("Quan bat dau tu 12h den 23h! ban da nhap sai(lan %d). Xin vui long nhap lai!", check);
		scanf("%d", &gioStart);
		check++;
	}
	check = 1;
	printf("Moi ban nhap phut bat dau: "); scanf("%d", &phutStart);
	while (phutStart < 0 || phutStart > 59)
	{
		if (check > 3) {
			printf("Ban da nhap sai qua 3 lan!");
			return;
		}
		printf("Phut tu 0 den 59! ban da nhap sai(lan %d). Xin vui long nhap lai!", check);
		scanf("%d", &phutStart);
		check++;
	}
	check = 1;
	printf("Moi ban nhap gio ket thuc: "); scanf("%d", &gioEnd);
	while (gioEnd < 12 || gioEnd > 23 || gioEnd < gioStart)
	{
		if (check > 3) {
			printf("Ban da nhap sai qua 3 lan!");
			return;
		}
		if (gioEnd < gioStart) {
			printf("Gio ket thuc khong the nho hon gio bat dau! ban da nhap sai(lan %d). Xin vui long nhap lai!", check);
		}
		else {
			printf("Quan dong cua luc 23h! ban da nhap sai(lan %d). Xin vui long nhap lai!", check);
		}

		scanf("%d", &gioEnd);
		check++;
	}
	check = 1;
	printf("Moi ban nhap phut ket thuc: "); scanf("%d", &phutEnd);
	while (phutEnd < 0 || phutEnd > 59 || (gioEnd == gioStart && phutStart > phutEnd))
	{

		if (check > 3) {
			printf("Ban da nhap sai qua 3 lan!");
			return;
		}
		if (gioEnd == gioStart && phutStart > phutEnd) {
			printf("Phut ket thuc phai lon hon phut bat dau! ban da nhap sai(lan %d). Xin vui long nhap lai!: \n", check);
		}
		else {
			printf("Phut tu 0 den 59! ban da nhap sai(lan %d). Xin vui long nhap lai!: ", check);
		}

		scanf("%d", &phutEnd);
		check++;
	}


	//tinh toan
	float gioStartDecimal, gioEndDecimal;
	gioStartDecimal = chuyenDoiGio(gioStart, phutStart);
	gioEndDecimal = chuyenDoiGio(gioEnd, phutEnd);
	//printf("%lf    -    %lf     =  %lf\n", gioEndDecimal, gioStartDecimal, gioEndDecimal- gioStartDecimal);
	printf("+=======================Hoa don=======================+\n");
	printf("Gio bat dau : %dh %d \n", gioStart, phutStart);
	printf("Gio ket thuc: %dh %d \n", gioEnd, phutEnd);
	printf("Tong gio    : %.2f h\n", gioEndDecimal - gioStartDecimal);
	printf("Thanh tien  : %.2f VND\n", tongTienKaraoke(gioStartDecimal, gioEndDecimal));

}
void tinhTienDien() {

	double bac1 = 1678, bac2 = 1734, bac3 = 2014, bac4 = 2536, bac5 = 2834, bac6 = 2927;
	double SoDien, GiaDien;

	printf("+==============Tinh tien dien==============+\n");
	printf("nhap so dien la: "); scanf("%lf", &SoDien);
	if (SoDien < 0) {
		printf("so dien ban nhap chua dung xin vui long kiem tra lai");
	}
	else if (SoDien <= 50) {
		GiaDien = SoDien * 50;
	}
	else if (SoDien <= 100) {
		GiaDien = ((SoDien - 50) * bac2) + (bac1 * 50);

	}
	else if (SoDien <= 200) {
		GiaDien = ((SoDien - 100) * bac3) + (bac1 * 50) + (bac2 * 50);

	}
	else if (SoDien <= 300) {
		GiaDien = ((SoDien - 200) * bac4) + (bac1 * 50) + (bac2 * 50) + (bac3 * 100);

	}
	else if (SoDien <= 400) {
		GiaDien = ((SoDien - 300) * bac5) + (bac1 * 50) + (bac2 * 50) + (bac3 * 100) + (bac4 * 100);
	}
	else if (SoDien >= 400) {
		GiaDien = ((SoDien - 400) * bac6) + (bac1 * 50) + (bac2 * 50) + (bac3 * 100) + (bac4 * 100) + (bac5 * 100);
	}
	printf("so dien phai dong la: %.2f d", GiaDien);


}
void doiTien() {
	int i = 1;
	while (i == 1)
	{
		printf("+==============Doi Tien==============+\n");
		printf("Chuc nang doi tien dang bao tri. Xin vui long quay lai sau. Cam on va xin gap lai!\n");
		printf("\nBan co muon tiep tuc dung chac nang nay khong?");
		printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
		scanf("%d", &i);
		system("cls");
	}
	printf("\nDang quay lai Menu trong 1s...............................\n");
	Sleep(1000);
	system("cls");
}
void tinhLaiSuat() {
	int i = 1;
	while (i == 1)
	{
		printf("+==============Tinh Lai Suat==============+\n");
		printf("Chuc Nang Tinh Lai Suat dang bao tri. Xin vui long quay lai sau. Cam on va xin gap lai!\n");
		printf("\nBan co muon tiep tuc dung chac nang nay khong?");
		printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
		scanf("%d", &i);
		system("cls");
	}
	printf("\nDang quay lai Menu trong 1s...............................\n");
	Sleep(1000);
	system("cls");
}
void tienMuaXe() {
	int i = 1;
	while (i == 1)
	{
		printf("+==============Tinh tien mua Xe==============+\n");
		printf("Chuc nang tinh tien xe dang bao tri. Xin vui long quay lai sau. Cam on va xin gap lai!\n");
		printf("\nBan co muon tiep tuc dung chac nang nay khong?");
		printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
		scanf("%d", &i);
		system("cls");
	}
	printf("\nDang quay lai Menu trong 1s...............................\n");
	Sleep(1000);
	system("cls");
}
void sapXepTTSinhVien() {
	int i = 1;
	while (i == 1)
	{
		printf("+==============Sap Xep Thong Tin Sinh Vien==============+\n");
		printf("Chuc nang sap xep thong tin sinh vien dang bao tri. Xin vui long quay lai sau. Cam on va xin gap lai!\n");
		printf("\nBan co muon tiep tuc dung chac nang nay khong?");
		printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
		scanf("%d", &i);
		system("cls");
	}
	printf("\nDang quay lai Menu trong 1s...............................\n");
	Sleep(1000);
	system("cls");
}
void gameFPOLY() {
	int i = 1;
	while (i == 1)
	{
		printf("+==============Game Fpoly==============+\n");
		printf("Chuc nang game Fpoly dang bao tri. Xin vui long quay lai sau. Cam on va xin gap lai!\n");
		printf("\nBan co muon tiep tuc dung chac nang nay khong?");
		printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
		scanf("%d", &i);
		system("cls");
	}
	printf("\nDang quay lai Menu trong 1s...............................\n");
	Sleep(1000);
	system("cls");
}
void tinhToanPhanSo() {
	int i = 1;
	while (i == 1)
	{
		printf("+==============Tinh toan phan so==============+\n");
		printf("Chuc nang tinh toan phan so dang bao tri. Xin vui long quay lai sau. Cam on va xin gap lai!\n");
		printf("\nBan co muon tiep tuc dung chac nang nay khong?");
		printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
		scanf("%d", &i);
		system("cls");
	}
	printf("\nDang quay lai Menu trong 1s...............................\n");
	Sleep(1000);
	system("cls");
}
void lapChucNang(int check) {
	int checkLap = 1;
	int out = 0;
	while (checkLap == 1)
	{
		switch (check)
		{
		case 1://done 90%
			system("cls");
			chucNangSo1(); break;
		case 2://done 90% 
			system("cls");
			chucNangSo2();
			break;
		case 3://done 90%
			system("cls"); 
			tinhTienKaraoke(); 
			break;
		case 4:
			//done 90%
			system("cls"); 
			tinhTienDien();
			break;
		case 5: doiTien(); break;
		case 6: tinhLaiSuat(); break;
		case 7: tienMuaXe(); break;
		case 8: sapXepTTSinhVien(); break;
		case 9: gameFPOLY(); break;
		case 10: tinhToanPhanSo(); break;
		case 0:
			printf("\ncam on ban da su dung chuong trinh! chuc ban mot ngay tot lanh <3\n");
			out = 1;
			break;
		default:
			system("cls");
			printf("\nban da nhap sai! xin vui long kiem tra lai ( dang quay lai menu trong 1s )\n");
			Sleep(1000);
			system("cls");
			break;
		}
		if (out == 1) {
			break;
		}
		printf("\nBan co muon tiep tuc dung chac nang nay khong?");
		printf("moi ban nhap (nhap 1 de tiep tuc | nhap khac so 1 de tro lai menu ) : ");
		scanf("%d", &checkLap);
		if (checkLap != 1) {
			printf("\nDang quay lai Menu trong 1s...............................\n");
			Sleep(1000);
			system("cls");
		}
		system("cls");
	}

}
int main()
{
	int menu;
	int checkSai = 0;
	do
	{
		printf("+----------------------------Menu-------------------------------+\n");
		printf("| 1.  kiem tra so nguyen                                        |\n");
		printf("| 2.  tim uoc so chung va boi so chung cua 2 so                 |\n");
		printf("| 3.  chuong trinh tinh tien cho quan Karaoke                   |\n");
		printf("| 4.  tinh tien dien                                            |\n");
		printf("| 5.  Chuc nang doi tien                                        |\n");
		printf("| 6.  Chuc nang tinh lai suat vay ngan hang, vay tra gop        |\n");
		printf("| 7.  Chuong trinh vay tien mua xe                              |\n");
		printf("| 8.  sap xep thong tin sinh vien                               |\n");
		printf("| 9.  game Fpoly - LOTT                                         |\n");
		printf("| 10. Tinh toan phan So                                         |\n");
		printf("| 0. Thoat                                                      |\n");
		printf("+---------------------------------------------------------------+\n");

		if (checkSai == 1) {
			printf("Ban da nhap sai! Xin vui long nhap lai!\n");
			checkSai = 0;
		}
		printf("\nMoi ban nhap (1,2,3,4,5,6,7,8,9,10,0): ");

		if (scanf("%d", &menu) != 1 || menu < 0 || menu >8) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF)// xoa bo nho dem tranh xay ra vong lap vo tan || clear buffer
			{
			}
			checkSai = 1;
			//menu = -1;
			continue;
		}
		lapChucNang(menu);

	} while (menu != 0);

}

