#!/bin/bash

a=test_1
b=test_1

test_1=haha

require_def()
{
        for varname in $@
        do
                if [ -z ${!varname} ]; then 
                        echo "Var '$varname' is not definded"
                        return 1
                fi
        done
}

require_def a b test_1 || exit 1
