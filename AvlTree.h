#ifndef _AVLTREE_H
#define _AVLTREE_H
#include "AvlNode.h"
#include <list>
template <class T> 
class AvlTree {

	private:
		AvlNode<T>* root;
		bool insertNode(AvlNode<T>* cmp, AvlNode<T>*& node);
		bool nodeBalanced(AvlNode<T>* node);
		AvlNode<T>* composedRotation1(AvlNode<T>*& node, bool update= false);
		AvlNode<T>* composedRotation2(AvlNode<T>*& node, bool update= false);
		AvlNode<T>* srcNodeR(AvlNode<T>* node, AvlNode<T>*& searching );
		AvlNode<T>* rightRotation(AvlNode<T>*& node, bool update= false);
		AvlNode<T>* leftRotation(AvlNode<T>*& node, bool update=false);
	
	public:
		bool balanced();
		bool balance(AvlNode<T>*& node);

		AvlTree();
		AvlTree(AvlNode<T>*& root);

		~AvlTree();
		
		bool buscartitulo(AvlNode<T>* node,Cancion song);
		/*		
		bool buscarArtista(AvlNode<T>* node, Cancion song);	
		bool buscarAlbun(AvlNode<T>* node, Cancion song);	
		bool buscarGenero(AvlNode<T>* node,Cancion song);
		*/
		void setRoot(AvlNode<T>*& root);
		AvlNode<T>* getRoot();
		AvlNode<T>* insertNode(AvlNode<T>*& nNode);
		AvlNode<T>* insertNode(T node);
		AvlNode<T>* rmNodeMinor(AvlNode<T>*& node);
		AvlNode<T>* rmNodeGreater(AvlNode<T>*& node);
		bool rmNode(AvlNode<T>*& node);
		bool rmNode(T node);
		AvlNode<T>* srcFather(AvlNode<T>* node);
		AvlNode<T>* srcFather(T node);
		string printTree();
		string preOrder();
		string inOrder();
		string posOrder();
		int height();

};

#include "AvlTree.hxx"
#endif
