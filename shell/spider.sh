#! /bin/bash

#
#使用两个FIFO文件来储存需要爬取的URL和需要解析的网页，以达到互斥的目的
#

#调用函数库
. get.sh
. take.sh
. webparse.sh




#while :
#do
takeurl url_list
if [ -n $hostname1 -a -n $filename ];then
echo $hostname1 $filename
getweb $hostname1 $filename  >> ./web/web_addr
fi
parse web_addr url_list
sleep 5
#done


