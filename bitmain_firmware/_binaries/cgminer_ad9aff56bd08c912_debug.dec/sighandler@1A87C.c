void __fastcall __noreturn sighandler(int sig)
{
  sigaction_0(15, &termhandler, 0);
  sigaction_0(2, &inthandler, 0);
  kill_work();
}
