// DigitalBillboardPlugin - plugin.cpp
//
// Ini adalah "skeleton" (kerangka dasar) plugin X-Plane.
// Tujuannya: memastikan seluruh pipeline (compile via GitHub Actions -> load di X-Plane)
// beneran jalan dulu, sebelum kita nambahin fitur billboard video-nya.
//
// 4 fungsi di bawah ini WAJIB ada di setiap plugin X-Plane:
//   XPluginStart, XPluginStop, XPluginEnable, XPluginDisable

#include "XPLMDefs.h"
#include "XPLMPlugin.h"
#include "XPLMUtilities.h"
#include <cstring>

PLUGIN_API int XPluginStart(char* outName, char* outSig, char* outDesc)
{
    // outName, outSig, outDesc adalah buffer yang sudah dialokasikan X-Plane,
    // kita cukup isi pakai strcpy (JANGAN pakai buffer lebih panjang dari 256 char)
    strcpy(outName, "Digital Billboard Plugin");
    strcpy(outSig, "yourname.digitalbillboard"); // ganti "yourname" sesuai keinginanmu
    strcpy(outDesc, "Menampilkan billboard digital / video di dunia X-Plane.");

    // Baris ini akan muncul di file Log.txt X-Plane kalau plugin berhasil dimuat
    XPLMDebugString("[DigitalBillboard] Plugin started successfully.\n");

    return 1; // return 1 = sukses, X-Plane akan lanjut load plugin ini
}

PLUGIN_API void XPluginStop(void)
{
    XPLMDebugString("[DigitalBillboard] Plugin stopped.\n");
}

PLUGIN_API int XPluginEnable(void)
{
    XPLMDebugString("[DigitalBillboard] Plugin enabled.\n");
    return 1;
}

PLUGIN_API void XPluginDisable(void)
{
    XPLMDebugString("[DigitalBillboard] Plugin disabled.\n");
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFrom, int inMsg, void* inParam)
{
    (void)inFrom;
    (void)inMsg;
    (void)inParam;
    // Nanti di sini kita bisa tangani pesan dari X-Plane / plugin lain kalau perlu.
}

// =====================================================================
// TODO (langkah selanjutnya, belum diimplementasi di skeleton ini):
//   - Generate texture ID pakai XPLMGenerateTextureNumbers
//   - Upload data pixel frame video secara berkala
//   - Gambar quad 3D di posisi billboard pakai texture itu
// Bagian ini yang paling teknis, kita bangun bertahap setelah
// skeleton ini terbukti berhasil di-load X-Plane.
// =====================================================================
