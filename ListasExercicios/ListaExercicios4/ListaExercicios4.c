/******************************************************************************/
int main(){
   
   TListaNova ListaNova;
   TLista Lista;
   int Erro;
   
   TLista_Inicializa( &Lista );
   TLista_InsereElementoFinal( &Lista, 9, &Erro );
   TLista_InsereElementoFinal( &Lista, 4, &Erro );
   TLista_InsereElementoFinal( &Lista, 4, &Erro );
   TLista_InsereElementoFinal( &Lista, 4, &Erro );
   TLista_InsereElementoFinal( &Lista, 9, &Erro );
   TLista_InsereElementoFinal( &Lista, 5, &Erro );
   TLista_InsereElementoFinal( &Lista, 5, &Erro );
   TLista_InsereElementoFinal( &Lista, 9, &Erro );
   TLista_InsereElementoFinal( &Lista, 7, &Erro );
   TLista_InsereElementoFinal( &Lista, 1, &Erro );
   TLista_InsereElementoFinal( &Lista, 9, &Erro );
   TLista_InsereElementoFinal( &Lista, 9, &Erro );



   return 0;
}
