void __cdecl equihash_nonce_submit(uint8_t *nonce, uint8_t *verify, int fixed_nonce_bytes, char *job_id)
{
  int v4; // r2
  char tmp42[1028]; // [sp+18h] [bp+10h] BYREF

  ++total_7653;
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    v4 = golden_nonce_7652++;
    snprintf(tmp42, 0x400u, "Golden Nonce Found! %d\n", v4);
    applog(3, tmp42, 0);
  }
  print_solver_line(nonce, verify, fixed_nonce_bytes, job_id);
  ++total_shares_7654;
  t1_7656 = now();
  if ( status_period_7657 + t0_7655 < t1_7656 )
  {
    t0_7655 = t1_7656;
    printf("status: %lld %lld\n", total_7653, total_shares_7654);
    fflush((FILE *)stdout);
  }
}
