#!/bin/bash

WORKING_DIRECTORY='/home/guoshiwei/development/test_env/DistributedCron'
PROG_NAME='./bin/DCronAgent'
pid_num=`ps ax|fgrep $PROG_NAME|fgrep -v fgrep|fgrep -v monitor|awk '{print $1}'|wc -l`

start_prog()
{
    cd $WORKING_DIRECTORY
    $PROG_NAME -l log/`basename $PROG_NAME`.log -D
    echo "[`date`] START $PROG_NAME"
}

if [ $pid_num == 0  ];
then
    echo $PROG_NAME existes.
    start_prog
fi
