int __fastcall sub_11580(unsigned __int64 a1, char *a2, size_t a3, int a4)
{
  __int64 v6; // r2
  __int64 v7; // r0
  double v8; // r0
  double v9; // d8
  bool v11; // cf
  __int64 v12; // r0
  double v13; // d0
  double v14; // r0
  __int64 v15; // r0
  __int64 v16; // r0
  __int64 v17; // r0
  __int16 v18; // [sp+1Ch] [bp-4h] BYREF

  v18 = 0;
  if ( a1 > 0xDE0B6B3A763FFFFLL )
  {
    LODWORD(v6) = -1530494976;
    HIDWORD(v6) = (char *)&loc_38D7C + 2;
    LODWORD(v7) = sub_5CBC4(a1, v6);
    LODWORD(v8) = sub_5CB50(v7);
    v18 = 69;
    v9 = v8 / 1000.0;
    goto LABEL_3;
  }
  v11 = (unsigned int)&loc_38D7C + 2 >= HIDWORD(a1);
  if ( (_UNKNOWN *)((char *)&loc_38D7C + 2) == (_UNKNOWN *)HIDWORD(a1) )
    v11 = (unsigned int)a1 <= 0xA4C67FFF;
  if ( !v11 )
  {
    LODWORD(v12) = sub_5CBC4(a1, 1000000000000LL);
    LODWORD(v8) = sub_5CB50(v12);
    v18 = 80;
    v9 = v8 / 1000.0;
    goto LABEL_3;
  }
  if ( a1 > 0xE8D4A50FFFLL )
  {
    LODWORD(v16) = sub_5CBC4(a1, 1000000000);
    LODWORD(v8) = sub_5CB50(v16);
    v18 = 84;
    v9 = v8 / 1000.0;
    goto LABEL_3;
  }
  if ( a1 > 0x3B9AC9FF )
  {
    LODWORD(v15) = sub_5CBC4(a1, 1000000);
    LODWORD(v8) = sub_5CB50(v15);
    v18 = 71;
    v9 = v8 / 1000.0;
    goto LABEL_3;
  }
  if ( a1 > 0xF423F )
  {
    LODWORD(v17) = sub_5CBC4(a1, 1000);
    LODWORD(v8) = sub_5CB50(v17);
    v18 = 77;
    v9 = v8 / 1000.0;
    goto LABEL_3;
  }
  if ( a1 > 0x3E7 )
  {
    LODWORD(v8) = sub_5CB50(a1);
    v18 = 75;
    v9 = v8 / 1000.0;
LABEL_3:
    if ( !a4 )
      return snprintf(a2, a3, "%.3g%s", v9, (const char *)&v18);
    goto LABEL_9;
  }
  LODWORD(v8) = sub_5CB50(a1);
  v9 = v8;
  if ( !a4 )
    return snprintf(a2, a3, "%d%s", (unsigned int)v8, (const char *)&v18);
LABEL_9:
  if ( v9 <= 0.0 )
  {
    v13 = 0.0;
  }
  else
  {
    v13 = v9;
    v14 = log10(v8);
    floor(v14);
  }
  return snprintf(a2, a3, "%*.*f%s", a4 + 1, (int)((double)(a4 - 1) - v13), v9, (const char *)&v18);
}
