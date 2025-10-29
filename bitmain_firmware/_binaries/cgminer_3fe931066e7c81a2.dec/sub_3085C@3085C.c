void __fastcall sub_3085C(unsigned int *a1, char *s, int a3, _BYTE *a4)
{
  char *v6; // r5

  if ( *a4 )
  {
    if ( !a3 )
    {
      *a4 = 0;
      goto LABEL_5;
    }
    sub_307C8(a1, "{");
    *a4 = 0;
    v6 = sub_30500(s, 1);
  }
  else
  {
    if ( !a3 )
    {
LABEL_5:
      v6 = sub_30500(s, a3);
      sub_307C8(a1, "CMD=");
      sub_307C8(a1, v6);
      sub_307C8(a1, (char *)delim);
      if ( v6 == s )
        return;
      goto LABEL_6;
    }
    sub_307C8(a1, (char *)",");
    v6 = sub_30500(s, 1);
  }
  sub_307C8(a1, (char *)"\"");
  sub_307C8(a1, v6);
  sub_307C8(a1, "\":[");
  if ( v6 != s )
LABEL_6:
    free(v6);
}
