int __fastcall platform_get_sensor_addr(int a1, int a2)
{
  return *(_DWORD *)(*(_DWORD *)(dword_186A98 + 120 * a1 + 84) + 24 * a2 + 20);
}
