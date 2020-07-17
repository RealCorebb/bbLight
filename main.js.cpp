#include <pgmspace.h>
char main_js[] PROGMEM = R"=====(
window.addEventListener('load', setup);
function handle_M_B_S(e) {
  e.preventDefault();
  var name = e.target.className;
  var val = e.target.id;
  if(e.target.className.indexOf('m') > -1) {
    elems = document.querySelectorAll('#mode li a');
    [].forEach.call(elems, function(el) {
      el.classList.remove('active');
      name = e.target.className;
    });
    e.target.classList.add('active');
  }
  submitVal(name, val);
}
var r = "255";
var g = "255";
var b = "255";
function cutHex(h) {return (h.charAt(0)=="#") ? h.substring(1,7):h}
function HexToR(h) {return parseInt((cutHex(h)).substring(0,2),16)}
function HexToG(h) {return parseInt((cutHex(h)).substring(2,4),16)}
function HexToB(h) {return parseInt((cutHex(h)).substring(4,6),16)}

function onChangeColor() {
  
   r = HexToR(this.value).toString();
   g = HexToG(this.value).toString();
   b = HexToB(this.value).toString();
   w = document.getElementById("gamma").value;
   var newcolor = r+','+g+','+b+','+w;
   console.log(newcolor);
   submitVal('C', newcolor)
}
function onChangeGamma() {
  
   w = document.getElementById("gamma").value;
   var newcolor = r+','+g+','+b+','+w;
   console.log(newcolor);
   submitVal('C', newcolor)
}
function submitVal(name, val) {
  var xhttp = new XMLHttpRequest();
  xhttp.open('GET', 'set?' + name + '=' + val, true);
  xhttp.send();
}




function setup(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (xhttp.readyState == 4 && xhttp.status == 200) {
      document.getElementById('mode').innerHTML = xhttp.responseText;
      elems = document.querySelectorAll('ul li a'); // adds listener also to existing s and b buttons
      [].forEach.call(elems, function(el) {
        el.addEventListener('touchstart', handle_M_B_S, false);
        el.addEventListener('click', handle_M_B_S, false);
      });
    }
  };
  document.getElementById("color").addEventListener("change", onChangeColor);
  document.getElementById("gamma").addEventListener("change", onChangeGamma);
  xhttp.open('GET', 'modes', true);
  xhttp.send();
}
)=====";
