#include <iostream>
#include <sstream>

using namespace std;

class Parklot{
  private:
    int kapasitasFix = 20;
  public:
    void menu();
    void choice();
    void masuk();
    void keluar();
    void setting();
    void harga();
    void cekKendaraan();
    int kapasitas = 20;
    int jamMasuk;
    int jamKeluar;
    int posisiData;
    int totalHarga;
    int displayJam;
    string jamM;
    string jamK;
    string noPol[999];
    string tipeKendaraan[999];
    string jam[999];
    void setKapasitasFix(int f){
      kapasitasFix = f;
    }
    int getKapasitasFix(){
      return kapasitasFix;
    }
};

void Parklot::setting(){
  string jawab;
  int ubah;
  cout << "Apakah anda yakin ingin merubah setting default? (y/n) : ";
  cin >> jawab;
  if (jawab == "y" || jawab == "Y"){
    cout << "Masukkan jumlah dari slot parkir : ";
    cin >> ubah;
    setKapasitasFix(ubah);
    kapasitas = getKapasitasFix();
  }
}

void Parklot::menu(){
  cout << "Pilih Menu" << endl;
  cout << "=======================" << endl;
  cout << "1. Kendaraan Masuk" << endl;
  cout << "2. Kendaraan Keluar" << endl;
  cout << "3. Cek Kendaraan" << endl;
  cout << "4. Setting" << endl;
  cout << "5. Tutup Aplikasi" << endl;
  cout << "=======================" << endl;
  cout << "Kapasitas sementara : " << kapasitas;
}

void Parklot::masuk(){
  int i;
  string tipe;
  for (i=0; i < kapasitas; i++){
    if (noPol[i] == ""){
      cout << "Masukaan nomor kendaraan : ";
      cin >> noPol[i];
      cout << "Tipe kendaraan : " << endl;
      cout << "1. Mobil" << endl;
      cout << "2. Motor" << endl;
      cout << "Masukkan tipe kendaraan : ";
      cin >> tipe;
      if (tipe == "1"){
        tipeKendaraan[i] = "Mobil";
      }else if (tipe == "2"){
        tipeKendaraan[i] = "Motor";
      }
      cout << "Masukkan jam saat ini : ";
      cin >> jam[i];
      kapasitas--;
      system("cls");
      break;
    }
  }
  cout << "     KENDARAAN MASUK!!!" << endl;
  cout << "===========================" << endl;
  cout << "     Parkiran UNTIRTA" << endl;
  cout << "===========================" << endl;
  cout << "Plat No\t\t: " << noPol[i] << endl;
  cout << "Jam Masuk\t: " << jam[i] << endl; 
  cout << "===========================" << endl;
  cout << "\nTekan \"ENTER\" untuk melanjutkan";
  cin.get();
  cin.get();
}

void Parklot::harga(){
  int subTotalJam;
  //parsing jam masuk
  int hourMasuk;
  int minuteMasuk;
  int secondMasuk;
  stringstream memJamMasuk;
  stringstream memMenitMasuk;
  stringstream memDetikMasuk;
  jamM = jam[posisiData];
  for (int i = 0; i < 2; i++)
  memJamMasuk << jamM[i];
  memJamMasuk >> hourMasuk;
  for (int j = 3; j < 5; j++)
  memMenitMasuk << jamM[j];
  memMenitMasuk >> minuteMasuk;
  for (int k = 6; k < 8; k++)
  memDetikMasuk << jamM[k];
  memDetikMasuk >> secondMasuk;
  jamMasuk = ((hourMasuk*60)*60) + (minuteMasuk*60) + secondMasuk;
  //parsing jam keluar
  int hourKeluar;
  int minuteKeluar;
  int secondKeluar;
  stringstream memJamKeluar;
  stringstream memMenitKeluar;
  stringstream memDetikKeluar;
  for (int l = 0; l < 2; l++)
  memJamKeluar << jamK[l];
  memJamKeluar >> hourKeluar;
  for (int m = 3; m < 5; m++)
  memMenitKeluar << jamK[m];
  memMenitKeluar >> minuteKeluar;
  for (int n = 6; n < 8; n++)
  memDetikKeluar << jamK[n];
  memDetikKeluar >> secondKeluar;
  jamKeluar = ((hourKeluar*60)*60) + (minuteKeluar*60) + secondKeluar;
  subTotalJam = jamKeluar - jamMasuk;
  //parsing total jam
  int totalJam;
  int totalMenit;
  int totalDetik;
  totalJam = subTotalJam / 3600;
  displayJam = totalJam;
  totalMenit = (subTotalJam % 3600) / 60;
  totalDetik = subTotalJam % 60;
  //rumus harga
  if (tipeKendaraan[posisiData] == "Mobil"){
    if (totalJam <= 1){
      totalHarga = 3000;   
    }else if (totalJam > 1){
      totalHarga = 3000;
      for (int i = 0; i < (totalJam-1); i++){
        totalHarga += 2000;
      }
    }
  }else if (tipeKendaraan[posisiData] == "Motor"){
    if (totalJam <= 1){
      totalHarga = 2000;   
    }else if (totalJam > 1){
      totalHarga = 2000;
      for (int i = 0; i < (totalJam-1); i++){
        totalHarga += 1000;
      }
    }
  }
}

