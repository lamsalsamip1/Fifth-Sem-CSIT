<html>
    <body>

    <table>
        <tr>
            <td>Product Code</td>
            <td>Product Name</td>
            <td>Price</td>
        </tr>
    
    <?php

$product = array(
    "pcode"=>array("p01","p02","p03","p04","p05"),
    "pname"=>array("Keyboard","Mouse","Monitor","CPU","Speaker"),
    "price"=>array(1000,500,5000,10000,2000)

);
// foreach $product as $row{
//     echo"<tr>";
//     foreach $row as $value{
//         echo "<td>$value</td>"
//     }
//     echo "></tr>";
// }
for($i=0;$i<count($product['pcode']);$i++){
    echo"<tr>";
    echo"<td>".$product['pcode'][$i]."</td>";
    echo"<td>".$product['pname'][$i]."</td>";
    echo"<td>".$product['price'][$i]."</td>";
    echo"</tr>";
}

?>
    </body>
</html>



