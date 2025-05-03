#include "menu.hpp"
using namespace std;

void Menu::showMenu() {
    int option;
    do {
        cout << "---- Hits ----\n\n" << endl;
        playlist.print();
        cout << "\n---- Menu ----" << endl;
        cout << "1. Agregar cancion" << endl;
        cout << "2. Agregar cancion por posicion" << endl;
        cout << "3. Borrar cancion" << endl;
        cout << "4. Salir" << endl;
        cout << "Presione su opcion: ";
        cin >> option;
        cin.ignore();

        system("cls");
        switch(option) {
            case 1:
                addSong();
                pressToContinue();
                break;
            case 2:
                addSongbyPosition();
                pressToContinue();
                break;
            case 3:
                deleteSong();
                pressToContinue();
                break;
            case 4:
                cout << "\n\n\nSaliendo del programa...\n\n" << endl;
                return;
            default:
                cout << "Opcion no valida. " <<endl;
            }
        }
    while(option!=4);
    }

void Menu::addSong() {
    int numSongs;
    cout << "\nNumero de canciones a agregar: ";
    cin >> numSongs;

    // Asegura que la posición en la lista se inicialice en 0
    int currentPosition = 0;

    for (int i = 0; i < numSongs; i++) {
        string name, author, performer;
        int rankingPosition;

        cout << "\nCancion " << (i + 1) << "/" << numSongs << endl;
        cout << "\nNombre de la cancion: ";
        cin.ignore();
        getline(cin, name);
        cout << "Autor: ";
        getline(cin, author);
        cout << "Interprete: ";
        getline(cin, performer);
        cout << "Posicion en el ranking: ";
        cin >> rankingPosition;

        try {
            playlist.insertData(currentPosition, Song(name, author, performer, rankingPosition));
            cout << "Cancion agregada con exito" << endl;
            currentPosition++;
            }
        catch (ListException& e) {
            cout << "Error: " << e.what() << endl;
            }
        }

    cout << "\n---- Hits ----" << endl;
    playlist.print();
    }

void Menu::addSongbyPosition() {
    int numSongs;
    cout << "\nNumero de canciones a agregar: ";
    cin >> numSongs;

    for (int i = 0; i < numSongs; i++) {
        string name, author, performer;
        int rankingPosition;
        int position;

        cout << "\nCancion " << (i + 1) << "/" << numSongs << endl;
        cout << "\nNombre de la cancion: ";
        cin.ignore();
        getline(cin, name);
        cout << "Autor: ";
        getline(cin, author);
        cout << "Interprete: ";
        getline(cin, performer);
        cout << "Posicion en el ranking: ";
        cin >> rankingPosition;
        cout << "Ingrese la posicion en la que se va a agregar la cancion: ";
        cin >> position;

        try {
            playlist.insertData(position, Song(name, author, performer,rankingPosition));
            cout << "Cancion agregada con exito" << endl;
            }
        catch (ListException& e) {
            cerr << "Error: " << e.what() << endl;
            }
        }

    cout << "\n---- Hits ----" << endl;
    playlist.print();
}

void Menu::deleteSong() {
    int position;

    cout << "\nIngrese posicion de la cancion a borrar: ";
    cin >> position;

    try {
        playlist.deleteData(position);
        cout << "Cancion borrada con exito" << endl;
        cout << "\n---- Hits ----" << endl;
        playlist.print();
        }
    catch (ListException& e) {
        cout << "Error: " << e.what() << endl;
        }
    }

void Menu::pressToContinue() {
    cout<<"\n\nPresione cualquier tecla para continuar... "<<endl;
    getch();
    system("cls");
    }
