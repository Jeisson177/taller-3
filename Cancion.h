#ifndef _CANCION_H
#define _CANCION_H
#include <string>
using namespace std;

class Cancion {

private:
  string artista;
  string genero;
  string titulo;
  string album;

public:
  Cancion();
  Cancion(string titulo, string artista, string album, string genero);
  ~Cancion();
  void setArtista(string artista);
  string getArtista();
  void setTitulo(string titulo);
  string getTitulo();
  void setAlbum(string album);
  string getAlbum();
  void setGenero(string genero);
  string getGenero();
};

#include "Cancion.hxx"
#endif