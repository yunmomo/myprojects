#! /bin/bash



IFS=':'

cat /etc/passwd | {


while read f1 f2 f3 f4 f5 f6 f7
do
echo "帐号： $f1, login shells是: $f7"
done



}
