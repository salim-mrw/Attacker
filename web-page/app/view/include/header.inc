<!DOCTYPE html>
<html lang="en" data-theme="light">
	<head>
		<title><?=$title;?></title>
		<meta charset="utf-8"/>
		<meta name="theme-color" media="(prefers-color-scheme: light)" content="var(--mode-color)" />
		<meta name="theme-color" media="(prefers-color-scheme: dark)" content="var(--mode-color)" />
		<link rel="manifest" href='manifest.json'>
		<link rel="icon" sizes="192x192" href="<?=$logo;?>"/>
		<script src="app/module/qrcode.js"></script>
		<!--<script src="app/module/fullcalendar/index.global.min.js"></script>
		<script src="app/module/chart.js"></script>-->
		<link rel="stylesheet" href="app/module/googlefont/font.css" />
		<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
		<link rel="stylesheet" href="<?=$style;?>"/>
	</head>
	<body class="pt-0 pb-5 bg-dark text-light">