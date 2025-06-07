# Pemodelan Pendinginan Kopi Menggunakan Metode Euler
```
Nama: Benedict Aurelius
NPM: 2306209095
```
## Deskripsi Program
Program ini mengimplementasikan **Metode Euler**, sebuah metode numerik yang digunakan untuk **menyelesaikan persamaan diferensial biasa (PDB) dengan nilai awal**. Metode ini sangat fundamental dalam analisis numerik untuk memodelkan sistem dinamis yang perubahannya dapat dideskripsikan oleh suatu laju.

Studi kasus yang diimplementasikan dalam program ini adalah **pemodelan suhu secangkir kopi yang mendingin seiring waktu, yang dijelaskan oleh Hukum Pendinginan Newton**. Persamaan utama yang menjadi fokus adalah:

$$\frac{dT}{dt} = -k(T - T_a)$$

Metode Euler bekerja secara iteratif dengan mengambil langkah-langkah kecil sepanjang waktu dan menggunakan laju perubahan (garis singgung) pada setiap titik untuk memperkirakan suhu pada titik waktu berikutnya.

## Cara Compile dan Run Program
### Prasyarat
* **Compiler C:** Pastikan sistem Anda memiliki compiler C (misalnya, GCC) yang terinstal.

### Langkah-langkah
1.  **Unduh atau Salin Kode:** Simpan kode sumber dari repositori ini dalam sebuah file dengan nama `euler_cooling.c`.

2.  **Compile Program:** Buka terminal atau *command prompt* pada direktori tempat Anda menyimpan file `.c` dan gunakan perintah berikut untuk mengkompilasi program:

    ```bash
    gcc euler.c -o euler
    ```

    * `gcc`: adalah perintah untuk compiler GCC.
    * `euler.c`: adalah nama file kode sumber Anda.
    * `-o euler`: menentukan nama file output yang akan dieksekusi.

3.  **Jalankan Program:** Setelah kompilasi berhasil, Anda dapat menjalankan program dengan perintah:

    ```bash
    ./euler
    ```

    Program akan meminta Anda untuk memasukkan nilai-nilai berikut:
    * Suhu awal kopi (`T0`)
    * Suhu ruangan/ambien (`Ta`)
    * Waktu akhir simulasi (`t_akhir`)
    * Ukuran langkah/interval waktu (`h`)

    Masukkan nilai yang sesuai dan tekan Enter setelah setiap input.

## Hasil Output Program
![Output](https://hackmd.io/_uploads/HJnEr8b7gg.png)

## Grafik Plot
![Grafik](https://hackmd.io/_uploads/rJ28BUbXlg.png)

## Penjelasan Kode
Untuk penjelasan yang lebih mendalam mengenai teori di balik Metode Euler, implementasi kode, dan analisis hasil, Anda dapat menonton video berikut:

[![Video Penjelasan](https://img.youtube.com/vi/PpI-Qo33NwE/0.jpg)](https://www.youtube.com/watch?v=PpI-Qo33NwE)