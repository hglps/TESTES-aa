btree* form_btree(char *text)
{
  btree *bt = create_empty();
  int integer, i=0,index=0;
  char extractText[100];

  while(text[index] == '(') index+=1;
  if(text[index] == ')')
  {
    index++;
    return NULL;
  }
  else
  {
    while(text[index] != '(')
    {
      extractText[i++] = text[index];
      index+=1;
    }
    extractText[i] = '\0';
    integer = atoi(extractText);
    bt = create_btree(integer,NULL,NULL);
    bt->left = form_btree(text);
  }
  index+=1;
  return bt;
}
