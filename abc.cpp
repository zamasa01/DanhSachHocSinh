#include <iomanip>
#include <iostream>
using namespace std;

struct hocSinh {
	char ten[30];
	int stt, lop, id, toan, ly, hoa;
	float trungBinhMon;
} hs[10];

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void nhapData(int &dem) {
	cout << "\nNhap ID hoc sinh " << dem << " : ", cin >> hs[dem-1].id;
	cout << "Nhap ten hoc sinh " << dem << " : ", getchar(), cin.getline(hs[dem-1].ten, size(hs[dem-1].ten));
	cout << "Nhap diem toan hoc sinh " << dem << " :", cin >> hs[dem-1].toan;
	cout << "Nhap diem ly hoc sinh " << dem << " :", cin >> hs[dem-1].ly;
	cout << "Nhap diem hoa hoc sinh " << dem << " :", cin >> hs[dem-1].hoa;
	hs[dem-1].trungBinhMon = (hs[dem-1].toan + hs[dem-1].ly + hs[dem-1].hoa) / 3;
	hs[dem-1].stt = dem;
	dem++;
}

void xuatData(int stt) {
	cout << setprecision(2);
	cout << setw(5) << hs[stt].stt
		<< setw(7) << hs[stt].id
		<< setw(25) << hs[stt].ten
		<< setw(10) << hs[stt].toan
		<< setw(10) << hs[stt].ly
		<< setw(10) << hs[stt].hoa
		<< setw(13) << hs[stt].trungBinhMon
		<< endl;
}

void xuatDanhSachhs(int dem) {
	cout << "\n\033[36m";
	cout << setw(5) << "STT"
		<< setw(7) << "ID"
		<< setw(25) << "TEN"
		<< setw(10) << "DIEM TOAN"
		<< setw(10) << "DIEM LY"
		<< setw(10) << "DIEM HOA"
		<< setw(13) << "DIEM T.BINH"
		<< endl;
	cout << "\033[0m";
	cout << setprecision(2);
	for (int i = 0; i < dem - 1; i++) {
		cout << setw(5) << hs[i].stt
			<< setw(7) << hs[i].id
			<< setw(25) << hs[i].ten
			<< setw(10) << hs[i].toan
			<< setw(10) << hs[i].ly
			<< setw(10) << hs[i].hoa
			<< setw(13) << hs[i].trungBinhMon
			<< endl;
	}
}

void xoaData(int &dem) {
	int n;
	cout << "Nhap so thu tu hoc sinh can xoa: ", cin >> n;
	for (int i = n; i < dem; i++) {
		hs[i - 1].id = hs[i].id;
		strcpy_s(hs[i - 1].ten, hs[i].ten);
		hs[i - 1].toan = hs[i].toan;
		hs[i - 1].ly = hs[i].ly;
		hs[i - 1].hoa = hs[i].hoa;
	}
	dem--;
}

void chinhSua() {
	int stt, muc, infoi;
	char infoc[30];
	cout << "Nhap so thu tu hoc sinh can chinh sua: ", cin >> stt;
	cout << "1. ID" << endl;
	cout << "2. Ten" << endl;
	cout << "3. Diem Toan" << endl;
	cout << "4. Diem Ly" << endl;
	cout << "5. Diem Hoa" << endl;
	cout << "Chon so: ", cin >> muc;
	switch (muc) {
	case 1: cout << "Noi dung thay doi: ", cin >> hs[stt - 1].id; break;
	case 2: cout << "Noi dung thay doi: ", getchar(), cin.getline(hs[stt - 1].ten, size(hs[stt - 1].ten)); break;
	case 3: cout << "Noi dung thay doi: ", cin >> hs[stt - 1].toan; break;
	case 4: cout << "Noi dung thay doi: ", cin >> hs[stt - 1].ly; break;
	case 5: cout << "Noi dung thay doi: ", cin >> hs[stt - 1].hoa; break;
	}
}

