void __cdecl fan_control(unsigned __int8 level)
{
  switch ( level )
  {
    case 0u:
      set_fan_speed(0x64u);
      break;
    case 1u:
      set_fan_speed(0xA005Au);
      break;
    case 2u:
      set_fan_speed(0x140050u);
      break;
    case 3u:
      set_fan_speed(0x1E0046u);
      break;
    case 4u:
      set_fan_speed(0x28003Cu);
      break;
    case 5u:
      set_fan_speed(0x320032u);
      break;
    case 6u:
      set_fan_speed(0x3C0028u);
      break;
    case 7u:
      set_fan_speed(0x46001Eu);
      break;
    case 8u:
      set_fan_speed(0x500014u);
      break;
    case 9u:
      set_fan_speed(0x5A000Au);
      break;
    default:
      set_fan_speed(0x640000u);
      break;
  }
}
