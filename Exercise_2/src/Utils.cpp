#include "Utils.hpp"


/*Questa funzione legge la singola riga, e salva solo il secondo valore, che è l'unico che serve per il programma
Verrà utilizzata solo per le prime due righe del file input in quanto sono in formato diverso rispetto a come sono
scritti il resto dei dati del file */

double read_single_line(ifstream& fileInput)
{
    //leggo la riga di file e la converto in stringa
    string linea1;
    getline(fileInput,linea1);
    //cout<<linea1;


    //la linea letta la trasformo in istringstream, per poterla separare in elementi diversi
    //utilizzando ; come divisore
    istringstream isline(linea1);
    string elem1;
    string elem2;
    getline(isline, elem1, ';');
    getline(isline, elem2);

    //converto la stringa in double
    double S;
    S=stof(elem2);

    return S;
}




/*Questa funzione legge i dati del file (dalla quarta riga in poi) e, per ogni riga, salva all'interno del vettore w
il primo elemento (quello a sinistra del separatore ; ) e in r il secondo.
I valori letti saranno di tipo stringa, quindi dovranno essere convertiti in double, per poter farci i conti desiderati */

void load_arrays(ifstream& fileInput,double* ptr_w, double* ptr_r)

{
    string riga;
    string elem_w;
    string elem_r;

    int i=0;

    while (getline(fileInput,riga))
    {
        //cout<<riga<<'\n';


        istringstream isriga(riga);

        getline(isriga, elem_w, ';');
        getline(isriga, elem_r,' ');


        double elem_d_w=stof(elem_w);
        double elem_d_r=stof(elem_r);

        ptr_w[i]= elem_d_w;
        ptr_r[i]= elem_d_r;

        i=i+1;

    }
}



/*Questa funzione calcola i valori V e r con i calcoli richiesti dal Readme_file */

void calcolo_V_r(const double* ptr_w, const double* ptr_r, double& V, double& r, double S, int n)
{
    double guadtot=0;

    for (int i = 0; i < n; ++i)
    {
        double guadparz=ptr_w[i]*ptr_r[i];

        guadtot=guadtot+guadparz;
    }

    V= S*(guadtot+1);
    r= V/S-1;
}



/*Questa funzione stampa su un file output i valori all'interno dei vettori.
 * Poichè abbiamo solo il puntatore di tali vettori, è richiesto un ciclo while */

void stampa_vettore_fo(ofstream& fileOutput, const double* ptr_arr, int n)
{
    fileOutput<<"[ ";
    for (int i=0;i<n;++i)
    {
        fileOutput<<ptr_arr[i]<<" ";
    }
    fileOutput<<"]" <<'\n';
}



/*Questa funzione stampa a schermo i valori all'interno dei vettori.
 * Poichè abbiamo solo il puntatore di tali vettori, è richiesto un ciclo while */

void stampa_vettore_screen(ostream& fileOutput, const double* ptr_arr, int n)
{
    fileOutput<<"[ ";
    for (int i=0;i<n;++i)
    {
        fileOutput<<ptr_arr[i]<<" ";
    }
    fileOutput<<"]" <<'\n';
}
















