#ifndef PROJECT_H
#define PROJECT_H

typedef struct file_table
   {
          char filename[20];
           int word_count;
  }file_table_t;
  
  typedef struct node     //main Structure.
  {
         char *word;
          file_table_t *ft;
          int file_count;
          struct node *link;
  }node;

int project_hash(char *key);
void file(FILE *fp,node *struct_ptr[], char *file_name);
 void create_text_node(node **head, char *word, char *file_name);
void file_word_count(node *head, char *file_name);
node *create_link(char *word, char *file_name);

#endif
