#ifndef _AVLNODE_H
#define _AVLNODE_H
#include <list>
#include <string>
#include "Cancion.h"
using namespace std;

template <class T> class AvlNode {

private:
  list<Cancion> songs;
  AvlNode<T>* left_ch;
  AvlNode<T>* right_ch;

public:
  AvlNode(Cancion can);
  AvlNode();
  ~AvlNode();

  void setLeft_ch(AvlNode<T> *&nleft_ch);
  AvlNode<T> *getLeft_ch();
  void setRight_ch(AvlNode<T> *&nright_ch);
  void agregarCancion(Cancion can);
  list<Cancion> getSongList();
  bool addSong();
  void setSongList(Cancion song);
  AvlNode<T> *getRight_ch();
  AvlNode<T> *subMinor();
  AvlNode<T> *subGreater();
  AvlNode<T> *rmSubMinor();
  AvlNode<T> *rmSubGreater();
  int height(int acumulador = 0);
  int compareTo(T Titulo);
  int compareTo(AvlNode<T> *&c);
  string toString(int level = 0, string car = "root ");
  string toString(bool unique);
  string preOrder();
  string inOrder();
  string posOrder();
};
#include "AvlNode.hxx"
#endif