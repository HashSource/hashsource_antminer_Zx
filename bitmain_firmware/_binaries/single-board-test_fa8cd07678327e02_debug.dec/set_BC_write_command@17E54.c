void __cdecl set_BC_write_command(unsigned int value)
{
  char tmp42[1027]; // [sp+Ch] [bp+Ch] BYREF
  unsigned __int8 i; // [sp+40Fh] [bp+40Fh]

  i = 0;
  if ( (value & 0x80000000) != 0 )
  {
    while ( (get_BC_write_command() & 0x80000000) != 0 )
    {
      usleep(0x3E8u);
      if ( ++i > 0x64u )
      {
        i = 0;
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          snprintf(tmp42, 0x400u, "%s: timeout\n\n", "set_BC_write_command");
          applog(2, tmp42, 0);
        }
        break;
      }
    }
  }
  write_axi_fpga(0x30u, value);
}
