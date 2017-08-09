/******************************************************************************/
#include "TNode.h"
/******************************************************************************/
TNode* TNode_New( key Information ){

   TNode* New;

   New = (TNode*)malloc( sizeof( TNode ) );
   New->info  = Information;
   New->left  = NULL;
   New->right = NULL;

   return New;
}
/******************************************************************************/
int TNode_Grade( TNode *Node ){

   int Grade;

   Grade = 0;
   if( Node ){
      if( Node->left )
         Grade++;
      if( Node->right )
         Grade++;
   }

   return Grade;
}
/******************************************************************************/
int TNode_Complete( TNode *Node ){
   
   int Grade;
   
   Grade = TNode_Grade( Node );

   if( Grade == 2 )
      return TNode_Complete( Node->left ) && TNode_Complete( Node->right );
   return !Grade;
}
/******************************************************************************/
void TNode_ShowInOrder( TNode *Node ){

   if( Node ){
      TNode_ShowInOrder( Node->left );
      printf( "\n %d", Node->info );
      TNode_ShowInOrder( Node->right );
   }
}
/******************************************************************************/
TNode* TNode_GetMinor( TNode *Node ){

   TNode *Minor, *MinorAux;

   if( Node ){
      Minor = TNode_GetMinor( Node->left );
      if( !Minor || Minor->info > Node->info )
         Minor = Node;
      
      MinorAux = TNode_GetMinor( Node->right );
      if( MinorAux && Minor->info > MinorAux->info )
         Minor = MinorAux;
   }else
      Minor = NULL;
   return Minor;
}
/******************************************************************************/
TNode* TNode_SeekInfo( TNode *Node, key info ){

   TNode* Seek;

   if( !Node )
      Seek = NULL;
   else if( Node->info == info )
      Seek = Node;
   else if( Node->info < info )
      Seek = TNode_SeekInfo( Node->left, info );
   else if( Node->info > info )
      Seek = TNode_SeekInfo( Node->right, info );

   return Seek;
}
/******************************************************************************/
void TNode_ShowLeaf( TNode *Node ){

   if( Node )
      if( !Node->left && !Node->right )
         printf( "\n %d", Node->info );
      else{
         TNode_ShowLeaf( Node->left );
         TNode_ShowLeaf( Node->right );
      }
}
/******************************************************************************/
void TNode_ShowHigherThan( TNode *Node, int x ){

   if( Node ){
      if( Node->info > x )
         printf( "\n %d", Node->info );
      TNode_ShowHigherThan( Node->left, x );
      TNode_ShowHigherThan( Node->right, x );
   }
}
/******************************************************************************/
int TNode_Count( TNode* Node ){

   if( Node )
      return 1+TNode_Count( Node->left ) + TNode_Count( Node->right );
   return 0;
}
/******************************************************************************/
int TNode_CountPairInt( TNode* Node ){

   int Count;

   Count = 0;

   if( Node ){
      if( !(Node->info%2) ) //Se for par, Node->info%2 == 0
         Count = 1;
      Count += TNode_CountPairInt( Node->left ) + TNode_CountPairInt( Node->right );
   }

   return Count;
}
/******************************************************************************/
int TNode_CountFathersWithOneSon( TNode* Node ){

   int Count;

   Count = 0;

   if( Node ){
      if( ( !Node->left && Node->right ) || //Tiver apenas o filho da direita
            !Node->right && Node->left )    //Tiver apenas o filho da esquerda
         Count = 1;
      Count += TNode_CountFathersWithOneSon( Node->left ) + TNode_CountFathersWithOneSon( Node->right );
   }

   return Count;

}
/******************************************************************************/
TNode* TNode_Empties( TNode *Node ){

   if( Node ){
      Node->left = TNode_Empties( Node->left );
      Node->right = TNode_Empties( Node->right );
   }
   return NULL;
}
/******************************************************************************/
TNode* TNode_Clone( TNode *Node ){

   TNode *Clone;

   if( !Node )
      Clone = NULL;
   else{
      Clone = TNode_New( Node->info );
      Clone->left = TNode_Clone( Node->left );
      Clone->right = TNode_Clone( Node->right );
   }

   return Clone;
}
/******************************************************************************/
int TNode_Compare( TNode *First, TNode *Second ){
   
   if( First && Second ) //Se ambos forem ponteiros, então comparamos suas informações
      if( First->info == Second->info ) //Se as informações forem iguais, comparamos seus filhos
         if( TNode_Compare( First->left, Second->left ) ) //Se os filhos à esquerda forem iguais, comparamos os à direita
            if( TNode_Compare( First->right, Second->right ) ) //Se os filhos à direita forem iguais, então os nós são iguais
               return TRUE;

   return !First && !Second; //Se nenhum dos dois forem ponteiros, então são equivalentes.
}
/******************************************************************************/
TNode* TNode_GetElements( TNode *Node, key Array[], int *i ){

   if( Node ){
      TNode_GetElements( Node->left, Array, i );
      Array[(*i)++] = Node->info;
      TNode_GetElements( Node->right, Array, i );
   }

   return Node;
}
/******************************************************************************/
void TNode_Insert( TNode *Node, key Key ){

   if( Node )
      if( Key < Node->info )
         if( Node->right )
            TNode_Insert( Node->right, Key );
         else
            Node->right = TNode_New( Key );
      else if( Key > Node->info )
         if( Node->left )
            TNode_Insert( Node->left, Key );
         else
            Node->left = TNode_New( Key );
}
/******************************************************************************/
TNode* TNode_Remove( TNode *Node, key Info ){
   
   TNode* Aux;
   int *Keys, i, x;

   if( Node )
      if( Node->info < Info )
         Node->left = TNode_Remove( Node->left, Info );
      else if( Node->info > Info )
         Node->right = TNode_Remove( Node->right, Info );
      else
         if( !(Node->right) )
            Node = Node->left;
         else{
            if( (Node->left) ){
               Keys = (key*)malloc( sizeof( key )*TNode_Count( Node->left ) );
               x = 0;
               TNode_GetElements( Node->left, Keys, &x );
               for( i = 0; i < x; i++ )
                  TNode_Insert( Node->right, Keys[i] );
            }
            Node = Node->right;
         }
   return Node;
}
/******************************************************************************/
