#! /bin/bash

#
#取出需要访问到网址并解析
#
takeurl(){
hostname1=
filename=
local File_Web
File_Web=${1:?'需要提供储存网址的文件名'}
File_Web=./web/$File_Web
#while read url
#do

if read url < $File_Web;then
url=${url/#'http://'/}
hostname1=${url%%/*}
filename=${url##$hostname1}
if [ -z $filename ];then
filename='/'
fi
fi
#echo $hostname1 $filename
#done < $File_Web
}
