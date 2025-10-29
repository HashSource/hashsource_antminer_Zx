void __noreturn sub_3A934()
{
  int v0; // r5
  int v1; // r8
  int v2; // r1
  unsigned int v3; // r3
  int v4; // r1
  unsigned int v5; // [sp+4h] [bp-8h]

  while ( 1 )
  {
    v0 = 2;
    dword_9A4A2 = 0;
    dword_9A4A6 = 0;
    do
    {
      v1 = 6;
      do
      {
        while ( 1 )
        {
          v5 = *(_DWORD *)(dword_75C50[0] + 4);
          if ( v5 == -1 )
            goto LABEL_9;
          v2 = (v5 >> 8) & 7;
          v3 = 120 * (unsigned __int8)v5;
          *(_DWORD *)((char *)&unk_9A2A8 + 4 * v2 + 457) = v3;
          if ( (_BYTE)v5 )
          {
            if ( !*((_BYTE *)&unk_9A2A8 + v2 + 427) )
            {
              *((_BYTE *)&unk_9A2A8 + v2 + 427) = 1;
              ++byte_9A4A0;
              dword_9A2BC |= 1 << v2;
            }
          }
          else if ( *((_BYTE *)&unk_9A2A8 + v2 + 427) == 1 )
          {
            *((_BYTE *)&unk_9A2A8 + v2 + 427) = 0;
            if ( 1 << v2 )
              v4 = 0;
            else
              v4 = dword_9A2BC & 1;
            dword_9A2BC = v4;
            --byte_9A4A0;
          }
          if ( v3 > dword_9A4A2 )
            dword_9A4A2 = 120 * (unsigned __int8)v5;
          if ( (v3 >= dword_9A4A6 || !v3) && dword_9A4A6 )
            break;
          dword_9A4A6 = 120 * (unsigned __int8)v5;
LABEL_9:
          sub_2A884();
          if ( !--v1 )
            goto LABEL_16;
        }
        sub_2A884();
        --v1;
      }
      while ( v1 );
LABEL_16:
      --v0;
    }
    while ( v0 );
    sleep(1u);
  }
}
