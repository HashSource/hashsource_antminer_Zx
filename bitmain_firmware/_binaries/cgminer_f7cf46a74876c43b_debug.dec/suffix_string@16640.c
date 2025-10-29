void __fastcall suffix_string(uint64_t val, char *buf, size_t bufsiz, int sigdigits)
{
  __int16 v6; // r3
  double v7; // d8
  int v8; // r1
  double v9; // r0
  char suffix[8]; // [sp+1Ch] [bp-8h] BYREF

  *(_WORD *)suffix = 0;
  if ( val > 0xDE0B6B3A763FFFFLL )
  {
    val /= 0x38D7EA4C68000uLL;
    v6 = 69;
    goto LABEL_3;
  }
  if ( val > 0x38D7EA4C67FFFLL )
  {
    val /= 0xE8D4A51000uLL;
    v6 = 80;
    goto LABEL_3;
  }
  if ( val > 0xE8D4A50FFFLL )
  {
    val /= 0x3B9ACA00uLL;
    v6 = 84;
    goto LABEL_3;
  }
  if ( val > 0x3B9AC9FF )
  {
    val /= 0xF4240uLL;
    v6 = 71;
LABEL_3:
    *(_WORD *)suffix = v6;
    v7 = (double)(int)val / 1000.0;
    if ( !sigdigits )
    {
LABEL_4:
      snprintf(buf, bufsiz, "%.3g%s", v7, suffix);
      return;
    }
    goto LABEL_9;
  }
  if ( val > 0xF423F )
  {
    val /= 0x3E8uLL;
    v6 = 77;
    goto LABEL_3;
  }
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
      goto LABEL_4;
  }
LABEL_9:
  if ( v7 > 0.0 )
  {
    v9 = log10(*(double *)&val);
    floor(v9);
    v8 = (int)(3.0 - v7);
  }
  else
  {
    v8 = 3;
  }
  snprintf(buf, bufsiz, "%*.*f%s", sigdigits + 1, v8, v7, suffix);
}
