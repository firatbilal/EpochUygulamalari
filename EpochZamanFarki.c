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
    t.tm_year = ts.yil - 1900;  // tm_year 1900 yilindan itibaren olan yildir
    t.tm_mon = ts.ay - 1;       // tm_mon Ocak'tan itibaren olan aydir
    t.tm_mday = ts.gun;
    t.tm_hour = ts.saat;
    t.tm_min = ts.dakika;
    t.tm_sec = ts.saniye;
    t.tm_isdst = -1;  // Yaz saati uygulamasi bayragi

    return mktime(&t);
}

int main() {
    TarihBirlestir tarih1, tarih2;
    printf("Ilk tarihi giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &tarih1.tarihSaat.yil, &tarih1.tarihSaat.ay, &tarih1.tarihSaat.gun, &tarih1.tarihSaat.saat, &tarih1.tarihSaat.dakika, &tarih1.tarihSaat.saniye);

    printf("Ikinci tarihi giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &tarih2.tarihSaat.yil, &tarih2.tarihSaat.ay, &tarih2.tarihSaat.gun, &tarih2.tarihSaat.saat, &tarih2.tarihSaat.dakika, &tarih2.tarihSaat.saniye);

    tarih1.epochZamani = epochCevir(tarih1.tarihSaat);
    tarih2.epochZamani = epochCevir(tarih2.tarihSaat);

    double fark = difftime(tarih2.epochZamani, tarih1.epochZamani);

    printf("Ilk tarihin epoch zamani: %ld\n", tarih1.epochZamani);
    printf("Ikinci tarihin epoch zamani: %ld\n", tarih2.epochZamani);
    printf("Zaman farki saniye cinsinden: %.f\n", fark);

    return 0;
}

