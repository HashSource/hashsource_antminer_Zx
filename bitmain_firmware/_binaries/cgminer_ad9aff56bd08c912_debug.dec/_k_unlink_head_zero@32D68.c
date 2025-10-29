K_ITEM *__fastcall k_unlink_head_zero(K_LIST *list, const char *file, const char *func, const int line)
{
  K_ITEM *v5; // r0
  K_ITEM *v6; // r4

  v5 = k_unlink_head(list, file, func, line);
  v6 = v5;
  if ( v5 )
    memset(v5->data, 0, list->siz);
  return v6;
}
