#include "AvlTree.h"
#include "Cancion.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main() {
	
typedef list<Cancion>* T;
ifstream inputFile("elfile.txt");

	

	//Arbol de titulo
	//treeTitle->insertNode(Rootsonglist);

	 if (!inputFile.is_open()) {
        cerr << "no se logro abrir el archivo!" << endl;
        return 1;
    }
	bool first = true;
    string line;

	AvlNode<T> *Rootsonglist = new AvlNode<T>();

	//creo las instancias de los cuatro arboles necesarios, y añado en todos la misma raiz
	AvlTree<T> *treeArtist = new AvlTree<T>();
	AvlTree<T> *treeAlbum = new AvlTree<T>();
	AvlTree<T> *treeTitle = new AvlTree<T>();
	AvlTree<T> *treeGenre= new AvlTree<T>();

    while (getline(inputFile,line)) {

		if(first){

			stringstream ss(line);
			string word;
			int counter=0;
			Cancion can1;

			while(ss >> word){

				if(counter == 0){

					can1.setTitulo(word);
					counter ++;
					} else if(counter == 1){

						can1.setArtista(word);
						counter++;
					}else if(counter == 2){

						can1.setAlbum(word);
						counter++;
					}else if(counter == 3){

						can1.setGenero(word);
						counter++;
					}else{counter = 0;}

			}

			Rootsonglist->setSongList(can1);

			//creo las instancias de los cuatro arboles necesarios, y añado en todos la misma raiz
			treeTitle->setRoot(Rootsonglist);

			first = false;

		}else{

			stringstream ss(line);
			string word;
			int counter=0;
			Cancion can;

			while(ss >> word){

				if(counter == 0){

					can.setTitulo(word);
					counter ++;
				} else if(counter == 1){

					can.setArtista(word);
					counter++;
				}else if(counter == 2){

					can.setAlbum(word);
					counter++;
				}else if(counter == 3){

					can.setGenero(word);
					counter++;
				}else{counter = 0;}

			}

			

			//busqueda en arbol titulo
			bool existe = false;
			existe = treeTitle->buscartitulo(Rootsonglist,can);

			if(!existe){

				AvlNode<T> *song = new AvlNode<T>(can) ;

				treeTitle->insertNode(song);
			
			}
			//agregar al arbol titulo

		}
		
    }

/*
int op=0;
while(op!=8){
	switch(op){
	case 0:
		cout<<"Ingrese la opcion que desea realizar\n"
			<<"ingresar nueva cancion:	 1\n"
			<<"Eliminar cancion:		 2\n"
			<<"Buscar cancion por titulo:  3\n"
			<<"Buscar cancion por artista: 4\n"
			<<"Buscar cancion por albun:   5\n"
			<<"Buscar cancion por Genero:  6\n"
			<<"Altura del arbol:		 7\n"
			<<"salir:				 8\n";
		cin>>op;
	break;
	case 1:
		cout<<"Eligio insertar cancion\n";
	      cout<<"\ningrese titulo de la cancion\n";
		cin>>Titulo;
		temp->setTitulo(Titulo);
		cout<<"\ningrese Artista de la cancion\n";
		cin>>Artista;
		temp->setArtista(Artista);
		cout<<"\ningrese Albun de la cancion\n";
		cin>>Albun;
		temp->setAlbun(Albun);
		cout<<"\ningrese Genero de la cancion\n";
		cin>>Genero;
		temp->setGenero(Genero);
		tree->insertNode(temp);
		op=0;
		//cout<<"lo ingresadp fue\n"<<temp->getGenero;

	break;
	case 2:
		cout<<"ha elegido eliminar cancion\n";
		op=0;
	break;
 	case 3:
		cout<<"buscar cancion por titulo\n intruduzca el titulo: ";
		cin>>Titulo;
		temp=tree->buscartitulo(tree->getRoot(), Titulo);
		if (temp != nullptr) {
			cout<<"cancion encontrada";
    			// hacer algo con el nodo encontrado
		} else {
    		cout << "No se encontró un nodo con el título buscado\n";
		}
		op=0;
	break;
	case 4:
		cout<<"buscar cancion por Artista\n intruduzca el Artista: ";
		cin>>Artista;
			
		temp=tree->buscarArtista(tree->getRoot(), Artista);
		if (temp != nullptr) {
			cout<<"cancion encontrada";
    			// hacer algo con el nodo encontrado
		} else {
    		cout << "No se encontró un nodo con el Artista buscado\n";
		}

		op=0;
	break;
	case 5:
		cout<<"buscar cancion por Albun\n intruduzca el Albun: ";
		cin>>Artista;
		temp=tree->buscarAlbun(tree->getRoot(), Albun);
		if (temp != nullptr) {
			cout<<"cancion encontrada";
    			// hacer algo con el nodo encontrado
		} else {
    		cout << "No se encontró un nodo con el Albun buscado\n";
		}
		
		op=0;
	break;
	case 6:
		cout<<"buscar cancion por genero\n intruduzca el genero : ";
		cin>>Genero;
		temp=tree->buscarGenero(tree->getRoot(), Genero);
		if (temp != nullptr) {
			cout<<"cancion encontrada";
    			// hacer algo con el nodo encontrado
		} else {
    		cout << "No se encontró un nodo con el genero buscado\n";
		}
		op=0;
	break;
	case 7:
		cout<<"altura ";
		op;
	default:
		cout<<"opcion no valida, sera redirigido al menu principal\n";
		op=0;
	break;

	}
	
cout << '\n' << tree->printTree();
}

  AvlNode<T> *left = new AvlNode<T>((T)(80));

  //tree->insertNode((T)(110));
  //tree->insertNode((T)(105));
  //tree->insertNode((T)(107));
  //tree->insertNode((T)(114));
  //tree->insertNode((T)(116));
  //tree->insertNode((T)(100));
  //tree->insertNode((T)(122));

  cout << '\n'
       << "Impresion\n"
       << tree->printTree() << "\nIn order: " << tree->inOrder();
  cout << "\nPre order: " << tree->preOrder();
  cout << "\nPost order: " << tree->posOrder();
  //cout << '\n' << tree->printTree();
 // cout << "\nAltura " << left->getData() << ": " << left->height();
 // cout << "\nAltura arbol: " << tree->height();
*/
  return 0;
}