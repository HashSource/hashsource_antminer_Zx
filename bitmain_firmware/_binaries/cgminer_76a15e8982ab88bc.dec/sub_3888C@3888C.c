int __fastcall sub_3888C(int result, const char *a2, const char *a3, int a4)
{
  int v4; // r6

  v4 = result;
  if ( !byte_78AA0 || result == 3 )
  {
    if ( a4 )
    {
      pthread_mutex_trylock(&stru_785D0);
      sub_38804(38);
      off_72D18();
      if ( byte_72C1C )
      {
LABEL_5:
        result = sub_199A4(v4, a2, a3);
        if ( result )
          return result;
      }
    }
    else if ( byte_72C1C )
    {
      goto LABEL_5;
    }
    sub_3877C();
    printf("%s%s%s", a2, a3, "                    \n");
    sub_38804(49);
    return off_72D18();
  }
  return result;
}
