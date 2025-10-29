int __fastcall sub_18274(int a1, int a2)
{
  if ( pthread_mutex_lock(&stru_77B74) )
    sub_B35C("inc_dev_status", 8308);
  dword_786D0 = a1;
  dword_78948 = a2;
  if ( pthread_mutex_unlock(&stru_77B74) )
    sub_B50C("inc_dev_status", 8311);
  return off_72D18();
}
