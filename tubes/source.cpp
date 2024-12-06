#include "header.h"
#include <iostream>

using namespace std;

void createSutradara(ListSutradara &S){
    firstParent(S) = NULL;
};

adrParent createElmSutradara(int id, string nama, int umur) {
    adrParent S = new elmSutradara;
    infoParent(S).id = id;
    infoParent(S).nama = nama;
    infoParent(S).umur = umur;
    nextParent(S) = NULL;
    return S;
}

//point a
void addSutradara(ListSutradara &S, int id, string nama, int umur) {
    adrParent elmSutradara = createElmSutradara(id, nama, umur);
    if (firstParent(S) == NULL) {
        firstParent(S) = elmSutradara;
    } else {
        adrParent temp = firstParent(S);
        while (nextParent(temp) != NULL) {
            temp = nextParent(temp);
        }
        nextParent(temp) = elmSutradara;
    }
}


//point b
void showAllSutradara(ListSutradara &S) {
    adrParent temp = firstParent(S);
    if (temp == NULL) {
        cout << "Tidak ada data sutradara" << endl;
    } else {
        while (temp != NULL) {
            cout << "Nama: " << infoParent(temp).nama << ", Umur: " << infoParent(temp).umur << endl;
            temp = nextParent(temp);
        }
    }
}

//point c
void deleteSutradara(graph &G,ListSutradara &S,int id){
     adrParent prev = NULL;
    adrParent curr = searchSutradara(S, id);
    if (curr != NULL) {
        adrvertex vertexPrev = NULL;
        adrvertex vertexCurr = start(G);
        while (vertexCurr != NULL) {
            if (edgeParent(vertexCurr) == curr) {
                if (vertexPrev == NULL) {
                    start(G) = nextVertex(vertexCurr);
                } else {
                    nextVertex(vertexPrev) = nextVertex(vertexCurr);
                }
                // Hapus vertex
                nextVertex(vertexCurr) = NULL;
                edgeChild(vertexCurr) = NULL;
                edgeParent(vertexCurr) = NULL;
            }
            vertexPrev = vertexCurr;
            vertexCurr = nextVertex(vertexCurr);
        }
        if (prev == NULL) {
            firstParent(S) = nextParent(curr);
        } else {
            nextParent(prev) = nextParent(curr);
        }
        nextParent(curr) = NULL;
    }
};

//poin d
adrParent searchSutradara(ListSutradara S, int id){
    adrParent temp = firstParent(S);
    while (temp != NULL) {
        if (infoParent(temp).id == id) {
            return temp;
        }
        temp = nextParent(temp);
    }
    return NULL;
};

void createFilm(ListFilm &F){
    firstChild(F) = NULL;
    lastChild(F) = NULL;
};

adrChild createElmFilm(string judul, int tahun, string genre) {
    adrChild baru = new elmFilm;
    infoChild(baru).judul = judul;
    infoChild(baru).tahun = tahun;
    infoChild(baru).genre = genre;
    nextChild(baru) = NULL;
    prevChild(baru) = NULL;
    return baru;
};

//poin e
void addFilm(ListFilm &F, string judul, int tahun, string genre) {
    adrChild baru = createElmFilm(judul, tahun, genre);
    if (firstChild(F) == NULL) {
        firstChild(F) = baru;
        lastChild(F) = baru;
    } else {
        prevChild(baru) = lastChild(F);
        nextChild(lastChild(F)) = baru;
        lastChild(F) = baru;
    }
};


//poin f
adrChild searchFilm(ListFilm F, string judul) {
    adrChild temp = firstChild(F);
    while (temp != NULL) {
        if (infoChild(temp).judul == judul) {
            return temp;
        }
        temp = nextChild(temp);
    }
    return NULL;
};

void createGraph(graph &G) {
    start(G) = NULL;
};

adrvertex createElmVertex(adrParent sutradara, adrChild film) {
    adrvertex v = new vertex;
    edgeChild(v) = film;
    edgeParent(v) = sutradara;
    nextVertex(v) = NULL;
    return v;
};


