int __fastcall sub_3AF90(int a1)
{
  int v1; // r6
  char *v2; // r4
  unsigned __int8 *v3; // lr
  unsigned __int8 *v4; // r8
  unsigned int v5; // r7
  int v6; // r9
  int v7; // r3
  char *v8; // r3
  int *v9; // r3
  int v10; // t1
  char *v11; // r3
  _DWORD *v12; // r2
  unsigned int v13; // r0
  unsigned int v14; // t1
  unsigned int v15; // t1
  bool v16; // cc
  int v17; // r0
  __int64 *v19; // r12
  int v20; // lr
  __int64 v21; // r2
  unsigned int v22; // r0
  int v23; // r8
  char *v24; // r10
  char *v25; // r9
  int *v26; // r0
  int *v27; // r0
  int *v28; // r0
  int *v29; // r0
  pthread_mutex_t *mutex; // [sp+18h] [bp-1724h]
  unsigned int v31; // [sp+1Ch] [bp-1720h]
  int v32; // [sp+20h] [bp-171Ch]
  _DWORD *v33; // [sp+34h] [bp-1708h]
  char v35[4]; // [sp+40h] [bp-16FCh] BYREF
  int v36; // [sp+44h] [bp-16F8h]
  struct timeval v37; // [sp+48h] [bp-16F4h] BYREF
  _DWORD v38[8]; // [sp+50h] [bp-16ECh] BYREF
  _BYTE v39[32]; // [sp+70h] [bp-16CCh] BYREF
  char v40[360]; // [sp+90h] [bp-16ACh] BYREF
  _BYTE s[1344]; // [sp+1F8h] [bp-1544h] BYREF
  char v42[4100]; // [sp+738h] [bp-1004h] BYREF

  v33 = *(_DWORD **)(a1 + 36);
  mutex = (pthread_mutex_t *)v33[5];
  memset(s, 0, sizeof(s));
  sub_2A84C(&v37);
  dbl_78E18 = 0.0;
  pthread_mutex_lock(&stru_78E88);
  v1 = dword_7C294;
  pthread_mutex_unlock(&stru_78E88);
  if ( pthread_mutex_lock(mutex) )
  {
    v26 = _errno_location();
    snprintf(
      v42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v26,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      6302);
    sub_38730(3, v42, 1);
    sub_16CA8(1);
  }
  if ( pthread_rwlock_rdlock((pthread_rwlock_t *)&mutex[1]) )
  {
    v29 = _errno_location();
    snprintf(
      v42,
      0x1000u,
      "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v29,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      6302);
    sub_38730(3, v42, 1);
    sub_16CA8(1);
  }
  if ( pthread_mutex_unlock(mutex) )
  {
    v27 = _errno_location();
    snprintf(
      v42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v27,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      6302);
    sub_38730(3, v42, 1);
    sub_16CA8(1);
  }
  if ( v1 )
  {
    v2 = 0;
    while ( 1 )
    {
      --v1;
      pthread_mutex_lock(&stru_78E88);
      v3 = (unsigned __int8 *)&dword_7C28C + 1357 * dword_7C290;
      --dword_7C294;
      v4 = v3 + 1360;
      v5 = v3[1368];
      v6 = v3[1357];
      v32 = v3[1358];
      v31 = v3[1356];
      memcpy(s, v3 + 12, sizeof(s));
      if ( (unsigned int)dword_7C290 > 0x62 )
        v7 = 0;
      else
        v7 = dword_7C290 + 1;
      v36 = *((_DWORD *)v4 + 1);
      dword_7C290 = v7;
      pthread_mutex_unlock(&stru_78E88);
      if ( v5 > 4 )
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
        {
          snprintf(v42, 0x1000u, "Error:scanhash chainid=%u\n", v5);
          sub_38730(5, v42, 0);
        }
        goto LABEL_24;
      }
      pthread_mutex_lock(&stru_78EA0);
      v8 = &mutex[4].__size[4 * v6 + 16];
      v10 = *(_DWORD *)(v8 + 6);
      v9 = (int *)(v8 + 6);
      if ( v10 )
        v2 = (char *)sub_1A44C(*v9, 0);
      pthread_mutex_unlock(&stru_78EA0);
      if ( !v2 )
        break;
      *((_DWORD *)v2 + 90) = v36;
      memcpy(v2 + 367, s, 0x540u);
      sub_4EEE0(v40, 200, 9);
      sub_54F8C((int)v40, v2 + 224, 0x8Cu);
      memset(v39, 0, sizeof(v39));
      memset(v38, 0, sizeof(v38));
      memset(v42, 0, 0x5CFu);
      memcpy(v42, v2 + 224, 0x5CFu);
      sub_55930((int)v42, 1487, v38);
      sub_55930((int)v38, 32, v39);
      v11 = v40;
      v12 = v2 + 192;
      do
      {
        v14 = (unsigned __int8)*--v11;
        v13 = v14;
        v15 = *((unsigned __int8 *)v12 - 1);
        v12 = (_DWORD *)((char *)v12 - 1);
        v16 = v13 > v15;
        if ( v13 < v15 )
          break;
        if ( v16 )
        {
          v17 = sub_4EAF4(v40, (unsigned int)s);
          if ( !v17 )
            goto LABEL_32;
LABEL_18:
          if ( v17 == 2 )
          {
            v24 = (char *)&unk_9D4B4 + 12 * v5 + 4 * (unsigned __int8)(v31 / (unsigned __int8)byte_9D6F3) + 304;
            ++*(_DWORD *)(v24 + 3);
          }
          if ( byte_77144 )
          {
            byte_77144 = 0;
            memset(&unk_9D5A7, 0, 0x10u);
          }
LABEL_22:
          sub_2F934(v2, v35, 1);
          sub_15780((void **)v2);
          v2 = 0;
          goto LABEL_23;
        }
      }
      while ( v11 != v39 );
      v17 = sub_4EAF4(v40, (unsigned int)s);
      if ( v17 )
        goto LABEL_18;
      sub_25E28(a1, (int)v2, 1);
LABEL_32:
      v19 = (__int64 *)((char *)&unk_78E60 + 8 * v5);
      v20 = *((unsigned __int8 *)&unk_9D4B4 + v5 + 8);
      v21 = *v19 + 1;
      ++*(_QWORD *)&dbl_78E18;
      *v19 = v21;
      if ( v20 )
      {
        v22 = v31 / (unsigned __int8)byte_9D6F3;
        v23 = (unsigned __int8)v22;
        if ( (unsigned __int8)v22 <= 2u )
        {
          sub_1A730(a1, (int)v2);
          v25 = (char *)&unk_9D4B4 + 12 * v5 + 4 * v23 + 256;
          ++*(_DWORD *)(v25 + 3);
          goto LABEL_22;
        }
        if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          snprintf(v42, 0x1000u, "Which Nonce Cause Err![%d] %08x", (unsigned __int8)v22, v32);
          sub_38730(7, v42, 0);
        }
        goto LABEL_23;
      }
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
      {
        snprintf(v42, 0x1000u, "ChainID Cause Error! ChainID:[%d]", v5);
LABEL_30:
        sub_38730(3, v42, 0);
      }
LABEL_23:
      if ( !v1 )
        goto LABEL_24;
    }
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 2 )
      goto LABEL_23;
    snprintf(v42, 0x1000u, "%s %d: work %02x not find error", *(const char **)(v33[1] + 8), v33[2], v6);
    goto LABEL_30;
  }
LABEL_24:
  if ( pthread_rwlock_unlock((pthread_rwlock_t *)&mutex[1]) )
  {
    v28 = _errno_location();
    snprintf(
      v42,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v28,
      "driver-btm-zcash.c",
      "bitmain_scanhash",
      6411);
    sub_38730(3, v42, 1);
    sub_16CA8(1);
  }
  off_75ED8();
  *(_QWORD *)&dbl_78E18 = vshld_n_s64(*(__int64 *)&dbl_78E18, 0x10u) - *(_QWORD *)&dbl_78E18;
  return 0;
}
