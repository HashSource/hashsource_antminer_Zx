void __fastcall sub_49A18(_BYTE *a1, char a2, int a3)
{
  int v5; // r0
  char s[4096]; // [sp+18h] [bp-1000h] BYREF

  v5 = sub_3C92C(a1 + 2, (unsigned __int8)(8 * a2 - 21));
  if ( (a1[8] & 0x1F) == v5 )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(
        s,
        0x1000u,
        "chain[%d] asic[%d] %02x %02x %02x %02x\n",
        a3,
        (unsigned __int8)(a1[7] / (unsigned __int8)byte_9A4C7),
        (unsigned __int8)a1[3],
        (unsigned __int8)a1[4],
        (unsigned __int8)a1[5],
        (unsigned __int8)a1[6]);
      sub_385C8(7, s, 0);
    }
  }
  else if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(s, 0x1000u, "%s chain%d CRC error crc = %02x\n", "pm_handle", a3, v5);
    sub_385C8(3, s, 0);
  }
}
