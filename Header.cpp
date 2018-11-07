#include "Header.h"
//class Khoa
void Khoa::setMaKhoa(char* str){
	if (strlen(str) <= 4)
		strcpy(maKhoa, str);
}
void Khoa::setTenKhoa(char* str){
	if (strlen(str) <= 100){
		strcpy(tenKhoa, str);
	}
}
void Khoa::setNamTL(int n){
	if (n > 0){
		namThanhLap = n;
	}
}
char* Khoa::getMaKhoa(){
	return maKhoa;
}
char* Khoa::getTenKhoa(){
	return tenKhoa;
}
int Khoa::getNamTL(){
	return namThanhLap;
}

//class SinhVien
void SVien::setMaSV(char*str){
	if (strlen(str) <= 8){
		strcpy(maSV, str);
	}
}
void SVien::setNam(int n){
	if (n > 0){
		nam = n;
	}
}
void SVien::setTenSV(char*str){
	if (strlen(str) <= 100){
		strcpy(tenSV, str);
	}
}
char* SVien::getMaSV(){
	return maSV;
}
char* SVien::getTenSV(){
	return tenSV;
}
int SVien::getNam(){
	return nam;
}

//class Mon Hoc
void MHoc::setMaMH(char* str){
	if (strlen(str) <= 8){
		strcpy(maMH, str);
	}
}
void MHoc::setTenMH(char*str){
	if (strlen(str) <= 100){
		strcpy(tenMH, str);
	}
}
void MHoc::setTinChi(int n){
	if (n > 0){
		tinChi = n;
	}
}
char* MHoc::getMaMH(){
	return maMH;
}
char* MHoc::getTenMH(){
	return tenMH;
}
int MHoc::getTinChi(){
	return tinChi;
}

//class Hoc Phan
void HPhan::setMaHP(int n){
	if (n > 0){
		maHP = n;
	}
}
void HPhan::setHocKi(int n){
	if (n > 0){
		hocKi = n;
	}
}
void HPhan::setNam(int n){
	if (n > 0){
		nam = n;
	}
}
void HPhan::setGiaoVien(char* str){
	if (strlen(str) <= 50){
		strcpy(giaoVien, str);
	}
}
int HPhan::getMaHP(){
	return maHP;
}
int HPhan::getHocKi(){
	return hocKi;
}
int HPhan::getNam(){
	return nam;
}
char* HPhan::getGiaoVien(){
	return giaoVien;
}

//class Ket Qua
void KetQua::setDiem(float n){
	if (n >= 0){
		diem = n;
	}
}
float KetQua::getDiem(){
	return diem;
}

//class Dieu Kien
void DieuKien::setMaMHTruoc(char* str){
	if (strlen(str) <= 8){
		strcpy(MaMHTruoc, str);
	}
}
char* DieuKien::getMaMHTruoc(){
	return MaMHTruoc;
}

