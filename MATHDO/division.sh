#!/bin/bash
a="$1"
b="$2"
div=`echo "$a / $b" | bc`
echo "bash: $1/$2=$div"