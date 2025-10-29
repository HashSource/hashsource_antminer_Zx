void __fastcall set_work_ntime(work *work, int ntime)
{
  char *v2; // r3

  v2 = work->ntime;
  *(_DWORD *)&work->data[68] = bswap32(ntime);
  if ( v2 )
  {
    free(v2);
    work->ntime = bin2hex(&work->data[68], 4u);
  }
}
