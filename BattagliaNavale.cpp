#include <iostream>
#include <ctime>
#ifndef reset
#define RES "\x1b[0m"     //reset
#define BOL "\x1b[1m"     //bold
#define ITAL "\x1b[3m"     //italic
#define UNDE "\x1b[4m"       //underline
#define inv "\x1b[7m"     //inverse
#define Black "\x1b[30m"      //color black
#define Red "\x1b[31m"        //color red
#define Green "\x1b[32m"      //color green
#define Yellow "\x1b[33m"     //color yellow
#define Blue "\x1b[34m"       //color blue
#define Magenta "\x1b[35m"    //color magenta
#define Cyan "\x1b[36m"       //color cyan
#define White "\x1b[37m"      //color while
#define Gray "\x1b[90m"       //color gray
#define Bred "\x1b[91m"     //color bright red
#define Bgreen "\x1b[92m"   //color bright green
#define Byellow "\x1b[93m"  //color bright yellow
#define Bblue "\x1b[94m"    //color bright blue
#define Bmagenta "\x1b[95m" //color bright magenta
#define Bcyan "\x1b[96m"    //color bright cyan
#define Bwhite "\x1b[97m"   //color bright white
#define color_bg_black "\x1b[40m"
#define color_bg_red "\x1b[41m"
#define color_bg_green "\x1b[42m"
#define color_bg_yellow "\x1b[43m"
#define color_bg_blue "\x1b[44m"
#define color_bg_magenta "\x1b[45m"
#define color_bg_cyan "\x1b[46m"
#define color_bg_white "\x1b[47m"
#define color_bg_gray "\x1b[100m"
#define color_bg_bright_red "\x1b[101m"
#define color_bg_bright_green "\x1b[102m"
#define color_bg_bright_yellow "\x1b[103m"
#define color_bg_bright_blue "\x1b[104m"
#define color_bg_bright_magenta "\x1b[105m"
#define color_bg_bright_cyan "\x1b[106m"
#define color_bg_bright_white "\x1b[107m"
#endif
using namespace std;

void riempimentoMatrice(char matrice[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrice[i][j] = ' ';
        }
    }
}

void stampaTabella(char matrice[10][10])
{
    int numero_riga = 1;
    cout << Bred << "\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t10" << RES << endl << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                cout << Bred << numero_riga << RES;
                numero_riga++;
            }
            switch (matrice[i][j]) {
            case 'X': cout << "\t[" << Red << "X" << RES << "]"; break;
            case ' ': cout << "\t[ ]"; break;
            case 'M': cout << "\t[" << Blue << "M" << RES << "]"; break;
            case 'C': cout << "\t[" << Red << "C" << RES << "]"; break;
            }
        }
        cout << endl << endl;
    }
}

bool controllaPosizionamentoValidoOrriz(int grandezza_nave, int posizione_colonna, int posizione_riga, char matrice[10][10])
{
    bool libero = true;
    switch (grandezza_nave)
    {
    case 1:
        if ((posizione_colonna <= 10 && posizione_colonna >= 1) && (posizione_riga <= 10 && posizione_riga >= 1)) {
            if (matrice[posizione_riga - 1][posizione_colonna - 1] == 'X') {
                libero = false;
            }
        }
        else {
            libero = false;
        } break;
    case 2:
        if ((posizione_colonna <= 9 && posizione_colonna >= 1) && (posizione_riga <= 10 && posizione_riga >= 1)) {
            for (int i = 0; i < 2; i++) {
                if (matrice[posizione_riga - 1][posizione_colonna + i - 1] == 'X') {
                    libero = false;
                }
            }
        }
        else {
            libero = false;
        } break;
    case 3:
        if ((posizione_colonna <= 8 && posizione_colonna >= 1) && (posizione_riga <= 10 && posizione_riga >= 1)) {
            for (int i = 0; i < 3; i++) {
                if (matrice[posizione_riga - 1][posizione_colonna + i - 1] == 'X') {
                    libero = false;
                }
            }
        }
        else {
            libero = false;
        } break;
    case 4:
        if ((posizione_colonna <= 7 && posizione_colonna >= 1) && (posizione_riga <= 10 && posizione_riga >= 1)) {
            for (int i = 0; i < 4; i++) {
                if (matrice[posizione_riga - 1][posizione_colonna + i - 1] == 'X') {
                    libero = false;
                }
            }
        }
        else {
            libero = false;
        } break;
    }
    return libero;
}

