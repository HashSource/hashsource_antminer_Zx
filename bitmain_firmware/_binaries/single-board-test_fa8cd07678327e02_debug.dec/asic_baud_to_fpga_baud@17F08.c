unsigned __int8 __cdecl asic_baud_to_fpga_baud(unsigned __int8 asic_baud)
{
  unsigned __int8 v1; // r3
  char tmp42[1024]; // [sp+10h] [bp+8h] BYREF

  switch ( asic_baud )
  {
    case 0u:
      v1 = 1;
      break;
    case 1u:
      v1 = 3;
      break;
    case 2u:
      v1 = 5;
      break;
    case 6u:
      v1 = 13;
      break;
    case 0x1Au:
      v1 = 53;
      break;
    default:
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "%s: Don't support ASIC baud = %d, error!!!\n", "asic_baud_to_fpga_baud", asic_baud);
        applog(2, tmp42, 0);
      }
      v1 = 53;
      break;
  }
  return v1;
}
