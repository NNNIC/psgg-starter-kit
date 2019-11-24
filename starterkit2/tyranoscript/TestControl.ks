
[iscript]
    f.curstate = '';
    f.nextstate = '';
    f.yesno = 0;
    f.butval='';
    f.clkval='';
    f.glkval='';
    f.lnkval='';
    f.callstack=[];
[endscript]

[jump target=*S_START]

; [SYN-G-GEN OUTPUT START]  indent(0) $/./$
;  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
;------------------------------
;    S_ABOUT_LOOP
;
*S_ABOUT_LOOP
[iscript]
    f.curstate = 'S_ABOUT_LOOP';
    f.nextstate ='';
    f.yesno=0;
[endscript]
次は、ループを試してみよう。[p]
ループは、[p]
初期値・・・・・ f.count = 0 とか[p]
条件・・・・・・・ f.count < 10 とか[p]
再初期化・・・ f.count = f.count + 1 とか [p]
設定するんだよ。[p]
繰り返す内容は、サブルーチンで実装するんだよ。[p]
*S_ABOUT_LOOP___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_LOOP1';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_ABOUT_LOOP
;
;------------------------------
;    S_ADJUST_CHARAREGION
;    文字が表示される領域を調整
*S_ADJUST_CHARAREGION
[iscript]
    f.curstate = 'S_ADJUST_CHARAREGION';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[position layer=message0 page=fore margint="45" marginl="50" marginr="70" marginb="60"]
*S_ADJUST_CHARAREGION___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SHOW_MSGWINDOW';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_ADJUST_CHARAREGION
;
;------------------------------
;    S_AKANE_EMOTION
;    キャラクターの表情登録
*S_AKANE_EMOTION
[iscript]
    f.curstate = 'S_AKANE_EMOTION';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_face name="akane" face="angry" storage="chara/akane/angry.png"]
[chara_face name="akane" face="doki" storage="chara/akane/doki.png"]
[chara_face name="akane" face="happy" storage="chara/akane/happy.png"]
[chara_face name="akane" face="sad" storage="chara/akane/sad.png"]
*S_AKANE_EMOTION___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SETUP_YAMATO';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_AKANE_EMOTION
;
;------------------------------
;    S_CHECK_COUNT
;
*S_CHECK_COUNT
[iscript]
    f.curstate = 'S_CHECK_COUNT';
    f.nextstate ='';
    f.yesno=0;
[endscript]
*S_CHECK_COUNT___branch
;
; BRANCH
;
[iscript]
    if ( f.count < 2 ) {  f.nextstate='S_SHOW_AKANE4'; }
    else if ( f.count < 4 ) {  f.nextstate='S_SHOW_AKANE5'; }
    else if ( f.count < 8 ) {  f.nextstate='S_SHOW_AKANE6'; }
    else if ( f.count < 9 ) {  f.nextstate='S_SHOW_AKANE8'; }
    else {  f.nextstate = 'S_SHOW_AKANE7'; }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_CHECK_COUNT
;
;------------------------------
;    S_DISP_MENU
;    メニューボタンの表示
*S_DISP_MENU
[iscript]
    f.curstate = 'S_DISP_MENU';
    f.nextstate ='';
    f.yesno=0;
[endscript]
@showmenubutton
*S_DISP_MENU___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SETUP_MESSAGEWINDOW';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_DISP_MENU
;
;------------------------------
;    S_END
;
*S_END
[iscript]
    f.curstate = 'S_END';
    f.nextstate ='';
    f.yesno=0;
[endscript]
;
; typ = end
;
[s]
[jump target=&f.curstate]
;------------------------------
;    S_FIRSTSTEP
;
*S_FIRSTSTEP
[iscript]
    f.curstate = 'S_FIRSTSTEP';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[title name="ティラノスクリプト解説"]
[stop_keyconfig]
@call storage="tyrano.ks"
@layopt layer="message" visible=false
[hidemenubutton]
*S_FIRSTSTEP___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_TITLE';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_FIRSTSTEP
;
;------------------------------
;    S_GOSUB1
;
*S_GOSUB1
[iscript]
    f.curstate = 'S_GOSUB1';
    f.nextstate ='';
    f.yesno=0;
[endscript]
;
; typ = gosub
;
[iscript]
    f.callstack.push('S_OK_GOSUB');
    f.nextstate = 'S_SUBSTART1';
[endscript]
[jump target=&f.nextstate]
;------------------------------
;    S_LOOP1
;    あかねを１０回よぶ
*S_LOOP1
[iscript]
    f.curstate = 'S_LOOP1';
    f.nextstate ='';
    f.yesno=0;
[endscript]
;
; typ = loop
;
[iscript]
    f.count = 0;
    f.nextstate = 'S_LOOP1_LoopCheckAndGosub____';
[endscript]
[jump target=&f.nextstate]
*S_LOOP1_LoopCheckAndGosub____
[iscript]
    f.curstate = 'S_LOOP1_LoopCheckAndGosub____';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[iscript]
    if (f.count < 10) {
        f.callstack.push('S_LOOP1_LoopNext____');
        f.nextstate = 'S_SUBSTART2';
    }
    else {
        f.nextstate='S_SERIF02';
    }
