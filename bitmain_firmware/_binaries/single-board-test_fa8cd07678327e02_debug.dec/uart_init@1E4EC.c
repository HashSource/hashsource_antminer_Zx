int __cdecl uart_init(int comport, int baud)
{
  char tmp42[1024]; // [sp+10h] [bp+8h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "%s chain=%d baudrate=%d\n", "uart_init", comport, baud);
    applog(2, tmp42, 0);
  }
  return gChain;
}
