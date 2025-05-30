#include <stdio.h>
#include <math.h>    // Untuk fungsi matematika seperti exp, cos, fabs
#include <complex.h> // Untuk operasi bilangan kompleks (csqrt, cabs, creal)
#include <stdlib.h>

// Fungsi yang ingin dicari akarnya
double f(double x)
{
    return exp(-x) - cos(x); // f(x) = e^(-x) - cos(x)
}

int main()
{
    double xr, h, eps; // xr: tebakan awal, h: langkah relatif, eps: toleransi error
    int maxit;         // maxit: jumlah iterasi maksimum

    // Input dari user
    printf("Masukkan tebakan awal (xr): ");
    if (scanf("%lf", &xr) != 1)
    {
        fprintf(stderr, "Input tidak valid untuk xr.\n");
        return 1;
    }

    printf("Masukkan langkah relatif (h): ");
    if (scanf("%lf", &h) != 1)
    {
        fprintf(stderr, "Input tidak valid untuk h.\n");
        return 1;
    }

    printf("Masukkan toleransi relatif (eps): ");
    if (scanf("%lf", &eps) != 1)
    {
        fprintf(stderr, "Input tidak valid untuk eps.\n");
        return 1;
    }

    printf("Masukkan jumlah iterasi maksimum (maxit): ");
    if (scanf("%d", &maxit) != 1)
    {
        fprintf(stderr, "Input tidak valid untuk maxit.\n");
        return 1;
    }

    // Inisialisasi tiga nilai awal
    double x2 = xr;
    double x1 = xr + h * xr;
    double x0 = xr - h * xr;
    int iter = 0;

    // Variabel untuk menyimpan hasil perhitungan Muller's Method
    double h0, h1, d0, d1, a, b, c;
    complex double rad, den, dxr;
    double final_xr = xr;

    // Header tampilan hasil iterasi
    printf("=========================================================================================================================\n");
    printf("                                                     Muller's Method                                                     \n");
    printf("=========================================================================================================================\n");
    printf("Iterasi\t|    x0    \t|    x1    \t|    x2    \t|   f(x0)  \t|   f(x1)  \t|   f(x2)  \t|  delta(x) \t|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");

    // Mulai proses iterasi
    do
    {
        iter++;

        // Menghitung selisih antar titik
        h0 = x1 - x0;
        h1 = x2 - x1;

        // Cek apakah selisih terlalu kecil, bisa menyebabkan error numerik
        if (fabs(h0) < 1e-12 || fabs(h1) < 1e-12)
        {
            fprintf(stderr, "Error: Langkah terlalu kecil, metode mungkin gagal.\n");
            break;
        }

        // Hitung diferensial terbagi (selisih nilai fungsi)
        d0 = (f(x1) - f(x0)) / h0;
        d1 = (f(x2) - f(x1)) / h1;

        // Hitung koefisien a, b, dan c dari polinomial kuadrat
        a = (d1 - d0) / (h1 + h0);
        b = a * h1 + d1;
        c = f(x2);

        // Menghitung akar dari diskriminan kuadrat dalam bentuk kompleks
        complex double b_complex = b + 0.0 * I;
        complex double ac4 = 4.0 * a * c + 0.0 * I;
        rad = csqrt(b_complex * b_complex - ac4); // sqrt(b^2 - 4ac)

        // Memilih penyebut dengan nilai absolut terbesar agar stabil secara numerik
        double abs_b_plus_rad = cabs(b_complex + rad);
        double abs_b_minus_rad = cabs(b_complex - rad);
        if (abs_b_plus_rad > abs_b_minus_rad)
        {
            den = b_complex + rad;
        }
        else
        {
            den = b_complex - rad;
        }

        // Cek jika penyebut terlalu kecil, bisa menyebabkan pembagian dengan nol
        if (cabs(den) < 1e-12)
        {
            fprintf(stderr, "Error: Penyebut sangat kecil, metode mungkin gagal.\n");
            break;
        }

        // Hitung perubahan xr (delta x)
        dxr = (2.0 * c + 0.0 * I) / den;
        xr = x2 - creal(dxr); // Akar baru dengan hanya bagian real-nya
        final_xr = xr;

        // Tampilkan hasil iterasi ke layar
        printf("%5d\t| %11.7f\t| %11.7f\t| %11.7f\t| %9.7f\t| %9.7f\t| %9.7f\t| %10.7f\t|\n",
               iter, x0, x1, x2, f(x0), f(x1), f(x2), fabs(creal(dxr)));

        // Cek konvergensi: apakah delta cukup kecil dibandingkan toleransi atau iterasi maksimal tercapai
        if (fabs(creal(dxr)) <= eps * fabs(xr) || iter >= maxit)
        {
            // Cetak satu kali lagi dengan status "Konvergen"
            x0 = x1;
            x1 = x2;
            x2 = xr;
            printf("%5d\t| %11.7f\t| %11.7f\t| %11.7f\t| %9.7f\t| %9.7f\t| %9.7f\t| %10s\t|\n",
                   iter + 1, x0, x1, x2, f(x0), f(x1), f(x2), "Konvergen");
            break;
        }

        // Update nilai untuk iterasi berikutnya
        x0 = x1;
        x1 = x2;
        x2 = xr;

    } while (1); // Loop terus sampai konvergen atau gagal

    // Tampilkan hasil akhir
    printf("=========================================================================================================================\n");
    printf("                                                       Hasil Akhir                                                       \n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");

    if (iter <= maxit)
    {
        printf("Akar perkiraan setelah %d iterasi: %11.7f\n", iter + 1, final_xr);
    }
    else
    {
        printf("Metode tidak konvergen setelah %d iterasi.\n", maxit);
    }
    printf("=========================================================================================================================\n");

    return 0;
}