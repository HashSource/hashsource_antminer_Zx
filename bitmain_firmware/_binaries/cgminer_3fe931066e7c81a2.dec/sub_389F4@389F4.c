int __fastcall sub_389F4(int result, const char *a2, const char *a3, int a4)
{
  int v4; // r6

  v4 = result;
  if ( !byte_7BC78 || result == 3 )
  {
    if ( a4 )
    {
      pthread_mutex_trylock(&mutex);
      sub_3896C(38);
      off_75ED8();
      if ( byte_75DD0 )
      {
LABEL_5:
        result = sub_199E8(v4, a2, a3);
        if ( result )
          return result;
      }
    }
    else if ( byte_75DD0 )
    {
      goto LABEL_5;
    }
    sub_388E4();
    printf("%s%s%s", a2, a3, "                    \n");
    sub_3896C(49);
    return off_75ED8();
  }
  return result;
}
