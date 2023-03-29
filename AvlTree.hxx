#ifndef _AVLTREE_HXX
#define _AVLTREE_HXX
#include "AvlTree.h"
using namespace std;

template<class T>
AvlTree<T>::AvlTree(){

}

template<class T>
AvlTree<T>::AvlTree(AvlNode<T>*& root){

	this->root = root;
}

template<class T>
AvlTree<T>::~AvlTree(){

	if(this->root){
		delete this->root;
		this->root = NULL;
	}
}

template<class T>
void AvlTree<T>::setRoot(AvlNode<T> *&root){
	this->root = root;
}

template<class T>
AvlNode<T>* AvlTree<T>::getRoot(){
	return this->root;
}

template<class T>
AvlNode<T>* AvlTree<T>::insertNode(AvlNode<T> *& nNode){

	if(this->insertNode(this->root, nNode)){
		this->balance(nNode);
		return nNode;
	}
	else{return NULL;}
}

template<class T>
bool AvlTree<T>::insertNode(AvlNode<T>* cmp, AvlNode<T>*& nNode){//se organiza por titulo cancion

	list<Cancion> songlistEx = cmp->getSongList();
	list<Cancion> songlistN = nNode->getSongList();
	list<Cancion>::iterator it_ex = songlistEx.begin();
	list<Cancion>::iterator it_n = songlistN.begin();

 	if((*it_ex).getTitulo() == (*it_n).getTitulo())
		return false;
	else if((*it_ex).getTitulo() > (*it_n).getTitulo()){

		if(!cmp->getLeft_ch()){
			cmp->setLeft_ch(nNode);
			return true;
		} else
			return this->insertNode(cmp->getLeft_ch(), nNode);
		
	} else if((*it_ex).getTitulo() < (*it_n).getTitulo()){
		if(!cmp->getRight_ch()){
			cmp->setRight_ch(nNode);
			return true;
		}else
			return this->insertNode(cmp->getRight_ch(), nNode);
	}

	return true;
	
}

template<class T>
AvlNode<T>* AvlTree<T>::insertNode(T node){

	AvlNode<T>* c = new AvlNode<T>(node);

	if(this->insertNode(this->root, c)){
		this->balance(c);
		return c;
	}else{
		return NULL;
	}
	
}

template<class T>
AvlNode<T>* AvlTree<T>::srcFather(AvlNode<T>* searching){

	if(!this->root)
		return NULL;
	
	if(this->root== searching)
		return this->root;
	
	return this->srcNodeR(this->getRoot(), searching);
}

template<class T>
AvlNode<T>* AvlTree<T>::srcNodeR(AvlNode<T>* node, AvlNode<T>*& searching){

	if(!node)
		return NULL;
	if(node->getLeft_ch()== searching || node->getRight_ch() == searching)
		return node;
	if(!node->getLeft_ch() && !node->getRight_ch())
		return NULL;
	if(!node->getLeft_ch() && node->getRight_ch() != searching)
		return this->srcNodeR(node->getRight_ch(), searching);
	if(node->getLeft_ch() != searching && !node->getRight_ch())
		return this->srcNodeR(node->getLeft_ch(), searching);
	else{
		while(this->srcNodeR(node->getLeft_ch(), searching))
			node= this->srcNodeR(node->getLeft_ch(), searching);
		if(node->getRight_ch())
			while(this->srcNodeR( node->getRight_ch(), searching))
				node=this->srcNodeR(node->getRight_ch(), searching);
		if(node == this->root && (!(this->root->getRight_ch() == searching || this->root->getLeft_ch() == searching)))
			node = NULL;
	}

	return node;
	
}

template<class T >
AvlNode<T>* AvlTree<T>::srcFather(T searching){
	
	AvlNode<T>* node = this->root;
	if(!node)
		return node;
	if(node->getTitulo() == searching)
		return node;
	bool found= false;

	while(!found){
		if(!node->getLeft_ch() || node->getRight_ch())
			return NULL;
		if(node->getTitulo() < searching && !node->getRight_ch())
			return NULL;
		if(node->getTitulo() > searching && !node->getLeft_ch())
			return NULL;
		if(node->getTitulo() < searching && node->getRight_ch()){
			if(node->getRight_ch()->getTitulo() == searching)
				found = true;
			else
				node = node->getRight_ch();
		}else if((node->getTitulo() > searching && node->getLeft_ch())){

			if(node->getLeft_ch()->getTitulo() == searching){
				found = true;
			}else{
				node = node->getLeft_ch();
			}
			
		}
		
	}

	return node;

}

template<class T>
bool AvlTree<T>::rmNode(AvlNode<T>*& node){
	
	AvlNode<T>* father=this->srcFather(node);
	if(!(node->getRight_ch() || node->getLeft_ch())){
		if(father->getRight_ch() == node){
			delete node;
			node = NULL;
			father->setRight_ch(node);
		}else{
			delete node;
			node = NULL;
			father->setLeft_ch(node);
		}
			
	}
	else if((!node->getRight_ch())  && (node->getLeft_ch()))
		this->rmNodeGreater(node);
	else
		this->rmNodeMinor(node);

	this->balance(node);
	return true;
	
}

