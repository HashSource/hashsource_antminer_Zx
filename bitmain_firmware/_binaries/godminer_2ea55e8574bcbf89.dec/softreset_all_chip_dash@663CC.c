int __fastcall softreset_all_chip_dash(int *a1)
{
  sub_65CB4((int)a1);
  usleep((__useconds_t)&stru_1869C.st_value);
  sub_659A0((int)a1, 8, 0);
  sub_659A0((int)a1, 1, 4);
  sub_65DF4(a1, 255);
  return 0;
}
