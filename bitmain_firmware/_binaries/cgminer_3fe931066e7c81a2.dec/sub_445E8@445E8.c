int __fastcall sub_445E8(int result, int a2)
{
  int v2; // r4
  int v4; // r3
  int v5; // r7
  int v6; // [sp+8h] [bp-100Ch] BYREF
  char v7; // [sp+Ch] [bp-1008h]
  char s[4080]; // [sp+10h] [bp-1004h] BYREF

  v2 = result;
  if ( *((_BYTE *)&unk_9D4B4 + result + 8) )
  {
    v4 = (unsigned __int8)byte_7AD48;
    dword_7C064[result] = result;
    if ( v4 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "%s chainid = %d", "tty_init_chain", result);
      sub_38730(5, s, 0);
    }
    *((_BYTE *)&dword_78E10[194] + v2) = 1;
    if ( sub_2F174(a2 + (v2 << 6) + 890, 0, (void *(*)(void *))sub_4B0C0, &dword_7C064[v2]) )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
      {
        snprintf(s, 0x1000u, "create rx read thread for chain %d failed", v2);
        goto LABEL_11;
      }
    }
    else if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
    {
      snprintf(s, 0x1000u, "create rx read thread for chain %d ok", v2);
LABEL_11:
      sub_38730(3, s, 0);
    }
    sub_2A92C();
    v6 = a2;
    v7 = v2;
    v5 = sub_2F174(a2 + (v2 << 6) + 634, 0, (void *(*)(void *))sub_42B54, &v6);
    sub_2A92C();
    if ( v5 )
    {
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
        goto LABEL_22;
      snprintf(s, 0x1000u, "create tx read thread for chain %d failed", v2);
    }
    else
    {
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
        goto LABEL_22;
      snprintf(s, 0x1000u, "create tx read thread for chain %d ok", v2);
    }
    sub_38730(3, s, 0);
    if ( byte_7AD48 || byte_78E08 )
    {
LABEL_19:
      strcpy(s, "open device over");
      sub_38730(5, s, 0);
      return sub_2A92C();
    }
LABEL_22:
    if ( dword_766C4 <= 4 )
      return sub_2A92C();
    goto LABEL_19;
  }
  return result;
}
