#include <stdio.h>
#include <time.h>

typedef struct {
    int yil;
    int ay;
    int gun;
    int saat;
    int dakika;
    int saniye;
} TarihSaat;

typedef union {
    TarihSaat tarihSaat;
    time_t epochZamani;
} TarihBirlestir;

time_t epochCevir(TarihSaat ts) {
    struct tm t;
    t.tm_year = ts.yil - 1900;
    t.tm_mon = ts.ay - 1;
    t.tm_mday = ts.gun;
    t.tm_hour = ts.saat;
    t.tm_min = ts.dakika;
    t.tm_sec = ts.saniye;
    t.tm_isdst = -1;

    return mktime(&t);
}

int main() {
    TarihBirlestir mesaiBaslangici, mesaiBitisi;
    printf("Mesainin basladigi tarihi ve saati giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &mesaiBaslangici.tarihSaat.yil, &mesaiBaslangici.tarihSaat.ay, &mesaiBaslangici.tarihSaat.gun, &mesaiBaslangici.tarihSaat.saat, &mesaiBaslangici.tarihSaat.dakika, &mesaiBaslangici.tarihSaat.saniye);

    printf("Mesainin bittigi tarihi ve saati giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &mesaiBitisi.tarihSaat.yil, &mesaiBitisi.tarihSaat.ay, &mesaiBitisi.tarihSaat.gun, &mesaiBitisi.tarihSaat.saat, &mesaiBitisi.tarihSaat.dakika, &mesaiBitisi.tarihSaat.saniye);

    mesaiBaslangici.epochZamani = epochCevir(mesaiBaslangici.tarihSaat);
    mesaiBitisi.epochZamani = epochCevir(mesaiBitisi.tarihSaat);

    double fark = difftime(mesaiBitisi.epochZamani, mesaiBaslangici.epochZamani);

    printf("Mesainin basladigi zamanin epoch zamani: %ld\n", mesaiBaslangici.epochZamani);
    printf("Mesainin bittigi zamanin epoch zamani: %ld\n", mesaiBitisi.epochZamani);
    printf("Mesai suresi saniye cinsinden: %.f\n", fark);

    // Saat cinsinden zaman farkini hesapla
    double saatFarki = fark / 3600.0;
    printf("Gunluk toplam mesai suresi: %.2f saat\n", saatFarki);

    return 0;
}

