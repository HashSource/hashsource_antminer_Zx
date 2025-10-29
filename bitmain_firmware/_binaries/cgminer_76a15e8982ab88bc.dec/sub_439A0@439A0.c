int __fastcall sub_439A0(int result, int a2)
{
  int v2; // r4
  int v4; // r3
  int v5; // r7
  int v6; // [sp+8h] [bp-100Ch] BYREF
  char v7; // [sp+Ch] [bp-1008h]
  char s[4080]; // [sp+10h] [bp-1004h] BYREF

  v2 = result;
  if ( *((_BYTE *)&unk_9A2A8 + result + 8) )
  {
    v4 = (unsigned __int8)byte_77B70;
    dword_78E8C[result] = result;
    if ( v4 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(s, 0x1000u, "%s chainid = %d", "tty_init_chain", result);
      sub_385C8(5, s, 0);
    }
    *((_BYTE *)&dword_75C50[194] + v2) = 1;
    if ( sub_2EFE4(a2 + (v2 << 6) + 890, 0, (void *(*)(void *))sub_49DEC, &dword_78E8C[v2]) )
    {
      if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
      {
        snprintf(s, 0x1000u, "create rx read thread for chain %d failed", v2);
        goto LABEL_11;
      }
    }
    else if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
    {
      snprintf(s, 0x1000u, "create rx read thread for chain %d ok", v2);
LABEL_11:
      sub_385C8(3, s, 0);
    }
    sub_2A884();
    v6 = a2;
    v7 = v2;
    v5 = sub_2EFE4(a2 + (v2 << 6) + 634, 0, (void *(*)(void *))sub_41DBC, &v6);
    sub_2A884();
    if ( v5 )
    {
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
        goto LABEL_22;
      snprintf(s, 0x1000u, "create tx read thread for chain %d failed", v2);
    }
    else
    {
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
        goto LABEL_22;
      snprintf(s, 0x1000u, "create tx read thread for chain %d ok", v2);
    }
    sub_385C8(3, s, 0);
    if ( byte_77B70 || byte_75C48 )
    {
LABEL_19:
      strcpy(s, "open device over");
      sub_385C8(5, s, 0);
      return sub_2A884();
    }
LABEL_22:
    if ( dword_73504 <= 4 )
      return sub_2A884();
    goto LABEL_19;
  }
  return result;
}
