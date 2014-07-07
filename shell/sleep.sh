#! /bin/bash

echo -n Count:
#记录当前光标位置
tput sc


count=0
while true
do
if [ $count -lt 40 ];then
let count++
sleep 1
#回复光标位置
tput rc
#清除从当前光标到行尾之间到所有内容
tput ed
echo -n $count
else
echo
exit 0
fi
done

