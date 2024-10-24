<?php

	include 'view/include/initialization.inc';
	include 'controller/component/component.php';

	ob_start();

	session_start();

    $logo = 'view/logo/favicon.svg';
    $title = 'Attacker';
    $style = $user_style;
    $script = $user_script;

    include 'view/include/header.inc';
    include 'view/include/navbar.php';
    include 'view/public/scan/scan.php';
    include 'view/public/attack/attack.php';
    include 'view/public/info.php';

	ob_end_flush();

	include 'view/include/footer.inc';

?>

<?php 

//$request = $_SERVER['REQUEST_URI'];
//if($request == '/home'):
/*if($action == 'login'):*/

/*elseif ($action == 'sign'):

	$title = 'Sign';

elseif ($action == 'forget'):

	$title = 'Forget Password';

elseif ($action == 'privacy'):

	$title = 'Police Privacy';

else:

	$title = 'Not Found 404';
	echo 'page is not found 404';

endif;*/

//header($_SERVER['PHP_SELF']);
/*if($request == '/login'):
	require __DIR__ . '/public/template/user_info/user_info.php';
elseif($request == '/home'):
	require __DIR__ . '/public/template/home/home.php';
endif;*/ 

?>