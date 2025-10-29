int __fastcall sub_3AD9C(int a1)
{
  int v1; // r7
  char *v2; // r4
  unsigned __int8 *v3; // r3
  unsigned __int8 *v4; // r10
  unsigned int v5; // r6
  int v6; // r8
  char *v7; // r3
  int *v8; // r3
  int v9; // t1
  char *v10; // r3
  _DWORD *v11; // r2
  unsigned int v12; // r0
  unsigned int v13; // t1
  unsigned int v14; // t1
  bool v15; // cc
  int v16; // r0
  int v17; // r3
  unsigned int v19; // r0
  unsigned int v20; // r12
  char *v21; // r8
  char *v22; // r2
  int *v23; // r0
  int *v24; // r0
  int *v25; // r0
  int *v26; // r0
  int v27; // [sp+14h] [bp-1738h]
  unsigned int v28; // [sp+18h] [bp-1734h]
  pthread_mutex_t *mutex; // [sp+1Ch] [bp-1730h]
  int v30; // [sp+20h] [bp-172Ch]
  _DWORD *v31; // [sp+34h] [bp-1718h]
  char v33[4]; // [sp+44h] [bp-1708h] BYREF
  int v34; // [sp+48h] [bp-1704h]
  struct timeval v35; // [sp+4Ch] [bp-1700h] BYREF
  int v36[3]; // [sp+54h] [bp-16F8h] BYREF
  _DWORD v37[8]; // [sp+60h] [bp-16ECh] BYREF
  _BYTE v38[32]; // [sp+80h] [bp-16CCh] BYREF
  char v39[360]; // [sp+A0h] [bp-16ACh] BYREF
  _BYTE s[1344]; // [sp+208h] [bp-1544h] BYREF
  char v41[4088]; // [sp+748h] [bp-1004h] BYREF

  v31 = *(_DWORD **)(a1 + 36);
  mutex = (pthread_mutex_t *)v31[5];
  memset(s, 0, sizeof(s));
  sub_2A7A4(&v35);
  dbl_75C58 = 0.0;
  pthread_mutex_lock(&stru_75CC8);
  v1 = dword_79088;
  pthread_mutex_unlock(&stru_75CC8);
  if ( pthread_mutex_lock(mutex) )
  {
    v23 = _errno_location();
    snprintf(
      v41,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v23,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      5806);
    sub_385C8(3, v41, 1);
    sub_16BE0(1);
  }
  if ( pthread_rwlock_rdlock((pthread_rwlock_t *)&mutex[1]) )
  {
    v26 = _errno_location();
    snprintf(
      v41,
      0x1000u,
      "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v26,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      5806);
    sub_385C8(3, v41, 1);
    sub_16BE0(1);
  }
  if ( pthread_mutex_unlock(mutex) )
  {
    v25 = _errno_location();
    snprintf(
      v41,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v25,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      5806);
    sub_385C8(3, v41, 1);
    sub_16BE0(1);
  }
  if ( !v1 )
    goto LABEL_28;
  v2 = 0;
  do
  {
    --v1;
    pthread_mutex_lock(&stru_75CC8);
    v3 = (unsigned __int8 *)&dword_79080 + 1357 * dword_79084;
    --dword_79088;
    v4 = v3 + 1360;
    v5 = v3[1368];
    v6 = v3[1357];
    v30 = v3[1358];
    v28 = v3[1356];
    memcpy(s, v3 + 12, sizeof(s));
    v34 = *((_DWORD *)v4 + 1);
    pthread_mutex_unlock(&stru_75CC8);
    if ( v5 > 4 && (byte_77B70 || byte_75C48 || dword_73504 > 4) )
    {
      snprintf(v41, 0x1000u, "Error:scanhash chainid=%u\n", v5);
      sub_385C8(5, v41, 0);
    }
    pthread_mutex_lock(&stru_75CE0);
    v7 = &mutex[4].__size[4 * v6 + 16];
    v9 = *(_DWORD *)(v7 + 6);
    v8 = (int *)(v7 + 6);
    if ( v9 )
      v2 = (char *)sub_1A598(*v8, 0);
    pthread_mutex_unlock(&stru_75CE0);
    if ( !v2 )
    {
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
        goto LABEL_24;
      snprintf(v41, 0x1000u, "%s %d: work %02x not find error", *(const char **)(v31[1] + 8), v31[2], v6);
LABEL_34:
      sub_385C8(3, v41, 0);
      goto LABEL_24;
    }
    *((_DWORD *)v2 + 85) = v34;
    memcpy(v2 + 367, s, 0x540u);
    v36[0] = 200;
    v36[2] = (int)v39;
    v36[1] = 9;
    sub_4D714(v39, 200, 9);
    sub_537BC((int)v39, v2 + 224, 0x8Cu);
    memset(v38, 0, sizeof(v38));
    memset(v37, 0, sizeof(v37));
    memset(v41, 0, 0x5CFu);
    memcpy(v41, v2 + 224, 0x5CFu);
    sub_54160((int)v41, 1487, v37);
    sub_54160((int)v37, 32, v38);
    v10 = v39;
    v11 = v2 + 192;
    while ( 1 )
    {
      v13 = (unsigned __int8)*--v10;
      v12 = v13;
      v14 = *((unsigned __int8 *)v11 - 1);
      v11 = (_DWORD *)((char *)v11 - 1);
      v15 = v12 > v14;
      if ( v12 < v14 )
      {
LABEL_18:
        v16 = sub_4CEC0(v36, (unsigned int)s);
        if ( !v16 )
        {
          sub_25D80(a1, (int)v2, 1);
          goto LABEL_36;
        }
LABEL_19:
        if ( v16 == 2 )
        {
          v21 = (char *)&unk_9A2A8 + 12 * v5 + 4 * (unsigned __int8)(v28 / (unsigned __int8)byte_9A4C7) + 272;
          ++*(_DWORD *)(v21 + 3);
          ++*(_DWORD *)((char *)&unk_9A2A8 + 4 * v5 + 211);
        }
        if ( byte_73F7C )
        {
          byte_73F7C = 0;
          memset(&unk_9A37B, 0, 0x10u);
        }
LABEL_23:
        sub_2F7A4(v2, v33, 1);
        sub_156B8((void **)v2);
        v2 = 0;
        goto LABEL_24;
      }
      if ( v15 )
        break;
      if ( v10 == v38 )
        goto LABEL_18;
    }
    v16 = sub_4CEC0(v36, (unsigned int)s);
    if ( v16 )
      goto LABEL_19;
LABEL_36:
    ++*(_QWORD *)&dbl_75C58;
    ++qword_75CA0[v5];
    v19 = v28 / (unsigned __int8)byte_9A4C7;
    v20 = (unsigned __int8)v19;
    if ( !byte_75C49 || !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
    {
      if ( v5 <= 4 )
        goto LABEL_41;
      goto LABEL_49;
    }
    v27 = (unsigned __int8)v19;
    snprintf(v41, 0x1000u, "%s: chain %d which_asic_nonce %d ", "bitmain_scanhash", v5, (unsigned __int8)v19);
    sub_385C8(7, v41, 0);
    v20 = v27;
    if ( v5 > 4 )
      goto LABEL_49;
LABEL_41:
    if ( !*((_BYTE *)&unk_9A2A8 + v5 + 8) )
    {
LABEL_49:
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
        goto LABEL_24;
      snprintf(v41, 0x1000u, "ChainID Cause Error! ChainID:[%d]", v5);
      goto LABEL_34;
    }
    if ( v20 <= 2 )
    {
      v22 = (char *)&unk_9A2A8 + 12 * v5 + 4 * v20 + 224;
      ++*(_DWORD *)(v22 + 3);
      goto LABEL_23;
    }
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(v41, 0x1000u, "Which Nonce Cause Err![%d] %08x", v20, v30);
      sub_385C8(7, v41, 0);
    }
LABEL_24:
    pthread_mutex_lock(&stru_75CC8);
    if ( (unsigned int)dword_79084 > 0x62 )
      v17 = 0;
    else
      v17 = dword_79084 + 1;
    dword_79084 = v17;
    pthread_mutex_unlock(&stru_75CC8);
  }
  while ( v1 );
LABEL_28:
  if ( pthread_rwlock_unlock((pthread_rwlock_t *)&mutex[1]) )
  {
    v24 = _errno_location();
    snprintf(
      v41,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v24,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      5906);
    sub_385C8(3, v41, 1);
    sub_16BE0(1);
  }
  off_72D18();
  *(_QWORD *)&dbl_75C58 = vshld_n_s64(*(__int64 *)&dbl_75C58, 0xDu) - *(_QWORD *)&dbl_75C58;
  return 0;
}
