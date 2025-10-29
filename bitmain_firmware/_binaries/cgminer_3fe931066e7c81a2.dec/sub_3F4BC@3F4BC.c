int __fastcall sub_3F4BC(int a1)
{
  int v1; // r3
  __int16 v2; // r2
  __int16 v3; // r12
  int v4; // r1
  _DWORD *v5; // r3
  char v6; // t1
  _WORD *v7; // r4
  int v8; // t1
  int v9; // r4
  int v10; // r5
  int result; // r0
  _BYTE v12[13]; // [sp+13h] [bp-1015h] BYREF
  int v13; // [sp+20h] [bp-1008h] BYREF
  __int16 v14; // [sp+24h] [bp-1004h] BYREF
  char s[4056]; // [sp+28h] [bp-1000h] BYREF

  v1 = 0;
  v2 = 34;
  memset(&v12[1], 0, 12);
  v13 = 0;
  v14 = 0;
  do
  {
    v3 = *(unsigned __int8 *)(a1 + v1++);
    v2 += v3;
  }
  while ( v1 != 12 );
  v4 = a1 - 1;
  v5 = &v12[4];
  *(_DWORD *)&v12[1] = 303082069;
  do
  {
    v6 = *(_BYTE *)++v4;
    *((_BYTE *)v5 + 1) = v6;
    v5 = (_DWORD *)((char *)v5 + 1);
  }
  while ( v5 != (int *)((char *)&v13 + 3) );
  LOBYTE(v14) = HIBYTE(v2);
  v7 = v12;
  HIBYTE(v14) = v2;
  pthread_mutex_lock(&stru_790A0);
  do
  {
    v8 = *((unsigned __int8 *)v7 + 1);
    v7 = (_WORD *)((char *)v7 + 1);
    sub_3C7B0(v8);
  }
  while ( v7 != (__int16 *)((char *)&v14 + 1) );
  usleep(0x30D40u);
  v9 = sub_3C7C8();
  v10 = sub_3C7C8();
  pthread_mutex_unlock(&stru_790A0);
  usleep(0x30D40u);
  if ( v9 == 18 && v10 == 1 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "%s ok", "write_hash_ID_PIC16F1704_new");
      sub_38730(5, s, 0);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( byte_7AD48 || (result = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 2 )
  {
    snprintf(
      s,
      0x1000u,
      "%s chain %d failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
      "write_hash_ID_PIC16F1704_new",
      dword_7909C,
      v9,
      v10);
    sub_38730(3, s, 0);
    return 0;
  }
  return result;
}
