bool __fastcall io_add(io_data *io_data, char *buf)
{
  size_t v4; // r7
  char *ptr; // r0
  char *cur; // r2
  int v7; // r8
  size_t v8; // r3
  size_t v9; // r5
  char *v10; // r0

  v4 = strlen(buf);
  cur = io_data->cur;
  ptr = io_data->ptr;
  v7 = cur - ptr;
  v8 = cur - ptr + 12 + v4;
  if ( io_data->siz < v8 )
  {
    v9 = io_data->siz + 0x20000;
    if ( v8 > v9 )
      v9 = ((unsigned int)vcvts_n_f32_u32(v8, 0x10u) + 2) << 16;
    v10 = (char *)realloc(ptr, v9);
    cur = &v10[v7];
    io_data->siz = v9;
    io_data->ptr = v10;
    io_data->cur = &v10[v7];
  }
  memcpy(cur, buf, v4 + 1);
  io_data->cur += v4;
  return 1;
}
