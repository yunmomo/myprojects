</head>
<body>
<div id="top" class="box">
	<div class="logo">
		<img src="images/logo.jpg" />	
	</div>
	<div class="search">
    <form action="index.php?c=list" method="get" id="topSearch">
        <input name="searchkey" type="text" /> 
		<input name="c" type="hidden" value="list" /> 
		<img src="images/search.gif" style="cursor: pointer;" width="63" height="25" onclick="$('#topSearch').submit()" />
    </form>
	</div>
    
    <div class="topLink">
        <ul>
            <li><a href="/admin.php">管理入口</a> |</li>
            <li><a href="http://www.uestc.edu.cn/" target="_blank">学校主页</a></li>
        </ul>
    </div>
	<div class="clear"></div>
</div>

<div id="menu" class="box">
    <ul>
        <li><a href="index.php?c=index">首 页</a></li>
        <li class="pop"><a href="index.php?c=about">机构设置</a>
        	<ul>
                            <li><a href="index.php?c=about&id=17">部门职责</a></li>
                            <li><a href="index.php?c=about&id=18">领导职责</a></li>
                            <li><a href="index.php?c=about&id=19">机构设置</a></li>
                        </ul>
        </li>
                <li class="pop"><a href="index.php?c=list&cid=58">服务指南</a>
        <ul>
<li><a href="index.php?c=list&cid=59">国防科研处</a></li>
<li><a href="index.php?c=list&cid=60">高新技术处</a></li>
<li><a href="index.php?c=list&cid=61">基础研究与国际合作处</a></li>
<li><a href="index.php?c=list&cid=62">社会科学处</a></li>
<li><a href="index.php?c=list&cid=63">综合计划与成果处</a></li>
</ul>
        </li>
                <li class="pop"><a href="index.php?c=list&cid=45">科研平台</a>
        <ul>
<li><a href="index.php?c=list&cid=48">国家级重点实验室</a></li>
<li><a href="index.php?c=list&cid=99">国家工程技术研究中心</a></li>
<li><a href="index.php?c=list&cid=49">省部级重点实验室</a></li>
<li><a href="index.php?c=list&cid=85">省部级工程中心</a></li>
<li><a href="index.php?c=list&cid=47">科学技术研究院</a></li>
</ul>
        </li>
                <li class="pop"><a href="index.php?c=list&cid=57">科研政策</a>
        <ul>
<li><a href="index.php?c=list&cid=73">科技项目管理办法</a></li>
<li><a href="index.php?c=list&cid=74">科研平台管理办法</a></li>
<li><a href="index.php?c=list&cid=75">科技奖励管理办法</a></li>
<li><a href="index.php?c=list&cid=76">知识产权管理办法</a></li>
<li><a href="index.php?c=list&cid=77">本校科技管理办法</a></li>
<li><a href="index.php?c=list&cid=78">科技成果管理办法</a></li>
</ul>
        </li>
                <li class="pop"><a href="index.php?c=list&cid=64">成果奖励</a>
        <ul>
<li><a href="index.php?c=list&cid=82">技术成果</a></li>
<li><a href="index.php?c=list&cid=98">成果公报</a></li>
</ul>
        </li>
                <li class="pop"><a href="index.php?c=list&cid=65">知识产权</a>
                </li>
                <li class="pop"><a href="index.php?c=list&cid=71">科技合作</a>
        <ul>
<li><a href="index.php?c=list&cid=83">产学研合作</a></li>
<li><a href="index.php?c=list&cid=84">技术需求及指南发布</a></li>
</ul>
        </li>
                <li class="pop"><a href="index.php?c=list&cid=51">资料下载</a>
        <ul>
<li><a href="index.php?c=list&cid=53">横向项目</a></li>
<li><a href="index.php?c=list&cid=54">科研平台</a></li>
<li><a href="index.php?c=list&cid=55">科技成果</a></li>
<li><a href="index.php?c=list&cid=56">国际科技合作</a></li>
</ul>
        </li>
                <li><a href="index.php?c=feedback">在线咨询</a></li>
    </ul>
</div>

<script type="text/javascript">
/* <![CDATA[ */
$('#menu .pop').each(function(){
    var offset = $(this).offset();
    $('ul', this).css({'top' : offset.top + 20, 'left' : offset.left - 8});
    $('li', this).hover(function(){
        $(this).addClass("msel");
    }, function(){
        $(this).removeClass("msel");
    });
    
    $(this).hover(function(){
        $('ul', this).show();
        $(this).addClass("mon");
    }, function(){
        $('ul', this).hide();
        $(this).removeClass("mon");
    });
});
/* ]]> */
</script>

<div id="banner" class="box">
    <a href="#none"><img src="uploads/1310222008058.jpg" id="2" width="1069" height="200"></a></div>

