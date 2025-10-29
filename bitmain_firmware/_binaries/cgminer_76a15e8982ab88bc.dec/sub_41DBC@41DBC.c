int __fastcall sub_41DBC(int *a1)
{
  pthread_t v2; // r0
  int v3; // r8
  int v4; // r4
  char *v5; // r3
  int v6; // r3
  int v7; // r1
  int v8; // r7
  int v9; // r11
  int v11; // [sp+10h] [bp-10BCh]
  int v12; // [sp+14h] [bp-10B8h]
  int *v13; // [sp+1Ch] [bp-10B0h]
  struct timeval v14; // [sp+24h] [bp-10A8h] BYREF
  struct timeval v15; // [sp+2Ch] [bp-10A0h] BYREF
  _BYTE v16[148]; // [sp+34h] [bp-1098h] BYREF
  char s[4088]; // [sp+C8h] [bp-1004h] BYREF

  v2 = pthread_self();
  pthread_detach(v2);
  v3 = *a1;
  v4 = *((unsigned __int8 *)a1 + 4);
  v13 = *(int **)(v3 + 630);
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "Start To Fill Work!ChainIndex:[%d]", v4);
    sub_385C8(7, s, 0);
  }
  v12 = 0;
  sub_2A7A4(&v14);
  sub_2A7A4(&v15);
LABEL_7:
  while ( 1 )
  {
    v5 = (char *)dword_75C50 + v4;
    if ( *((_BYTE *)&dword_75C50[187] + v4) )
      return 0;
    while ( 1 )
    {
      if ( !v5[732] || byte_75F30 || byte_75C68 )
      {
        sub_2A884();
        goto LABEL_7;
      }
      sub_2A7A4(&v14);
      v6 = v14.tv_usec - v15.tv_usec + (v14.tv_usec - v15.tv_usec < 0 ? 0xF4000 : 0);
      if ( v14.tv_usec - v15.tv_usec < 0 )
        v6 += 576;
      v7 = v14.tv_sec - v15.tv_sec;
      if ( v14.tv_usec - v15.tv_usec < 0 )
        --v7;
      if ( !*((_BYTE *)&dword_75C50[1] + v4) && v6 + 1000000 * v7 < (unsigned int)dword_9A2B8 )
        break;
      sub_2A7A4(&v15);
      while ( 1 )
      {
        pthread_mutex_lock(&stru_75CE0);
        v8 = sub_2472C((int)v13, *v13);
        pthread_mutex_unlock(&stru_75CE0);
        if ( v8 )
          break;
        if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
        {
          snprintf(s, 0x1000u, "Work Error![%d]", v12);
          sub_385C8(3, s, 0);
        }
      }
      v9 = *(_DWORD *)(v8 + 1828) & 0x7F;
      *((_BYTE *)&dword_75C50[1] + v4) = 0;
      memset(v16, 0, 0x92u);
      v12 = (unsigned __int8)v9;
      v16[3] = v9;
      v16[2] = 32;
      memcpy(&v16[4], (const void *)(v8 + 224), 0x8Cu);
      v11 = v3 + 4 * (v9 + 28);
      sub_41CC8(v16, 146);
      pthread_mutex_lock(&stru_75CE0);
      if ( *(_DWORD *)(v11 + 6) )
      {
        sub_156B8(*(void ***)(v11 + 6));
        *(_WORD *)(v11 + 6) = 0;
        *(_WORD *)(v11 + 8) = 0;
      }
      *(_DWORD *)(v3 + 4 * (v9 + 28) + 6) = sub_1A598(v8, 0);
      pthread_mutex_unlock(&stru_75CE0);
      if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        snprintf(s, 0x1000u, "ChainID[%d] Wirte Work. workid=%d", v4, v9);
        sub_385C8(7, s, 0);
      }
      sub_3BFB4(v4, v16, 0x92u);
      byte_75F31 = 1;
      sub_2A7A4((struct timeval *)&dword_75F34);
      sub_2A8AC();
      sub_156B8((void **)v8);
      v5 = (char *)dword_75C50 + v4;
      if ( *((_BYTE *)&dword_75C50[187] + v4) )
        return 0;
    }
    sub_2A8AC();
  }
}
