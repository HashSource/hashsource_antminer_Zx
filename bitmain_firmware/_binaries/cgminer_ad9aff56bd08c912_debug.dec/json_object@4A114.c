json_t_0 *json_object()
{
  char *v0; // r0
  _DWORD *v1; // r4
  void *v3; // r0

  v0 = (char *)jsonp_malloc(0x24u);
  v1 = v0;
  if ( v0 )
  {
    *(_DWORD *)v0 = 0;
    *((_DWORD *)v0 + 1) = 1;
    if ( hashtable_init((hashtable_t *)(v0 + 8)) )
    {
      v3 = v1;
      v1 = 0;
      jsonp_free(v3);
    }
    else
    {
      v1[7] = 0;
      v1[8] = 0;
    }
  }
  return (json_t_0 *)v1;
}
