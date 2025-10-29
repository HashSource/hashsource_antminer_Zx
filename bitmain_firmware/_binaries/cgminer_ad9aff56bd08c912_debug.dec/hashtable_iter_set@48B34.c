void __fastcall hashtable_iter_set(void *iter, json_t *value)
{
  json_t *v3; // r0
  size_t refcount; // r3
  size_t v5; // r3

  v3 = (json_t *)*((_DWORD *)iter + 2);
  if ( !v3 || (refcount = v3->refcount, refcount == -1) || (v5 = refcount - 1, (v3->refcount = v5) != 0) )
  {
    *((_DWORD *)iter + 2) = value;
  }
  else
  {
    json_delete(v3);
    *((_DWORD *)iter + 2) = value;
  }
}
