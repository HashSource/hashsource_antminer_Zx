int __cdecl pack_ioctl_pkg(uint8_t *str, uint32_t str_len, uint32_t oper_type, void *param)
{
  int status_cmd; // r3
  char tmp42[1024]; // [sp+18h] [bp+10h] BYREF
  uint8_t *work_str; // [sp+418h] [bp+410h]
  uint8_t *address; // [sp+41Ch] [bp+414h]
  base_type_t *item_0; // [sp+420h] [bp+418h]
  base_type_t *item; // [sp+424h] [bp+41Ch]

  switch ( oper_type )
  {
    case 0u:
      item = (base_type_t *)param;
      status_cmd = makeup_get_status_cmd(str, str_len, *((_BYTE *)param + 1), *(_BYTE *)param, *((_BYTE *)param + 2));
      break;
    case 1u:
      item_0 = (base_type_t *)param;
      status_cmd = makeup_set_config_cmd(
                     str,
                     str_len,
                     *((_BYTE *)param + 1),
                     *(_BYTE *)param,
                     *((_BYTE *)param + 2),
                     *((_DWORD *)param + 1));
      break;
    case 2u:
      work_str = (uint8_t *)param;
      status_cmd = makeup_work_pkg(str, (uint8_t *)param);
      break;
    case 3u:
      address = (uint8_t *)param;
      status_cmd = makeup_set_address_cmd(str, str_len, *(_BYTE *)param);
      break;
    case 4u:
      status_cmd = makeup_chain_inactive_cmd(str, str_len);
      break;
    default:
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        snprintf(tmp42, 0x400u, "unknow ioctl type %d\n", oper_type);
        applog(0, tmp42, 0);
      }
      status_cmd = 0;
      break;
  }
  return status_cmd;
}
