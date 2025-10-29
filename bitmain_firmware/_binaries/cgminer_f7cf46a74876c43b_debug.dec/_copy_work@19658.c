void __fastcall copy_work(work *work, const work *base_work, int noffset)
{
  uint32_t id; // r7
  char *job_id; // r0
  char *nonce1; // r0
  char *ntime; // r0
  char *coinbase; // r0
  unsigned __int8 p[4]; // [sp+4h] [bp-8h] BYREF

  id = work->id;
  clean_work(work);
  memcpy(work, base_work, sizeof(work));
  work->id = id;
  job_id = base_work->job_id;
  if ( job_id )
    work->job_id = _strdup(job_id);
  nonce1 = base_work->nonce1;
  if ( nonce1 )
    work->nonce1 = _strdup(nonce1);
  ntime = base_work->ntime;
  if ( ntime )
  {
    if ( noffset )
    {
      *(_DWORD *)&work->data[68] = bswap32(bswap32(*(_DWORD *)&work->data[68]) + noffset);
      hex2bin(p, base_work->ntime, 4u);
      *(_DWORD *)p = bswap32(noffset + bswap32(*(unsigned int *)p));
      work->ntime = bin2hex(p, 4u);
    }
    else
    {
      work->ntime = _strdup(ntime);
    }
  }
  else if ( noffset )
  {
    *(_DWORD *)&work->data[68] = bswap32(noffset + bswap32(*(_DWORD *)&work->data[68]));
  }
  coinbase = base_work->coinbase;
  if ( coinbase )
    work->coinbase = _strdup(coinbase);
}
