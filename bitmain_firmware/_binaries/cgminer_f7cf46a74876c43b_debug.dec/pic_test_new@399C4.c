void pic_test_new()
{
  int v0; // r4
  unsigned __int8 version; // [sp+6h] [bp-2Ah] BYREF
  unsigned __int8 voltage; // [sp+7h] [bp-29h] BYREF
  unsigned __int8 temp_offset_send[8]; // [sp+8h] [bp-28h] BYREF
  unsigned __int8 temp_offset_receive[8]; // [sp+10h] [bp-20h] BYREF
  unsigned __int8 hash_id_send[12]; // [sp+18h] [bp-18h] BYREF
  unsigned __int8 hash_id_receive[12]; // [sp+24h] [bp-Ch] BYREF

  *(_DWORD *)temp_offset_send = 387323156;
  version = 0;
  *(_DWORD *)hash_id_send = 218893066;
  *(_DWORD *)&hash_id_send[4] = 286265102;
  *(_DWORD *)&hash_id_send[8] = 353637138;
  voltage = 0;
  memset(hash_id_receive, 0, sizeof(hash_id_receive));
  memset(temp_offset_receive, 0, sizeof(temp_offset_receive));
  *(_DWORD *)&temp_offset_send[4] = 454695192;
  v0 = 0;
  reset_PIC16F1704_pic_new();
  PIC1704_update_pic_app_program_new();
  jump_from_loader_to_app_PIC16F1704_new();
  get_PIC16F1704_software_version_new(&version);
  write_hash_ID_PIC16F1704_new(hash_id_send);
  read_hash_id_PIC16F1704_new(hash_id_receive);
  write_temperature_offset_PIC16F1704_new(temp_offset_send);
  read_temperature_offset_PIC16F1704_new(temp_offset_receive);
  set_PIC16F1704_voltage_new(0x78u);
  get_PIC16F1704_voltage_new(&voltage);
  enable_PIC16F1704_dc_dc_new();
  enable_PIC16F1704_dc_dc_new();
  heart_beat_PIC16F1704_new();
  usleep(0x1E8480u);
  heart_beat_PIC16F1704_new();
  usleep(0x1E8480u);
  heart_beat_PIC16F1704_new();
  usleep(0x1E8480u);
  do
  {
    printf("i = %d\n", v0++);
    usleep(0x1E8480u);
  }
  while ( v0 != 35 );
  heart_beat_PIC16F1704_new();
  usleep(0x1E8480u);
  heart_beat_PIC16F1704_new();
  usleep(0x1E8480u);
  heart_beat_PIC16F1704_new();
  usleep(0x1E8480u);
}
