void *__fastcall read_status_from_monitor(void *a1, int a2)
{
  memcpy(a1, &dword_1742F8[54 * *(_DWORD *)(a2 + 220) + 320], 0xD8u);
  return a1;
}
