@echo off
set num=0
:Begin
set /a num+=1
echo The time is :%num%
Data > Data.in
Correct < Data.in > Correct.out
Mine < Data.in > Mine.out
fc Correct.out Mine.out
if not errorlevel 1 goto Begin
pause
