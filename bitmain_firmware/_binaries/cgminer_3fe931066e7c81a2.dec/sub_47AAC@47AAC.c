int __fastcall sub_47AAC(unsigned __int64 a1, char *a2, size_t a3, int a4, char a5)
{
  __int64 v7; // r0
  double v8; // r0
  double v9; // d8
  __int64 v11; // r0
  double v12; // d0
  double v13; // r0
  int v14; // r3
  int v15; // [sp+0h] [bp-24h]
  char v16[8]; // [sp+1Ch] [bp-8h] BYREF

  *(_WORD *)v16 = 0;
  if ( a1 > 0x3B9AC9FF )
  {
    LODWORD(v7) = sub_5CBC4(a1, 1000000);
    LODWORD(v8) = sub_5CB50(v7);
    strcpy(v16, "G");
    v9 = v8 / 1000.0;
    goto LABEL_3;
  }
  if ( a1 > 0xF423F )
  {
    LODWORD(v11) = sub_5CBC4(a1, 1000);
    LODWORD(v8) = sub_5CB50(v11);
    strcpy(v16, "M");
    v9 = v8 / 1000.0;
    goto LABEL_3;
  }
  if ( a1 > 0x3E7 )
  {
    LODWORD(v8) = sub_5CB50(a1);
    strcpy(v16, "K");
    v9 = v8 / 1000.0;
LABEL_3:
    if ( !a4 )
      return snprintf(a2, a3, "%.3g%s", v9, v16);
    goto LABEL_7;
  }
  LODWORD(v8) = sub_5CB50(a1);
  v9 = v8;
  if ( !a4 )
    return snprintf(a2, a3, "%d%s", (unsigned int)v8, v16);
LABEL_7:
  if ( v9 <= 0.0 )
  {
    v12 = 0.0;
  }
  else
  {
    v12 = v9;
    v13 = log10(v8);
    floor(v13);
  }
  v14 = a4 + 1;
  v15 = (int)((double)(a4 - 1) - v12);
  if ( a5 )
    return snprintf(a2, a3, "%*.*f%s", v14, v15, v9, v16);
  else
    return snprintf(a2, a3, "%*.*f", v14, v15, v9);
}