template<class T>
bool AvlTree<T>::rmNode(T node){
	AvlNode<T>* father = this->srcFather(node);

	if(!father)
		return 0;
	AvlNode<T>* nodo;

	if(father->getLeft_ch()){
		if(father->getLeft_ch()->getTitulo() == node)
			nodo = father->getLeft_ch();
	}else
		nodo = father->getRight_ch();

	if(!(nodo->getRight_ch()||nodo->getLeft_ch())){
		if(father->getRight_ch() == nodo){
			delete nodo;
			nodo = NULL;
			father->setRight_ch(nodo);
		}else{
			delete nodo;
			nodo = NULL;
			father->setLeft_ch(nodo);
		}
	} else if((!nodo->getRight_ch()) && (nodo->getLeft_ch())){
		this->rmNodeGreater(nodo);
	}else{this->rmNodeMinor(nodo);}

	this->balance(father);
	return true;
	
}

template<class T>
AvlNode<T>* AvlTree<T>::rmNodeGreater(AvlNode<T> *&node){
	return node->rmSubGreater();
}

template<class T>
AvlNode<T>* AvlTree<T>::rmNodeMinor(AvlNode<T> *&node){
	return node->rmSubMinor();
}

template<class T>
string AvlTree<T>::printTree(){
	
	if(this->root)
		return "tree\n"+ this->root->toString()+"\n";
	else
		return " ";
}

template<class T>
int AvlTree<T>::height(){
	if(!this->root)
		return -1;
	return this->root->height();
}

template<class T>
string AvlTree<T>::preOrder(){
	return this->root->preOrder();
}

template<class T>
string AvlTree<T>::inOrder(){
	return this->root->inOrder();
}

template<class T>
string AvlTree<T>::posOrder(){
	return this->root->posOrder();
}

template<class T>
bool AvlTree<T>::balanced(){
	if(!this->root)
		return 1;
	return (this->nodeBalanced(this->root));
}

template<class T>
bool AvlTree<T>::nodeBalanced(AvlNode<T>* node){
	
	if(node->getLeft_ch()||node->getRight_ch()){

		if(!node->getLeft_ch())
			if(1+node->getRight_ch()->height() > 1 || 1+node->getRight_ch()->height() < -1)
				return 0;
		
		if(!node->getRight_ch())
			if(1+node->getLeft_ch()->height() > 1 || 1+node->getLeft_ch()->height() < -1)
				return 0;
		if(node->getLeft_ch() && node->getRight_ch())
			if(node->getLeft_ch()->height() - node->getRight_ch()->height() > 1 || node->getLeft_ch()->height() - node->getRight_ch()->height() < -1)
				return 0;
		if(node->getLeft_ch())
			if(!this->nodeBalanced(node->getLeft_ch()))
				return 0;
		if(node->getRight_ch())
			if(!this->nodeBalanced(node->getRight_ch()))
				return 0;
		
	}

	return 1;
}

template<class T>
AvlNode<T>* AvlTree<T>::composedRotation1(AvlNode<T>*& node, bool update){

	if(!node)
		return NULL;
	if(!this->srcFather(node))
		return NULL;
	
	AvlNode<T>* n = node->getLeft_ch();
	AvlNode<T>* Hnode = this->leftRotation(n);

	if(!Hnode)
		return NULL;
	node->setLeft_ch(Hnode);

	AvlNode<T>* Pnode = this->rightRotation(node);

	if(update){

		if(this->root == NULL)
			this->setRoot(Pnode);
		else{
			AvlNode<T>* toUpdate = this->srcFather(node);
			if(toUpdate->getRight_ch() == node)
				toUpdate->setRight_ch(Pnode);
			else
				toUpdate->setLeft_ch(Pnode);
		}
	}
	
	return Pnode;
}
template<class T>
AvlNode<T>* AvlTree<T>::composedRotation2(AvlNode<T>*& node, bool update){

	if(!node)
		return NULL;

	AvlNode<T>* n = node->getRight_ch();
	AvlNode<T>* Hnode = this->rightRotation(n);

	if(!Hnode)
		return NULL;
	node->setRight_ch(Hnode);
	AvlNode<T>* Pnode = this->leftRotation(node);

	if(update){
		if(this->root == node)
			this->setRoot(Pnode);
		else{
			AvlNode<T>* toUpdate = this->srcFather(node);
			if(toUpdate->getRight_ch() == node)
				toUpdate->setRight_ch(Pnode);
			else
				toUpdate->setLeft_ch(Pnode);
		}
	}
	return Pnode;
	
}