bool controllaPosizionamentoValidoVerti(int grandezza_nave, int posizione_colonna, int posizione_riga, char matrice[10][10])
{
    bool libero = true;
    switch (grandezza_nave)
    {
    case 1:
        if ((posizione_colonna <= 10 && posizione_colonna >= 1) && (posizione_riga <= 10 && posizione_riga >= 1)) {
            if (matrice[posizione_riga - 1][posizione_colonna - 1] == 'X') {
                libero = false;
            }
        }
        else {
            libero = false;
        } break;
    case 2:
        if ((posizione_colonna <= 10 && posizione_colonna >= 1) && (posizione_riga <= 9 && posizione_riga >= 1)) {
            for (int i = 0; i < 2; i++) {
                if (matrice[posizione_riga + i - 1][posizione_colonna - 1] == 'X') {
                    libero = false;
                }
            }
        }
        else {
            libero = false;
        } break;
    case 3:
        if ((posizione_colonna <= 10 && posizione_colonna >= 1) && (posizione_riga <= 8 && posizione_riga >= 1)) {
            for (int i = 0; i < 3; i++) {
                if (matrice[posizione_riga + i - 1][posizione_colonna - 1] == 'X') {
                    libero = false;
                }
            }
        }
        else {
            libero = false;
        } break;
    case 4:
        if ((posizione_colonna <= 10 && posizione_colonna >= 1) && (posizione_riga <= 7 && posizione_riga >= 1)) {
            for (int i = 0; i < 4; i++) {
                if (matrice[posizione_riga + i - 1][posizione_colonna - 1] == 'X') {
                    libero = false;
                }
            }
        }
        else {
            libero = false;
        } break;
    }
    return libero;
}

bool controlloNrBarche(int numero_nave, int& n1, int& n2, int& n3, int& n4) {
    bool valido = true;
    switch (numero_nave)
    {
    case 1:
        if (n1 == 0) {
            valido = false;
        }break;
    case 2:
        if (n2 == 0) {
            valido = false;
        }break;
    case 3:
        if (n3 == 0) {
            valido = false;
        }break;
    case 4:
        if (n4 == 0) {
            valido = false;
        }break;
    }
    return valido;
}

void controlloBarcaLibera(int numero_nave, int& n1, int& n2, int& n3, int& n4) {
    switch (numero_nave)
    {
    case 1: n1--; break;
    case 2: n2--; break;
    case 3: n3--; break;
    case 4: n4--; break;
    }
}

void inserimentoBarcheOrriz(char matrice[10][10], int grandezza_nave, int posizione_colonna, int posizione_riga) {
    int i = posizione_riga - 1;
    int j = posizione_colonna - 1;
    switch (grandezza_nave) {
    case 1:
        matrice[i][j] = 'X';
        break;
    case 2:
        matrice[i][j] = 'X';
        matrice[i][j + 1] = 'X';
        break;
    case 3:
        matrice[i][j] = 'X';
        matrice[i][j + 1] = 'X';
        matrice[i][j + 2] = 'X';
        break;
    case 4:
        matrice[i][j] = 'X';
        matrice[i][j + 1] = 'X';
        matrice[i][j + 2] = 'X';
        matrice[i][j + 3] = 'X';
        break;
    }
}

void inserimentoBarcheVerti(char matrice[10][10], int grandezza_nave, int posizione_colonna, int posizione_riga) {
    int i = posizione_riga - 1;
    int j = posizione_colonna - 1;
    switch (grandezza_nave) {
    case 1:
        matrice[i][j] = 'X';
        break;
    case 2:
        matrice[i][j] = 'X';
        matrice[i + 1][j] = 'X';
        break;
    case 3:
        matrice[i][j] = 'X';
        matrice[i + 1][j] = 'X';
        matrice[i + 2][j] = 'X';
        break;
    case 4:
        matrice[i][j] = 'X';
        matrice[i + 1][j] = 'X';
        matrice[i + 2][j] = 'X';
        matrice[i + 3][j] = 'X';
        break;
    }
}


