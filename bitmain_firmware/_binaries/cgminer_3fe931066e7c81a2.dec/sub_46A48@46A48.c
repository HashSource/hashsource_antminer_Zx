int __fastcall sub_46A48(int a1)
{
  int v1; // r6
  int v2; // r5
  int v4; // r4
  int v5; // r7
  int v6; // t1
  int v8; // r2
  int v9; // r1
  char v10; // r3
  int v11; // [sp+4h] [bp-1010h] BYREF
  int v12; // [sp+8h] [bp-100Ch]
  char v13; // [sp+Ch] [bp-1008h]
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  v1 = 644283;
  v2 = 0;
  v4 = 0;
  v5 = 1;
  while ( 1 )
  {
    v6 = *(unsigned __int8 *)++v1;
    if ( v6 == 1 )
      break;
LABEL_3:
    ++v4;
    v2 += 9;
    if ( v4 == 4 )
      return v5;
  }
  v11 = 0;
  v12 = 0;
  v13 = 0;
  pthread_mutex_lock(&stru_790D0);
  dword_7909C = v4;
  v5 = sub_42100(&v11, 0, 9u);
  sub_2A92C();
  pthread_mutex_unlock(&stru_790D0);
  if ( v5 )
  {
    if ( v5 > 0 )
    {
      sub_56CD8((unsigned int *)((char *)&v11 + 1), 2, (int)&unk_69AF8 + 16 * v4);
      v8 = a1 + v2;
      v9 = v12;
      v10 = v13;
      *(_DWORD *)(a1 + v2) = v11;
      *(_DWORD *)(v8 + 4) = v9;
      *(_BYTE *)(v8 + 8) = v10;
    }
    goto LABEL_3;
  }
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "chain%d pic not support flash data storage, adopt file mode\n", v4);
    sub_38730(5, s, 0);
  }
  return v5;
}
