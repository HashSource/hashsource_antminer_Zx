int __fastcall sub_42200(int a1)
{
  unsigned __int8 v1; // r5
  int v2; // r8
  char v3; // r1
  int v4; // r5
  unsigned __int8 v5; // r1
  size_t v6; // r0
  int result; // r0
  int s; // [sp+10h] [bp-1000h] BYREF
  __int16 v9; // [sp+14h] [bp-FFCh]
  char v10; // [sp+16h] [bp-FFAh]

  v1 = a1;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(
      (char *)&s,
      0x1000u,
      "%s chainID%d asics %d addrInterval %d",
      "software_set_address_chain",
      a1,
      *((unsigned __int8 *)&unk_9A2A8 + a1 + 497),
      (unsigned __int8)byte_9A4C7);
    sub_385C8(5, (const char *)&s, 0);
  }
  v2 = v1;
  sub_42188(v1);
  sub_2A884();
  v3 = byte_9A4C7;
  v4 = 0;
  while ( 1 )
  {
    v5 = v4 * v3;
    s = 0;
    ++v4;
    v9 = 0;
    v10 = 0;
    v6 = sub_3CB3C((int)&s, v5);
    sub_3BFB4(v2, &s, v6);
    result = sub_2A884();
    if ( v4 == 3 )
      break;
    v3 = byte_9A4C7;
  }
  return result;
}
