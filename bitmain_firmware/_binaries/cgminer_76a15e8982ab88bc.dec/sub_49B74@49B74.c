void __fastcall sub_49B74(int a1, int a2, char a3)
{
  int v5; // r0
  int v6; // r3
  bool v7; // cc
  char *v8; // r1
  char *v9; // r2
  char v10; // r1
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  v5 = sub_3C92C((_BYTE *)(a1 + 2), 51);
  if ( (*(_BYTE *)(a1 + 8) & 0x1F) == v5 )
  {
    if ( (unsigned int)dword_78BC4 > 0x63 || (unsigned int)dword_78BBC > 0x63 )
    {
      if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
      {
        strcpy(s, "Will Clean!");
        sub_385C8(5, s, 0);
      }
      sub_46EEC();
    }
    else
    {
      pthread_mutex_lock(&stru_769B8);
      v6 = dword_78BBC;
      v7 = (unsigned int)dword_78BBC > 0x62;
      v8 = (char *)&dword_78BBC + 7 * dword_78BBC;
      if ( (unsigned int)dword_78BBC > 0x62 )
        v6 = 0;
      v9 = v8 + 8;
      *(_DWORD *)(v8 + 13) = *(_DWORD *)(a1 + 3);
      v8[17] = *(_BYTE *)(a1 + 7);
      v10 = *(_BYTE *)(a1 + 2);
      v9[10] = a3;
      if ( v7 )
        dword_78BBC = v6;
      v9[4] = v10;
      if ( !v7 )
      {
        if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          snprintf(s, 0x1000u, "%s: p_wr = %d reg_value_num = %d", "reg_handle", v6, dword_78BC4);
          sub_385C8(7, s, 0);
          v6 = dword_78BBC;
        }
        dword_78BBC = v6 + 1;
      }
      if ( (unsigned int)dword_78BC4 > 0x63 )
      {
        dword_78BC4 = 100;
        if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
        {
          snprintf(s, 0x1000u, "%s: reg fifo full!!!", "reg_handle");
          sub_385C8(4, s, 0);
        }
      }
      else
      {
        ++dword_78BC4;
      }
      pthread_mutex_unlock(&stru_769B8);
    }
  }
  else if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(s, 0x1000u, "%s CRC error crc = %02x\n", "reg_handle", v5);
    sub_385C8(3, s, 0);
  }
}
