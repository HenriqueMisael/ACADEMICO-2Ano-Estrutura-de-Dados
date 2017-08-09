#ifndef _TNODE_H
   #define _TNODE_H
   /******************************************************************************/
   #include "Standart.h"
   /******************************************************************************/
   typedef int key;
   typedef struct estrutura{
      key info;
      struct estrutura *left, *right;
   } TNode;
#endif
