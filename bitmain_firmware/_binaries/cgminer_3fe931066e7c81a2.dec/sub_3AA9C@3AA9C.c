void __noreturn sub_3AA9C()
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
    dword_9D6CE = 0;
    dword_9D6D2 = 0;
    do
    {
      v1 = 6;
      do
      {
        while ( 1 )
        {
          v5 = *(_DWORD *)(dword_78E10[0] + 4);
          if ( v5 == -1 )
            goto LABEL_9;
          v2 = (v5 >> 8) & 7;
          v3 = 120 * (unsigned __int8)v5;
          *(_DWORD *)((char *)&unk_9D4B4 + 4 * v2 + 489) = v3;
          if ( (_BYTE)v5 )
          {
            if ( !*((_BYTE *)&unk_9D4B4 + v2 + 459) )
            {
              *((_BYTE *)&unk_9D4B4 + v2 + 459) = 1;
              ++byte_9D6CC;
              dword_9D4C8 |= 1 << v2;
            }
          }
          else if ( *((_BYTE *)&unk_9D4B4 + v2 + 459) == 1 )
          {
            *((_BYTE *)&unk_9D4B4 + v2 + 459) = 0;
            if ( 1 << v2 )
              v4 = 0;
            else
              v4 = dword_9D4C8 & 1;
            dword_9D4C8 = v4;
            --byte_9D6CC;
          }
          if ( v3 > dword_9D6CE )
            dword_9D6CE = 120 * (unsigned __int8)v5;
          if ( (v3 >= dword_9D6D2 || !v3) && dword_9D6D2 )
            break;
          dword_9D6D2 = 120 * (unsigned __int8)v5;
LABEL_9:
          sub_2A92C();
          if ( !--v1 )
            goto LABEL_16;
        }
        sub_2A92C();
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
