#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define firstParent(P) P.firstParent
#define nextParent(P) P->nextParent
#define infoParent(P) P->infoParent

#define firstChild(P) P.firstChild
#define lastChild(P) P.lastChild
#define nextChild(P) P->nextChild
#define prevChild(P) P->prevChild
#define infoChild(P) P->infoChild

#define start(G) G.start
#define nextVertex(G) G->nextVertex
#define edgeParent(G) G->edgeParent
#define edgeChild(G) G->edgeChild
#include <iostream>

using namespace std;

struct film{
     string judul;
     int tahun;
     string genre;
     int totalSutradara;
};

struct sutradara{
    int id;
    string nama;
    int umur;
};

typedef sutradara *adrParent;
typedef film *adrChild;
typedef vertex *adrvertex;

struct vertex{
    adrvertex nextVertex;
    adrParent edgeParent;
    adrChild edgeChild;
};

//single linked list
struct elmSutradara{
    sutradara infoParent;
    adrParent nextParent;
};

//double linked list
struct elmFilm{
    film infoChild;
    adrChild nextChild;
    adrChild prevChild;
};

struct ListSutradara{
    adrParent firstParent;
};

struct ListFilm{
    adrChild firstChild;
    adrChild lastChild;
};


struct graph{
    adrvertex start;
};
void createSutradara(ListSutradara &S);
adrParent createElmSutradara(int id, string nama, int umur);
void addSutradara(ListSutradara &S, int id, string nama, int umur);
void showAllSutradara(ListSutradara &S);
void deleteSutradara(graph &G,ListSutradara &S,int id);
adrParent searchSutradara(ListSutradara S, int id);
void createFilm(ListFilm &F);
adrChild createElmFilm(string judul, int tahun, string genre);
void addFilm(ListFilm &F, string judul, int tahun, string genre);
adrChild searchFilm(ListFilm F, string judul) ;
void createGraph(graph &G);
adrvertex createElmVertex(adrParent sutradara, adrChild film);
void connection(graph &G, ListSutradara &S, ListFilm &F, int id, string judulFilm);
void showAllSutradaraAndFilm(graph G);
adrChild searchFilmBySutradara(graph G, int id) ;
void hapusFilmSutradara(graph &G, ListFilm &F, int id);
void showSutradaraFilmTersedikit(graph G, ListSutradara S);


#endif // HEADER_H_INCLUDED
