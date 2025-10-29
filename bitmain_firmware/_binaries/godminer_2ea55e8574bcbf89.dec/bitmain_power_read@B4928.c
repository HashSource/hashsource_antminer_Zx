int __fastcall bitmain_power_read(__int16 a1, int a2, int a3)
{
  int v5; // r0
  int v6; // r4
  int v7; // r3
  int v8; // r6
  unsigned __int8 *v9; // r8
  int v10; // r4
  int v11; // t1
  int v13; // r2
  int v15; // [sp+14h] [bp-1848h]
  int v16; // [sp+1Ch] [bp-1840h] BYREF
  char v17; // [sp+20h] [bp-183Ch]
  char v18; // [sp+21h] [bp-183Bh]
  __int16 v19; // [sp+22h] [bp-183Ah]
  unsigned __int8 v20[52]; // [sp+24h] [bp-1838h] BYREF
  char s[2040]; // [sp+58h] [bp-1804h] BYREF
  char v22[4100]; // [sp+858h] [bp-1004h] BYREF

  memset(v20, 0, 0x32u);
  v17 = a1;
  v19 = a1 + 12 + a3;
  v18 = a3;
  v16 = 101100117;
  if ( dword_185764 )
  {
    v15 = 0;
  }
  else
  {
    v15 = sub_B370C();
    if ( v15 < 0 )
    {
      snprintf(s, 0x800u, "%s: auto exec bitmain_power_open, but open power failed", "bitmain_power_read");
      V_LOCK();
      logfmt_raw(v22, 0x1000u, 0, s);
      V_UNLOCK();
      v13 = 887;
LABEL_12:
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
        177,
        "bitmain_power_read",
        18,
        v13,
        100,
        v22);
      return v15;
    }
  }
  v5 = sub_B2D80((void *)dword_185760, (unsigned __int8 *)&v16, 8u, v20, a3 + 7);
  LOBYTE(v6) = v5;
  if ( v5 )
  {
    v15 = -2147482880;
    strcpy(s, "set DA conversion N failed");
    V_LOCK();
    logfmt_raw(v22, 0x1000u, 0, s);
    V_UNLOCK();
    v13 = 897;
    goto LABEL_12;
  }
  v7 = 0;
  do
  {
    v6 = (unsigned __int8)(v6 + 1);
    snprintf(s, 0x800u, "read_back_data[%d]: %02X", v7, v20[v7]);
    V_LOCK();
    logfmt_raw(v22, 0x1000u, 0, s);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
      177,
      "bitmain_power_read",
      18,
      905,
      100,
      v22);
    v7 = v6;
  }
  while ( v6 <= a3 + 6 );
  if ( a3 )
  {
    v8 = a2 + (unsigned __int8)(a3 - 1);
    v9 = &v20[4];
    v10 = a2 - 1;
    do
    {
      v11 = *++v9;
      *(_BYTE *)++v10 = v11;
      snprintf(s, 0x800u, "buf[%d]: %02X", v10 - a2, v11);
      V_LOCK();
      logfmt_raw(v22, 0x1000u, 0, s);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
        177,
        "bitmain_power_read",
        18,
        910,
        100,
        v22);
    }
    while ( v10 != v8 );
  }
  return v15;
}
