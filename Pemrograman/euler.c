#include <stdio.h>

float laju_pendinginan(float T, float Ta, float k) {
    return -k * (T - Ta);
}

int main() {
    // --- Deklarasi Parameter ---
    float T0;           // Suhu awal kopi
    float Ta;           // Suhu ambien/ruangan
    const float k = 0.1;  // Konstanta pendinginan
    float t_akhir;      // Waktu akhir simulasi
    float h;            // Ukuran langkah

    // --- Sesi Input dari Pengguna ---
    printf("==================================================================\n");
    printf("|        Program Simulasi Pendinginan Kopi (Metode Euler)        |\n");
    printf("==================================================================\n");
    printf("|           Silakan masukkan parameter untuk simulasi.           |\n");
    printf("------------------------------------------------------------------\n");

    printf("| Masukkan suhu awal kopi (misal: 95.0): ");
    scanf("%f", &T0);
    printf("| Masukkan suhu ruangan/ambien (misal: 25.0): ");
    scanf("%f", &Ta);
    printf("| Masukkan waktu akhir simulasi dalam menit (misal: 10.0): ");
    scanf("%f", &t_akhir);
    printf("| Masukkan ukuran langkah/interval waktu (misal: 2.0): ");
    scanf("%f", &h);
    
    // Validasi sederhana agar ukuran langkah tidak nol atau negatif
    if (h <= 0) {
        printf("------------------------------------------------------------------\n");
        printf("|    Ukuran langkah harus lebih besar dari 0. Program berhenti.  |\n");
        printf("==================================================================\n");
        return 1; // Keluar dari program dengan kode error
    }

    // --- Variabel Iterasi ---
    float t = 0.0;        // Waktu saat ini, mulai dari 0
    float T = T0;         // Suhu saat ini, mulai dari suhu awal

    // --- Proses Perhitungan ---
    printf("------------------------------------------------------------------\n");
    printf("|                         Hasil Simulasi                         |\n");
    printf("------------------------------------------------------------------\n");
    printf("| Parameter yang Digunakan:\n");
    printf("| - Suhu Awal (T0)   : %.2f C\n", T0);
    printf("| - Suhu Ruangan (Ta): %.2f C\n", Ta);
    printf("| - Konstanta (k)    : %.2f\n", k);
    printf("| - Waktu Akhir      : %.2f menit\n", t_akhir);
    printf("| - Ukuran Langkah (h): %.2f menit\n", h);
    printf("------------------------------------------------------------------\n");
    printf("|\tWaktu (menit)\t\t|\tSuhu Aproksimasi (C)     |\n");
    printf("------------------------------------------------------------------\n");

    // Cetak kondisi awal
    printf("|\t%13.2f\t\t|\t%22.2f   |\n", t, T);

    // Loop iterasi menggunakan Metode Euler
    while (t < t_akhir) {
        // Hitung turunan pada titik saat ini
        float dT_dt = laju_pendinginan(T, Ta, k);
        
        // Aplikasikan rumus Euler untuk mendapatkan suhu berikutnya
        T = T + h * dT_dt;
        
        // Majukan waktu
        t = t + h;
        
        // Cetak hasil langkah ini
        printf("|\t%13.2f\t\t|\t%22.2f   |\n", t, T);
    }

    printf("==================================================================\n");

    // --- Hasil Akhir ---
    printf("|                          Hasil Akhir:                          |\n");
    printf("| Perkiraan suhu kopi setelah %.2f menit adalah: %.2f Celsius   |\n", t_akhir, T);
    printf("==================================================================\n");

    return 0;
}