// Alternative name is 'copyadvanceafter.constprop.20'
void __fastcall copyadvanceafter(unsigned __int8 **ch, char **param, char **buf)
{
  _BYTE *v3; // r2
  int v4; // r3
  char *v5; // r2
  bool v6; // zf
  _BYTE *v7; // r3
  char *v8; // r3

  v3 = *ch;
  v4 = **ch;
  if ( **ch )
  {
    while ( v4 != 44 )
    {
      v6 = v4 == 92;
      v7 = v3;
      if ( v6 && v3[1] )
        v7 = v3 + 1;
      *ch = v7 + 1;
      v5 = (*param)++;
      *v5 = *v7;
      v3 = *ch;
      v4 = **ch;
      if ( !**ch )
        goto LABEL_10;
    }
    *ch = v3 + 1;
  }
LABEL_10:
  v8 = (*param)++;
  *v8 = 0;
}
