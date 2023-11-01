<?php
$in = ">?)8'1<$9'\"8526,03(-##4#030(3:>+0/%,'!& 8#%?5\"6-";
$out = "";
$chars = str_split($in);
var_dump(count($chars));
foreach ($chars as $char) {
    $bin = decbin(ord($char));
    $bin = substr($bin, 0 -5);
    $out .= $bin;
}
// var_dump($out);
$chunks = str_split($out, 8);
foreach ($chunks as $chunk) {
    //var_dump($chunk);
    $x = (int) bindec($chunk);
    $t = $x ^ 164;
    $out = chr($t);
    // var_dump($x, $t, $out);
    var_dump($out);
}
var_dump(count($chunks));
