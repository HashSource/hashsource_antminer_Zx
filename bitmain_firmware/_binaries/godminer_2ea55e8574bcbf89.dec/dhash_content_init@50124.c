_DWORD *__fastcall dhash_content_init(int a1)
{
  _DWORD *result; // r0
  char v3[4096]; // [sp+18h] [bp-1000h] BYREF

  switch ( a1 )
  {
    case 1:
      result = dhash_content_ckb_2042();
      break;
    case 2:
      result = dhash_content_kda_2110();
      break;
    case 3:
      result = dhash_content_hns_2130();
      break;
    case 4:
      result = dhash_content_dcr_1727();
      break;
    case 5:
      result = dhash_content_dash_1766();
      break;
    case 6:
      result = dhash_content_eth_2280();
      break;
    case 7:
      result = dhash_content_eth_2282();
      break;
    case 8:
      result = dhash_content_ltc_1489();
      break;
    case 9:
      result = dhash_content_zec_1746();
      break;
    case 10:
      result = dhash_content_rvn_2020();
      break;
    case 11:
      result = dhash_content_kas_2380();
      break;
    default:
      V_LOCK();
      logfmt_raw(v3, 0x1000u, 0, "ALGO %d does not define dhash_content", a1);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/dhash_content/dhash_content.c",
        161,
        "dhash_content_init",
        18,
        56,
        100,
        v3);
      result = 0;
      break;
  }
  return result;
}
