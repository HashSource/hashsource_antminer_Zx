size_t __fastcall sub_3BFB4(int a1, const void *a2, size_t a3)
{
  int v5; // r2
  int v6; // r10
  char v7; // r6
  int v8; // r9
  int v9; // r4
  int v11; // r7
  size_t v12; // r7
  unsigned __int8 *v13; // r2
  int v14; // r12
  int v15; // r0
  int v16; // r1
  int v17; // r3
  size_t v18; // r2
  _DWORD *v19; // r7
  int v20; // r2
  pthread_mutex_t *mutex; // [sp+0h] [bp-21Ch]
  int v22; // [sp+4h] [bp-218h]
  int v23; // [sp+8h] [bp-214h]
  _DWORD s[129]; // [sp+18h] [bp-204h] BYREF

  memset(s, 0, 0x200u);
  mutex = &stru_75CFC[a1];
  pthread_mutex_lock(mutex);
  switch ( a1 )
  {
    case 0:
      v6 = 4096;
      v7 = 24;
      v22 = 1028;
      v23 = 1029;
      goto LABEL_3;
    case 1:
      v6 = 4096;
      v7 = 16;
      v22 = 1030;
      v23 = 1031;
      goto LABEL_3;
    case 2:
      v6 = 4096;
      v7 = 8;
      v22 = 1032;
      v23 = 1033;
      goto LABEL_3;
    case 3:
      v6 = 4096;
      v7 = 0;
      v22 = 1034;
      v23 = 1035;
      goto LABEL_3;
    case 4:
      v6 = 4100;
      v7 = 24;
      v22 = 1036;
      v23 = 1037;
      goto LABEL_3;
    case 5:
      v6 = 4100;
      v7 = 16;
      v22 = 1038;
      v23 = 1039;
      goto LABEL_3;
    case 6:
      v6 = 4100;
      v7 = 8;
      v22 = 1040;
      v23 = 1041;
      goto LABEL_3;
    case 7:
      v6 = 4100;
      v7 = 0;
      v22 = 1042;
      v23 = 1043;
      goto LABEL_3;
    case 8:
      v6 = 4104;
      v7 = 24;
      v22 = 1044;
      v23 = 1045;
      goto LABEL_3;
    case 9:
      v6 = 4104;
      v7 = 16;
      v22 = 1046;
      v23 = 1047;
LABEL_3:
      v8 = 21;
      break;
    default:
      a3 = 0;
      printf("%s: The uart%d is not supported!!!\n", "uart_send", v5);
      return a3;
  }
  while ( 1 )
  {
    v9 = dword_75C50[0];
    if ( a3 <= (unsigned __int8)(*(_DWORD *)(dword_75C50[0] + v6) >> v7) )
      break;
    usleep(0xBB8u);
    if ( !--v8 )
    {
      a3 = 0;
      pthread_mutex_unlock(mutex);
      printf("%s: uart%d always dose not has enough send fifo space, break\n", "uart_send", a1);
      return a3;
    }
  }
  if ( *(int *)(dword_75C50[0] + 4 * v22) < 0 )
  {
    v11 = 21;
    while ( 1 )
    {
      usleep(0xBB8u);
      v9 = dword_75C50[0];
      if ( *(int *)(dword_75C50[0] + 4 * v22) >= 0 )
        break;
      if ( !--v11 )
      {
        a3 = 0;
        pthread_mutex_unlock(mutex);
        printf("%s: uart%d always busy, break\n", "uart_send", a1);
        return a3;
      }
    }
  }
  memcpy(s, a2, a3);
  v12 = a3 >> 2;
  if ( a3 >> 2 )
  {
    v13 = (unsigned __int8 *)s;
    do
    {
      v14 = *v13;
      v15 = v13[3];
      v16 = v13[2];
      v17 = v13[1] << 16;
      v13 += 4;
      *(_DWORD *)(v9 + 4 * v23) = v17 | (v14 << 24) | v15 | (v16 << 8);
      v9 = dword_75C50[0];
    }
    while ( v13 != (unsigned __int8 *)&s[v12] );
  }
  v18 = a3 & 3;
  if ( (a3 & 3) != 0 )
  {
    v19 = &s[v12 + 128];
    if ( v18 == 2 )
    {
      v20 = (*((unsigned __int8 *)v19 - 512) << 24) | (*((unsigned __int8 *)v19 - 511) << 16);
    }
    else if ( v18 == 3 )
    {
      v20 = (*((unsigned __int8 *)v19 - 510) << 8)
          | (*((unsigned __int8 *)v19 - 511) << 16)
          | (*((unsigned __int8 *)v19 - 512) << 24);
    }
    else
    {
      v20 = *((unsigned __int8 *)v19 - 512) << 24;
    }
    *(_DWORD *)(v9 + 4 * v23) = v20;
    v9 = dword_75C50[0];
  }
  *(_DWORD *)(v9 + 4 * v22) = a3 | 0x80000000;
  pthread_mutex_unlock(mutex);
  return a3;
}
