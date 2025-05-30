# Penerapan Metode Muller untuk Mencari Akar Persamaan Transendental
```
Nama: Benedict Aurelius
NPM: 2306209095
```
## Deskripsi Program
Program ini mengimplementasikan **Metode Muller**, sebuah metode numerik iteratif yang digunakan untuk mencari akar dari suatu fungsi. Metode ini sangat berguna terutama untuk menemukan akar dari **persamaan transendental** yang sulit atau tidak mungkin diselesaikan secara analitik.

Studi kasus yang diimplementasikan dalam program ini adalah pencarian akar dari persamaan:

$\qquad f(x) = e^{-x} - \cos(x) = 0$

Keunggulan Metode Muller adalah **tidak memerlukan perhitungan turunan fungsi**, yang seringkali rumit atau tidak praktis untuk fungsi transendental seperti contoh di atas. Metode ini bekerja dengan melakukan interpolasi kuadratik (parabola) melalui tiga tebakan awal dan menggunakan akar dari parabola tersebut sebagai aproksimasi akar fungsi yang sebenarnya.

## Cara Compile dan Run Program
### Prasyarat
* **Compiler C:** Pastikan sistem anda memiliki compiler C (misalnya, GCC) terinstal.
* **Library Math:** Program ini menggunakan fungsi-fungsi matematika dari library `math.h` (untuk `exp` dan `cos`) dan `complex.h` (untuk bilangan kompleks dan akar kuadrat kompleks `csqrt`). Pastikan library ini tersedia dalam lingkungan kompilasi anda.

### Langkah-langkah
1.  **Download Zip:** Anda dapat mengunduh kode sumber program ini dalam format zip dari repositori atau tautan yang diberikan. Ekstrak file zip tersebut untuk mendapatkan file `muller.c`. Atau, anda dapat membuat file baru dengan nama `muller.c` dan menyalin kode tersebut ke dalamnya.

2.  **Compile Program:** Buka terminal atau command prompt pada direktori tempat anda menyimpan file `muller.c` dan gunakan perintah berikut untuk mengkompilasi program:

    ```bash
    gcc muller.c -o muller -lm
    ```

    * `gcc`: adalah perintah untuk compiler GCC.
    * `muller.c`: adalah nama file kode sumber anda.
    * `-o muller`: menentukan nama file output executable menjadi `muller`.
    * `-lm`: menghubungkan (link) dengan library matematika (`libm.so`) yang diperlukan untuk fungsi `exp`, `cos`, dan fungsi matematika lainnya.

3.  **Jalankan Program:** Setelah kompilasi berhasil, anda dapat menjalankan program dengan perintah:

    ```bash
    ./muller
    ```

    Program akan meminta anda untuk memasukkan nilai-nilai berikut:
    * Tebakan awal (`xr`)
    * Langkah relatif (`h`)
    * Toleransi relatif (`eps`)
    * Jumlah iterasi maksimum (`maxit`)

    Masukkan nilai-nilai yang sesuai dan tekan Enter setelah setiap input.

## Hasil Output Program
![Output](https://hackmd.io/_uploads/Sk5AbgvGlx.png)

## Grafik Plot
![Grafik](https://hackmd.io/_uploads/B1MKElwMle.png)

## Penjelasan Kode
Untuk penjelasan yang lebih mendalam mengenai teori di balik Metode Muller, implementasi kode, dan analisis hasil, Anda dapat menonton video berikut:

[![Video Penjelasan](https://img.youtube.com/vi/iXdjCH2kYyc/0.jpg)](https://www.youtube.com/watch?v=iXdjCH2kYyc)