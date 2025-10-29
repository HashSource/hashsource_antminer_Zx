int __fastcall sub_1D5F0(int a1, int a2)
{
  pthread_mutex_t *v2; // r6
  __int64 v5; // r2
  size_t v6; // r0
  int v7; // r2
  int v8; // lr
  int v9; // r0
  int v10; // r12
  int v11; // r11
  int v12; // r0
  int v13; // r12
  int v14; // lr
  int v15; // r12
  int v16; // r2
  int v17; // lr
  const char *v19; // r0
  char *v20; // r11
  char s[4100]; // [sp+18h] [bp-1004h] BYREF

  v2 = (pthread_mutex_t *)(a1 + 244);
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 244)) )
    sub_B35C("gen_stratum_work", 7936);
  if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 268)) )
    sub_B3C8("gen_stratum_work", 7936);
  v5 = *(_QWORD *)(a1 + 648);
  *(_QWORD *)(a2 + 1784) = v5;
  *(_QWORD *)(a1 + 648) = v5 + 1;
  *(_DWORD *)(a2 + 1792) = 2;
  if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 268)) )
    sub_B578("gen_stratum_work", 7941);
  if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 268)) )
    sub_B5E4("gen_stratum_work", 7941);
  if ( pthread_mutex_unlock(v2) )
    sub_B50C("gen_stratum_work", 7941);
  memset((void *)(a2 + 224), 0, 0x5CFu);
  memcpy((void *)(a2 + 224), (const void *)(a1 + 1604), 0x80u);
  v6 = strlen(*(const char **)(a1 + 636));
  sub_29788((_BYTE *)(a2 + 332), *(unsigned __int8 **)(a1 + 636), v6 >> 1);
  memcpy((void *)(a2 + 352 - *(_DWORD *)(a2 + 1792)), (const void *)(a2 + 1784), *(_DWORD *)(a2 + 1792));
  sub_163CC((char *)(a2 + 364), 0x540u);
  *(_QWORD *)(a2 + 1800) = *(_QWORD *)(a1 + 712);
  *(_DWORD *)(a2 + 1776) = _strdup(*(const char **)(a1 + 672));
  *(_DWORD *)(a2 + 1808) = _strdup(*(const char **)(a1 + 636));
  *(_DWORD *)(a2 + 1796) = _strdup(*(const char **)(a1 + 692));
  if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 268)) )
    sub_B578("gen_stratum_work", 7962);
  off_72D18();
  if ( byte_75C49 )
  {
    v19 = sub_29688(a2 + 224, 143);
    v20 = (char *)v19;
    if ( byte_75C49 )
    {
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
        goto LABEL_18;
      snprintf(s, 0x1000u, "[THR%d] Generated stratum header %s", *(_DWORD *)(a2 + 1744), v19);
      sub_385C8(7, s, 0);
      if ( byte_75C49 )
      {
        if ( byte_77B70 || byte_75C48 )
        {
LABEL_16:
          snprintf(
            s,
            0x1000u,
            "[THR%d] job_id %s, nonce1 %s, nonce2 %llu, ntime %s",
            *(_DWORD *)(a2 + 1744),
            *(const char **)(a2 + 1776),
            *(const char **)(a2 + 1808),
            *(_QWORD *)(a2 + 1784),
            *(const char **)(a2 + 1796));
          sub_385C8(7, s, 0);
          goto LABEL_17;
        }
LABEL_18:
        if ( dword_73504 <= 6 )
          goto LABEL_17;
        goto LABEL_16;
      }
    }
LABEL_17:
    free(v20);
  }
  v7 = dword_73E98;
  v8 = *(_DWORD *)(a1 + 76);
  v9 = *(_DWORD *)(a1 + 80);
  v10 = *(_DWORD *)(a1 + 84);
  *(_DWORD *)(a2 + 160) = *(_DWORD *)(a1 + 72);
  *(_DWORD *)(a2 + 164) = v8;
  *(_DWORD *)(a2 + 168) = v9;
  *(_DWORD *)(a2 + 172) = v10;
  v11 = *(_DWORD *)(a1 + 88);
  v12 = *(_DWORD *)(a1 + 96);
  v13 = *(_DWORD *)(a1 + 100);
  *(_DWORD *)(a2 + 180) = *(_DWORD *)(a1 + 92);
  v14 = dword_73E98;
  *(_DWORD *)(a2 + 188) = v13;
  v15 = v7 + 1;
  v16 = dword_782F4;
  *(_DWORD *)(a2 + 1828) = v14;
  v17 = dword_740CC;
  *(_DWORD *)(a2 + 184) = v12;
  *(_DWORD *)(a2 + 176) = v11;
  *(_DWORD *)(a2 + 1748) = a1;
  *(_DWORD *)(a2 + 1824) = v17;
  *(_BYTE *)(a2 + 1772) = 1;
  *(_BYTE *)(a2 + 1768) = 0;
  *(_BYTE *)(a2 + 1928) = 83;
  *(_DWORD *)(a2 + 1732) = 60;
  dword_73E98 = v15;
  dword_782F4 = v16 + 1;
  sub_11994(a2);
  return sub_2A7A4((struct timeval *)(a2 + 1752));
}
