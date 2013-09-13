 /* Copyright (c) 2013 the authors listed at the following URL, and/or
  2 the authors of referenced articles or incorporated external code:
  3 http://en.literateprograms.org/Red-black_tree_(C)?action=history&offset=20120524204657
  4
  5 Permission is hereby granted, free of charge, to any person obtaining
  6 a copy of this software and associated documentation files (the
  7 "Software"), to deal in the Software without restriction, including
  8 without limitation the rights to use, copy, modify, merge, publish,
  9 distribute, sublicense, and/or sell copies of the Software, and to
 10 permit persons to whom the Software is furnished to do so, subject to
 11 the following conditions:
 12
 13 The above copyright notice and this permission notice shall be
 14 included in all copies or substantial portions of the Software.
 15
 16 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 17 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 18 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 19 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 20 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 21 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 22 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 23
 24 Retrieved from: http://en.literateprograms.org/Red-black_tree_(C)?oldid=18555
 25 */

 #include "rbtree.h"
  #include <stdio.h>
  #include <assert.h>
  #include <stdlib.h> /* rand() */
  #include "lightbulb.h"

  static int compare_int(void* left, void* right);
  static void print_tree(rbtree t);
  static void print_tree_helper(rbtree_node n, int indent);


 static int compare_int(void* leftp, void* rightp) {
      int left = (int)leftp;
      int right = (int)rightp;
      if (left < right)
          return -1;
      else if (left > right)
          return 1;
      else {
         assert (left == right);
         return 0;
     }
  }

  #define INDENT_STEP  4

  void print_tree_helper(rbtree_node n, int indent);

  void print_tree(rbtree t) {
      print_tree_helper(t->root, 0);
      printf("");
  }

  void print_tree_helper(rbtree_node n, int indent) {
      int i;
      if (n == NULL) {
          printf("<empty tree>");
          return;
      }
      if (n->right != NULL) {
          print_tree_helper(n->right, indent + INDENT_STEP);
      }
      for(i=0; i<indent; i++)
          printf(" ");
      if (n->color == BLACK)
          printf("%d\n", (int)n->key);
      else
          printf("<%d>\n", (int)n->key);
      if (n->left != NULL) {
          print_tree_helper(n->left, indent + INDENT_STEP);
      }
  }

  int main() {
      int i;
      rbtree t = rbtree_create();
      print_tree(t);
        struct lightbulb bulb;

     //   rbtree_insert(t,(void*)bulb->type,(void*)bulb,compare_int);
        int x = rand() % 10000;
    int y = rand() % 10000;

          printf("Inserting %d -> %d\n\n", x, y);

          rbtree_insert(t, (void*)x, (void*)y, compare_int);
          print_tree(t);
          createBulb(&bulb);
          printf("asd");
          scanf("%d",&i);
          rbtree_insert(t, (void*)45, (void*)&bulb, compare_int);
          print_tree(t);
      /*for(i=0; i<5000; i++) {
          int x = rand() % 10000;
          int y = rand() % 10000;

          print_tree(t);
          printf("Inserting %d -> %d\n\n", x, y);

          rbtree_insert(t, (void*)x, (void*)y, compare_int);
          assert(rbtree_lookup(t, (void*)x, compare_int) == (void*)y);
      }
      for(i=0; i<60000; i++) {
          int x = rand() % 10000;

          print_tree(t);
          printf("Deleting key %d\n\n", x);

          rbtree_delete(t, (void*)x, compare_int);
     }*/
     return 0;
 }
