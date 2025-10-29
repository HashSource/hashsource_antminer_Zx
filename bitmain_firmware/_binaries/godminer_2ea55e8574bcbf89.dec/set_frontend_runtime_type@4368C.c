_DWORD *__fastcall set_frontend_runtime_type(int a1, int a2)
{
  _DWORD *v4; // r4
  char v6[4100]; // [sp+10h] [bp-1004h] BYREF

  switch ( a2 )
  {
    case 0:
    case 1:
      v4 = frontend_runtime_ckb();
      goto LABEL_3;
    case 2:
      v4 = frontend_runtime_kda();
      goto LABEL_3;
    case 3:
      v4 = frontend_runtime_hns();
      goto LABEL_3;
    case 4:
      v4 = frontend_runtime_dcr();
      goto LABEL_3;
    case 5:
      v4 = frontend_runtime_dash();
      goto LABEL_3;
    case 6:
    case 7:
      v4 = frontend_runtime_eth();
      goto LABEL_3;
    case 8:
      v4 = frontend_runtime_ltc();
      goto LABEL_3;
    case 9:
      v4 = frontend_runtime_zec();
      goto LABEL_3;
    case 10:
      v4 = frontend_runtime_rvn();
      goto LABEL_3;
    case 11:
      v4 = frontend_runtime_kas();
LABEL_3:
      if ( v4 )
      {
        v4[18] = a1;
        if ( dword_173E38 )
          free((void *)dword_173E38);
        v4[19] = a2;
        dword_173E38 = (int)v4;
      }
      break;
    default:
      V_LOCK();
      v4 = 0;
      logfmt_raw(v6, 0x1000u, 0, "ALGO %d does not define Frontend_Base", a2);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/frontend/frontend_interface.c",
        161,
        "set_frontend_runtime_type",
        25,
        58,
        100,
        v6);
      break;
  }
  return v4;
}
