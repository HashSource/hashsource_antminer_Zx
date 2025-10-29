int sub_45F7C()
{
  FILE *v0; // r7
  int v1; // r5
  char *v2; // r6
  int v3; // t1
  int i; // r4
  char *v6; // r3
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  v0 = fopen("/config/chips_freq.config", "w+");
  if ( v0 )
  {
    v1 = 631471;
    v2 = (char *)&unk_78F58;
    do
    {
      v3 = *(unsigned __int8 *)++v1;
      if ( v3 == 1 )
      {
        for ( i = 0; i != 12; i += 4 )
        {
          v6 = &v2[i];
          fprintf(v0, "%d ", *((_DWORD *)v6 + 48));
        }
      }
      v2 += 12;
    }
    while ( v1 != 631475 );
    fclose(v0);
    return 0;
  }
  else if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s open %s failed\n", "scan_freq_save_freq", "/config/chips_freq.config");
    sub_385C8(5, s, 0);
    return -1;
  }
  else
  {
    return -1;
  }
}
