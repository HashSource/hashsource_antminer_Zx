void __fastcall sub_4AE48(int a1, int a2, char a3)
{
  int v5; // r0
  int v6; // r3
  bool v7; // cc
  char *v8; // r1
  char *v9; // r2
  char v10; // r1
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  v5 = sub_3CC6C((_BYTE *)(a1 + 2), 51);
  if ( (*(_BYTE *)(a1 + 8) & 0x1F) == v5 )
  {
    if ( (unsigned int)dword_7BD9C > 0x63 || (unsigned int)dword_7BD94 > 0x63 )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        strcpy(s, "Will Clean!");
        sub_38730(5, s, 0);
      }
      sub_481B4();
    }
    else
    {
      pthread_mutex_lock(&stru_79B78);
      v6 = dword_7BD94;
      v7 = (unsigned int)dword_7BD94 > 0x62;
      v8 = (char *)&dword_7BD94 + 7 * dword_7BD94;
      if ( (unsigned int)dword_7BD94 > 0x62 )
        v6 = 0;
      v9 = v8 + 8;
      *(_DWORD *)(v8 + 13) = *(_DWORD *)(a1 + 3);
      v8[17] = *(_BYTE *)(a1 + 7);
      v10 = *(_BYTE *)(a1 + 2);
      v9[10] = a3;
      if ( v7 )
        dword_7BD94 = v6;
      v9[4] = v10;
      if ( !v7 )
      {
        if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          snprintf(s, 0x1000u, "%s: p_wr = %d reg_value_num = %d", "reg_handle", v6, dword_7BD9C);
          sub_38730(7, s, 0);
          v6 = dword_7BD94;
        }
        dword_7BD94 = v6 + 1;
      }
      if ( (unsigned int)dword_7BD9C > 0x63 )
      {
        dword_7BD9C = 100;
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
        {
          snprintf(s, 0x1000u, "%s: reg fifo full!!!", "reg_handle");
          sub_38730(4, s, 0);
        }
      }
      else
      {
        ++dword_7BD9C;
      }
      pthread_mutex_unlock(&stru_79B78);
    }
  }
  else if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
  {
    snprintf(s, 0x1000u, "%s CRC error crc = %02x\n", "reg_handle", v5);
    sub_38730(3, s, 0);
  }
}
