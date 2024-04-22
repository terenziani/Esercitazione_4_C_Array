/* Andrea Terenziani s284817

Questo programma serve per leggere in input i dati da un file, separarli e inserirli all'interno dei
rispettivi array w e r, e calcolare in definitiva il rate of return r e il final value of the portfolio V.

L'esercizio inoltre richiedeva di allocare dinamicamente la memoria e utilizzare array di dimensione fissata,
anzichè utilizzare la struttura vector della STL.       */





#include <iostream>
#include <fstream>
#include "Utils.hpp"
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;





int main()
{

    //dichiaro i file di input
    string filename("data.csv");
    ifstream ifs(filename);


    //dichiaro il file di output
    string filename2("result.txt");
    ofstream ofs(filename2);


    //controllo se i due file sono stati aperti correttamente
    if (! ofs.is_open())
    { cout<< "errore di apertura del file di output \n";
    }

    else if (! ifs.is_open())
    { cout << "errore di apertura del file input \n";
    }



    //se sono aperti correttamente svolgo le operazioni

    //leggo la prima riga di file per trovare S
    double S;
    S=read_single_line(ifs);




    //leggo la seconda riga di file per trovare n (il return sarà un double, da convertire in int)
    double n_double=read_single_line(ifs);
    int n = static_cast<int>(n_double);


    //leggo la terza riga per scartarla
    string linea3;
    getline(ifs,linea3);



    //alloco la memoria per due array
    double* ptr_w= new double [n];
    double* ptr_r= new double [n];



    //richiamo la funzione che legge ogni riga e inserisce i valori nell'array w e r
    load_arrays(ifs, ptr_w, ptr_r);



    //definisco le variabili output da passare come parametri per riferimento
    double V;
    double r;

    //richiamo la funzione per calcolare V e r
    calcolo_V_r(ptr_w, ptr_r, V, r, S, n);



    //stampo sul file di output
    ofs<<fixed << setprecision(2) <<"S = "<< S<<" , n = "<<n<<'\n';  //numero da rappresentare con 2 cifre decimali


    ofs<<"w = ";
    //richiamo la funzione di stampa vettore sul vettore w
    stampa_vettore_fo(ofs, ptr_w, n);

    ofs<<"r = ";
    //richiamo la funzione di stampa vettore sul vettore r
    stampa_vettore_fo(ofs, ptr_r, n);

    ofs<<fixed << setprecision(4)<<"Rate of return of the portfolio: "<<r<<'\n';
    ofs<<fixed << setprecision(2) <<"V:  "<<V<<'\n';



    //stampo a video
    cout<<fixed << setprecision(2) <<"S = "<< S<<" , n = "<<n<<'\n';
    cout<<"w = ";

    //richiamo la funzione di stampa vettore sul vettore w
    stampa_vettore_screen(cout, ptr_w, n);

    cout<<"r = ";
    //richiamo la funzione di stampa vettore sul vettore r
    stampa_vettore_screen(cout, ptr_r, n);

    cout<<fixed << setprecision(4)<<"Rate of return of the portfolio: "<<r<<'\n';
    cout<<fixed << setprecision(2)<<"V:  "<<V<<'\n';



    //disalloco la memoria
    delete [] ptr_r;
    delete [] ptr_w;


    //chiudo i file
    ifs.close();
    ofs.close();

    return 0;

}










