#include<stdio.h>
#include<dlist_t.h>


int main()
{
	dlist_t *head =NULL;

	dl_insert_first(&head,1);
	dl_insert_first(&head,2);
	dl_insert_last(&head,3);
	dl_insert_last(&head,4);

	dl_print_list(&head);

	dl_delete_first(&head);
	dl_print_list(&head);

	dl_delete_last(&head);

	dl_print_list(&head);
//	dl_delete_list(&head);
	dl_print_list(&head);

	dl_insert_after(&head,11);
	dl_print_list(&head);
	dl_insert_after(&head,12);
	dl_print_list(&head);
	dl_insert_after(&head,13);
	dl_print_list(&head);
	dl_insert_before(&head,24);
	dl_print_list(&head);
	dl_insert_before(&head,25);
	dl_print_list(&head);
	dl_insert_before(&head,26);
	dl_print_list(&head);


dl_delete_ele(&head,50);
	dl_print_list(&head);
dl_delete_ele(&head,53);
	dl_print_list(&head);
dl_delete_ele(&head,51);
	dl_print_list(&head);
	return 0;
}
