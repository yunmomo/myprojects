#! /bin/bash

getline()
{
locate i=0
while read line
do
let ++i
done < $1
echo "$1  共有$i行"
return $i
}



getline $1
if [ $? -gt 10 ];then
echo "文件大于10行"
fi
echo
echo 'getline执行完毕'
