int __fastcall sub_11C8C(int a1, int a2, int a3)
{
  int v6; // r3
  char v8[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
  {
    snprintf(v8, 0x1000u, "Thread %d being disabled", a2);
    sub_38730(4, v8, 0);
  }
  v6 = (unsigned __int8)byte_78E09;
  *(_QWORD *)(*(_DWORD *)(a1 + 36) + 48) = 0;
  if ( v6 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(v8, "Waiting on sem in miner thread");
    sub_38730(7, v8, 0);
  }
  sub_2F280((sem_t *)(a1 + 16), "cgminer.c", "mt_disable", 8561);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
  {
    snprintf(v8, 0x1000u, "Thread %d being re-enabled", a2);
    sub_38730(4, v8, 0);
  }
  return (*(int (__fastcall **)(int))(a3 + 92))(a1);
}
