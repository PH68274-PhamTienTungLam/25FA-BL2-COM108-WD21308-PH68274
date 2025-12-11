#pragma once

struct thuCung {
	char maThuCung[20];
	char tenThuCung[50];
	int namSinh;
};

void chucNang1() {
	struct thuCung ds[3];
	int i;
	int namHienTai = 2025;
	int n = 3;
	printf("=== NHAP THONG TIN CHO 3 THU CUNG ===\n");
	for (i = 0; i < n; i++) {
		printf("\nNhap thong tin thu cung thu %d:\n", i + 1);
		printf("Nhap ma thu cung: ");
		while ((getchar()) != '\n');
		fgets(ds[i].maThuCung, sizeof(ds[i].maThuCung), stdin);
		printf("Nhap ten thu cung: ");
		fgets(ds[i].tenThuCung, sizeof(ds[i].tenThuCung), stdin);
		printf("Nhap nam sinh: ");
		scanf("%d", &ds[i].namSinh);
	}
	printf("\n\n=== DANH SACH THU CUNG VUA NHAP ===\n");

	printf("%-15s %-25s %-15s %-10s\n", "MA", "TEN", "NAM SINH", "TUOI");
	printf("------------------------------------------------------------------\n");

	for (i = 0; i < 3; i++) {

		int tuoi = namHienTai - ds[i].namSinh;


		printf("%-15s %-25s %-15d %-10d\n",
			ds[i].maThuCung,
			ds[i].tenThuCung,
			ds[i].namSinh,
			tuoi);
	}
}
