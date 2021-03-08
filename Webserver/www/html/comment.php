<html>
<body>
<!-- <h1>Thank you for leaving a comment</h1> -->
<h1>Thank you <?php echo $_GET['FirstName'] . ' ' . $_GET['LastName']; ?> for leaving a comment!</h1>
<?php
echo "Comment left:<br>" . $_GET['Message'];
echo "<br><br>";
echo "Today's date is " . date('Y-m-d') . '<br>' ;
?>
</body>
</html>