int __fastcall get_statline(char *a1, size_t a2, cgpu_info *cgpu)
{
  double v3; // d0
  double v7; // d8
  uint64_t rolling; // r8
  char v10[16]; // [sp+28h] [bp-1064h] BYREF
  char v11[16]; // [sp+38h] [bp-1054h] BYREF
  char s[64]; // [sp+48h] [bp-1044h] BYREF
  char str[4100]; // [sp+88h] [bp-1004h] BYREF

  cgpu_runtime(cgpu);
  v7 = (double)cgpu->diff1 / v3 * 60.0;
  rolling = (unsigned __int64)cgpu->rolling;
  suffix_string((unsigned __int64)(cgpu->total_mhashes / v3), v10, 0x10u, 4);
  suffix_string(rolling, v11, 0x10u, 4);
  snprintf(a1, a2, "%s%d ", cgpu->drv->name, cgpu->device_id);
  cgpu->drv->get_statline_before(a1, a2, cgpu);
  LODWORD(rolling) = strlen(a1);
  snprintf(
    s,
    0x40u,
    "(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",
    opt_log_interval,
    v11,
    v10,
    cgpu->diff_accepted,
    cgpu->diff_rejected,
    cgpu->hw_errors,
    v7);
  if ( strlen(s) + (unsigned int)rolling >= a2 )
  {
    snprintf(str, 0x1000u, "tailsprintf buffer overflow in %s %s line %d", "cgminer.c", "get_statline", 3081);
    applog(3, str, 1);
    _quit(1, 1);
  }
  strcat(a1, s);
  return ((int (__fastcall *)(char *, size_t, cgpu_info *))cgpu->drv->get_statline)(a1, a2, cgpu);
}
