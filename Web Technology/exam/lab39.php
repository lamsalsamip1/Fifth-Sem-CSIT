<!DOCTYPE html>
<html>
  <body>

    <form method="post" action="lab39.php">
      Name: <input type="text" name="name">
      <input type="submit">
    </form>

    <?php
     if (isset($_POST['name'])) $name = $_POST['name'];
     else $name = "(Not entered)"; 
        if (empty($name)) {
          echo "Name is empty";
        } else {
          echo "Hello, $name!";
        }
      
    ?>

  </body>
</html>