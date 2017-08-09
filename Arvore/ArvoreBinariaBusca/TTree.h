#ifndef _TTREE_H
   #define _TTREE_H
   /******************************************************************************/
   #include "Standart.h"
   #include "TNode.c"
   /******************************************************************************/
   #define ERROR_EXISTING_ROOT 1
   #define ERROR_EMPTY_TREE    2
   /******************************************************************************/
   typedef struct{
      TNode* root;
   } TTree;
#endif
