int __fastcall sub_42B54(unsigned __int8 *a1)
{
  pthread_t v2; // r0
  int v3; // r8
  int v4; // r5
  int v5; // r10
  char *v6; // r3
  int v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r7
  int v11; // r11
  int v13; // [sp+Ch] [bp-10B8h]
  int *v14; // [sp+14h] [bp-10B0h]
  struct timeval v15; // [sp+1Ch] [bp-10A8h] BYREF
  struct timeval v16; // [sp+24h] [bp-10A0h] BYREF
  _BYTE v17[148]; // [sp+2Ch] [bp-1098h] BYREF
  char s[4096]; // [sp+C0h] [bp-1004h] BYREF

  v2 = pthread_self();
  pthread_detach(v2);
  v3 = *(_DWORD *)a1;
  v4 = a1[4];
  v14 = *(int **)(*(_DWORD *)a1 + 630);
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "Start To Fill Work!ChainIndex:[%d]", v4);
    sub_38730(7, s, 0);
  }
  sub_2A84C(&v15);
  v5 = 0;
  sub_2A84C(&v16);
LABEL_7:
  while ( 1 )
  {
    v6 = (char *)dword_78E10 + v4;
    if ( *((_BYTE *)&dword_78E10[187] + v4) )
      return 0;
    while ( 1 )
    {
      if ( !v6[732] || byte_790F0 || byte_78E28 )
      {
        sub_2A92C();
        goto LABEL_7;
      }
      sub_2A84C(&v15);
      v7 = v15.tv_usec - v16.tv_usec + (v15.tv_usec - v16.tv_usec < 0 ? 0xF4000 : 0);
      if ( v15.tv_usec - v16.tv_usec < 0 )
        v7 += 576;
      v8 = v15.tv_sec - v16.tv_sec;
      if ( v15.tv_usec - v16.tv_usec < 0 )
        --v8;
      if ( !*((_BYTE *)&dword_78E10[1] + v4) && v7 + 1000000 * v8 < (unsigned int)dword_9D4C4 )
        break;
      sub_2A84C(&v16);
      while ( 1 )
      {
        v9 = sub_247D4((int)v14, *v14);
        if ( v9 )
          break;
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
        {
          snprintf(s, 0x1000u, "Work Error![%d]", v5);
          sub_38730(3, s, 0);
        }
      }
      v10 = v9;
      v11 = *(_DWORD *)(v9 + 1828) & 0x7F;
      *((_BYTE *)&dword_78E10[1] + v4) = 0;
      v5 = (unsigned __int8)v11;
      memset(v17, 0, 0x92u);
      v17[2] = 32;
      v17[3] = v11;
      memcpy(&v17[4], (const void *)(v10 + 224), 0x8Cu);
      v13 = v3 + 4 * (v11 + 28);
      sub_42A60(v17, 146);
      pthread_mutex_lock(&stru_78EA0);
      if ( *(_DWORD *)(v13 + 6) )
      {
        sub_15780(*(void ***)(v13 + 6));
        *(_WORD *)(v13 + 6) = 0;
        *(_WORD *)(v13 + 8) = 0;
      }
      *(_DWORD *)(v3 + 4 * (v11 + 28) + 6) = sub_1A44C(v10, 0);
      pthread_mutex_unlock(&stru_78EA0);
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        snprintf(s, 0x1000u, "ChainID[%d] Wirte Work. workid=%d, jobid=%s", v4, v11, *(const char **)(v10 + 1776));
        sub_38730(7, s, 0);
      }
      sub_3C150(v4, v17, 0x92u);
      byte_790F1 = 1;
      sub_2A84C((struct timeval *)&dword_790F4);
      sub_2A954();
      sub_15780((void **)v10);
      v6 = (char *)dword_78E10 + v4;
      if ( *((_BYTE *)&dword_78E10[187] + v4) )
        return 0;
    }
    sub_2A954();
  }
}
