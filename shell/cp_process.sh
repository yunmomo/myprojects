#! /bin/bash


shopt -s -o nounset


if [ $# -ne 2 ];then
echo "用法： $0 源文件 目标文件[目标目录]"
echo
exit 1
fi

declare -i p=0;
SRC=$1;
DEST=$2;


Total=$(stat -c %s $SRC)
touch $DEST
p=0


(cp -f $SRC $DEST) &

{
while ((p<100))
do
Size=$(stat -c %s $DEST)
p=Size*100/Total;
echo $p
sleep 1
done
} | dialog --guage "复制进度" 10 50 0