template<class T>
AvlNode<T>* AvlTree<T>::leftRotation(AvlNode<T>*& node, bool update){

	if(!node)
		return NULL;

	AvlNode<T>* Pnode = node->getRight_ch();

	if(!Pnode)
		return NULL;
	AvlNode<T>* Rnode = Pnode->getLeft_ch();
	AvlNode<T>* Hnode = Pnode->getRight_ch();
	node->setRight_ch(Hnode);
	Pnode->setLeft_ch(node);
	Pnode->setRight_ch(Rnode);

	if(update){
		if(this->root == node)
			this->setRoot(Pnode);
		else{
			AvlNode<T>* toUpdate = this->srcFather(node);
			if(toUpdate->getRight_ch() == node)
				toUpdate->setRight_ch(Pnode);
			else
				toUpdate->setLeft_ch(Pnode);
		}
		
	}
	
	return Pnode;
}

template<class T>
AvlNode<T>* AvlTree<T>::rightRotation(AvlNode<T>*& node, bool update){

	if(!node)
		return NULL;
	
	AvlNode<T>* Pnode = node->getLeft_ch();

	if(!Pnode)
		return NULL;
	
	AvlNode<T>* Rnode = Pnode->getLeft_ch();
	AvlNode<T>* Hnode = Pnode->getRight_ch();

	node->setLeft_ch(Hnode);
	Pnode->setRight_ch(node);
	Pnode->setLeft_ch(Rnode);

	if(update){
		if(this->root == node)
			this->setRoot(Pnode);
		else{
			AvlNode<T>* toUpdate = this->srcFather(node);
			if(toUpdate->getRight_ch() == node)
				toUpdate->setRight_ch(Pnode);
			else
				toUpdate->setLeft_ch(Pnode);
		}
	}

	return Pnode;
	
}

template<class T>
bool AvlTree<T>::balance(AvlNode<T>*& node){

	if(this->balanced())
		return 1;
	
	AvlNode<T>* ft = this->srcFather(node);
	AvlNode<T>* lastFT = NULL;

	while(ft != lastFT){

		if(ft->getLeft_ch() || ft->getRight_ch()){

			if(ft->getLeft_ch() && !ft->getRight_ch()){
				if(!this->nodeBalanced(ft)){
					this->rightRotation(ft, true);
					ft = this->srcFather(ft);
				}
			} else if(!ft->getLeft_ch() && ft->getRight_ch()){

				if(!this->nodeBalanced(ft)){
					this->leftRotation(ft,true);
					ft = this->srcFather(ft);
				}
				
			}

			else if(ft->getLeft_ch() && ft->getRight_ch()){
				AvlNode<T>* n;

				if(!this->nodeBalanced(ft)){
					if(!this->nodeBalanced(ft->getLeft_ch())){
						n=ft->getLeft_ch();
						if(!n->getLeft_ch()){
							this->rightRotation(n);
						}else if(!n->getRight_ch())
							this->composedRotation1(n);
						else if(n->getLeft_ch()->height() - n->getRight_ch()->height() > 0)
							this->rightRotation(n);
						else
							this->composedRotation1(n);
					}
					else if(!this->nodeBalanced(ft->getRight_ch())){
						n = ft->getRight_ch();
						if(!n->getLeft_ch())
							this->leftRotation(n);
						else if(!n->getRight_ch())
							this->composedRotation2(n);
						else if(n->getLeft_ch()->height() - n->getLeft_ch()->height() < 0)
							this->leftRotation(n);
						else
							this->composedRotation2(n);
						
					}

					ft = this->srcFather(ft);
					
				}
			}
		}

		lastFT = ft;
		ft = this->srcFather(ft);
		
	}

	if(!ft){
		return 0;
	}

	return 1;
	
}

template <class T>
bool AvlTree<T>::buscartitulo(AvlNode<T>* node ,Cancion song) {

	list<Cancion>::iterator ls_it;
	list<Cancion> songlist = node->getSongList();
	ls_it = songlist.begin();
	bool found = false;

	for(;ls_it != songlist.end();ls_it++){

		if((*ls_it).getTitulo() == song.getTitulo()){
			node->agregarCancion(song);
			found = true;
		}

	}


	ls_it = songlist.begin();

	if(found){
		return found;
	}else{

		if(song.getTitulo() >  (*ls_it).getTitulo()){
			return buscartitulo(node->getRight_ch(),song);
		}else if(song.getTitulo() < (*ls_it).getTitulo()){
			return buscartitulo(node->getLeft_ch(), song);
		}
	}

	return found;

}

/*
template <class T>
bool AvlTree<T>::buscarArtista(AvlNode<T>* node, Cancion song) {
	return true;

}
template <class T>
bool AvlTree<T>::buscarAlbun(AvlNode<T>* node, Cancion song) {
	return true;
}

template <class T>
bool AvlTree<T>::buscarGenero(AvlNode<T>* node, Cancion song){
	return true;
}
*/

#endif