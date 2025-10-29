void __cdecl write_lcd(unsigned int line, char *buf, unsigned int size)
{
  unsigned int v3; // r3
  size_t sizea; // [sp+4h] [bp+4h]
  unsigned int linea; // [sp+Ch] [bp+Ch]
  char tmp42[1024]; // [sp+14h] [bp+14h] BYREF
  unsigned int Copied; // [sp+414h] [bp+414h]

  linea = line;
  sizea = size;
  Copied = 0;
  if ( buf && cgpu.lcd_fd > 0 )
  {
    if ( line <= 3 && size <= 0x40 )
    {
      lseek(cgpu.lcd_fd, 0, 0);
      memset(lcd_output, 32, sizeof(lcd_output));
      while ( sizea )
      {
        if ( sizea <= 0x10 )
        {
          memcpy(&lcd_output[16 * linea], &buf[Copied], sizea);
          break;
        }
        v3 = linea++;
        memcpy(&lcd_output[16 * v3], &buf[Copied], 0x10u);
        sizea -= 16;
        Copied += 16;
      }
      write(cgpu.lcd_fd, lcd_output, 0x40u);
    }
    else if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "%s: write_lcd's arg is overflow\n", "write_lcd");
      applog(2, tmp42, 0);
    }
  }
}
