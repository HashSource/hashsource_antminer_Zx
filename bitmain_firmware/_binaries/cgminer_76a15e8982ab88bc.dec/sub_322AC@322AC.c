int __fastcall sub_322AC(int *a1)
{
  int v2; // r0
  bool v3; // zf
  int v4; // r6
  void **v5; // r4
  void **v6; // r5

  if ( pthread_mutex_lock(&stru_75AF8) )
    sub_B6BC("tidyup", 4620);
  v2 = *a1;
  v3 = *a1 == -1;
  byte_75AEC = 1;
  if ( !v3 )
  {
    shutdown(v2, 2);
    close(*a1);
    *a1 = -1;
  }
  if ( dword_75AF4 )
  {
    free((void *)dword_75AF4);
    dword_75AF4 = 0;
  }
  v4 = dword_75B10;
  if ( dword_75B10 )
  {
    v5 = (void **)dword_75B10;
    do
    {
      v6 = (void **)v5[2];
      free(*((void **)*v5 + 1));
      free(*v5);
      free(v5);
      v5 = v6;
    }
    while ( (void **)v4 != v6 );
    dword_75B10 = 0;
  }
  if ( pthread_mutex_unlock(&stru_75AF8) )
    sub_B794("tidyup", 4641);
  return off_72D18();
}