[endscript]
[jump target=&f.nextstate]
*S_LOOP1_LoopNext____
[iscript]
    f.curstate = 'S_LOOP1_LoopNext____';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[iscript]
    f.count = f.count + 1;
    f.nextstate ='S_LOOP1_LoopCheckAndGosub____';
[endscript]
[jump target=&f.nextstate]
;------------------------------
;    S_OK_GOSUB
;
*S_OK_GOSUB
[iscript]
    f.curstate = 'S_OK_GOSUB';
    f.nextstate ='';
    f.yesno=0;
[endscript]
お、成功したようだね。[p]
*S_OK_GOSUB___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_ABOUT_LOOP';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_OK_GOSUB
;
;------------------------------
;    S_OWARI
;
*S_OWARI
[iscript]
    f.curstate = 'S_OWARI';
    f.nextstate ='';
    f.yesno=0;
[endscript]
サンプルの終わりだよ。[p]
*S_OWARI___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_END';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_OWARI
;
;------------------------------
;    S_RETURN1
;
*S_RETURN1
[iscript]
    f.curstate = 'S_RETURN1';
    f.nextstate ='';
    f.yesno=0;
[endscript]
;
; typ = subreturn
;
[iscript]
    f.nextstate = f.callstack.pop();
[endscript]
[jump target=&f.nextstate]
;------------------------------
;    S_RETURN2
;
*S_RETURN2
[iscript]
    f.curstate = 'S_RETURN2';
    f.nextstate ='';
    f.yesno=0;
[endscript]
;
; typ = subreturn
;
[iscript]
    f.nextstate = f.callstack.pop();
[endscript]
[jump target=&f.nextstate]
;------------------------------
;    S_SCENE_1
;
*S_SCENE_1
[iscript]
    f.curstate = 'S_SCENE_1';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[cm  ]
[clearfix]
[start_keyconfig]
@bg storage="room.jpg"
*S_SCENE_1___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_DISP_MENU';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SCENE_1
;
;------------------------------
;    S_SERIF01
;
*S_SERIF01
[iscript]
    f.curstate = 'S_SERIF01';
    f.nextstate ='';
    f.yesno=0;
[endscript]
#
StateGoの新機能、サブルーチンを試してみるか。[p]
よんでみるぞ…[p]
呼びたいサブルーチンに接続すればいいだけだ。[p]
*S_SERIF01___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_GOSUB1';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SERIF01
;
;------------------------------
;    S_SERIF02
;
*S_SERIF02
[iscript]
    f.curstate = 'S_SERIF02';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[font  size="30"   ]
これで大成功だ！[p]
[resetfont  ]
*S_SERIF02___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_OWARI';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SERIF02
;
;------------------------------
;    S_SET_CHARNAMEAREA
;    キャラクターの名前が表示される文字領域
*S_SET_CHARNAMEAREA
[iscript]
    f.curstate = 'S_SET_CHARNAMEAREA';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[ptext name="chara_name_area" layer="message0" color="white" size=24 x=50 y=410]
[chara_config ptext="chara_name_area"]
*S_SET_CHARNAMEAREA___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SETUP_AKANE';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SET_CHARNAMEAREA
;
;------------------------------
;    S_SETUP_AKANE
;    このゲームで登場するキャラクターを宣言
*S_SETUP_AKANE
[iscript]
    f.curstate = 'S_SETUP_AKANE';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_new  name="akane" storage="chara/akane/normal.png" jname="あかね"  ]
*S_SETUP_AKANE___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_AKANE_EMOTION';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SETUP_AKANE
;
;------------------------------
;    S_SETUP_MESSAGEWINDOW
;    メッセージウィンドウの設定
*S_SETUP_MESSAGEWINDOW
[iscript]
    f.curstate = 'S_SETUP_MESSAGEWINDOW';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[position layer="message0" left=20 top=400 width=920 height=200 page=fore visible=true]
*S_SETUP_MESSAGEWINDOW___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_ADJUST_CHARAREGION';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SETUP_MESSAGEWINDOW
;
;------------------------------
;    S_SETUP_YAMATO
;
*S_SETUP_YAMATO
[iscript]
    f.curstate = 'S_SETUP_YAMATO';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_new  name="yamato"  storage="chara/yamato/normal.png" jname="やまと" ]
*S_SETUP_YAMATO___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SERIF01';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SETUP_YAMATO
;
;------------------------------
;    S_SHOW_AKANE1
;
*S_SHOW_AKANE1
[iscript]
    f.curstate = 'S_SHOW_AKANE1';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_show  name="akane"  ]
サブルーチンの中のあかねよ[p]
直ぐに消えるわ…[p]
*S_SHOW_AKANE1___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SHOW_AKANE2';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_AKANE1
;
;------------------------------
;    S_SHOW_AKANE2
;
*S_SHOW_AKANE2
[iscript]
    f.curstate = 'S_SHOW_AKANE2';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_hide  name="akane"  ]