//He thong
HeThong::HeThong(){
	soLuongHP = 0;
	soLuongKhoa = 0;
	soLuongKQ = 0;
	soLuongMon = 0;
	soLuongSV = 0;
}
void HeThong::setSoLuongHP(int n){
	soLuongHP = n;
}
void HeThong::setSoLuongKhoa(int n){
	soLuongKhoa = n;
}
void HeThong::setSoLuongMon(int n){
	soLuongMon = n;
}
void HeThong::setSoLuongKQ(int n){
	soLuongKQ = n;
}
void HeThong::setSoLuongSV(int n){
	soLuongSV = n;
}
int HeThong::kiemTraMSSV(char*str){
	for (int i = 0; i < soLuongSV; i++){
		if (strcmp(str, sv[i].getMaSV()) == 0){
			return 0;
		}
	}
	return 1;
}
int HeThong::kiemTraMK(char*str){
	for (int i = 0; i < soLuongKhoa; i++){
		if (strcmp(str, khoa[i].getMaKhoa()) == 0){
			return 0;
		}
	}
	return 1;
}
int HeThong::kiemTraMaHP(int maHP){
	for (int i = 0; i < soLuongHP; i++){
		if (maHP==hocPhan[i].getMaHP()){
			return 0;
		}
	}
	return 1;
}
void HeThong::themSV(){
	char str[100];
	do{
		printf("nhap mssv: ");
		gets_s(str, 8);
		if (kiemTraMSSV(str)){
			sv[soLuongSV].setMaSV(str);
			break;
		}
		printf("Mssv da ton tai. Nhap lai.\n");
	} while (1);
	printf("nhap ten sinh vien: ");
	gets_s(str, 100);
	sv[soLuongSV].setTenSV(str);
	printf("nhap nam: ");
	int n;
	scanf_s("%d", &n);
	sv[soLuongSV].setNam(n);
	getchar();
	do{
		printf("nhap ma khoa: ");
		gets_s(str, 8);
		if (!kiemTraMK(str)){
			sv[soLuongSV].setMaKhoa(str);
			break;
		}
		printf("Ma khoa khong ton tai. Nhap lai.\n");
	} while (1);
	printf("nhap so hoc phan cua sinh vien: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++){
		int maHP;
		do{
			printf("nhap ma hoc phan thu %d: ",i+1);
			scanf_s("%d", &maHP);
			if (!kiemTraMaHP(maHP)){
				themKQ(sv[soLuongSV].getMaSV(), maHP);
				break;
			}
			printf("Ma hoc phan khong ton tai. Nhap lai.\n");
		} while (1);
	}
	soLuongSV++;
}
void HeThong::themKQ(char*mssv,int maHP){
	kq[soLuongKQ].setMaSV(mssv);
	kq[soLuongKQ].setMaHP(maHP);
	printf("nhap diem: ");
	float n;
	scanf_s("%f", &n);
	getchar();
	kq[soLuongKQ].setDiem(n);
	soLuongKQ++;
}
void HeThong::setKhoa(Khoa*k){
	khoa = k;
}
void HeThong::setMon(MHoc*m){
	mon = m;
}
void HeThong::setHP(HPhan*HP){
	hocPhan = HP;
}
void HeThong::setSV(SVien*SV){
	sv = SV;
}
void HeThong::setKQ(KetQua*KQ){
	kq = KQ;
}
int HeThong::timSV(char*mssv){
	for (int i = 0; i < soLuongSV; i++){
		if (strcmp(mssv, sv[i].getMaSV()) == 0){
			return i;
		}
	}
	return -1;
}
int HeThong::timKQ(char*mssv, int maHP){
	for (int i = 0; i < soLuongKQ; i++){
		if (strcmp(mssv, kq[i].getMaSV()) == 0 && kq[i].getMaHP()==maHP){
			return i;
		}
	}
	return -1;
}
void HeThong::xuatSV(){
	printf("mssv\tten\tma khoa\t\tnam\n");
	for (int i = 0; i < soLuongSV; i++){
		printf("%s\t", sv[i].getMaSV());
		printf("%s\t", sv[i].getTenSV());
		printf("%s\t", sv[i].getMaKhoa());
		printf("%d\t", sv[i].getNam());
		printf("\n  Diem (ma hoc phan: diem): ");
		for (int j = 0; j < soLuongKQ; j++){
			if (strcmp(kq[j].getMaSV(), sv[i].getMaSV()) == 0){
				printf("%d: %f\t", kq[j].getMaHP(),kq[j].getDiem());
			}
		}
		printf("\n");
	}
}
void HeThong::xuatSV(char*mssv){
	int i = timSV(mssv);
	printf("%s\t", sv[i].getMaSV());
	printf("%s\t", sv[i].getTenSV());
	printf("%s\t", sv[i].getMaKhoa());
	printf("%d\t", sv[i].getNam());
	printf("\n  Diem (ma hoc phan: diem): ");
	for (int j = 0; j < soLuongKQ; j++){
		if (strcmp(kq[j].getMaSV(), sv[i].getMaSV()) == 0){
			printf("%d: %f\t", kq[j].getMaHP(), kq[j].getDiem());
		}
	}
}
void HeThong::xuatTop10(int maHP){
	int k = 0;
	for (int i = 0; i < soLuongKQ; i++){
		if (kq[i].getMaHP() == maHP){
			KetQua temp = kq[k];
			kq[k] = kq[i];
			kq[i] = temp;
			k++;
		}
	}
	for (int i = 0; i < k; i++){
		for (int j = i; j < k; j++){
			if (kq[i].getDiem() < kq[j].getDiem()){
				KetQua temp = kq[i];
				kq[i] = kq[j];
				kq[j] = temp;
			}
		}
	}
	for (int i = 0; i < fmin(k*1.0, 10.0); i++){
		printf("%s\t%f", kq[i].getMaSV(), kq[i].getDiem());
		printf("\n");
	}
}
void HeThong::suaSV(char*mssv){
	int n;
	printf("1.Ten\n");
	printf("2.Nam\n");
	printf("3.Khoa\n");
	printf("4.Diem\n");
	printf("Ban chon: ");
	scanf_s("%d", &n);
	int i = timSV(mssv);
	char str[100];
	getchar();
	switch (n){
	case 1:
		printf("nhap ten: ");
		gets_s(str, 100);
		sv[i].setTenSV(str);
		break;
	case 2:
		printf("nhap nam: ");
		scanf_s("%d", &n);
		sv[i].setNam(n);
		break;
	case 3:
		do{
			printf("nhap ma khoa: ");
			gets_s(str, 8);
			if (!kiemTraMSSV(str)){
				sv[soLuongSV].setMaKhoa(str);
				break;
			}
			printf("Ma khoa khong ton tai. Nhap lai.\n");
		} while (1);
		break;
	default:
		do{
			printf("nhap ma hoc phan: ");
			scanf_s("%d", &n);
			if (!kiemTraMaHP(n)){
				float m;
				printf("nhap diem: ");
				scanf_s("%f", &m);
				kq[timKQ(mssv, n)].setDiem(m);
				break;
			}
			printf("Ma hoc phan khong ton tai. Nhap lai.\n");
		} while (1);
		getchar();
		break;
	}
}
void HeThong::xoaSV(char*mssv){
	int i = timSV(mssv);
	for (i; i < soLuongSV-1; i++){
		sv[i] = sv[i + 1];
	}
	soLuongSV--;
}