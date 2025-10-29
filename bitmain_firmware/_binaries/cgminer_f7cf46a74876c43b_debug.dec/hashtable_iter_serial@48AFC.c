size_t __fastcall hashtable_iter_serial(void *iter)
{
  return *((_DWORD *)iter + 3);
}
