uint32_t __cdecl print_solver_line(uint8_t *soln, uint8_t *header, int fixed_nonce_bytes, char *job_id)
{
  char *v4; // r0
  char *v5; // r0
  char *job_ida; // [sp+8h] [bp+0h]
  int fixed_nonce_bytesa; // [sp+Ch] [bp+4h]
  uint8_t *headera; // [sp+10h] [bp+8h]
  uint8_t *solna; // [sp+14h] [bp+Ch]
  uint8_t buffer[1487]; // [sp+1Ch] [bp+14h] BYREF
  uint8_t *p; // [sp+5ECh] [bp+5E4h]

  solna = soln;
  headera = header;
  fixed_nonce_bytesa = fixed_nonce_bytes;
  job_ida = job_id;
  p = buffer;
  memcpy(buffer, header, 0x8Cu);
  memcpy(&buffer[140], &unk_346C4, 3u);
  p = &buffer[143];
  memcpy(&buffer[143], solna, 0x540u);
  printf("sol: %s ", job_ida);
  p = headera + 100;
  printf("%02x%02x%02x%02x ", headera[100], headera[101], headera[102], headera[103]);
  v4 = s_hexdump(&headera[fixed_nonce_bytesa + 108], 32 - fixed_nonce_bytesa);
  printf("%s ", v4);
  v5 = s_hexdump(&buffer[143], 0x540u);
  printf("%s%s\n", "fd4005", v5);
  fflush((FILE *)stdout);
  return 1;
}
