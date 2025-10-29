void __fastcall cgsem_reset(cgsem_t *cgsem)
{
  int v2; // r0

  do
  {
    while ( 1 )
    {
      v2 = sem_trywait(cgsem);
      if ( v2 < 0 )
        break;
      if ( v2 )
        return;
    }
  }
  while ( *_errno_location() == 4 );
}
