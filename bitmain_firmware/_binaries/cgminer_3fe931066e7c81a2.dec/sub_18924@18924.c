int __fastcall sub_18924(int a1, int a2)
{
  if ( pthread_mutex_lock(&stru_7AD4C) )
    sub_B414("inc_dev_status", 8321);
  dword_7B8A8 = a1;
  dword_7BB20 = a2;
  if ( pthread_mutex_unlock(&stru_7AD4C) )
    sub_B5C4("inc_dev_status", 8324);
  return off_75ED8();
}