*S_SHOW_AKANE2___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_RETURN1';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_AKANE2
;
;------------------------------
;    S_SHOW_AKANE3
;
*S_SHOW_AKANE3
[iscript]
    f.curstate = 'S_SHOW_AKANE3';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_hide  name="akane"  ]
*S_SHOW_AKANE3___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_RETURN2';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_AKANE3
;
;------------------------------
;    S_SHOW_AKANE4
;
*S_SHOW_AKANE4
[iscript]
    f.curstate = 'S_SHOW_AKANE4';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_show  name="akane"  ]
サブルーチンの中のあかねよ[p]
直ぐに消えるわ…[p]
*S_SHOW_AKANE4___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SHOW_AKANE3';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_AKANE4
;
;------------------------------
;    S_SHOW_AKANE5
;
*S_SHOW_AKANE5
[iscript]
    f.curstate = 'S_SHOW_AKANE5';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_show  name="akane"  ]
いい加減にしてくれない![p]
*S_SHOW_AKANE5___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SHOW_AKANE3';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_AKANE5
;
;------------------------------
;    S_SHOW_AKANE6
;
*S_SHOW_AKANE6
[iscript]
    f.curstate = 'S_SHOW_AKANE6';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_show  name="akane"  ]
またね・・・[p]
*S_SHOW_AKANE6___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SHOW_AKANE3';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_AKANE6
;
;------------------------------
;    S_SHOW_AKANE7
;
*S_SHOW_AKANE7
[iscript]
    f.curstate = 'S_SHOW_AKANE7';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_show  name="akane" ]
おしまいよ！[p]
*S_SHOW_AKANE7___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SHOW_AKANE3';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_AKANE7
;
;------------------------------
;    S_SHOW_AKANE8
;
*S_SHOW_AKANE8
[iscript]
    f.curstate = 'S_SHOW_AKANE8';
    f.nextstate ='';
    f.yesno=0;
[endscript]
[chara_show  name="akane"  ]
好きよね・・・[p]
*S_SHOW_AKANE8___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SHOW_AKANE3';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_AKANE8
;
;------------------------------
;    S_SHOW_MSGWINDOW
;    メッセージウィンドウの表示
*S_SHOW_MSGWINDOW
[iscript]
    f.curstate = 'S_SHOW_MSGWINDOW';
    f.nextstate ='';
    f.yesno=0;
[endscript]
@layopt layer=message0 visible=true
*S_SHOW_MSGWINDOW___branch
;
; BRANCH
;
[iscript]
    if (f.nextstate == '') {
        f.nextstate = 'S_SET_CHARNAMEAREA';
    }
[endscript]
[jump target=&f.nextstate]
;
; END OF S_SHOW_MSGWINDOW
;
;------------------------------
;    S_START
;
*S_START
[iscript]
    f.curstate = 'S_START';
    f.nextstate ='';
    f.yesno=0;
[endscript]
;
; typ = start
;
[iscript]
    f.nextstate = 'S_FIRSTSTEP';
[endscript]
[jump target=&f.nextstate]
;------------------------------
;    S_SUBSTART1
;
*S_SUBSTART1
[iscript]
    f.curstate = 'S_SUBSTART1';
    f.nextstate ='';
    f.yesno=0;
[endscript]
;
; typ = substart
;
[iscript]
    f.nextstate = 'S_SHOW_AKANE1';
[endscript]
[jump target=&f.nextstate]
;------------------------------
;    S_SUBSTART2
;
*S_SUBSTART2
[iscript]
    f.curstate = 'S_SUBSTART2';
    f.nextstate ='';
    f.yesno=0;
[endscript]
;
; typ = substart
;
[iscript]
    f.nextstate = 'S_CHECK_COUNT';
[endscript]
[jump target=&f.nextstate]
;------------------------------
;    S_TITLE
;    タイトル表示
*S_TITLE
[iscript]
    f.curstate = 'S_TITLE';
    f.nextstate ='';
    f.yesno=0;
[endscript]
@bg storage="title.jpg"
[iscript]
    f.butval='';
[endscript]
[button x=100 y=250 graphic="title/button_start.png" target="S_TITLE___buttonlabel_START"]
[button x=100 y=320 graphic="title/button_load.png"  role="load" ]
[button x=100 y=390 graphic="title/button_cg.png" storage="cg.ks" ]
[button x=100 y=460 graphic="title/button_replay.png" storage="replay.ks" ]
[button x=100 y=530 graphic="title/button_config.png" role="sleepgame" storage="config.ks" ]
[s]
*S_TITLE___branch
;
; BRANCH
;
[iscript]
    if ( f.butval == 'START' ) {  f.nextstate='S_SCENE_1'; }
[endscript]
[jump target=&f.nextstate]
;
; BUTTON LABEL
;
*S_TITLE___buttonlabel_START
[iscript]
    f.butval = 'START'
[endscript]
[jump target="S_TITLE___branch"]
;
; END OF S_TITLE
;


; [SYN-G-GEN OUTPUT END]

