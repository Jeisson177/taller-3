#ifndef _AVLNODE_HXX
#define _AVLNODE_HXX
#include "AvlNode.h"
#include "Cancion.h"

template<class T>
AvlNode<T>::AvlNode(){
	
}

template <class T> 
AvlNode<T>::AvlNode(Cancion can) {

  	this->left_ch = NULL;
  	this->right_ch = NULL;
	this->agregarCancion(can);
	
}

template<class T>
void AvlNode<T>::agregarCancion(Cancion can){
	
	this->songs.push_back(can);

}

template <class T> AvlNode<T>::~AvlNode() {

  if (this->left_ch)
    delete this->left_ch;
  if (this->right_ch)
    delete this->right_ch;
}

template <class T> void AvlNode<T>::setLeft_ch(AvlNode<T> *&nLeft_ch) {

  this->left_ch = nLeft_ch;
}

template <class T> void AvlNode<T>::setSongList(Cancion song){
  list<Cancion> songs;
  songs.push_back(song);
  this->songs = songs;

}
template <class T> void AvlNode<T>::setRight_ch(AvlNode<T> *&nRight_ch) {

  this->right_ch = nRight_ch;
}

template <class T> AvlNode<T> *AvlNode<T>::getRight_ch() {

  return this->right_ch;
}

template <class T> AvlNode<T> *AvlNode<T>::getLeft_ch() {

  return this->left_ch;
}

template <class T> list<Cancion> AvlNode<T>::getSongList(){

  return this->songs;
}

template <class T> int AvlNode<T>::compareTo(T Titulo) {

  if (this->Titulo > Titulo) {
    return 1;
  } else if (this->Titulo < Titulo) {
    return -1;
  } else {
    return 0;
  }
}

template <class T> int AvlNode<T>::compareTo(AvlNode<T> *&c) {

  if (this->Titulo > c->getTitulo()) {
    return 1;
  } else if (this->Titulo < c->getTitulo()) {
    return -1;
  } else {
    return 0;
  }
}

template <class T> string AvlNode<T>::toString(int level, string root) {

  string ret = "";
  for (int i = 0; i < level; i++)
    ret += "\t\t";
  ret += root;
  ret += this->toString(true);
  ret += "\n";

  if (this->right_ch != NULL)
    ret += this->right_ch->toString(level + 1, "right: ");
  ret += "\n\n";

  if (this->left_ch != NULL)
    ret += this->left_ch->toString(level + 1, "left: ");
  ret += '\n';

  return ret;
}

template <class T> string AvlNode<T>::toString(bool unique) {
 /* string ret = "- ";
  ret += "'\'";

  try {
    ret += to_string(this->getTitulo());
  } catch (...) {
    ret += this->getTitulo();
  }

  ret += "\'";
  ret += " ";
  return ret;*/

    string ret = "";
    ret += "Título: " + this->getTitulo() + "\n";
    ret += "Artista: " + this->getArtista() + "\n";
    ret += "Álbum: " + this->getAlbun() + "\n";
    ret += "Género: " + this->getGenero() + "\n";
    return ret;
}

template <class T> string AvlNode<T>::preOrder() {

  string ret = "";
  ret += this->toString(true);

  if (this->left_ch != NULL)
    ret += this->left_ch->preOrder();
  if (this->right_ch != NULL)
    ret += this->right_ch->preOrder();

  return ret;
}

template <class T> string AvlNode<T>::inOrder() {

  string ret = "";

  if (this->left_ch != NULL)
    ret += this->left_ch->inOrder();

  ret += this->toString(true);

  if (this->right_ch != NULL)
    ret += this->right_ch->inOrder();

  return ret;
}

template <class T> string AvlNode<T>::posOrder() {
  string ret = "";

  if (this->left_ch != NULL)
    ret += this->left_ch->posOrder();
  if (this->right_ch != NULL)
    ret += this->right_ch->posOrder();

  ret += this->toString(true);
	return ret;
}

template <class T> AvlNode<T> *AvlNode<T>::subMinor() {

  AvlNode<T> *ret = this;

  if (!this->right_ch)
    return ret;
  ret = this->right_ch();

  while (ret->left_ch)
    ret = ret->left_ch;

  return ret;
}

template <class T> AvlNode<T> *AvlNode<T>::subGreater() {

  AvlNode<T> ret = this;

  if (!this->left_ch)
    return ret;
  ret = this->left_ch;

  while (ret->right_ch)
    ret = ret->right_ch;

  return ret;
}

template <class T> AvlNode<T> *AvlNode<T>::rmSubMinor() {

  AvlNode<T> *ret = this;
  AvlNode<T> *ret2 = NULL;

  if (!this->right_ch)
    return ret2;

  ret = this->right_ch;
  if (!ret->left_ch) {

    this->right_ch = ret->right_ch;
    this->Titulo = ret->Titulo;
    return ret;
  }

  while (ret->left_ch->left_ch)
    ret = ret->left_ch;
  ret2 = ret->left_ch;

  ret->left_ch = NULL;
  this->Titulo = ret2->getTitulo();
  return ret2;
}

template <class T> AvlNode<T> *AvlNode<T>::rmSubGreater() {

  AvlNode<T> *ret = this;
  AvlNode<T> *ret2 = NULL;

  if (!this->left_ch)
    return ret2;
  ret = this->left_ch;
  if (!ret->right_ch) {

    this->left_ch = ret->left_ch;
    this->Titulo = ret->Titulo;
    return ret;
  }

  while (ret->right_ch->right_ch)
    ret = ret->right_ch;

  ret2 = ret->right_ch;
  ret->right_ch = NULL;

  this->Titulo = ret2->getTitulo();
  return ret2;
}

template <class T> int AvlNode<T>::height(int acumulador) {

  if (!(this->right_ch || this->left_ch))
    return acumulador;

  int height = acumulador;
  if (this->left_ch)
    height = this->left_ch->height(acumulador + 1);
  if (this->right_ch)
    if (this->right_ch->height(acumulador + 1) > height)
      height = this->right_ch->height(acumulador + 1);

  return height;
}

#endif