void soSanhDToan(int dem) {
	for (int i = 0; i < dem; i++) {
		for (int j = i; j < dem; j++) {
			if (hs[i].toan < hs[j].toan) {
				swap(hs[i].id, hs[j].id);
				swap(hs[i].ten, hs[j].ten);
				swap(hs[i].toan, hs[j].toan);
				swap(hs[i].ly, hs[j].ly);
				swap(hs[i].hoa, hs[j].hoa);
			}
		}
	}
}

void soSanhDLy(int dem) {
	for (int i = 0; i < dem; i++) {
		for (int j = i; j < dem; j++) {
			if (hs[i].ly < hs[j].ly) {
				swap(hs[i].id, hs[j].id);
				swap(hs[i].ten, hs[j].ten);
				swap(hs[i].toan, hs[j].toan);
				swap(hs[i].ly, hs[j].ly);
				swap(hs[i].hoa, hs[j].hoa);
			}
		}
	}
}

void soSanhDHoa(int dem) {
	for (int i = 0; i < dem; i++) {
		for (int j = i; j < dem; j++) {
			if (hs[i].hoa < hs[j].hoa) {
				swap(hs[i].id, hs[j].id);
				swap(hs[i].ten, hs[j].ten);
				swap(hs[i].toan, hs[j].toan);
				swap(hs[i].ly, hs[j].ly);
				swap(hs[i].hoa, hs[j].hoa);
			}
		}
	}
}

void diemTrungBinhMon(int dem, float dtb[4]) {
	xuatDanhSachhs(dem);
	for (int i = 0; i < dem; i++) {
		dtb[0] += hs[i].toan;
		dtb[1] += hs[i].ly;
		dtb[2] += hs[i].hoa;
		dtb[3] += hs[i].trungBinhMon;
	}
	cout << setprecision(2);
	cout << "\033[32m";
	cout << setw(37) << "DIEM TRUNG BINH CUA LOP"
		<< setw(10) << dtb[0] / (dem - 1)
		<< setw(10) << dtb[1] / (dem - 1)
		<< setw(10) << dtb[2] / (dem - 1) 
		<< setw(13) << dtb[3] / (dem - 1)
		<< endl;
	cout << "\033[0m";
	system("pause");
}

void danhSachHSGioi(int dem) {
	cout << "\nDANH SACH HOC SINH GIOI CUA LOP" << endl;
	cout << "\033[36m";
	cout << setw(5) << "STT"
		<< setw(7) << "ID"
		<< setw(25) << "TEN"
		<< setw(10) << "DIEM TOAN"
		<< setw(10) << "DIEM LY"
		<< setw(10) << "DIEM HOA"
		<< setw(13) << "DIEM T.BINH"
		<< endl;
	cout << "\033[0m";
	cout << setprecision(2);
	for (int i = 0; i < dem - 1; i++) {
		if (hs[i].trungBinhMon >= 8) {
			xuatData(i);
		}
	}
	system("pause");
}

void danhSachHSKha(int dem) {
	cout << "\nDANH SACH HOC SINH TRUNG BINH KHA CUA LOP" << endl;
	cout << "\033[36m";
	cout << setw(5) << "STT"
		<< setw(7) << "ID"
		<< setw(25) << "TEN"
		<< setw(10) << "DIEM TOAN"
		<< setw(10) << "DIEM LY"
		<< setw(10) << "DIEM HOA"
		<< setw(13) << "DIEM T.BINH"
		<< endl;
	cout << "\033[0m";
	cout << setprecision(2);
	for (int i = 0; i < dem - 1; i++) {
		if (hs[i].trungBinhMon >= 5 && hs[i].trungBinhMon < 8) {
			xuatData(i);
		}
	}
	system("pause");
}

