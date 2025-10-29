int __fastcall sub_481EC(int a1, int a2, int a3, int a4)
{
  size_t v8; // r0
  int v9; // r8
  unsigned int v10; // r5
  int v11; // r10
  int v12; // r11
  int v13; // r5
  int v14; // r3
  int v15; // r1
  int v16; // r2
  unsigned int v17; // r3
  unsigned int v19; // r1
  _BYTE *v20; // r0
  _WORD *v21; // r12
  int v22; // [sp+10h] [bp-1024h]
  __int16 v23; // [sp+1Ch] [bp-1018h]
  int v24; // [sp+28h] [bp-100Ch] BYREF
  __int16 v25; // [sp+2Ch] [bp-1008h]
  char v26; // [sp+2Eh] [bp-1006h]
  char s[4048]; // [sp+30h] [bp-1004h] BYREF

  v25 = 0;
  v24 = 0;
  v26 = 0;
  sub_481B4();
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "%s: check chain J%d mode %d chipaddr %02x regaddr %02x", "check_asic_reg", a1, a4, a2, a3);
    sub_38730(7, s, 0);
  }
  v8 = sub_3CEF0((int)&v24, a4, a2, a3);
  sub_3C150(a1, &v24, v8);
  if ( !a3 && *((_BYTE *)&dword_78E10[864] + a1) )
    *((_BYTE *)&unk_9D4B4 + a1 + 529) = 0;
  v9 = a3;
  v10 = 0;
  v11 = a2;
  do
  {
LABEL_10:
    usleep(0x493E0u);
    pthread_mutex_lock(&stru_79B78);
    v12 = dword_7BD9C;
    pthread_mutex_unlock(&stru_79B78);
    if ( v12 )
    {
      v13 = 0;
      while ( 1 )
      {
        pthread_mutex_lock(&stru_79B78);
        v14 = dword_7BD98;
        v15 = *((unsigned __int8 *)&dword_7BD94 + 7 * dword_7BD98 + 18);
        if ( v15 != a1 )
        {
          ++dword_7BD98;
          --dword_7BD9C;
          if ( v14 == 99 )
            dword_7BD98 = 0;
          if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
          {
            snprintf(
              s,
              0x1000u,
              "%s: the return data is from chain%d, but it should be from chain%d chipaddr=0x%02x reg=0x%02x\n",
              "check_asic_reg",
              v15,
              a1,
              v11,
              v9);
            sub_38730(5, s, 0);
          }
          goto LABEL_18;
        }
        v16 = *((unsigned __int8 *)&dword_7BD94 + 7 * dword_7BD98 + 17);
        v17 = bswap32(*(int *)((char *)&dword_7BD94 + 7 * dword_7BD98 + 13));
        switch ( v9 )
        {
          case 0:
            if ( *((_BYTE *)&dword_78E10[864] + a1) )
            {
              ++*((_BYTE *)&unk_9D4B4 + a1 + 529);
              goto LABEL_23;
            }
            if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic address is 0x%08x", "check_asic_reg", v17);
            goto LABEL_31;
          case 12:
            if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic freq is 0x%08x", "check_asic_reg", v17);
            goto LABEL_31;
          case 20:
            if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic tm is 0x%08x", "check_asic_reg", v17);
            goto LABEL_31;
          case 28:
            if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic misc is 0x%08x", "check_asic_reg", v17);
            goto LABEL_31;
        }
        if ( v9 != 32 )
        {
          if ( v9 == 84 )
          {
            if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the start nonce offset is 0x%08x", "check_asic_reg", v17);
          }
          else
          {
            if ( v9 != 48 || !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
              goto LABEL_23;
            snprintf(s, 0x1000u, "%s: the asic IO strength is 0x%08x", "check_asic_reg", v17);
          }
LABEL_31:
          sub_38730(5, s, 0);
          goto LABEL_23;
        }
        v19 = v17 & 0xC0000000;
        if ( (v17 & 0xC0000000) == 0 )
        {
          v20 = &byte_79BA4[12 * a1 + 16];
          v23 = (unsigned __int8)v17 - 64;
          v22 = v17 & 0xFF00;
          v21 = (_WORD *)((char *)&unk_9D4B4 + 24 * a1 + 128);
          if ( (unsigned __int8)byte_79130[0] == v16 )
          {
LABEL_61:
            if ( (v17 & 0xFF00) != 0 )
            {
              switch ( v22 )
              {
                case 256:
                  v21[1] = v23;
                  v20[1] = 1;
                  break;
                case 4352:
                  byte_79B94[4 * a1 + v19] = v17;
                  v20[2] = 1;
                  break;
                case 65024:
                  byte_79BA4[4 * a1 + v19] = v17;
                  v20[3] = 1;
                  break;
              }
            }
            else
            {
              *v21 = v23;
              *v20 = 1;
            }
          }
          while ( 1 )
          {
            ++v19;
            v21 += 4;
            v20 += 4;
            if ( v19 == 3 )
              break;
            if ( (unsigned __int8)byte_79130[v19] == v16 )
              goto LABEL_61;
          }
        }
LABEL_23:
        ++dword_7BD98;
        --dword_7BD9C;
        if ( dword_7BD98 == 100 )
          dword_7BD98 = 0;
LABEL_18:
        ++v13;
        pthread_mutex_unlock(&stru_79B78);
        if ( v13 == v12 )
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
  if ( !v9 )
  {
    if ( (unsigned __int8)byte_9D6F4 < (unsigned int)*((unsigned __int8 *)&unk_9D4B4 + a1 + 529) )
      byte_9D6F4 = *((_BYTE *)&unk_9D4B4 + a1 + 529);
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(
        s,
        0x1000u,
        "%s: chain J%d has %d ASIC",
        "check_asic_reg",
        a1,
        *((unsigned __int8 *)&unk_9D4B4 + a1 + 529));
      sub_38730(5, s, 0);
    }
  }
  return sub_481B4();
}
