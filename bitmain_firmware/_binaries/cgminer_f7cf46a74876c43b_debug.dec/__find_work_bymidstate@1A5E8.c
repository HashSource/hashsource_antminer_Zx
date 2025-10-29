work *__fastcall _find_work_bymidstate(
        work *que,
        char *midstate,
        size_t midstatelen,
        char *data,
        int offset,
        size_t datalen)
{
  work *v6; // r5
  work *next; // r4

  v6 = que;
  if ( que )
  {
    next = (work *)que->hh.next;
    while ( memcmp(v6->midstate, midstate, midstatelen) || memcmp(&v6->data[offset], data, datalen) )
    {
      if ( !next )
        return next;
      v6 = next;
      next = (work *)next->hh.next;
    }
  }
  return v6;
}
