int get_power_voltage_calibration_data()
{
  bool v0; // cc
  int v1; // r10
  int v2; // r4
  unsigned __int64 v3; // r2
  unsigned int v4; // r11
  int v5; // r4
  _BYTE *v6; // lr
  int v7; // r2
  __int64 v8; // r0
  int v9; // t1
  int v10; // r3
  int v11; // r8
  double v12; // d0
  double v13; // d9
  int v14; // r7
  int v15; // s16
  int v16; // r10
  int v17; // r9
  unsigned int v18; // r1
  double *v19; // r8
  double v20; // d0
  int v22; // [sp+1Ch] [bp-1038h] BYREF
  int v23; // [sp+20h] [bp-1034h]
  int v24; // [sp+24h] [bp-1030h] BYREF
  int v25; // [sp+28h] [bp-102Ch]
  __int16 v26; // [sp+2Ch] [bp-1028h]
  unsigned int v27[3]; // [sp+30h] [bp-1024h] BYREF
  unsigned __int8 v28; // [sp+3Ch] [bp-1018h]
  _BYTE v29[15]; // [sp+3Dh] [bp-1017h] BYREF
  unsigned __int8 v30; // [sp+4Ch] [bp-1008h]
  unsigned __int8 v31; // [sp+4Dh] [bp-1007h]
  unsigned __int8 v32; // [sp+4Eh] [bp-1006h]
  unsigned __int8 v33; // [sp+4Fh] [bp-1005h]
  char v34[4100]; // [sp+50h] [bp-1004h] BYREF

  v0 = (unsigned int)dword_185768 > 0x62;
  if ( dword_185768 != 98 )
    v0 = (unsigned int)(dword_185768 - 100) > 2;
  v1 = !v0;
  if ( v0 )
  {
    bitmain_power_read(64, (int)v27, 32);
    v2 = (unsigned __int16)(v33 + (v32 << 8));
    if ( POWER_CRC16((int)v27, 30) == v2 )
    {
      HIDWORD(v3) = bswap32(v27[0]) & 0x1FFFFFF;
      LODWORD(v3) = bswap32(v27[1]);
      v4 = bswap32(v27[2]);
      v24 = v1;
      v25 = v1;
      v26 = v1;
      v5 = v1;
      v22 = v1;
      v23 = v1;
      sub_B3464((int)&v22, 12, v3);
      sub_B3464((int)&v24 + 3, 7, __PAIR64__(v1, v4));
      V_LOCK();
      logfmt_raw(v34, 0x1000u, v1, "%s SN:%s", "get_power_voltage_calibration_data", &v22);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
        177,
        "get_power_voltage_calibration_data",
        34,
        1070,
        100,
        v34);
      v6 = v29;
      v7 = (unsigned __int16)(v31 + (v30 << 8));
      v8 = 138547333LL * (unsigned __int16)(v31 + (v30 << 8));
      WORD2(v8) = (HIDWORD(v8) + ((unsigned int)(v7 - HIDWORD(v8)) >> 1)) >> 4;
      unk_185778 = v22;
      unk_18577C = v23;
      unk_185780 = v24;
      unk_185784 = v25;
      word_185788 = v26;
      dword_185830 = 100 * (WORD2(v8) % 0xCu)
                   + 100
                   + 10000 * ((unsigned __int16)(v31 + (v30 << 8)) / 0x174u)
                   + (unsigned __int16)(v7 - 31 * WORD2(v8))
                   + 1;
      while ( 1 )
      {
        v9 = (char)*++v6;
        v10 = v5 + 1;
        if ( v9 == -128 )
          break;
        ++v5;
        if ( v10 == 14 )
        {
          v11 = 15;
          dword_18578C = 15;
          v12 = 0.0;
          v13 = 18.2142857;
          v14 = (__int16)(v29[0] + (v28 << 8));
          v15 = v14;
          goto LABEL_16;
        }
      }
      dword_18578C = v5 + 1;
      v11 = v5 + 1;
      if ( (unsigned int)(v5 - 1) > 0xFE )
      {
        V_LOCK();
        logfmt_raw(v34, 0x1000u, 0, "%s power eeprom list get error!", "get_power_voltage_calibration_data");
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
          177,
          "get_power_voltage_calibration_data",
          34,
          1094,
          100,
          v34);
        return -1;
      }
      v13 = 255.0 / (double)v5;
      v14 = (__int16)(v29[0] + (v28 << 8));
      v15 = v14;
      v12 = v13 * 0.0;
      round();
LABEL_16:
      v16 = 1595279;
      v17 = 0;
      while ( 1 )
      {
        ++v17;
        *(_BYTE *)++v16 = (unsigned int)v12;
        if ( v17 == v11 )
          break;
        v12 = (double)v17 * v13;
        round();
      }
      sub_B2910();
      v19 = (double *)&unk_1857E8;
      v20 = (double)v15 / 1000.0 + v12;
      dbl_1857E0 = v20;
      do
      {
        v14 += (char)v29[v18 + 1];
        sub_B2910();
        v20 = (double)v14 / 1000.0 + v20;
        *v19++ = v20;
      }
      while ( v18 < v5 );
      return 0;
    }
    else
    {
      V_LOCK();
      logfmt_raw(v34, 0x1000u, v1, "%s error!", "get_power_voltage_calibration_data");
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
        177,
        "get_power_voltage_calibration_data",
        34,
        1055,
        100,
        v34);
      return -1;
    }
  }
  else
  {
    V_LOCK();
    logfmt_raw(v34, 0x1000u, 0, "%s power protocal not support!", "get_power_voltage_calibration_data");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/device/hal/power/bitmain_power_APW9.c",
      177,
      "get_power_voltage_calibration_data",
      34,
      1034,
      100,
      v34);
    return -1;
  }
}
