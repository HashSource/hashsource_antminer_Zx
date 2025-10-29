int __fastcall get_statline(char *a1, size_t a2, cgpu_info *cgpu)
{
  double v3; // d0
  double v7; // d8
  uint64_t rolling; // r8
  const char *v9; // r2
  size_t v10; // r0
  const char *v11; // r2
  int v13; // r3
  const char *v14; // r2
  int v15; // [sp+1Ch] [bp-1070h]
  char v16[16]; // [sp+28h] [bp-1064h] BYREF
  char v17[16]; // [sp+38h] [bp-1054h] BYREF
  char s[64]; // [sp+48h] [bp-1044h] BYREF
  char str[4100]; // [sp+88h] [bp-1004h] BYREF

  cgpu_runtime(cgpu);
  v7 = (double)cgpu->diff1 / v3 * 60.0;
  rolling = (unsigned __int64)cgpu->rolling;
  suffix_string((unsigned __int64)(cgpu->total_mhashes / v3), v16, 0x10u, 4);
  suffix_string(rolling, v17, 0x10u, 4);
  LOWORD(v9) = -1948;
  HIWORD(v9) = (unsigned int)"https://" >> 16;
  snprintf(a1, a2, v9, cgpu->drv->name, cgpu->device_id);
  cgpu->drv->get_statline_before(a1, a2, cgpu);
  v10 = strlen(a1);
  LOWORD(v11) = -1940;
  LODWORD(rolling) = v10;
  HIWORD(v11) = (unsigned int)"" >> 16;
  snprintf(
    s,
    0x40u,
    v11,
    opt_log_interval,
    v17,
    v16,
    LODWORD(cgpu->diff_accepted),
    HIDWORD(cgpu->diff_accepted),
    LODWORD(cgpu->diff_rejected),
    HIDWORD(cgpu->diff_rejected),
    cgpu->hw_errors,
    v15,
    v7);
  if ( strlen(s) + (unsigned int)rolling >= a2 )
  {
    LOWORD(v13) = -3136;
    LOWORD(v14) = -1884;
    HIWORD(v13) = (unsigned int)"iner" >> 16;
    HIWORD(v14) = (unsigned int)"sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m" >> 16;
    snprintf(str, 0x1000u, v14, v13, "get_statline", 3081);
    applog(3, str, 1);
    _quit(1, 1);
  }
  strcat(a1, s);
  return ((int (__fastcall *)(char *, size_t, cgpu_info *))cgpu->drv->get_statline)(a1, a2, cgpu);
}
