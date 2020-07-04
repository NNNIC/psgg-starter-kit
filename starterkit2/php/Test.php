<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="ja">
<head>
<meta http-equiv="Content-Type" 
        content="text/html; charset=utf-8">
<title>TEST</title>
</head>

<body>
<p><?php echo date("Y/m/d")."<br>"; 

    require('TestControl.php');

    $sm = new TestControl();
    $sm->Start();

    while($sm->IsEnd()==FALSE) {
        $sm->Update();        
    }

?> </p>
</body>
</html>