<?php 
	include('../../picturepc.inc');
?>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<title>ToDo List</title>
		<link rel="stylesheet" type="text/css" href="style.css" />
		<?php load_jquery(); ?>
		<script type="text/javascript">
			$(document).ready(function(){
				$("#page-wrap").load("update.php");
				setInterval('$("#page-wrap").load("update.php")', 240000);
			});
			
			$(window).ready(function(){
//				$("div").hide();
			});
		</script>
	</head>
	<body>
		<div id="page-wrap"></div>
	</body>
</html>
	