void danhSachHSYeu(int dem) {
	cout << "\nDANH SACH HOC SINH YEU CUA LOP" << endl;
	cout << "\033[36m";
	cout << setw(5) << "STT"
		<< setw(7) << "ID"
		<< setw(25) << "TEN"
		<< setw(10) << "DIEM TOAN"
		<< setw(10) << "DIEM LY"
		<< setw(10) << "DIEM HOA"
		<< setw(13) << "DIEM T.BINH"
		<< endl;
	cout << "\033[0m";
	cout << setprecision(2);
	for (int i = 0; i < dem - 1; i++) {
		if (hs[i].trungBinhMon < 5) {
			xuatData(i);
		}
	}
	system("pause");
}

void main() {
	int n, dem = 1, loop = 0;
	float dtb[4] = { 0,0,0,0 };
	/*cout << "Nhap so luong hoc sinh: ", cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap ID hoc sinh " << dem << " : ", cin >> hs[i].id;
		cout << "Nhap ten hoc sinh " << dem << " : ", getchar(), cin.getline(hs[i].ten, size(hs[i].ten));
		cout << "Nhap diem toan hoc sinh " << dem << " :", cin >> hs[i].toan;
		cout << "Nhap diem ly hoc sinh " << dem << " :", cin >> hs[i].ly;
		cout << "Nhap diem hoa hoc sinh " << dem << " :", cin >> hs[i].hoa;
		hs[i].trungBinhMon = (hs[i].toan + hs[i].ly + hs[i].hoa) / 3;
		hs[i].stt = dem;
		dem++;
	}*/

	hs[0].stt = dem;
	hs[0].id = 11245;
	strcpy_s(hs[0].ten, "Hoang Minh Tan");
	hs[0].toan = 6;
	hs[0].ly = 7;
	hs[0].hoa = 8;
	hs[0].trungBinhMon = float(hs[0].toan + hs[0].ly + hs[0].hoa) / 3;
	dem++;

	hs[1].stt = dem;
	hs[1].id = 11246;
	strcpy_s(hs[1].ten, "Nguyen Thanh Thuan");
	hs[1].toan = 8;
	hs[1].ly = 8;
	hs[1].hoa = 9;
	hs[1].trungBinhMon = float(hs[1].toan + hs[1].ly + hs[1].hoa) / 3;
	dem++;

	hs[2].stt = dem;
	hs[2].id = 11247;
	strcpy_s(hs[2].ten, "Bui Van Quyet");
	hs[2].toan = 5;
	hs[2].ly = 4;
	hs[2].hoa = 3;
	hs[2].trungBinhMon = float(hs[2].toan + hs[2].ly + hs[2].hoa) / 3;
	dem++;
	
	do {
		system("cls");
		xuatDanhSachhs(dem);
		cout << "\n\n1.  Nhap them thong tin hoc sinh" << endl;
		cout << "2.  Chinh sua thong tin hoc sinh" << endl;
		cout << "3.  Xoa thong tin hoc sinh" << endl;
		cout << "4.  Sap xep theo diem Toan" << endl;
		cout << "5.  Sap xep theo diem Ly" << endl;
		cout << "6.  Sap xep theo diem Hoa" << endl;
		cout << "7.  Xem diem trung binh mon va trung binh lop" << endl;
		cout << "8.  Xem danh sach hoc sinh Gioi" << endl;
		cout << "9.  Xem danh sach hoc sinh Trung Binh Kha" << endl;
		cout << "10. Xem dah sach hoc sinh Yeu" << endl;
		cout << "11. Dung Chuong Trinh" << endl;
		cout << "---> Chon so: ", cin >> n;
		switch (n) {
		case 1: nhapData(dem); break;
		case 2: chinhSua(); break;
		case 3: xoaData(dem); break;
		case 4: soSanhDToan(dem); break;
		case 5: soSanhDLy(dem); break;
		case 6: soSanhDHoa(dem); break;
		case 7: diemTrungBinhMon(dem, dtb); break;
		case 8: danhSachHSGioi(dem); break;
		case 9: danhSachHSKha(dem); break;
		case 10: danhSachHSYeu(dem); break;
		case 11: loop++; break;
		}
	} while (loop == 0);
}