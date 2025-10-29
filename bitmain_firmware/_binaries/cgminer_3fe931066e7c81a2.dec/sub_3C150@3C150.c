size_t __fastcall sub_3C150(int a1, const void *a2, size_t a3)
{
  int v4; // r10
  char v5; // r7
  int v6; // r9
  int v7; // r4
  int v9; // r9
  size_t v10; // r7
  char *v11; // r3
  int v12; // r8
  int v13; // r0
  int v14; // r1
  int v15; // r2
  size_t v16; // r3
  int v17; // r3
  int v18; // [sp+0h] [bp-122Ch]
  pthread_mutex_t *mutex; // [sp+10h] [bp-121Ch]
  int v21; // [sp+14h] [bp-1218h]
  int v22; // [sp+18h] [bp-1214h]
  char s[512]; // [sp+28h] [bp-1204h] BYREF
  char v25[4056]; // [sp+228h] [bp-1004h] BYREF

  memset(s, 0, sizeof(s));
  mutex = &stru_78EBC[a1];
  pthread_mutex_lock(mutex);
  switch ( a1 )
  {
    case 0:
      v4 = 384;
      v5 = 24;
      v22 = 101;
      v21 = 100;
      goto LABEL_3;
    case 1:
      v4 = 384;
      v5 = 16;
      v22 = 103;
      v21 = 102;
      goto LABEL_3;
    case 2:
      v4 = 384;
      v5 = 8;
      v22 = 105;
      v21 = 104;
      goto LABEL_3;
    case 3:
      v4 = 384;
      v5 = 0;
      v22 = 107;
      v21 = 106;
      goto LABEL_3;
    case 4:
      v4 = 388;
      v5 = 24;
      v22 = 109;
      v21 = 108;
      goto LABEL_3;
    case 5:
      v4 = 388;
      v5 = 16;
      v22 = 111;
      v21 = 110;
      goto LABEL_3;
    case 6:
      v4 = 388;
      v5 = 8;
      v22 = 113;
      v21 = 112;
      goto LABEL_3;
    case 7:
      v4 = 388;
      v5 = 0;
      v22 = 115;
      v21 = 114;
      goto LABEL_3;
    case 8:
      v4 = 392;
      v5 = 24;
      v22 = 117;
      v21 = 116;
      goto LABEL_3;
    case 9:
      v4 = 392;
      v5 = 16;
      v22 = 119;
      v21 = 118;
LABEL_3:
      v6 = 21;
      break;
    default:
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 4 )
        return 0;
      a3 = 0;
      snprintf(v25, 0x1000u, "%s: The uart%d is not supported!!!\n", "uart_send", v18);
      sub_38730(5, v25, 0);
      return a3;
  }
  while ( 1 )
  {
    v7 = dword_78E10[0];
    if ( a3 <= (unsigned __int8)(*(_DWORD *)(dword_78E10[0] + v4) >> v5) )
      break;
    usleep(0xBB8u);
    if ( !--v6 )
    {
      pthread_mutex_unlock(mutex);
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        snprintf(v25, 0x1000u, "%s: uart%d always dose not has enough send fifo space, break\n", "uart_send", a1);
LABEL_10:
        sub_38730(5, v25, 0);
      }
      return 0;
    }
  }
  if ( *(int *)(dword_78E10[0] + 4 * v21) < 0 )
  {
    v9 = 21;
    while ( 1 )
    {
      usleep(0xBB8u);
      v7 = dword_78E10[0];
      if ( *(int *)(dword_78E10[0] + 4 * v21) >= 0 )
        break;
      if ( !--v9 )
      {
        pthread_mutex_unlock(mutex);
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
        {
          snprintf(v25, 0x1000u, "%s: uart%d always busy, break\n", "uart_send", a1);
          goto LABEL_10;
        }
        return 0;
      }
    }
  }
  memcpy(s, a2, a3);
  v10 = a3 >> 2;
  if ( a3 >> 2 )
  {
    v11 = s;
    do
    {
      v12 = (unsigned __int8)*v11;
      v13 = (unsigned __int8)v11[3];
      v14 = (unsigned __int8)v11[2];
      v15 = (unsigned __int8)v11[1] << 16;
      v11 += 4;
      *(_DWORD *)(v7 + 4 * v22) = v15 | (v12 << 24) | v13 | (v14 << 8);
      v7 = dword_78E10[0];
    }
    while ( v11 != &s[4 * v10] );
  }
  v16 = a3 & 3;
  if ( (a3 & 3) != 0 )
  {
    if ( v16 == 2 )
    {
      v17 = ((unsigned __int8)s[4 * v10] << 24) | ((unsigned __int8)s[4 * v10 + 1] << 16);
    }
    else if ( v16 == 3 )
    {
      v17 = ((unsigned __int8)s[4 * v10 + 2] << 8)
          | ((unsigned __int8)s[4 * v10 + 1] << 16)
          | ((unsigned __int8)s[4 * v10] << 24);
    }
    else
    {
      v17 = (unsigned __int8)s[4 * v10] << 24;
    }
    *(_DWORD *)(v7 + 4 * v22) = v17;
    v7 = dword_78E10[0];
  }
  *(_DWORD *)(v7 + 4 * v21) = a3 | 0x80000000;
  pthread_mutex_unlock(mutex);
  return a3;
}
