#include"Header.h"
void main(){
	HeThong system;
	Khoa khoa[5];
	MHoc mon[10];
	HPhan HP[10];
	SVien SV[10];
	KetQua KQ[50];
	DieuKien DK[10];
	//data
	//khoa
	khoa[0].setMaKhoa("100");
	khoa[0].setTenKhoa("CNTT");
	khoa[0].setNamTL(1990);
	khoa[1].setMaKhoa("200");
	khoa[1].setTenKhoa("Hoa");
	khoa[1].setNamTL(1986);
	//sv
	SV[0].setMaKhoa("100");
	SV[0].setMaSV("1712001");
	SV[0].setNam(2);
	SV[0].setTenSV("Nguyen An");
	//Mon hoc
	mon[0].setMaKhoa("100");
	mon[0].setMaMH("2000000");
	mon[0].setTenMH("Huong Doi Tuong");
	mon[0].setTinChi(3);
	mon[1].setMaKhoa("100");
	mon[1].setMaMH("2000001");
	mon[1].setTenMH("Cau Truc Du Lieu");
	mon[1].setTinChi(2);
	mon[2].setMaKhoa("200");
	mon[2].setMaMH("2100000");
	mon[2].setTenMH("Hoa");
	mon[2].setTinChi(3);
	//Hoc phan
	HP[0].setGiaoVien("Nguyen Van A");
	HP[0].setHocKi(1);
	HP[0].setMaHP(3000);
	HP[0].setNam(2);
	HP[0].setMaMH("2000000");
	HP[1].setGiaoVien("Le Van B");
	HP[1].setHocKi(1);
	HP[1].setMaHP(3001);
	HP[1].setNam(2);
	HP[1].setMaMH("2000001");
	HP[2].setGiaoVien("Nguyen Van C");
	HP[2].setHocKi(2);
	HP[2].setMaHP(3100);
	HP[2].setNam(1);
	HP[2].setMaMH("2100000");
	//Ket qua
	KQ[0].setDiem(8);
	KQ[0].setMaSV("1712001");
	KQ[0].setMaHP(3000);
	KQ[1].setDiem(8);
	KQ[1].setMaSV("1712001");
	KQ[1].setMaHP(3001);
	//Dieu kien
	DK[0].setMaMH("2000000");
	DK[0].setMaMHTruoc("");
	DK[1].setMaMH("2000001");
	DK[1].setMaMHTruoc("");
	DK[2].setMaMH("2100000");
	DK[2].setMaMHTruoc("");
	//set he thong
	system.setHP(HP);
	system.setKhoa(khoa);
	system.setMon(mon);
	system.setSV(SV);
	system.setKQ(KQ);
	system.setSoLuongHP(3);
	system.setSoLuongKhoa(2);
	system.setSoLuongKQ(2);
	system.setSoLuongMon(3);
	system.setSoLuongSV(1);
	//menu 
	do{
		int n;
		printf("1.them sinh vien\n");
		printf("2.xuat thong tin toan bo sinh vien\n");
		printf("3.xuat thong tin sinh vien theo mssv\n");
		printf("4.xuat top 10 sinh vien theo ma hoc phan\n");
		printf("5.sua thong tin sinh vien\n");
		printf("6.xoa sinh vien\n");
		printf("Ban chon chuc nang: ");
		scanf_s("%d", &n);
		getchar();
		char str[100];
		switch (n){
		case 1:
			system.themSV();
			break;
		case 2:
			system.xuatSV();
			break;
		case 3:
			do{
				printf("nhap mssv: ");
				gets_s(str, 8);
				if (!system.kiemTraMSSV(str)){
					system.xuatSV(str);
					break;
				}
				printf("ma so sinh vien khong ton tai. Nhap lai\n");
			} while (1);
			break;
		case 4:
			int n;
			do{
				printf("nhap ma hoc phan: ");
				scanf_s("%d", &n);
				getchar();
				if (!system.kiemTraMaHP(n)){
					system.xuatTop10(n);
					break;
				}
				printf("ma hoc phan khong ton tai. Nhap lai\n");
			} while (1);
			break;
		case 5:
			do{
				printf("nhap mssv can sua: ");
				gets_s(str, 8);
				if (!system.kiemTraMSSV(str)){
					system.suaSV(str);
					break;
				}
				printf("ma so sinh vien khong ton tai. Nhap lai\n");
			} while (1);
			break;
		default:
			do{
				printf("nhap mssv can xoa: ");
				gets_s(str, 8);
				if (!system.kiemTraMSSV(str)){
					system.xoaSV(str);
					break;
				}
				printf("ma so sinh vien khong ton tai. Nhap lai\n");
			} while (1);
			break;
		}
		printf("\n");
		char ch;
		printf("ban muon thuc hien tiep chuong trinh(y/n):");
		scanf_s("%c", &ch);
		getchar();
		if (ch != 'y'){
			break;
		}
	} while (1);
}