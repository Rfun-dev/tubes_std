#include "header.h"
#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n=== Menu Program ===\n";
    cout << "1. Tambah Sutradara\n";
    cout << "2. Tampilkan Semua Sutradara\n";
    cout << "3. Tambah Film\n";
    cout << "4. Tampilkan Semua Relasi Sutradara dan Film\n";
    cout << "5. Tambah Relasi Sutradara dan Film\n";
    cout << "6. Cari Film Berdasarkan Sutradara\n";
    cout << "7. Hapus Relasi Film Berdasarkan Sutradara\n";
    cout << "8. Tampilkan Sutradara dengan Film Tersedikit\n";
    cout << "9. Keluar\n";
    cout << "=====================\n";
    cout << "Pilih menu: ";
}

int main() {
    // Deklarasi struktur data
    ListSutradara S;
    ListFilm F;
    graph G;

    // Inisialisasi list dan graph
    createSutradara(S);
    createFilm(F);
    createGraph(G);

    int pilihan;
    do {
        showMenu();
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer input

        switch (pilihan) {
        case 1: {
            // Tambah Sutradara
            int id, umur;
            string nama;
            cout << "Masukkan ID Sutradara: ";
            cin >> id;
            cin.ignore();
            cout << "Masukkan Nama Sutradara: ";
            getline(cin, nama);
            cout << "Masukkan Umur Sutradara: ";
            cin >> umur;
            addSutradara(S, id, nama, umur);
            cout << "Sutradara berhasil ditambahkan.\n";
            break;
        }
        case 2:
            // Tampilkan Semua Sutradara
            cout << "Daftar Sutradara:\n";
            showAllSutradara(S);
            break;
        case 3: {
            // Tambah Film
            string judul, genre;
            int tahun;
            cout << "Masukkan Judul Film: ";
            cin.ignore();
            getline(cin, judul);
            cout << "Masukkan Tahun Rilis: ";
            cin >> tahun;
            cin.ignore();
            cout << "Masukkan Genre Film: ";
            getline(cin, genre);
            addFilm(F, judul, tahun, genre);
            cout << "Film berhasil ditambahkan.\n";
            break;
        }
        case 4:
            // Tampilkan Semua Relasi Sutradara dan Film
            cout << "Relasi Sutradara dan Film:\n";
            showAllSutradaraAndFilm(G);
            break;
        case 5: {
            // Tambah Relasi Sutradara dan Film
            int idSutradara;
            string judulFilm;
            cout << "Masukkan ID Sutradara: ";
            cin >> idSutradara;
            cin.ignore();
            cout << "Masukkan Judul Film: ";
            getline(cin, judulFilm);
            connection(G, S, F, idSutradara, judulFilm);
            cout << "Relasi berhasil ditambahkan.\n";
            break;
        }
        case 6: {
            // Cari Film Berdasarkan Sutradara
            int id;
            cout << "Masukkan ID Sutradara: ";
            cin >> id;
            adrChild film = searchFilmBySutradara(G, id);
            if (film != NULL) {
                cout << "Film ditemukan: " << infoChild(film).judul << endl;
            } else {
                cout << "Film tidak ditemukan.\n";
            }
            break;
        }
        case 7: {
            // Hapus Relasi Film Berdasarkan Sutradara
            int id;
            cout << "Masukkan ID Sutradara: ";
            cin >> id;
            hapusFilmSutradara(G, F, id);
            cout << "Relasi film sutradara berhasil dihapus.\n";
            break;
        }
        case 8:
            // Tampilkan Sutradara dengan Film Tersedikit
            cout << "Sutradara dengan Film Tersedikit:\n";
            showSutradaraFilmTersedikit(G, S);
            break;
        case 9:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 9);

    return 0;
}
