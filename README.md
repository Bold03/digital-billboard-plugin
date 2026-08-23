# Digital Billboard Plugin (X-Plane) — Panduan Build via GitHub Actions

Ini plugin C++ untuk X-Plane. Kamu **tidak perlu install Visual Studio** —
compile-nya jalan otomatis di server GitHub tiap kali kamu upload/ubah kode.

## Langkah 1 — Bikin akun GitHub (kalau belum punya)
Daftar gratis di https://github.com

## Langkah 2 — Bikin repository baru
1. Klik tombol **"New repository"**
2. Kasih nama, misal: `digital-billboard-plugin`
3. Pilih **Public** (biar GitHub Actions gratis tanpa batas)
4. Klik **Create repository** (JANGAN centang "Add README", biar kosong)

## Langkah 3 — Upload semua file di folder ini
Kamu tidak perlu install `git` sama sekali:
1. Di halaman repo yang baru dibuat, klik **"uploading an existing file"**
2. Drag & drop **semua isi folder ini** (termasuk folder `.github` dan `src`,
   pastikan struktur foldernya ikut ke-upload, bukan cuma file di root)
3. Klik **Commit changes**

> Kalau GitHub website agak susah upload folder bersarang (`.github/workflows/...`),
> cara paling gampang: install GitHub Desktop (ringan, cuma ~100MB) lalu
> "Add local repository" -> pilih folder ini -> "Publish repository".

## Langkah 4 — Tunggu proses build
1. Buka tab **"Actions"** di repo kamu
2. Akan muncul workflow run bernama "Build X-Plane Plugin" yang sedang jalan
   (warna kuning = sedang proses, hijau = sukses, merah = gagal)
3. Tunggu sampai selesai (biasanya 1-3 menit)

## Langkah 5 — Download hasilnya
1. Klik workflow run yang sudah selesai (hijau)
2. Scroll ke bawah, ada bagian **"Artifacts"**
3. Download `DigitalBillboardPlugin-win` (kalau kamu pakai Windows)

## Langkah 6 — Pasang ke X-Plane
1. Extract zip yang didownload tadi
2. Kamu akan dapat folder `DigitalBillboardPlugin` (isinya sudah rapi
   sesuai struktur yang X-Plane butuhkan)
3. Copy folder itu ke:
   `X-Plane 12/Resources/plugins/`
4. Buka X-Plane, cek lewat menu **Plugins > Plugin Admin** — plugin
   "Digital Billboard Plugin" harus muncul di daftar dan berstatus enabled

## Langkah 7 — Cek log
Buka file `X-Plane 12/Log.txt`, cari baris:
```
[DigitalBillboard] Plugin started successfully.
```
Kalau baris ini muncul, artinya seluruh pipeline (compile cloud -> load
di X-Plane) sudah berhasil. Baru dari titik ini kita lanjut nambahin
fitur video billboard-nya beneran.

## Kalau ada error waktu build (tab Actions warna merah)
Klik run yang gagal, buka log-nya, copy pesan error-nya, terus kirim ke
saya di chat — saya bantu perbaiki kodenya dari situ.
