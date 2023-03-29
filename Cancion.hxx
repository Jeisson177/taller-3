#ifndef _CANCION_HXX
#define _CANCION_HXX
#include "Cancion.h"

Cancion::Cancion(){

}

Cancion::Cancion(string artista,string album,string genero,string titulo){
	this->artista = artista;
	this->titulo = titulo;
	this->album = album;
	this->genero = genero;
}

Cancion::~Cancion(){
	
}

void Cancion::setTitulo(string titulo){
	this->titulo = titulo;

}

string Cancion::getTitulo(){
	return this->titulo;
}

void Cancion::setArtista(string artista){
	this->artista = artista;

}

string Cancion::getArtista(){
	return this->artista;
}

void Cancion::setGenero(string genero){
	this->genero = genero;

}

string Cancion::getGenero(){
	return this->genero;
}

void Cancion::setAlbum(string album){
	this->album = album;

}

string Cancion::getAlbum(){
	return this->album;
}



#endif