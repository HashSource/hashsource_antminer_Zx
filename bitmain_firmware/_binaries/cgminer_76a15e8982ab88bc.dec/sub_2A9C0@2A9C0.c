void __fastcall sub_2A9C0(int a1, char *s)
{
  char *v3; // r0
  char *v4; // r6
  char v5[16]; // [sp+0h] [bp-1010h] BYREF
  char sa[4096]; // [sp+10h] [bp-1000h] BYREF

  v3 = strchr(s, 35);
  v4 = v3;
  if ( v3 )
  {
    if ( !*(_BYTE *)(a1 + 604) )
    {
      strcpy(v5, v3);
      *v4 = 0;
      if ( !strcmp(v5, "#xnsub") )
      {
        *(_BYTE *)(a1 + 604) = 1;
        if ( byte_75C49 )
        {
          if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
          {
            snprintf(sa, 0x1000u, "Pool %d extranonce subscribing enabled.", *(_DWORD *)a1);
            sub_385C8(7, sa, 0);
          }
        }
      }
    }
  }
}
