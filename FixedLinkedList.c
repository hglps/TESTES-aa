node* fix_list(node *head)
{
  node *new_list = create_list();
  while(head!=NULL)
  {
    new_list = add_to_node(new_list,head->item);
    head = head->next;
  }
  return new_list;
}
