unsigned int __fastcall sub_4A438(int a1, int a2, int a3, int a4)
{
  int *v6; // r4
  int v7; // r3
  int v8; // r3
  unsigned int v9; // r5
  char v11[4100]; // [sp+10h] [bp-1004h] BYREF

  LOWORD(v6) = (unsigned __int16)&dword_171448;
  if ( a3 >= a4 )
  {
    HIWORD(v6) = (unsigned int)&dword_171448 >> 16;
    *v6 = 0;
    goto LABEL_10;
  }
  HIWORD(v6) = (unsigned int)&dword_171448 >> 16;
  v7 = *v6;
  if ( *v6 > 120 )
  {
    *v6 = 0;
    goto LABEL_10;
  }
  if ( !v7 )
  {
LABEL_10:
    v9 = 0;
    goto LABEL_11;
  }
  v8 = v7 + 1;
  if ( !a2 )
  {
LABEL_8:
    v9 = 20;
    *v6 = v8;
    goto LABEL_11;
  }
  *v6 = v8;
  v9 = 10 * ((a4 - a3 + 10) / 5u);
  if ( a2 <= 0 && v8 )
  {
    ++v8;
    goto LABEL_8;
  }
LABEL_11:
  V_LOCK();
  logfmt_raw(v11, 0x1000u, 0, "initial_cnt:%d, temp_max:%d, target_temp:%d, voltage_bias:%d", *v6, a3, a4, v9);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
    183,
    "calc_voltage_bias_kas_2380",
    26,
    75,
    20,
    v11);
  return v9;
}