<!--area-->
<div class="box cl">
<div id="area">
    <div class="left">
    <div class="blk01" style="margin:0;">
        <div class="ttl">
            <h4>科研平台</h4>
            <div class="clear"></div>
        </div>
        <div class="nav" id="tree">
            <ul>
                        <li><a href='index.php?c=list&cid=48' class='cid48'>国家级重点实验室</a></li>
            <li><a href='index.php?c=list&cid=99' class='cid99'>国家工程技术研究中心</a></li>
            <li><a href='index.php?c=list&cid=49' class='cid49'>省部级重点实验室</a></li>
            <li><a href='index.php?c=list&cid=85' class='cid85'>省部级工程中心</a></li>
            <li><a href='index.php?c=list&cid=47' class='cid47'>科学技术研究院</a></li>
            </ul>
        </div>
        <script>
        $('#tree li ul').hide();
        $('#tree li ul').parent().append('<span class="catMore">>>></span>');
        $('#tree .catMore').parent().find('a').eq(0).click(function(){
            //if($(this).parent().find('ul').css('display') == 'none'){
//                $(this).parent().find('ul').show();
//            }else{
//                $(this).parent().find('ul').hide();
//            }
//            return false;
        })
        $('.cid45').addClass('sel');
        $('.cid45').parents().show();
        $('ul', $('.cid45').parent()).show();
        </script>
    </div>
</div>

<div class="right">
    <div class="blk_cnt" style="margin:0;">
    	<div class="ttl">
			<h4>
                <a href="index.php">首页</a> >
                <a href="index.php?c=list&cid=45" class="last">科研平台</a> >             </h4>
			<h5></h5>
			<div class="clear"></div>
		</div>
		
        <div class="cnt list">
            <div class="blk04">
            
                            <ul>
                   
                    <li><span class="time">2013-10-16</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=99">国家工程技术研究中心</a>] 
                    <a href="index.php?c=show&id=713">国家电磁辐射控制材料工程技术研究中心简介</a></li>
                   
                    <li><span class="time">2013-05-30</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=48">国家级重点实验室</a>] 
                    <a href="index.php?c=show&id=9">国家工程研究中心管理办法</a></li>
                   
                    <li><span class="time">2010-12-17</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=47">科学技术研究院</a>] 
                    <a href="index.php?c=show&id=301">东莞电子科技大学电子信息工程研究院</a></li>
                   
                    <li><span class="time">2010-10-12</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=49">省部级重点实验室</a>] 
                    <a href="index.php?c=show&id=285">综合电子系统技术教育部重点实验室(B类)</a></li>
                   
                    <li><span class="time">2010-10-12</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=49">省部级重点实验室</a>] 
                    <a href="index.php?c=show&id=286">神经信息教育部重点实验室</a></li>
                   
                    <li><span class="time">2010-10-12</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=49">省部级重点实验室</a>] 
                    <a href="index.php?c=show&id=287">光纤传感与通信教育部重点试验室</a></li>
                   
                    <li><span class="time">2010-10-12</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=49">省部级重点实验室</a>] 
                    <a href="index.php?c=show&id=288">光电探测与传感集成技术教育部重点实验室(B类)</a></li>
                   
                    <li><span class="time">2010-10-12</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=49">省部级重点实验室</a>] 
                    <a href="index.php?c=show&id=289">多频谱吸波材料与结构教育部重点实验室（B类）</a></li>
                   
                    <li><span class="time">2010-10-12</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=49">省部级重点实验室</a>] 
                    <a href="index.php?c=show&id=290">电力系统广域测量与控制四川省重点实验室</a></li>
                   
                    <li><span class="time">2010-10-12</span>
                    ·                     [<a class="cat" href="index.php?c=list&cid=49">省部级重点实验室</a>] 
                    <a href="index.php?c=show&id=291">显示科学与技术四川省重点实验室</a></li>
                                </ul>
                        <div class="next" style="text-align: center; margin-top:10px">
                 <span class="red"><strong>1</strong></span>
 <a href="/index.php?c=list&cid=45 http/1.0&page=2">2</a> 
 <a href="/index.php?c=list&cid=45 http/1.0&page=3">3</a> 
&nbsp;<a href="/index.php?c=list&cid=45 http/1.0&page=2">下一页</a>
&nbsp;<a href="/index.php?c=list&cid=45 http/1.0&page=3">尾页</a>

&nbsp;
1/3页, 

跳转到 <input type='text' id='topage' name='topage' size='4' />页
<script>
$("#topage").change(function(i){
    var count = 3;
    var page = parseInt($(this).val());
    if(page < 1 || isNaN(page)){
        page = 1;
    }else if(page > count){
        page = count;
    }
    
    var url = '/index.php?c=list&cid=45 http/1.0&page=_page_'.replace(/_page_/, page);
    window.location = url;
})
</script>            </div>
            </div>
        </div>
    </div>
</div>
    <div class="clear"></div>
</div>
</div>


<!--bottom-->
<div id="bottom">
	<div class="b_menu">
	<ul>
	</a></li>
	 <li><a href="#">网站导航</a></li>
	 <li><a href="#">法律申明</a></li>
	 <li><a href="#">版权所有</a></li>
	 <li><a href="#">联系我们</a></li>
	 <li style="background:none;"><a href="#"> 学校主页</a></li>
	 </ul>
</div>
	<div class="admin">
		©2013 电子科技大学科学技术发展研究院 All rights reserved. <br />
 		<a href="admin.php" target="_blank"><img src="images/admin.gif" /></a>
	</div>
	<div class="clear"></div>
</div>
</body>
</html>