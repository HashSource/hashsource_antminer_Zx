void sub_1AE44()
{
  int v0; // r4
  pthread_t v1; // r0
  int v2; // r0
  int v3; // r5
  char v4[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    strcpy(v4, "Killing off mining threads");
    sub_385C8(7, v4, 1);
  }
  if ( dword_78994 > 0 )
  {
    v0 = 0;
    do
    {
      while ( 1 )
      {
        v2 = sub_1AA90(v0);
        v3 = v2;
        if ( v2 )
        {
          if ( *(_DWORD *)(v2 + 12) )
            break;
        }
        ++v0;
        sub_2A36C(v2);
        if ( dword_78994 <= v0 )
          return;
      }
      sub_2A36C(v2);
      v1 = *(_DWORD *)(v3 + 12);
      if ( v1 )
        pthread_join(v1, 0);
      ++v0;
    }
    while ( dword_78994 > v0 );
  }
}
