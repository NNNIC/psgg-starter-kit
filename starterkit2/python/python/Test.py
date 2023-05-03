# coding=utf-8

from TestControl import TestControl

sm = TestControl()
sm.Start()

while(sm.IsEnd()==False) :
    sm.Update()