void Parklot::keluar(){
  string out;
  string jKeluar;
  string displayK;
  cout << "Masukkan nomor kendaraan : ";
  cin >> out;
  cout << "Masukkan jam saat ini : ";
  cin >> jKeluar;
  //displayK = jKeluar;
  jamK = jKeluar;
  harga();
  for (int i = 0; i < kapasitas; i++){
    if (noPol[i] == out){
      kapasitas += 1;
      posisiData += 1;
      jamM = jam[i];
      system("cls");
      cout << "    KENDARAAN KELUAR!!!" << endl;
      cout << "===========================" << endl;
      cout << "      Parkiran UNTIRTA" << endl;
      cout << "===========================" << endl;
      cout << "Plat No\t\t: " << noPol[i] << endl;
      cout << "Tipe Kendaraan\t: " << tipeKendaraan[i] << endl;
      cout << "Jam Masuk\t: " << jam[i] << endl;
      cout << "Jam Keluar\t: " << jamK << endl;
      cout << "===========================" << endl;
      cout << "Total jam\t: " << displayJam << endl;
      cout << "harga\t\t: " << totalHarga << endl;
      cout << "===========================" << endl;
      cout << "\nTekan \"ENTER\" untuk melanjutkan";
      noPol[i] = "";
      jam[i] = "";
      cin.get();
      cin.get();
      break;
    }
  }
  posisiData = 0;
}

void Parklot::cekKendaraan(){
  for (int i = 0; i < getKapasitasFix(); i++){
    cout << i+1 << ". ";
    if (noPol[i] == ""){
      cout << "Kosong" << endl;
    }else{
      cout << noPol[i] << endl; 
    }
  }
  cout << "Tekan \"ENTER\" untuk kembali";
  cin.get();
  cin.get();
  system("cls");
}

void Parklot::choice(){
  string pilih;
  cout << "\nMasukkan pilihan anda : ";
  cin >> pilih;
  if (pilih == "1"){
    if (kapasitas == 0){
      cout << "Tidak ada lahan yang tersedia, Tekan \"ENTER\" untuk melanjutkan" << endl;
      cin.get();
      cin.get();
      system("cls");
      menu();
      choice();
    }else{
      system("cls");
      masuk();
      system("cls");
      menu();
      choice();
    }
  }else if (pilih == "2"){
    if (kapasitas == getKapasitasFix()){
      cout << "Saat ini tidak ada kendaraan yang sedang parkir, Tekan \"ENTER\" untuk melanjutkan" << endl;
      cin.get();
      cin.get();
      system("cls");
      menu();
      choice();
    }else{
      system("cls");
      keluar();
      system("cls");
      menu();
      choice();
    }
  }else if (pilih == "3"){
      system("cls");
      cekKendaraan();
      system("cls");
      menu();
      choice();
  }else if (pilih == "4"){
    if (kapasitas != getKapasitasFix()){
      system("cls");
      cout << "Semua kendaraan harus keluar terlebih dahulu!!!" << endl;
      cout << "Tekan \"ENTER\" untuk melanjutkan";
      cin.get();
      cin.get();
      system("cls");
      menu();
      choice();
    }else{
      system("cls");
      setting();
      system("cls");
      menu();
      choice();
    }
  }else if (pilih == "5"){
      system("cls");
      if (kapasitas != getKapasitasFix()){
        cout << "Masih terdapat kendaraan yang belum keluar, anda tidak bisa menutup aplikasi ini!!!" << endl;
        cout << "Tekan \"ENTER\" untuk melanutkan" << endl;
        cin.get();
        system("cls");
        menu();
        choice();
      }
      cout << "Terimakasih sudah menggunakan aplikasi ini, sampai jumpa kembali\n" << endl;
      cin.get();
      cin.get();
  }else{
      cout << "Pilihan yang anda masukkan tidak valid!!, Tekan \"ENTER\" untuk melanjutkan";
      cin.get();
      cin.get();
      system("cls");
      menu();
      choice();
  }
}

int main(int argc, char const *argv[])
{
    Parklot parkir;
    parkir.menu();
    parkir.choice();
  return 0;
}
