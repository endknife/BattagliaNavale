#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const string nomefile = "archivio.dat";

struct studente
{
    string nome;
    string cognome;
    int debiti;
}studenti[2];

void readFromFile();

void writToFile();

int main()
{
    int mod;
    cout << "LETTURA SRITTURA DA FILE" << endl << endl;
    cout << "1| Lettura" << endl;
    cout << "2| Scrittura" << endl << endl;
    cout << "Scegli la modalita: ";
    cin >> mod;

    switch (mod)
    {
    case 1:
        readFromFile();
        break;
    case 2:
        writToFile();
        break;
    
    default:
        break;
    }
}

void writToFile(){
    int c = 0;
    fstream file;
    file.open(nomefile.c_str(), ios::out | ios::binary);
    if(file.is_open()){
        while(c < 2){
            cout << "Inserire il nome: ";
            cin >> studenti[c].nome;
            cout << "Inserire il cognome: ";
            cin >> studenti[c].cognome;
            cout << "Inserire i debiti: ";
            cin >> studenti[c].debiti;
            file.write((char*)studenti[c], sizeof(studenti));
            c++;
        }
        file.close();
    }
}
