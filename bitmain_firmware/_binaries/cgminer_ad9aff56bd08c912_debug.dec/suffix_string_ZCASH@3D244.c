void __fastcall suffix_string_ZCASH(uint64_t val, char *buf, size_t bufsiz, int sigdigits, bool display)
{
  double v7; // d9
  double v8; // d8
  int v9; // r3
  int v10; // s16
  double v11; // r0
  char suffix[8]; // [sp+1Ch] [bp-8h] BYREF

  *(_WORD *)suffix = 0;
  if ( val <= 0x3B9AC9FF )
  {
    if ( val <= 0xF423F )
    {
      v7 = (double)(int)val;
      if ( val < 0x3E8 )
      {
        if ( !sigdigits )
        {
          snprintf(buf, bufsiz, "%d%s", (_DWORD)val, suffix);
          return;
        }
      }
      else
      {
        strcpy(suffix, "K");
        v7 = v7 / 1000.0;
        if ( !sigdigits )
          goto LABEL_3;
      }
    }
    else
    {
      val /= 0x3E8uLL;
      strcpy(suffix, "M");
      v7 = (double)(int)val / 1000.0;
      if ( !sigdigits )
        goto LABEL_3;
    }
  }
  else
  {
    *(double *)&val = (double)(val / 0xF4240);
    strcpy(suffix, "G");
    v7 = *(double *)&val / 1000.0;
    if ( !sigdigits )
    {
LABEL_3:
      snprintf(buf, bufsiz, "%.3g%s", v7, suffix);
      return;
    }
  }
  v8 = (double)(sigdigits - 1);
  if ( v7 > 0.0 )
  {
    v11 = log10(*(double *)&val);
    floor(v11);
    v9 = sigdigits + 1;
    v10 = (int)(v8 - v7);
    if ( !display )
      goto LABEL_10;
  }
  else
  {
    v9 = sigdigits + 1;
    v10 = (int)v8;
    if ( !display )
    {
LABEL_10:
      snprintf(buf, bufsiz, "%*.*f", v9, v10, v7);
      return;
    }
  }
  snprintf(buf, bufsiz, "%*.*f%s", v9, v10, v7, suffix);
}
