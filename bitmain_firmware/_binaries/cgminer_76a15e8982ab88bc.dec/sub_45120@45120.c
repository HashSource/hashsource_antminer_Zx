void sub_45120()
{
  float v0; // s0
  int v1; // r5
  int v2; // r3
  char v3; // r1
  int v4; // r3
  _BOOL4 v5; // r3
  int v6; // r3
  char v7; // r0
  int v8; // r7
  int v9; // r3
  int v10; // r3
  char v11; // r1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = dword_9A4AA;
  dword_75F68 = dword_9A4AA;
  if ( byte_9A4CB )
  {
    v2 = (unsigned __int8)dword_9A4CC;
    if ( (unsigned __int8)dword_9A4CC <= 0x64u )
    {
      if ( (unsigned __int8)dword_9A4CC < 0x28u )
        v2 = 40;
      if ( byte_75F66 )
      {
        v4 = 6553600;
        v3 = 100;
      }
      else
      {
        v3 = v2;
        v4 = (100 - v2) | (v2 << 16);
      }
      byte_9A49E = v3;
      *(_DWORD *)(dword_75C50[0] + 132) = v4;
      return;
    }
  }
  v5 = dword_9A4AA > 62;
  if ( !dword_9A4AA )
    v5 = 1;
  if ( v5 )
  {
    byte_9A49E = 100;
    *(_DWORD *)(dword_75C50[0] + 132) = 6553600;
    LOBYTE(dword_9A4CC) = 100;
    return;
  }
  if ( dword_9A4AA > 35 )
  {
    if ( (unsigned int)(dword_9A4AA - dword_75F6C + 1) <= 2 )
      return;
    sub_4504C();
    v8 = (int)v0 & ~((int)v0 >> 31);
    LOBYTE(dword_9A4CC) = (int)v0 & ~((int)v0 >> 31);
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(s, 0x1000u, "%s: Set PWM percent : %d", "set_PWM_according_to_temperature", (int)v0 & ~((int)v0 >> 31));
      sub_385C8(7, s, 0);
      v1 = dword_75F68;
    }
    v9 = (unsigned __int8)v8;
    if ( (unsigned __int8)v8 <= 0x27u )
    {
      v9 = 40;
    }
    else if ( (unsigned __int8)v8 > 0x64u )
    {
      goto LABEL_29;
    }
    if ( !byte_75F66 )
    {
      v11 = v9;
      v10 = (100 - v9) | (v9 << 16);
      goto LABEL_30;
    }
LABEL_29:
    v10 = 6553600;
    v11 = 100;
LABEL_30:
    byte_9A49E = v11;
    dword_75F6C = v1;
    *(_DWORD *)(dword_75C50[0] + 132) = v10;
    return;
  }
  v6 = 2621500;
  if ( byte_75F66 )
    v7 = 100;
  else
    v7 = 40;
  if ( byte_75F66 )
    v6 = 6553600;
  byte_9A49E = v7;
  *(_DWORD *)(dword_75C50[0] + 132) = v6;
  LOBYTE(dword_9A4CC) = 40;
}
