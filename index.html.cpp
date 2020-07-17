#include <pgmspace.h>
char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang='en'>
<head>
  <meta http-equiv='Content-Type' content='text/html; charset=utf-8' />
  <meta name='viewport' content='width=device-width' />

  <title>bbLight Control</title>

  <script type='text/javascript' src='main.js'></script>

  <style>
  * {
    font-family:sans-serif;
    margin:0;
    padding:0;
  }

  body {
    width:100%;
    background-color:#202020;
  }
  
  h1 {
    width:65%;
  margin:0 auto;
    padding-bottom:30px;
  padding-top:30px;
    color:#454545;
    text-align:center;
  }
  div {
  width:25%;
  margin:0 auto;
  }
  #colorbar {
    left:50%;
  padding-bottom:30px;
  }
  #controls {
    width:65%;
    margin:0 auto;
    
  }
  details{
  color:#cccccc;
  font-size:20px;
  padding-bottom:10px;
  text-align:center;
  }
  ul {
    text-align:center;
  }

  ul#mode li {
    display:block;
  }

  ul#brightness li, ul#speed li, ul#auto li {
    display:inline-block;
    width:30%;
  }

  ul li a {
    display:block;
    margin:3px;
    padding:10px 5px;
    border:2px solid #454545;
    border-radius:5px;
    color:#454545;
    font-weight:bold;
    text-decoration:none;
  }

  ul li a.active {
    border:2px solid #909090;
    color:#909090;
  }
  </style>
</head>
<body>
  <h1>bbLight Control</h1>
  <div id='colobars' style="width:400px;margin:0 auto">
  <input type="color" id="color" name="c" style="width:400px;height:180px;margin:0 auto" value="#ff0000">
  <br><br>
  <label for="gamma" style="padding:2px;font-size:28px;text-align:center;border:2px solid #454545;background-color:#202020;color:#454545;border-radius:5px">Gamma</label> 
  <input type="range" id="gamma" name="gamma" style="width:280px"
         min="0" max="255">
  </input>
  <br><br>
  </div>
  <div id='controls'>
  <details>
  <summary>模式选择</summary>
    <ul id='mode'></ul>
</details>
    <ul id='brightness'>

      <li><a href='#' class='b' id='-'>&#9788;</a></li>
      <li><a href='#' class='b' id='+'>&#9728;</a></li>
    </ul>

    <ul id='speed'>
      <li><a href='#' class='s' id='-'>&#8722;</a></li>
      <li><a href='#' class='s' id='+'>&#43;</a></li>
    </ul>

    <ul id='auto'>
      <li><a href='#' class='a' id='-'>&#9632;</a></li>
      <li><a href='#' class='a' id='+'>&#9658;</a></li>
    </ul>
  </div>
</body>
</html>
)=====";