//poin g
void connection(graph &G, ListSutradara &S, ListFilm &F, int id, string judulFilm) {
    adrParent sutradara = searchSutradara(S, id);
    if (sutradara == NULL) {
        cout << "Sutradara dengan ID " << id << " tidak ditemukan.\n";
        return;
    }
    adrChild film = searchFilm(F, judulFilm);
    if (film == NULL) {
        cout << "Film dengan judul " << judulFilm << " tidak ditemukan.\n";
        return;
    }
    int relatiCount = 0;
    adrvertex current = start(G);
    while (current != NULL) {
        if (edgeChild(current) == film) {
            relatiCount++;
        }
        current = nextVertex(current);
    }
    if (relatiCount >= 2) {
        cout << "Film " << judulFilm << " sudah memiliki 2 relasi. Tidak dapat menambahkan relasi baru.\n";
        return;
    }
    adrvertex newVertex = createElmVertex(sutradara, film);
    if (start(G) == NULL) {
        start(G) = newVertex;
    } else {
        adrvertex temp = start(G);
        while (nextVertex(temp) != NULL) {
            temp = nextVertex(temp);
        }
        nextVertex(temp) = newVertex;
    }
};

//poin h
void showAllSutradaraAndFilm(graph G) {
    adrvertex v = start(G);
    if (v == NULL) {
        cout << "Graph Kosong\n";
    } else {
        while (v != NULL) {
            cout << "===================\n";
            cout << "Sutradara: " << infoParent(edgeParent(v)).nama << endl;
            cout << "Film: " << infoChild(edgeChild(v)).judul << endl;
            cout << "===================\n";
            v = nextVertex(v);
        }
    }
};

//poin i
adrChild searchFilmBySutradara(graph G, int id) {
    adrvertex v = start(G);
    if (v == NULL) {
        cout << "Graph Kosong\n";
        return NULL;
    } else {
        while (v != NULL) {
            if (infoParent(edgeParent(v)).id == id) {
                return edgeChild(v);
            }
            v = nextVertex(v);
        }
    }
    return NULL;
};

//poin j
void hapusFilmSutradara(graph &G, ListFilm &F, int id) {
    adrvertex currVertex = start(G);
    adrvertex prevVertex = NULL;
    while (currVertex != NULL) {
        if (infoParent(edgeParent(currVertex)).id == id) {
            adrChild currFilm = edgeChild(currVertex);
            adrChild prevFilm = NULL;
            adrChild tempFilm = firstChild(F);

            while (tempFilm != NULL) {
                if (tempFilm == currFilm) {
                    if (prevFilm == NULL) {
                        firstChild(F) = nextChild(tempFilm);
                    } else {
                        nextChild(prevFilm) = nextChild(tempFilm);
                    }
                    if (nextChild(tempFilm) != NULL) {
                        prevChild(nextChild(tempFilm)) = prevFilm;
                    }
                    nextChild(tempFilm) = NULL;
                    prevChild(tempFilm) = NULL;
                }
                prevFilm = tempFilm;
                tempFilm = nextChild(tempFilm);
            }

            if (prevVertex == NULL) {
                start(G) = nextVertex(currVertex);
            } else {
                nextVertex(prevVertex) = nextVertex(currVertex);
            }
            nextVertex(currVertex) = NULL;
            edgeParent(currVertex) = NULL;
            edgeChild(currVertex) = NULL;
        }
        prevVertex = currVertex;
        currVertex = nextVertex(currVertex);
    }
};

//poin k
void showSutradaraFilmTersedikit(graph G, ListSutradara S) {
    if (start(G) == NULL) {
        cout << "Graph Kosong\n";
        return;
    }

    adrParent sutradaraMin = NULL;
    int minFilmCount = INT_MAX;
    adrParent sutradara = firstParent(S);
    while (sutradara != NULL) {
        int filmCount = 0;
        adrvertex v = start(G);
        while (v != NULL) {
            if (edgeParent(v) == sutradara) {
                filmCount++;
            }
            v = nextVertex(v);
        }
        if (filmCount < minFilmCount) {
            minFilmCount = filmCount;
            sutradaraMin = sutradara;
        }

        sutradara = nextParent(sutradara);
    }

    if (sutradaraMin != NULL) {
        cout << "Sutradara dengan film tersedikit:\n";
        cout << "Nama: " << infoParent(sutradaraMin).nama << endl;
        cout << "Jumlah Film: " << minFilmCount << endl;
    } else {
        cout << "Tidak ada sutradara dengan data film.\n";
    }
};

