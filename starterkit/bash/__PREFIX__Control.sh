#!/bin/sh
echo : shell start !!

curfunc=""
nextfunc=""
tmpfunc=""
a=0

#[SYN-G-GEN OUTPUT START] $/./$
#  psggConverterLib.dll converted from TEST.xlsx. 
    #   S_END
    S_END()
    {
        #   GoNextState
            nextfunc=$tmpfunc
            tmpfunc=""
    }
    #   S_START
    S_START()
    {
        #    SetNextStateIf
            if [ "$tmpfunc" = "" ]; then
                tmpfunc="S_END"
            fi
        #   GoNextState
            nextfunc=$tmpfunc
            tmpfunc=""
    }


#[SYN-G-GEN OUTPUT END]

nextfunc="S_START"

echo : request $nextfunc

i=0
max=1000
while  [ $i -le $max ]; do
    #echo :  w $nextfunc
    echo : running $curfunc
    bFirst=0
    if [ "$nextfunc" != "" ]; then
        curfunc=$nextfunc
        nextfunc=""
        bFirst=1
    fi

    #[SYN-G-GEN OUTPUT START] $/^S/->#callfunc$
#  psggConverterLib.dll converted from TEST.xlsx. 
    if [ "$curfunc" = "S_END" ]; then
        S_END $bFirst
    fi
    if [ "$curfunc" = "S_START" ]; then
        S_START $bFirst
    fi


    #[SYN-G-GEN OUTPUT END]

    if [ "$curfunc" = "S_END" ]; then
        break
    fi
    #echo : loop
    #read a
done

echo : shell end!
