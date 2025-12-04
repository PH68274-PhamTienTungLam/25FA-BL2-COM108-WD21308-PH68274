#define  _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
void chucNangSo2_1() {//cho nguoi dung nhap tien, luc in ra kq bao loi!
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
		printf("Quan bat dau tu 12h den 23h! ban da nhap sai(lan %d). Xin vui long nhap lai!: ", check);
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
		printf("Phut tu 0 den 59! ban da nhap sai(lan %d). Xin vui long nhap lai!: ", check);
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
			printf("Gio ket thuc khong the nho hon gio bat dau! ban da nhap sai(lan %d). Xin vui long nhap lai!: ", check);
		}
		else {
			printf("Quan dong cua luc 23h! ban da nhap sai(lan %d). Xin vui long nhap lai!: ", check);
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
		printf("so dien ban nhap chua dung xin vui long kiem tra lai!");
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

	printf("+==============Doi Tien==============+\n");
	int menhGia[] = { 500,200,100,50,20,10,5,2,1 };
	int lengmenhGia, soLuong, soTien, i,soTienBanDau;
	double checkSoTien;
	int checkEror = 1;
	printf("Moi ban nhap so tien: ");
	scanf("%lf", &checkSoTien);
	while (kiemTraSoNguyen(checkSoTien)==1 ) {
		if (checkEror > 3) {
			printf("Ban da nhap sai qua 3 lan!");
			return;
		}
		printf("so tien ban vua nhap khong phai la so nguyen(sai lan %d)! xin vui long nhap lai: ", checkEror);
		scanf("%lf", &checkSoTien);
		checkEror++;
	}
	soTien = (int)checkSoTien;
	lengmenhGia = sizeof(menhGia) / sizeof(menhGia[0]);
	//for (i = 0; i < lengmenhGia; i++) {           // kiem tra so tien can kiem tra co bang menh gia khong
	//	if (soTien == menhGia[i]) {
	//		check = i;							//lay vi tri menh gia trung voi so tien can kiem tra
	//		break;
	//	}
	//}
	soTienBanDau = soTien;
	printf("+---------KET QUA DOI TIEN-----------+\n");
	printf("| %-10s | %-21s |\n","So Luong","Menh Gia");
	printf("+------------+-----------------------+\n");
	for (i = 0; i < lengmenhGia; i++) {
		if (soTienBanDau == menhGia[i]) {
			continue;
		}
 		if (soTien >= menhGia[i]) {
			soLuong = soTien / menhGia[i];
			if (soLuong > 0) {
				printf("| %-10d | %-21d |\n", soLuong, menhGia[i]);
				
			}
			soTien = soTien % menhGia[i];
		}
	}
	printf("+------------+-----------------------+\n");
}
void tinhLaiSuat() {
	printf("+==============Tinh Lai Suat==============+\n");
	float soTienVay, soTienLai, soTienGocPhaiTra, tongTien;
	const int kyHan = 12;
	const float laiSuat = 0.05;  // 5%
	int i = 0;
	printf("Moi ban nhap so tien ban muon vay: ");
	scanf("%f",&soTienVay);
	if (soTienVay < 0) {
		printf("So tien vay khong the la so am!");
		return;
	}
	soTienGocPhaiTra = soTienVay / kyHan;
	printf("+-------------------------Bang Lai Suat 12T---------------------------------+\n");
	printf("| Ky Han | Lai Phai Tra | Goc phai tra | So tien phai tra | So tien con lai |\n");
	printf("|--------|--------------|--------------|------------------|-----------------|\n");
	//8 14 14 18 17
	for ( i = 1; i <= kyHan; i++)
	{
		soTienLai = soTienVay * laiSuat;
		tongTien = soTienLai + soTienGocPhaiTra;
		soTienVay = soTienVay - soTienGocPhaiTra;
		if (soTienVay < 0) {
			soTienVay = 0;
		}
		printf("|%8d|%14.2f|%14.2f|%18.2f|%17.2f|\n",i,soTienLai,soTienGocPhaiTra,tongTien,soTienVay);
	}
	printf("|--------|--------------|--------------|------------------|-----------------|");

}
void tienMuaXe() {
	printf("+==============Tinh tien mua Xe==============+\n");
	double soTienLai, soTienGocPhaiTra, tongTien,phanTramVay,giaXe,lanDauTra,duNo;
	const int kyHanNam = 24;
	const int kyHanThang = kyHanNam*12;
	const double laiSuatNam = 0.072;  // 7.2%
	const double laiSuatThang = laiSuatNam/12;  // 7.2%/12 = 0.06
	const double soTienVay = 500000000;
	int i = 0;
	printf("Moi ban nhap so %% ban muon vay: ");
	scanf("%lf", &phanTramVay);
	if (phanTramVay <= 0 || phanTramVay >100) {
		printf("So %% vay Phai lon hon 0 va nho hon 101!");
		return;
	}
	giaXe = soTienVay / (phanTramVay / 100);
	lanDauTra = giaXe - soTienVay;
	soTienGocPhaiTra = soTienVay / kyHanThang;
	duNo = soTienVay;
	printf("Thong Tin Ho So:\n");
	printf("So tien vay co dinh: %.0f\n",soTienVay);
	printf("Ty le vay: %.1f%%\n", phanTramVay);
	printf("Gia Tri cua xe: %.0f VND\n", giaXe);
	printf("So tien phai tra lan dau la: %.0f VND\n", lanDauTra);
	printf("+--------------------------Bang Lai Suat -----------------------------------+\n");
	printf("| Ky Han | Lai Phai Tra | Goc phai tra | So tien phai tra | So tien con lai |\n");
	printf("|--------|--------------|--------------|------------------|-----------------|\n");
	//8 14 14 18 17
	for (i = 1; i <= kyHanThang; i++)
	{
		soTienLai = duNo * laiSuatThang;
		tongTien = soTienGocPhaiTra + soTienLai;
		duNo = duNo - soTienGocPhaiTra;
		if (duNo < 0) {
			duNo = 0;
		}
		printf("|%8d|%14.2f|%14.2f|%18.2f|%17.2f|\n", i, soTienLai, soTienGocPhaiTra, tongTien, duNo);
	}
	printf("|--------|--------------|--------------|------------------|-----------------|");
}
struct sinhVien
{
	char hoTen[100];
	double diem;
	char hocLuc[100];
};
typedef struct sinhVien sV;
void xepLoaiSV(sV *sv) {
	if (sv->diem >= 9.0) {
		strcpy(sv->hocLuc, "Xuat sac");
	}
	else if (sv->diem >= 8.0) {
		strcpy(sv->hocLuc, "Gioi");
	}
	else if (sv->diem >= 6.5) {
		strcpy(sv->hocLuc, "Kha");
	}
	else if (sv->diem >= 5.0) {
		strcpy(sv->hocLuc, "Trung binh");
	}
	else {
		strcpy(sv->hocLuc, "Yeu");
	}
}
void xoaBoNhoDem() {
	
	while (getchar() != '\n' && getchar() != EOF);
}
void hoanDoi(sV* a, sV* b) {
	sV temp = *a;
	*a = *b;
	*b = temp;
}

