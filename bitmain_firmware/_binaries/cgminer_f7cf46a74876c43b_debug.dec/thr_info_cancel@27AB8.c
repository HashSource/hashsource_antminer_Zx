void __fastcall thr_info_cancel(thr_info *thr)
{
  pthread_t pth; // r0
  cgsem_t *p_sem; // r0

  if ( thr )
  {
    pth = thr->pth;
    if ( pth )
    {
      pthread_cancel(pth);
      p_sem = &thr->sem;
      thr->pth = 0;
    }
    else
    {
      p_sem = &thr->sem;
    }
    j_sem_destroy(p_sem);
  }
}
