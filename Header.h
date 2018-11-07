#pragma once
#ifndef __HEADER_H__
#define __HEADER_H__
#include<stdio.h>
#include<string.h>
#include<math.h>
#pragma once
class Khoa
{
protected:
	char maKhoa[4];
private:
	char tenKhoa[100];
	int namThanhLap;
public:
	void setMaKhoa(char*);
	void setTenKhoa(char*);
	void setNamTL(int n);
	char* getMaKhoa();
	char* getTenKhoa();
	int getNamTL();
};

class SVien :public Khoa{
protected:
	char maSV[8];
private:
	char tenSV[100];
	int nam;
public:
	void setMaSV(char*);
	void setTenSV(char*);
	void setNam(int n);
	char* getMaSV();
	char* getTenSV();
	int getNam();
};

class MHoc :public Khoa{
protected:
	char maMH[8];
private:
	char tenMH[100];
	int tinChi;
public:
	void setMaMH(char* str);
	void setTenMH(char* str);
	void setTinChi(int n);
	char* getMaMH();
	char* getTenMH();
	int getTinChi();
};

class HPhan :public MHoc{
protected:
	int maHP;
private:
	int hocKi;
	int nam;
	char giaoVien[50];
public:
	void setMaHP(int n);
	void setHocKi(int n);
	void setNam(int n);
	void setGiaoVien(char*str);
	int getMaHP();
	int getHocKi();
	int getNam();
	char* getGiaoVien();
};

class KetQua :public HPhan, public SVien{
private:
	float diem;
public:
	void setDiem(float n);
	float getDiem();
};

class DieuKien :public MHoc{
private: 
	char MaMHTruoc[8];
public:
	void setMaMHTruoc(char*str);
	char*getMaMHTruoc();
};

class HeThong{
private: 
	SVien* sv;
	KetQua* kq;
	Khoa* khoa;
	MHoc* mon;
	HPhan* hocPhan;
	DieuKien* dk;
	int soLuongKQ;
	int soLuongHP;
	int soLuongMon;
	int soLuongKhoa;
	int soLuongSV;

public:
	HeThong();
	int kiemTraMSSV(char*str);
	int kiemTraMK(char*str);
	int kiemTraMaHP(int maHP);
	int timSV(char*mssv);
	int timKQ(char*mssv, int maHP);
	void setSoLuongKQ(int n);
	void setSoLuongHP(int n);
	void setSoLuongMon(int n);
	void setSoLuongKhoa(int n);
	void setSoLuongSV(int n);
	void setKhoa(Khoa*khoa);
	void setMon(MHoc*mon);
	void setHP(HPhan*HP);
	void setSV(SVien* sv);
	void setKQ(KetQua*KQ);
	void themSV();
	void themKQ(char*mssv,int maHP);
	void xuatSV();
	void xuatSV(char*mssv);
	void xuatTop10(int maHP);
	void suaSV(char*mssv);
	void xoaSV(char*mssv);
};
#endif