void stampaTabellaFaseRiempimento(char matrice[10][10], int mod)
{
    riempimentoMatrice(matrice);
    bool riempimento_navi = true;
    int nave1cella = 1, nave2cella = 2, nave3cella = 2, nave4cella = 1;
    int navi_rimanenti;
    int nr_nave;
    bool controllo_pos_valida_generale;
    int colonna, riga;
    bool check_nr_barche;
    int senso_pos;
    srand(time(NULL));

    while (riempimento_navi == true)
    {
        system("cls");
        switch (mod)
        {
        case 1:
            cout << Yellow << "Modalita:" << RES << " giocatore contro giocatore con un campo" << endl << endl;
            break;
        case 2:
            cout << Yellow << "Modalita:" << RES << " giocatore contro PC" << endl << endl;
            break;
        }
        stampaTabella(matrice);
        cout << endl;
        cout << "1) Nave a 1 cella = " << Cyan << nave1cella << RES << "\t" << "[" << Red << "X" << RES << "] " << endl;
        cout << "2) Nave a 2 celle = " << Cyan << nave2cella << RES << "\t";
        for (int i = 0; i < 2; i++) {
            cout << "[" << Red << "X" << RES << "] ";
        }
        cout << endl;
        cout << "3) Nave a 3 celle = " << Cyan << nave3cella << RES << "\t";
        for (int i = 0; i < 3; i++) {
            cout << "[" << Red << "X" << RES << "] ";
        }
        cout << endl;
        cout << "4) Nave a 4 celle = " << Cyan << nave4cella << RES << "\t";
        for (int i = 0; i < 4; i++) {
            cout << "[" << Red << "X" << RES << "] ";
        }
        cout << endl;

        do
        {
            cout << endl << "Inserire numero nave(1-4): ";

            switch (mod)
            {
            case 1: cin >> nr_nave; break;
            case 2: nr_nave = rand() % 4 + 1; break;
            default:
                break;
            }

            check_nr_barche = controlloNrBarche(nr_nave, nave1cella, nave2cella, nave3cella, nave4cella);
            if (nr_nave <= 4 && nr_nave >= 1 && check_nr_barche == true) {
                do {
                    cout << "Inserire tipologia poszionamento 1)orrizontale 2)verticale: ";
                    switch (mod)
                    {
                    case 1: cin >> senso_pos; break;
                    case 2: senso_pos = rand() % 2 + 1; break;
                    default:
                        break;
                    }
                } while (senso_pos > 2 || senso_pos < 1);
                cout << "Inserire coordinate(colonna/riga): ";

                switch (mod)
                {
                case 1: cin >> colonna >> riga; break;
                case 2:
                    colonna = rand() % 10 + 1;
                    riga = rand() % 10 + 1;
                    break;
                default:
                    break;
                }

                if (senso_pos == 1) {
                    controllo_pos_valida_generale = controllaPosizionamentoValidoOrriz(nr_nave, colonna, riga, matrice);
                }
                else {
                    controllo_pos_valida_generale = controllaPosizionamentoValidoVerti(nr_nave, colonna, riga, matrice);
                }

            }
            if (nr_nave <= 4 && nr_nave >= 1 && check_nr_barche == true && controllo_pos_valida_generale == true) {
                controlloBarcaLibera(nr_nave, nave1cella, nave2cella, nave3cella, nave4cella);
            }
        } while ((nr_nave > 4 || nr_nave < 1) && (check_nr_barche == false) && (controllo_pos_valida_generale == false));

        if (controllo_pos_valida_generale == true) {
            if (senso_pos == 1) {
                inserimentoBarcheOrriz(matrice, nr_nave, colonna, riga);
            }
            else {
                inserimentoBarcheVerti(matrice, nr_nave, colonna, riga);
            }
        }

        navi_rimanenti = nave1cella + nave2cella + nave3cella + nave4cella;

        if (navi_rimanenti == 0)
        {
            riempimento_navi = false;
        }
        system("cls");
    }
    stampaTabella(matrice);
    cout << endl;
    cout << "1) Nave a 1 cella = " << Cyan << nave1cella << RES << "\t" << "[" << Red << "X" << RES << "] " << endl;
    cout << "2) Nave a 2 celle = " << Cyan << nave2cella << RES << "\t";
    for (int i = 0; i < 2; i++) {
        cout << "[" << Red << "X" << RES << "] ";
    }
    cout << endl;
    cout << "3) Nave a 3 celle = " << Cyan << nave3cella << RES << "\t";
    for (int i = 0; i < 3; i++) {
        cout << "[" << Red << "X" << RES << "] ";
    }
    cout << endl;
    cout << "4) Nave a 4 celle = " << Cyan << nave4cella << RES << "\t";
    for (int i = 0; i < 4; i++) {
        cout << "[" << Red << "X" << RES << "] ";
    }
    cout << endl;
}

