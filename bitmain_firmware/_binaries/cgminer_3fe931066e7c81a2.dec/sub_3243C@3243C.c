int __fastcall sub_3243C(int *a1)
{
  int v2; // r0
  bool v3; // zf
  int v4; // r6
  void **v5; // r4
  void **v6; // r5

  if ( pthread_mutex_lock(&stru_78CB8) )
    sub_B774("tidyup", 4620);
  v2 = *a1;
  v3 = *a1 == -1;
  byte_78CAC = 1;
  if ( !v3 )
  {
    shutdown(v2, 2);
    close(*a1);
    *a1 = -1;
  }
  if ( dword_78CB4 )
  {
    free((void *)dword_78CB4);
    dword_78CB4 = 0;
  }
  v4 = dword_78CD0;
  if ( dword_78CD0 )
  {
    v5 = (void **)dword_78CD0;
    do
    {
      v6 = (void **)v5[2];
      free(*((void **)*v5 + 1));
      free(*v5);
      free(v5);
      v5 = v6;
    }
    while ( (void **)v4 != v6 );
    dword_78CD0 = 0;
  }
  if ( pthread_mutex_unlock(&stru_78CB8) )
    sub_B84C("tidyup", 4641);
  return off_75ED8();
}
