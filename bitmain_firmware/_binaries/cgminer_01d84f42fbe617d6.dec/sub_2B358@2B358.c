void __fastcall sub_2B358(int a1, char *s)
{
  char *v3; // r0
  char *v4; // r6
  char v5[16]; // [sp+0h] [bp-810h] BYREF
  char sa[2048]; // [sp+10h] [bp-800h] BYREF

  v3 = strchr(s, 35);
  v4 = v3;
  if ( v3 )
  {
    if ( !*(_BYTE *)(a1 + 572) )
    {
      strcpy(v5, v3);
      *v4 = 0;
      if ( !strcmp(v5, "#xnsub") )
      {
        *(_BYTE *)(a1 + 572) = 1;
        if ( byte_630C1 )
        {
          if ( byte_632F0 || byte_630C0 || dword_60964 > 6 )
          {
            snprintf(sa, 0x800u, "Pool %d extranonce subscribing enabled.", *(_DWORD *)a1);
            sub_38438(7, sa, 0);
          }
        }
      }
    }
  }
}