void sapXepTTSinhVien() {
	sV ds[100];
	printf("+==============Sap Xep Thong Tin Sinh Vien==============+\n");
	int i = 0, n;
	printf("Moi ban nhap so luong sinh vien can nhap: ");
	scanf("%d", &n);
	int check = 0;
	while(n < 1)
	{
		if (check > 3) {
			printf("ban nhap sai qua 3 lan!");
			return;
		}
		check++;
		printf("So luong sinh vien phai lon hon 1! (sai lan %d) Xin vui long nhap lai: ",check);
		scanf("%d",&n);
	}
	for (i = 0; i < n; i++) {
		printf("nhap thong tin sinh vien thu %d: \n", i + 1);
		printf("Ho va Ten: ");
		xoaBoNhoDem();
		fgets(ds[i].hoTen, 100, stdin);
		ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = 0;
		printf("Diem: ");
		scanf("%lf", &ds[i].diem);
		xepLoaiSV(&ds[i]);
	}
	for (i = 0; i < n-1; i++) {
		if (ds[i].diem < ds[i + 1].diem) {
			hoanDoi(&ds[i], &ds[i + 1]);
			i = -1;
		}
		
	}
	printf("--------------------------------------------------------\n");
	printf("| %-25s | %-10s |%-13s|\n", "Ho va Ten", "Diem", "Hoc Luc");
	printf("--------------------------------------------------\n");
	for (i = 0; i < n; i++) {
		printf("| %-25s | %-10.1lf |%-13s|\n",ds[i].hoTen,ds[i].diem,ds[i].hocLuc);
	}
	printf("--------------------------------------------------------\n");

}
void gameFPOLY() {

	printf("+==============Game Fpoly==============+\n");
	int so1, so2, kq1, kq2,dem=0,check=1;
	printf("Moi ban nhap so dau tien: ");
	scanf("%d",&so1);
	while (so1 < 0 || so1 >15) {
		if (check > 3) {
			printf("Ban da nhap sai 3 lan!");
			return;
		}
		printf("Ban da nhap sai (lan %d )! Vui long chon so tu 0 den 15! Xin vui long nhap lai: ",check);
		scanf("%d",&so1);
		check++;
	}
	check = 1;
	printf("moi ban nhap so thu 2: ");
	scanf("%d",&so2);
	while (so2 < 0 || so2 >15) {
		if (check > 3) {
			printf("Ban da nhap sai 3 lan!");
			return;
		}
		printf("Ban da nhap sai (lan %d )! Vui long chon so tu 0 den 15! Xin vui long nhap lai: ", check);
		scanf("%d", &so2);
		check++;
	}
	srand(time(0));
	kq1 = rand() % 15 + 1;
	kq2 = rand() % 15 + 1;
	printf("Chung toi dang tim ra 2 con so may man. Xin vui long cho 1 giay. Xin cam on!\n");
	Sleep(1000);
	printf("2 so may man la: %d va %d\n", kq1,kq2);
	if (so1 == kq1 || so1 == kq2) {
		dem++;
	}
	if (so2 == kq1 || so2 == kq2) {
		dem++;
	}
	if (dem == 2) {
		printf("chuc minh ban da trung giai nhat!");
	}
	else if (dem == 1) {
		printf("chuc minh ban da trung giai nhi!");
	}
	else {
		printf("Chuc ban may man lan sau!");
	}

}
struct phanSo
{
	int tu;
	int mau;
};
typedef struct phanSo ps;
void rutGonPS(ps *a) {
	int ucln = timUCLN(a->tu, a->mau);
	a->tu = a->tu / ucln;
	a->mau = a->mau / ucln;
	if (a->mau < 0) {
		a->tu = -a->tu;
		a->mau = -a->mau;
	}
}
void nhapPS(ps *a) {
	printf("nhap tu so: ");
	scanf("%d",&a->tu);
	printf("nhap mau so: ");
	scanf("%d", &a->mau);
	int check = 0;
	while (a->mau == 0) {
		if (check >=3) {
			printf("ban dan nhap sai qua 3 lan!");
			return;
			//exit(0);
		}
		check++;
		printf("mau so phai khac 0 (sai lan %d )! xin vui long nhap lai: ",check);
		scanf("%d",&a->mau);
		
	}

}
void xuatPS(ps a) {
	rutGonPS(&a);
	if (a.mau == 1) {
		printf("%d",a.tu);
	}
	else if (a.tu == 0) {
		printf("0");
	}
	else {
		printf("%d/%d",a.tu,a.mau);
	}
}
ps tong(ps a,ps b) {
	ps kq;
	kq.tu = (a.tu * b.mau) + (b.tu * a.mau);
	kq.mau = a.mau * b.mau;
	rutGonPS(&kq);
	return kq;
}
ps hieu(ps a, ps b) {
	ps kq;
	kq.tu = (a.tu * b.mau) - (b.tu * a.mau);
	kq.mau = a.mau * b.mau;
	rutGonPS(&kq);
	return kq;
}
ps tich(ps a, ps b) {
	ps kq;
	kq.tu = a.tu * b.tu;
	kq.mau = a.mau * b.mau;
	rutGonPS(&kq);
	return kq;
}
ps thuong(ps a, ps b) {
	ps kq;
	kq.tu = a.tu * b.mau;
	kq.mau = a.mau * b.tu;
	rutGonPS(&kq);
	return kq;
}
void tinhToanPhanSo() {

	printf("+==============Tinh toan phan so==============+\n");
	ps ps1, ps2, kq;
	printf("Moi nhap phan so thu 1: \n");
	nhapPS(&ps1);
	printf("Moi nhap phan so thu 2: \n");
	nhapPS(&ps2);
	printf("Tong cua hai phan so: "); xuatPS(ps1); printf(" + ");  xuatPS(ps2); printf(" = "); xuatPS(tong(ps1,ps2)); printf("\n");
	printf("Hieu cua hai phan so: "); xuatPS(ps1); printf(" + ");  xuatPS(ps2); printf(" = "); xuatPS(hieu(ps1,ps2)); printf("\n");
	printf("Tich cua hai phan so: "); xuatPS(ps1); printf(" + ");  xuatPS(ps2); printf(" = "); xuatPS(tich(ps1,ps2)); printf("\n");
	printf("Thuong cua hai phan so: "); xuatPS(ps1); printf(" + ");  xuatPS(ps2); printf(" = "); xuatPS(thuong(ps1,ps2)); printf("\n");
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
		case 5:
			//done 90%
			system("cls");
			doiTien();
			break;
		case 6:
			//done 90%
			system("cls");
			tinhLaiSuat();
			break;
		case 7:
			//done 90%
			system("cls");
			tienMuaXe();
			break;
		case 8:
			// chua co kiem tra nguoi dung nhap vao!
			system("cls");
			sapXepTTSinhVien();
			break;
		case 9:
			//done 90%
			system("cls");
			gameFPOLY();
			break;
		case 10:
			//done 90% chua kiem tra triet de mau so = 0
			system("cls");
			tinhToanPhanSo();
			break;
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
		system("cls");
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
		printf("| 0.  Thoat                                                     |\n");
		printf("+---------------------------------------------------------------+\n");

		if (checkSai == 1) {
			printf("Ban da nhap sai! Xin vui long nhap lai!\n");
			checkSai = 0;
		}
		printf("\nMoi ban nhap (1,2,3,4,5,6,7,8,9,10,0): ");

		if (scanf("%d", &menu) != 1 || menu < 0 || menu >10) {
			
			while ( getchar() != '\n' && getchar() != EOF)// xoa bo nho dem tranh xay ra vong lap vo tan || clear buffer
			{
			}
			checkSai = 1;
			//menu = -1;
			continue;
		}
 		lapChucNang(menu);

	} while (menu != 0);

}

