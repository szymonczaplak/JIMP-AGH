#ifndef multiplayer2_h
#define multiplayer2_h

enum wartosci{WARTOSC_O = -1, WARTOSC_X = 1};
enum trudnosc {TRUDNOSC_SZYMPANS = 1, TRUDNOSC_CZLOWIEK = 2, TRUDNOSC_PRO = 3};

int wczytanie_deklaracji(void);

int wczytaj_symbol_gracza(void);

void ruch_gracz_2(int wybor_gracza2, int tablica[3][3]);

void gracz2(void);

int sprawdzam_poziom(int tryb, int tablica[3][3]);

int sprawdzam_pion(int tryb, int tablica[3][3]);

int sprawdzam_skosy(int tryb, int tablica[3][3]);

int zagrozenie(int tryb, int tablica[3][3]);

int poziom_trudnosci(void);

void ruch_szympansa(int tablica[3][3]);

void ruch_komputera(int tablica[3][3]);

void ruch_pierwszy(int tablica [3][3]);

int ruch_drugi(int tablica [3][3]);

void ruch_trzeci(int scenariusz, int tablica [3][3]);

int strategiczny_ruch_komputera(int ktory, int scenariusz, int tablica[3][3]);

void ruch_gracz_1(int wybor_gracza1, int tablica[3][3]);

int czysc_tablice(int tablica[3][3]);

void wypisz_tablice(int tablica[3][3]);

void gracz1(void);

void ruch(int wybor, int  tablica[3][3]);

int wczytaj_wspolrzedna(char tekst[]);

int werdykt_wygranej(int suma);

int sprawdz_wygrana(int tablica[3][3]);

int tryb_gry(void);

#endif