bool verificaColpoBuonoSbagliato(char matrice_barche[10][10], int posizione_colonna, int posizione_riga, char matrice_colpi[10][10]) {
    bool verifica;
    if (matrice_barche[posizione_riga - 1][posizione_colonna - 1] == 'X') {
        matrice_colpi[posizione_riga - 1][posizione_colonna - 1] = 'C';
        verifica = true;
    }
    else {
        matrice_colpi[posizione_riga - 1][posizione_colonna - 1] = 'M';
        verifica = false;
    }
    return verifica;
}

void faseGioco(char matrice_con_pos_navi[10][10]) {
    char matrice_con_pos_colpi[10][10];
    riempimentoMatrice(matrice_con_pos_colpi);
    char var_inutile;
    float celle_beccate = 0;
    float celle_non_beccate = 0;
    int colonna, riga;
    bool valore_colpo;

    cout << endl << "Inserisci qualsiasi lettera per far incominciare il gioco: ";
    cin >> var_inutile;

    while (celle_beccate < 15) {
        system("cls");
        stampaTabella(matrice_con_pos_colpi);
        cout << endl;
        cout << "Cella mancata = [" << Blue << "M" << RES << "]" << endl;
        cout << "Cella colpita = [" << Red << "C" << RES << "]" << endl;
        cout << "Inserire coordinate colpo(colonna/riga): ";
        cin >> colonna >> riga;
        while ((colonna > 10 || colonna < 1) || (riga > 10 || riga < 1)) {
            cout << "Coordinata non valida!" << endl;
            cout << "Inserire coordinate colpo(colonna/riga): ";
            cin >> colonna >> riga;
        }
        valore_colpo = verificaColpoBuonoSbagliato(matrice_con_pos_navi, colonna, riga, matrice_con_pos_colpi);
        if (valore_colpo == true) {
            if (matrice_con_pos_colpi[riga][colonna] == ' ') {
                celle_beccate++;
            }
        }
        else {
            celle_non_beccate++;
        }
    }
    system("cls");
    stampaTabella(matrice_con_pos_colpi);
    cout << endl;
    cout << "HAI VINTO!" << endl;
    cout << "In totale hai utilizzato " << celle_beccate + celle_non_beccate << " colpi." << endl;
    cout << "I colpi che sono andati a segno sono: " << celle_beccate << endl;
    float percentuale = ((celle_beccate) / (celle_beccate + celle_non_beccate)) * 100;
    cout << "La percentuale di precizine e': " << percentuale << "%" << endl;
}

int main()
{
    int modalita;
    string primo_giocatore, secondo_giocatore;
    char campo_navale_giocatore_uno[10][10];
    char campo_navale_giocatore_due[10][10];
    cout << Byellow <<"######################################" << endl;
    cout << "#" << Yellow <<"    BENVENUTI A BATTAGLIA NAVALE    " << Byellow << "#" << endl;
    cout << "######################################" << RES << endl;
    cout << endl << Bcyan << "######################################" << endl;
    cout << "#" << Cyan << "          By Zago & Hamayal         " << Bcyan << "#" << endl;
    cout << "#" << Cyan << "                                    " << Bcyan << "#" << endl;
    cout << "#" << Cyan << " MODALITA':                         " << Bcyan << "#" << endl;
    cout << "#" << Cyan << " 1)" << White << "P VS P" << Byellow << " [una tabella]             " << Bcyan << "#" << endl;
    cout << "#" << Cyan << " 2)" << White << "P VS PC" << Byellow << " [una tabella]            " << Bcyan << "#" << endl;
    cout << "#" << Cyan << " 3)" << White << "P VS P" << Byellow << " [due tabelle]             " << Bcyan << "#" << endl;
    cout << "#" << Cyan << "                                    " << Bcyan << "#" << endl;
    cout << "######################################" << RES << endl;
    cout << endl;
    cout << Bred << "Inserire modalità: " << RES;
    cin >> modalita;

    switch (modalita)
    {
    case 1:
        stampaTabellaFaseRiempimento(campo_navale_giocatore_uno, modalita);
        faseGioco(campo_navale_giocatore_uno);
        break;
    case 2:
        stampaTabellaFaseRiempimento(campo_navale_giocatore_uno, modalita);
        faseGioco(campo_navale_giocatore_uno);
        break;
    case 3:
        system("cls");
        cout << "Inserire nome giocatore numero 1: ";
        cin >> primo_giocatore;
        cout << "Inserire nome giocatore numero 2: ";
        cin >> secondo_giocatore;
        //stampaTabellaFaseRiempimentoMultiPlayer(campo_navale_giocatore_uno, modalita);
        stampaTabellaFaseRiempimento(campo_navale_giocatore_due, modalita);
        faseGioco(campo_navale_giocatore_uno);
        break;
    }
}
