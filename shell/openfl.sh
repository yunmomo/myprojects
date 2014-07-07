#! /bin/bash



datafile='hello.sh'
exec 3<&0
exec <$datafile
while read
do
echo $REPLY
done
exec 0<&3 3<&-
