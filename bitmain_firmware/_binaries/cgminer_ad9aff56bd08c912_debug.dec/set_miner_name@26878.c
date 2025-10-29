void __fastcall set_miner_name(char *name)
{
  const char *v1; // r1
  const char *v3; // r0
  FILE *v4; // r4
  const char *v5; // r2
  const char *v6; // r1
  const char *v7; // r0
  FILE *v8; // r4
  const char *v9; // r1
  char rbuf1[128]; // [sp+0h] [bp-1084h] BYREF
  char tmp42[4100]; // [sp+80h] [bp-1004h] BYREF

  LOWORD(v1) = -23732;
  LOWORD(v3) = 5784;
  HIWORD(v1) = (unsigned int)"d has %d ASIC" >> 16;
  HIWORD(v3) = (unsigned int)"freq %d, [%d, %d], invalid nonce %d, ox status %d\n" >> 16;
  v4 = fopen(v3, v1);
  memset(rbuf1, 0, sizeof(rbuf1));
  fgets(rbuf1, 128, v4);
  fclose(v4);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v5) = 5808;
    HIWORD(v5) = (unsigned int)"id nonce %d, ox status %d\n" >> 16;
    snprintf(tmp42, 0x1000u, v5, rbuf1);
    applog(5, tmp42, 0);
  }
  LOWORD(v6) = 5820;
  LOWORD(v7) = 5784;
  HIWORD(v6) = (unsigned int)"f" >> 16;
  HIWORD(v7) = (unsigned int)"freq %d, [%d, %d], invalid nonce %d, ox status %d\n" >> 16;
  v8 = fopen(v7, v6);
  fputs(rbuf1, v8);
  LOWORD(v9) = 5824;
  HIWORD(v9) = (unsigned int)" ox status %d\n" >> 16;
  fprintf(v8, v9, name);
  fclose(v8);
}
