void display_arguments()
{
  size_t v0; // r0
  char output[4][16]; // [sp+0h] [bp+0h] BYREF

  memset(output, 0, sizeof(output));
  lseek(cgpu.lcd_fd, 0, 0);
  memset(output, 32, sizeof(output));
  v0 = strlen(app_conf->name);
  memcpy(output, app_conf->name, v0);
  sprintf(output[1], "IC:%2d", app_conf->asic_num);
  sprintf(output[2], "FREQ: %d", app_conf->pcba_freq);
  sprintf(output[3], "Voltage: %d", app_conf->pcba_voltage);
  write(cgpu.lcd_fd, output, 0x40u);
}
