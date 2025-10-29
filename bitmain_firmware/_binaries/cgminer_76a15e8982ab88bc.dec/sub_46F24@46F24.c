int __fastcall sub_46F24(int a1, int a2, int a3, int a4)
{
  size_t v8; // r0
  int v9; // r3
  unsigned int v10; // r5
  int v11; // r9
  int v12; // r10
  int v13; // r7
  int v14; // r5
  int v15; // r3
  int v16; // r1
  int v17; // r2
  unsigned int v18; // r3
  unsigned int v20; // r1
  char *v21; // r0
  _WORD *v22; // r12
  int v23; // [sp+14h] [bp-1020h]
  int v24; // [sp+28h] [bp-100Ch] BYREF
  __int16 v25; // [sp+2Ch] [bp-1008h]
  char v26; // [sp+2Eh] [bp-1006h]
  char s[4048]; // [sp+30h] [bp-1004h] BYREF

  v25 = 0;
  v24 = 0;
  v26 = 0;
  sub_46EEC();
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "%s: check chain J%d mode %d chipaddr %02x regaddr %02x", "check_asic_reg", a1, a4, a2, a3);
    sub_385C8(7, s, 0);
  }
  v8 = sub_3CBB0((int)&v24, a4, a2, a3);
  sub_3BFB4(a1, &v24, v8);
  if ( !a3 && *((_BYTE *)&dword_75C50[864] + a1) )
    *((_BYTE *)&unk_9A2A8 + a1 + 497) = 0;
  v9 = a3;
  v10 = 0;
  v11 = a2;
  v12 = v9;
  do
  {
LABEL_10:
    usleep((__useconds_t)sub_493E0);
    pthread_mutex_lock(&stru_769B8);
    v13 = dword_78BC4;
    pthread_mutex_unlock(&stru_769B8);
    if ( v13 )
    {
      v14 = 0;
      while ( 1 )
      {
        pthread_mutex_lock(&stru_769B8);
        v15 = dword_78BC0;
        v16 = *((unsigned __int8 *)&dword_78BBC + 7 * dword_78BC0 + 18);
        if ( v16 != a1 )
        {
          ++dword_78BC0;
          --dword_78BC4;
          if ( v15 == 99 )
            dword_78BC0 = 0;
          if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
          {
            snprintf(
              s,
              0x1000u,
              "%s: the return data is from chain%d, but it should be from chain%d chipaddr=0x%02x reg=0x%02x\n",
              "check_asic_reg",
              v16,
              a1,
              v11,
              v12);
            sub_385C8(5, s, 0);
          }
          goto LABEL_18;
        }
        v17 = *((unsigned __int8 *)&dword_78BBC + 7 * dword_78BC0 + 17);
        v18 = bswap32(*(int *)((char *)&dword_78BBC + 7 * dword_78BC0 + 13));
        switch ( v12 )
        {
          case 0:
            if ( *((_BYTE *)&dword_75C50[864] + a1) )
            {
              ++*((_BYTE *)&unk_9A2A8 + a1 + 497);
              goto LABEL_23;
            }
            if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic address is 0x%08x", "check_asic_reg", v18);
            goto LABEL_31;
          case 12:
            if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic freq is 0x%08x", "check_asic_reg", v18);
            goto LABEL_31;
          case 20:
            if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic tm is 0x%08x", "check_asic_reg", v18);
            goto LABEL_31;
          case 28:
            if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic misc is 0x%08x", "check_asic_reg", v18);
            goto LABEL_31;
        }
        if ( v12 != 32 )
        {
          if ( v12 == 84 )
          {
            if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the start nonce offset is 0x%08x", "check_asic_reg", v18);
          }
          else
          {
            if ( v12 != 48 || !byte_77B70 && !byte_75C48 && dword_73504 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic IO strength is 0x%08x", "check_asic_reg", v18);
          }
LABEL_31:
          sub_385C8(5, s, 0);
          goto LABEL_23;
        }
        v20 = v18 & 0xC0000000;
        if ( (v18 & 0xC0000000) == 0 )
        {
          v23 = v18 & 0xFF00;
          v21 = (char *)&unk_769F4 + 8 * a1;
          v22 = (_WORD *)((char *)&unk_9A2A8 + 16 * a1 + 128);
          if ( (unsigned __int8)byte_75F70[0] == v17 )
          {
LABEL_61:
            if ( (v18 & 0xFF00) != 0 )
            {
              switch ( v23 )
              {
                case 256:
                  v21[1] = 1;
                  v22[1] = (unsigned __int8)v18;
                  break;
                case 4352:
                  byte_769D4[4 * a1 + v20] = v18;
                  v21[2] = 1;
                  break;
                case 65024:
                  byte_769E4[4 * a1 + v20] = v18;
                  v21[3] = 1;
                  break;
              }
            }
            else
            {
              *v21 = 1;
              *v22 = (unsigned __int8)v18;
            }
          }
          while ( 1 )
          {
            ++v20;
            v22 += 4;
            v21 += 4;
            if ( v20 == 2 )
              break;
            if ( (unsigned __int8)byte_75F70[v20] == v17 )
              goto LABEL_61;
          }
        }
LABEL_23:
        ++dword_78BC0;
        --dword_78BC4;
        if ( dword_78BC0 == 100 )
          dword_78BC0 = 0;
LABEL_18:
        ++v14;
        pthread_mutex_unlock(&stru_769B8);
        if ( v14 == v13 )
        {
          v10 = 0;
          goto LABEL_10;
        }
      }
    }
    ++v10;
    usleep(0x186A0u);
  }
  while ( v10 <= 2 );
  if ( !v12 )
  {
    if ( (unsigned __int8)byte_9A4C8 < (unsigned int)*((unsigned __int8 *)&unk_9A2A8 + a1 + 497) )
      byte_9A4C8 = *((_BYTE *)&unk_9A2A8 + a1 + 497);
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(
        s,
        0x1000u,
        "%s: chain J%d has %d ASIC",
        "check_asic_reg",
        a1,
        *((unsigned __int8 *)&unk_9A2A8 + a1 + 497));
      sub_385C8(5, s, 0);
    }
  }
  return sub_46EEC();
}
