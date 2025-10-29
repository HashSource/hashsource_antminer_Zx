work *__fastcall _find_work_byid(work *que, uint32_t id)
{
  void *next; // r3

  if ( que )
  {
    next = que->hh.next;
    if ( id != que->id )
    {
      if ( next )
      {
        que = (work *)*((_DWORD *)next + 460);
        while ( *((_DWORD *)next + 457) != id )
        {
          if ( !que )
            return que;
          next = que;
          que = (work *)que->hh.next;
        }
      }
      return (work *)next;
    }
  }
  return que;
}
