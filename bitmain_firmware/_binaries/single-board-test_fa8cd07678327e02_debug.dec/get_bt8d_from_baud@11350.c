uint8_t __cdecl get_bt8d_from_baud(const uint32_t baud)
{
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  size_t max; // [sp+408h] [bp+408h]
  size_t index; // [sp+40Ch] [bp+40Ch]

  max = 5;
  for ( index = 0; ; ++index )
  {
    if ( index >= max )
    {
      if ( index != max )
        return -1;
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        strcpy(tmp42, "get bt8d value failed!!!,use default to continue\n");
        applog(3, tmp42, 0);
      }
      return get_bt8d_from_baud(0x1C200u);
    }
    if ( baud_BT8D_values[index].baud == baud )
      break;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(tmp42, 0x400u, "get bt8d %d\n", baud_BT8D_values[index].bt8d);
    applog(3, tmp42, 0);
  }
  return baud_BT8D_values[index].bt8d;
}
